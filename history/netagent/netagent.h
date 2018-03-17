#ifndef __CMD_H__
#define __CMD_H__

#define MAX_MSG_SIZE 2048
#define SERV_PORT 8888
#define MNF 10
/*ÿ���������*/
/*�������10̨��������*/
#define MAX_REQUEST 10
/*ÿ̨������ദ��128������*/
#define MAX_CMD_CNT 128
/*ÿ��������󳤶�255*/
#define MAX_CMD_LEN 255
#define RET_SP	"��"
#define REQ_SP  "��"
#define CMD_SP  ":"
#define IP2CMD_SP "��"

struct HostList{
	/*��һ�ڵ�!*/
	struct HostList *pNext;
	char sIpAddr[16];
	int iPort;
};

int ProcessMessage(int iSockFd, struct sockaddr_in *pCliAddr,
	 socklen_t iCliLen,char sMessage[]);
struct HostList *SearchHost(char sIpAddr[],struct HostList *pHead);
int request(char sIp[], int iPort, char sMsg[],...);
void do_Action(int iSockFd, struct sockaddr_in *pCliAddr, socklen_t iCliLen);
int Parse_Host(char sLine[],struct HostList *pHost);
int LoadHostList(char sFileName[],struct HostList **pptHead);
int SendToAllServer(struct HostList *pHostList, char sExceptHost1[],
	char sExceptHost2[],char sMessage[],...);
	
#endif
