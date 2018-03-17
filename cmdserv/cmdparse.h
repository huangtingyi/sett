#ifndef CMD_PARSE_H
#define CMD_PARSE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wwlog.h>
#include <wwfile.h>
#include <wwtiny.h>
#include <bintree.h>

#include "stt_ticket.h"
#include "cmdparse.h"
#include "cmdsupp.h"

/*定义业务类型*/
#define BUSI 11
#define QUERY 12

#define AKEYFLAG  1

#define SUBST "#{SUBST}"
#define NEWLINE "#{N}"
#define NEWLINEVAL "\n"

#define CMDHEAD "a"
#define CMDTAIL "b"
#define INIPATH "./"

#define DN		1 	/*电话号码                  */
#define IMSI		2 	/*IMSI                      */
#define ESN		3 	/*电子序列号                */
#define PIC             4 	/*长途线路                  */
#define AKEY            5 	/*鉴权码                    */
#define CHECKSUM        6 	/*(暂无定义,不使用)         */
#define KEYID           7 	/*(暂无定义,不使用)         */
#define PREPAIDY	8 	/*预付费标识是              */
#define PREPAIDN	9 	/*预付费标识否              */
#define SMS0R		10	/*短信发送许可              */
#define SMS0E		11	/*短信发送禁止              */
#define SMS1R		12	/*短信接收许可              */
#define SMS1E		13	/*短信接收禁止              */
#define SMS2R		14	/*短信收发许可              */
#define SMS2E		15	/*短信收发禁止              */
#define INETRIM0R  	16	/*所有来话许可              */
#define INETRIM0E  	17	/*所有来话禁止              */
#define INETRIM1R  	18	/*所有呼出许可              */
#define INETRIM1E  	19	/*所有呼出禁止              */
#define INETRIM2R  	20	/*所有来去话许可            */
#define INETRIM2E  	21	/*所有来去话禁止            */
#define ROAMING0R	22	/*本地漫游许可              */
#define ROAMING0E	23	/*本地漫游禁止              */
#define ROAMING1R	24	/*省内漫游许可              */
#define ROAMING1E	25	/*省内漫游禁止              */
#define ROAMING2R	26	/*国内漫游许可              */
#define ROAMING2E	27	/*国内漫游禁止              */
#define ROAMING3R	28	/*国际漫游许可              */
#define ROAMING3E	29	/*国际漫游禁止              */
#define BASICR		30	/*基本话音业务许可          */
#define BASICE		31	/*基本话音业务禁止          */
#define LOCALR		32	/*本地呼叫能力限定许可      */
#define LOCALE		33	/*本地呼叫能力限定禁止      */
#define VMRR		34	/*话音邮箱许可              */
#define VMRE		35	/*话音邮箱禁止              */
#define CFBR		36	/*遇忙前转许可              */
#define CFBE		37	/*遇忙前转禁止              */
#define CFNRR		38	/*无应答前转 许可           */
#define CFNRE		39	/*无应答前转 禁止           */
#define CFUR		40	/*立即转移许可              */
#define CFUE		41	/*立即转移禁止              */
#define CFCR		42	/*不可及的呼叫转移许可      */
#define CFCE		43	/*不可及的呼叫转移禁止      */
#define CTR		44	/*呼叫转移到语音信箱许可    */
#define CTE		45	/*呼叫转移到语音信箱禁止    */
#define MWNR		46	/*消息等待通知许可          */
#define MWNE		47	/*消息等待通知禁止          */
#define CWR		48	/*呼叫等待许可              */
#define CWE		49	/*呼叫等待禁止              */
#define CHR		50	/*呼叫保持许可              */
#define CHE		51	/*呼叫保持禁止              */
#define A3WCR		52	/*三方呼叫许可              */
#define A3WCE		53	/*三方呼叫禁止              */
#define CLIRR		54	/*主叫号码识别显示许可      */
#define CLIRE		55	/*主叫号码识别显示禁止      */
#define CNIRR		56	/*主叫号码识别限制许可      */
#define CNIRE		57	/*主叫号码识别限制禁止      */
#define CCR		58	/*会议电话许可              */
#define CCE		59	/*会议电话禁止              */
#define INTERNETR	60	/*互联网数据业务许可        */
#define INTERNETE	61	/*互联网数据业务禁止	    */

