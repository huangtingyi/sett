#ifndef __WWTELNET_H__
#define __WWTELNET_H__
  /* These are the telnet command constansts from RFC 854 */
  #define TNC_EOR        239   /* End of Record RFC 885                  */
  #define TNC_SE         240   /* End of subnegotiation parameters.      */             
  #define TNC_NOP        241   /* No operation.                          */             
  #define TNC_DATA_MARK  242   /* The data stream portion of a Synch.    */             
                                  /* This should always be accompanied   */             
                                  /* by a TCP Urgent notification.       */             
  #define TNC_BREAK      243   /* NVT character BRK.                     */             
  #define TNC_IP         244   /* The function IP.                       */
  #define TNC_AO         245   /* The function ABORT OUTPUT.             */
  #define TNC_AYT        246   /* The function ARE YOU THERE.            */
  #define TNC_EC         247   /* The function ERASE CHARACTER.          */
  #define TNC_EL         248   /* The function ERASE LINE.               */
  #define TNC_GA         249   /* The GO AHEAD signal.                   */
  #define TNC_SB         250   /* Indicates that what follows is         */
                                  /* subnegotiation of the indicated     */
                                  /* option.                             */
  #define TNC_WILL       251   /* Indicates the desire to begin          */
                                  /* performing, or confirmation that    */
                                  /* you are now performing, the         */
                                  /* indicated option.                   */
  #define TNC_WONT       252   /* Indicates the refusal to perform,      */
                                  /* or continue performing, the         */
                                  /* indicated option.                   */
  #define TNC_DO         253   /* Indicates the request that the         */
                                  /* other party perform, or             */
                                  /* confirmation that you are expecting */
                                  /* the other party to perform, the     */
                                  /* indicated option.                   */
  #define TNC_DONT       254   /* Indicates the demand that the          */
                                  /* other party stop performing,        */
                                  /* or confirmation that you are no     */
                                  /* longer expecting the other party    */
                                  /* to perform, the indicated option.   */
  #define TNC_IAC        255   /* Data Byte 255.                         */
                                                                                      
  /* Telnet options from RFC 1010 */                                                  
  #define TNO_BINARY       0      /* Binary Transmission                   */
  #define TNO_ECHO         1      /* Echo                                  */
  #define TNO_RECONNECT    2      /* Reconnection                          */
  #define TNO_SGA          3      /* Suppress Go Ahead                     */
  #define TNO_AMSN         4      /* Approx Message Size Negotiation       */
  #define TNO_STATUS       5      /* Status                                */
  #define TNO_TIMING_MARK  6      /* Timing Mark                           */
  #define TNO_RCTE         7      /* Remote Controlled Trans and Echo -BELL*/
  #define TNO_OLW          8      /* Output Line Width                     */
  #define TNO_OPS          9      /* Output Page Size                      */
  #define TNO_OCRD         10     /* Output Carriage-Return Disposition    */
  #define TNO_OHTS         11     /* Output Horizontal Tab Stops           */
  #define TNO_OHTD         12     /* Output Horizontal Tab Disposition     */
  #define TNO_OFD          13     /* Output Formfeed Disposition           */
  #define TNO_OVT          14     /* Output Vertical Tabstops              */
  #define TNO_OVTD         15     /* Output Vertical Tab Disposition       */
  #define TNO_OLD          16     /* Output Linefeed Disposition           */
  #define TNO_EA           17     /* Extended ASCII                        */
  #define TNO_LOGOUT       18     /* Logout                                */
  #define TNO_BYTE_MACRO   19     /* Byte Macro                            */
  #define TNO_DET          20     /* Data Entry Terminal                   */
  #define TNO_SUPDUP       21     /* SUPDUP                                */
  #define TNO_SUPDUP_OUTPUT 22     /* SUPDUP Output                        */
  #define TNO_SL           23     /* Send Location                         */
  #define TNO_TERMTYPE     24     /* Terminal Type                         */
  #define TNO_EOR          25     /* End of Record                         */
  #define TNO_TACACS_ID    26     /* TACACS User Identification            */
  #define TNO_OM           27     /* Output Marking                        */
  #define TNO_TLN          28     /* Terminal Location Number              */
  #define TNO_3270REGIME   29     /* 3270 regime                           */
  #define TNO_X3PAD	   30     /* X.3 PAD                               */
  #define TNO_NAWS      	 31     /* Window size                     */
  #define TNO_TERM_SPEED   32     /* Terminal speed                        */
  #define TNO_RFLOW        33     /* Remote flow control                   */
  #define TNO_LINEMODE     34     /* Linemode option                       */
  #define TNO_XDISPLOC	   35     /* X Display Location                    */
  #define TNO_AUTH         37     /* Authenticate                          */
  #define TNO_ENCRYPT      38     /* Encryption option                     */
                                                                               
  #define TNO_EOL          255    /* Extended-Options-List  [84,JBP]       */              
                                                                                
  /*Sub options*/                                                               
  #define TNOS_TERM_IS     0                                                 
  #define TNOS_TERMTYPE_SEND 1      /* Sub option                          */
  #define TNOS_REPLY       2
  #define TNOS_NAME        3

  #define TNSDATA        1 
  #define TNSIAC         2 
  #define TNSIAC_SB      3 
  #define TNSIAC_WILL    4 
  #define TNSIAC_DO      5 
  #define TNSIAC_WONT    6 
  #define TNSIAC_DONT    7 
  #define TNSIAC_SBIAC   8 
  #define TNSIAC_SBDATA  9 
  #define TNSSBDATA_IAC  10
  
  
  #define MAX_CMD_LEN 8192
  #define true 1
  #define false 0
  
  
