#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <assert.h>
#include <string.h>

#include "list.h"
#include "wwfile.h"
#include "wwtiny.h"
#include "wwnet.h"
#include "wwtelnet.h"

/*
  注意：返回结果串中可能包含\0，所以一般不能用字符串库函数处理.
*/
int ProcessChr( int iSockFd, unsigned char ch,char sResultStr[] );
int TelnetSendCh( struct TelnetStruct *serv, char Ch );
int TelnetSendCmd( struct TelnetStruct *serv, char sCommand[], int iLen );
void WriteLiteralChar(char ch, char sResultStr[]);

/*关闭连接*/
int TelnetDisconnect( struct TelnetStruct *serv )
{
	TelnetSendCmd( serv, "exit", -1 );
	serv->OnDisconnect( serv );
	close(serv->iSockFd);
	return 0;
}

/*
发送命令行,结尾无\n的自动添加\n以执行命令
因为某些命令可能包含'\0'所以需要指定长度否则使用字符串方式处理
会有问题
iLen为 -1 时自动取strlen值.
*/
int TelnetSendCmd( struct TelnetStruct *serv, char sCommand[], int iLen )
{
	int iCmdLen,iRet;
	char *p=sCommand;

	iCmdLen = iLen;
	if ( iCmdLen == -1 )
		iCmdLen = strlen( sCommand );

	iRet = write( serv->iSockFd, p, iCmdLen );

	if ( sCommand[iCmdLen-1] != '\n' ){

		write( serv->iSockFd, "\n", 1 );
	}

	return iRet;
}

int TelnetInitial(  struct TelnetStruct *serv,char sHost[], int iPort,
	char sUserName[],char sPassword[],
	char sLoginPrompt[], char sPasswordPrompt[], char sLoginedPrompt[] )
{
	memset( serv, 0, sizeof( struct TelnetStruct ) );

	serv->iPort = iPort;
	serv->iTimeOut = 30;
	strcpy( serv->sHost, sHost );
	strcpy( serv->sUserName, sUserName);
	strcpy( serv->sPassword, sPassword);
	strcpy( serv->sLoginPrompt, sLoginPrompt );
	strcpy( serv->sPasswordPrompt, sPasswordPrompt );
	strcpy( serv->sLoginedPrompt, sLoginedPrompt );

	return 0;
}
int CheckLogin(char sInput[])
{
	char sTemp[8192];

	strcpy(sTemp,sInput);
	Upper(sTemp);

	if(strstr(sTemp,"INVALID")!=NULL)
		return false;
	if(strstr(sTemp,"INCORRECT")!=NULL)return false;
	if(strstr(sTemp,"ERROR")!=NULL)return false;
	if(strstr(sTemp,"FAIL")!=NULL)return false;
	if(strstr(sTemp,"TIMEOUT")!=NULL)return false;
	if(strstr(sTemp,"WRONG")!=NULL)return false;
	if(strstr(sTemp,"LOCKED")!=NULL)return false;
	if(strstr(sTemp,"ALREADY LOGGED ON")!=NULL)return false;
	return true;
}
int TelnetProcMain( struct TelnetStruct *serv )
{
	char sBuf[2048],sResultStr[8192],sTemp[128],*pRes;
	MY_FDSET iFdSet,iPreFdSet;
	int iTargetServerFd,i,iLen,iRet,iStep=0;

	/*确定以下函数不能不空*/
	assert( serv->OnDataRecv );
	assert( serv->OnLogined );
	assert( serv->OnTimeOut );
	assert( serv->OnError );
	assert( serv->ProcCmd );
	assert( serv->OnDisconnect );

	iTargetServerFd = ConnectTcpServer( serv->sHost, serv->iPort );
	if ( iTargetServerFd < 0 ){

		printf("无法连接目标服务器,进程退出!\n" );
		return -1;
	}

	serv->iSockFd = iTargetServerFd;
	serv->iLogined = false;

	InitMySet( &iFdSet );
	Item2MySet( &iFdSet, iTargetServerFd );

	while(1){

		iPreFdSet = iFdSet;

		/*在进行select前先进行发送*/
		if(serv->iLogined==true)
			serv->ProcCmd( serv );

		/* 时间为0表示阻塞,直至事件发生 */
		iRet=WaitMySetRead(FD_SETSIZE,serv->iTimeOut,&iPreFdSet);

		if(iRet<0){
	    		perror("select");
	    		serv->OnError(serv,"Select()返回-1,对端断开或出错.",-1);
	    		break;
		}

		if(iRet==0){
			serv->OnTimeOut( serv );
			continue;
		}

		if(SearchMySet(&iPreFdSet,iTargetServerFd)==FOUND){

			memset( sBuf, 0 , sizeof( sBuf ));
			memset( sResultStr, 0 , sizeof( sResultStr ));

			if((iLen=read(iTargetServerFd,sBuf,sizeof(sBuf)))<=0)
				break;

			/*服务器断开，或网络出错*/
			if(iLen<=0){
				serv->OnDisconnect( serv );
				break;
			}

			sBuf[iLen] = 0;

			for(i=0;i<iLen;i++)
				ProcessChr(iTargetServerFd,(unsigned char)sBuf[i],
					sResultStr);

			pRes = sResultStr;

			serv->OnDataRecv( serv, pRes );

			if(serv->iLogined==false){

				if(CheckLogin(pRes)==false){
					printf("登录失败,信息:\n");
					printf("%s\n",pRes);
					return -1;
				}
				if(strstr(pRes,serv->sLoginPrompt)!=NULL&&
					iStep==0){
					sprintf(sTemp,"%s\n",serv->sUserName);
					SockSendBuf(iTargetServerFd,sTemp,-1);
					iStep++;
				}

				if(strstr(pRes,serv->sPasswordPrompt)!=NULL&&
					iStep==1){
					sprintf(sTemp,"%s\n",serv->sPassword);
					SockSendBuf(iTargetServerFd,sTemp,-1);
					iStep++;
				}

				if(strstr(pRes,serv->sLoginedPrompt)!=NULL&&
					iStep==2){
					printf("\n\n登陆成功!\n\n");
					iStep++;
					serv->iLogined = true;
					serv->OnLogined( serv, pRes );
				}

			}
			fflush( stdout );
		}
	}/*endofwhile*/
	return 0;
}