#define	COS		62	/*;COS值*/
#define	CRBTE		63	/*;取消炫铃*/
#define	ACCOUNTLOCK2E	64	/*;欠费复机:未加锁(甘肃用)*/
#define	ACCOUNTLOCK1R	65	/*;欠费停机:呼出锁(甘肃用)*/
#define	WINCOS6		66	/*;智能网(PPC)*/
#define	INTERIM2E	67	/*;呼入呼出业务限定*/
#define	USERLOCK2E	68	/*;报停复机:未加锁(甘肃用)*/
#define	INTERIM1E	69	/*;呼出业务限定*/
#define	USERLOCK0R	70	/*;主动停机:呼入锁(甘肃用)*/
#define	USERLOCK1R	71	/*;主动停机:呼出锁(甘肃用)*/
#define	WINCOS8		72	/*;智能网(VPN)*/
#define	INTERIM1R	73	/*;呼出业务限定*/
#define	INTERIM0E	74	/*;来话业务限定*/
#define	INTERIM2R	76	/*;呼入呼出业务限定*/
#define	STOLENLOCKR	77	/*;被盗锁(甘肃用)*/
#define	INTERIM0R	78	/*;来话业务限定*/
#define	CRBTR		79	/*;增加炫铃*/
#define	DUPLOCKR	80	/*;复制锁(甘肃用)*/
#define	SMPE		81	/*;智能网业务(甘肃用)*/
#define	STOLENLOCKE	82	/*;被盗锁(甘肃用)*/
#define	ACCOUNTLOCK2R	83	/*;欠费停机:呼入、呼出锁(甘肃用)*/
#define	ACCOUNTLOCK0R	84	/*;欠费停机:呼入锁(甘肃用)*/
#define	USERLOCK2R	85	/*;主动停机:呼入、呼出锁(甘肃用)*/
#define	SMPR		86	/*;智能网业务(甘肃用)*/
#define	DUPLOCKE	87	/*;复制锁(甘肃用)*/

#define	LSTCFD		88	/*;移动自由呼CFD(新疆用)*/
#define	LSTINTERIM	89	/*;查询来话业务限定*/
#define	LSTCFNA		90	/*;移动自由呼CFNA(新疆用)*/
#define	LSTROAMING	91	/*;ROAMING*/
#define	LSTCFB		92	/*;移动自由呼CFB(新疆用)*/
#define	LSTINTERNET	93	/*;查询INTERNET功能*/
#define	LSTWINSVR	94	/*;查询智能网功能*/
#define	INQCODE		95	/*;号码互查*/
#define	LSTCFU		96	/*;移动自由呼CFU(新疆用)*/
#define	LSTSMS		97	/*;查询短信服务*/
#define	LSTLOCAL	99	/*;LOCAL*/
#define	LSTSUPSVR	100	/*;查询用户补充业务*/

#define	CL0E		101	/*;彩铃业务*/
#define	CL0R		102	/*;彩铃业务*/
#define	PPCE		103	/*;智能业务PPC*/
#define	PPCR		104	/*;智能业务PPC*/
#define	VPNR		105	/*;智能业务VPN*/
#define	VPNE		106	/*;智能业务VPN*/
#define	RFCR		107	/*;远程业务控(甘肃用)*/
#define	RFCE		108	/*;远程业务控制(甘肃用)*/
#define	CFSVR0R		109	/*;移动自由呼:遇忙前转(新疆用)*/
#define	CFSVR0E		110	/*;移动自由呼:遇忙前转(新疆用)*/
#define	CFSVR1E		111	/*;移动自由呼:隐含条件前转(新疆用)*/
#define	CFSVR1R		112	/*;移动自由呼:隐含条件前转(新疆用)*/
#define	CFSVR2R		113	/*;移动自由呼:无应答前转(新疆用)*/
#define	CFSVR2E		114	/*;移动自由呼:无应答前转(新疆用)*/
#define	CFSVR3E		115	/*;移动自由呼:无条件前转(新疆用)*/
#define	CFSVR3R		116	/*;移动自由呼:无条件前转(新疆用)*/
#define	SMP0E		117	/*;智能业务(甘肃用)*/
#define	SMP1E		118	/*;智能业务(甘肃用)*/
#define	SMP1R		119	/*;智能业务(甘肃用)*/



struct CmdTable {
        char *sName;
        int iValue;
};

struct BusiTemplate{
	struct BusiTemplate *pNext;
	char sPrefix[128];
	char sCmdType[128];
	char sTemplate[1024];
};
struct ResultStruct{
	struct ResultStruct *pNext;
	
	char sName[128];
	char sTemplate[1024];
	char sSubParam[1024];
};


int InitialTemplate(char sMscType[],char sAreaCode[],struct BusiTemplate **pptHead);

int GetBusiTemplate(struct BusiTemplate *ptHead,char sName[],char sValue[]);
int BindValue(struct InfoItemStruct *ptInfoItem,char sSource[],char sResults[]);
int HasSubParam(char sTemplate[]);
struct InfoItemStruct *GenInfoItemList(char sInfoLine[],
	char cSepItem,char cSepVal);
void GetInfoItemValue(struct InfoItemStruct *ptHead,char sName[],
        char sValue[]);	
char *replace(char sSource[],char sPattern[],char sReplacement[],char sDest[]);
struct ResultStruct *AddCmd(char sValue[],char sSubSt[],struct ResultStruct **pptHead);
int ProcCmd(int(*Proc)(int iBusi,struct ResultStruct **pptHead),
	struct InfoItemStruct *ptInfoItem,char sCmdType[],struct ResultStruct **pptResult);
struct InfoItemStruct * GetItemValue(struct InfoItemStruct *ptHead,char sName[],char sValue[]);
void SwapItemValue(char sNameA[],char sNameB[],struct InfoItemStruct *ptInfoItem);
int GetBusiCode(struct InfoItemStruct *ptInfoItem);
int SearchBusiCode(char sName[]);
int IsValidAkey(struct InfoItemStruct *ptInfoItem);
#endif