/*
  以下结构中的
  	char sLogPrompt[128];
  	char sPwdPrompt[128];
  	char sLoginedPrompt[128];
  三项内容设置相关提示符，当反回结果中包含此内容表示执行到相应步骤
  则进行下一步处理，以方便针对不同服务器使用.
  sLogPrompt:输出用户提示符时的提示.
  sPwdPrompt:要求输入密码时的提示
  sLoginedPrompt:登陆成功后的提示符。
  三项内容最好不要重叠。
  注意:由于不同服务器实现,网络及缓冲区满等原因，可能导致同一字符串分多次返回导致错误如：
  aix5.2上输入密码提示可能是：(1)bill's P (2)assword:两次返回所以sPwdPrompt可能要设置为assword:
  例:aix5.2 loginprompt:login pwdprompt:assword sLoginedprompt:Welcome  
*/
struct TelnetStruct
{
  	/*以下进行操作前需要初始化*/
  	int  iPort;
  	int  iTimeOut;
  	char sHost[16];
  	char sUserName[128];
  	char sPassword[128];
  	char sLoginPrompt[128];
  	char sPasswordPrompt[128];
  	char sLoginedPrompt[128];
  	
  	void (*OnDataRecv)( struct TelnetStruct *serv, char sData[] );
  	void (*OnLogined)( struct TelnetStruct *serv, char sData[] );
  	void (*OnTimeOut)( struct TelnetStruct *serv );
  	void (*OnDisconnect)( struct TelnetStruct *serv );  	
  	void (*OnError)( struct TelnetStruct *serv, char sMsg[], int iErrNo );
  	void (*ProcCmd)( struct TelnetStruct *serv );
  	
  	/*以下不需要手工初始化*/
  	int iSockFd; 	          
  	int iLogined;                  
};


int TelnetInitial(  struct TelnetStruct *serv,char sHost[], int iPort,
	char sUserName[],char sPassword[],
	char sLoginPrompt[], char sPasswordPrompt[], char sLoginedPrompt[] );
int TelnetProcMain( struct TelnetStruct *serv );
int TelnetDisconnect( struct TelnetStruct *serv );	
  
#endif