int TelnetCmdAnswer( int iSockFd, unsigned char chAns,
	unsigned char chOption )
{
	char sBuf[128];

	sprintf( sBuf,"%c%c%c", TNC_IAC ,(char)chAns ,(char)chOption );

	return write( iSockFd, sBuf, 3 );
}

void WriteLiteralChar(char ch, char sResultStr[])
{
	/*putchar(ch);*/
	char sTemp[2];

	sTemp[0]=ch;
	sTemp[1]=0;
	strcat(sResultStr,sTemp);
}
int ProcessChr( int iSockFd, unsigned char ch,char sResultStr[] )
{
	static int bIAC = 0;
	static int bSubNegoc = 0;
	static int EscFlag = 0;
	static char unsigned chVerb ='\0';
	static int iSbCnt = 0;
	static char strSubOption[1024];

	char sSendBuf[1024];

	if ( chVerb != '\0' ){
		switch( ch ){
	     	case TNO_ECHO:
	     		switch ( chVerb ){
	                case TNC_WILL:
	                TelnetCmdAnswer( iSockFd, TNC_DONT, ch );
	                break;
	                case TNC_WONT:
	                TelnetCmdAnswer( iSockFd, TNC_DONT, ch);
	                break;
	        	}
	        	break;
	     	case TNO_SGA:
	     		if ( chVerb==TNC_WILL )
	     			TelnetCmdAnswer( iSockFd, TNC_DO, ch);
	     		break;
	     	case TNO_TERMTYPE:
	     		if ( chVerb == TNC_DO )
	     			TelnetCmdAnswer( iSockFd, TNC_WILL, ch);
	     		break;
	     	case TNO_SL:
	     		if ( chVerb == TNC_DO ){
	                     TelnetCmdAnswer( iSockFd, TNC_WILL, ch);
	                     sprintf(sSendBuf,"%c%c%c%s%c%c",TNC_IAC,TNC_SB,
	                     		TNO_SL ,"SinoTerm" ,TNC_IAC ,TNC_SE);
	                     SockSendBuf( iSockFd, sSendBuf, 13 );
	                }
	                break;
	     	case TNO_EOR:
	     		if ( chVerb == TNC_DO )
	     			TelnetCmdAnswer( iSockFd, TNC_WILL, ch);
	     		break;
	     	default:
	     		if ( chVerb == TNC_WILL )
	     			TelnetCmdAnswer( iSockFd, TNC_DONT, ch);
	     		else
	     			TelnetCmdAnswer( iSockFd, TNC_WONT, ch);
	     		break;
	    }
	    chVerb = '\0';
	    strSubOption[0] = '\0';
	    return 0;
	}
	if ( bSubNegoc != 0 ){
		if ( ch == TNC_SE ){
			bSubNegoc = false;
			if ((strSubOption[0] == TNO_TERMTYPE)
			   &&(strSubOption[1] == TNOS_TERMTYPE_SEND )){
	                        sprintf( sSendBuf, "%c%c%c%c%s%c%c",
	                        	TNC_IAC ,TNC_SB ,TNO_TERMTYPE ,
	                        	TNOS_TERM_IS,"ansi",TNC_IAC ,TNC_SE);
				SockSendBuf( iSockFd, sSendBuf, 10 );
			}
			strSubOption[0] = '\0';
		}
		else
			strSubOption[iSbCnt++] = ch;
		return 0;
	}

	if ( bIAC != 0 ){
		switch ( ch ){
			case TNC_IAC: /* Double 0xFF means one. */
				WriteLiteralChar(ch, sResultStr);
				break;
			case TNC_DO:
			case TNC_WILL:
			case TNC_DONT:
			case TNC_WONT:
				chVerb=ch;
				break;
			case TNC_SB:
				bSubNegoc=true;
				break;
		}
		bIAC = false;
		return 0;
	}

	if ( EscFlag != 0 ){
		printf("Esc\n");
	}

	switch ( ch ){
		case TNC_IAC:
			bIAC = true;
			break;
		default:
			WriteLiteralChar( ch, sResultStr );
			break;
	}

	return 0;
}

