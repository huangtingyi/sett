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

/*����ҵ������*/
#define BUSI 11
#define QUERY 12

#define AKEYFLAG  1

#define SUBST "#{SUBST}"
#define NEWLINE "#{N}"
#define NEWLINEVAL "\n"

#define CMDHEAD "a"
#define CMDTAIL "b"
#define INIPATH "./"

#define DN		1 	/*�绰����                  */
#define IMSI		2 	/*IMSI                      */
#define ESN		3 	/*�������к�                */
#define PIC             4 	/*��;��·                  */
#define AKEY            5 	/*��Ȩ��                    */
#define CHECKSUM        6 	/*(���޶���,��ʹ��)         */
#define KEYID           7 	/*(���޶���,��ʹ��)         */
#define PREPAIDY	8 	/*Ԥ���ѱ�ʶ��              */
#define PREPAIDN	9 	/*Ԥ���ѱ�ʶ��              */
#define SMS0R		10	/*���ŷ������              */
#define SMS0E		11	/*���ŷ��ͽ�ֹ              */
#define SMS1R		12	/*���Ž������              */
#define SMS1E		13	/*���Ž��ս�ֹ              */
#define SMS2R		14	/*�����շ����              */
#define SMS2E		15	/*�����շ���ֹ              */
#define INETRIM0R  	16	/*�����������              */
#define INETRIM0E  	17	/*����������ֹ              */
#define INETRIM1R  	18	/*���к������              */
#define INETRIM1E  	19	/*���к�����ֹ              */
#define INETRIM2R  	20	/*������ȥ�����            */
#define INETRIM2E  	21	/*������ȥ����ֹ            */
#define ROAMING0R	22	/*�����������              */
#define ROAMING0E	23	/*�������ν�ֹ              */
#define ROAMING1R	24	/*ʡ���������              */
#define ROAMING1E	25	/*ʡ�����ν�ֹ              */
#define ROAMING2R	26	/*�����������              */
#define ROAMING2E	27	/*�������ν�ֹ              */
#define ROAMING3R	28	/*�����������              */
#define ROAMING3E	29	/*�������ν�ֹ              */
#define BASICR		30	/*��������ҵ�����          */
#define BASICE		31	/*��������ҵ���ֹ          */
#define LOCALR		32	/*���غ��������޶����      */
#define LOCALE		33	/*���غ��������޶���ֹ      */
#define VMRR		34	/*�����������              */
#define VMRE		35	/*���������ֹ              */
#define CFBR		36	/*��æǰת���              */
#define CFBE		37	/*��æǰת��ֹ              */
#define CFNRR		38	/*��Ӧ��ǰת ���           */
#define CFNRE		39	/*��Ӧ��ǰת ��ֹ           */
#define CFUR		40	/*����ת�����              */
#define CFUE		41	/*����ת�ƽ�ֹ              */
#define CFCR		42	/*���ɼ��ĺ���ת�����      */
#define CFCE		43	/*���ɼ��ĺ���ת�ƽ�ֹ      */
#define CTR		44	/*����ת�Ƶ������������    */
#define CTE		45	/*����ת�Ƶ����������ֹ    */
#define MWNR		46	/*��Ϣ�ȴ�֪ͨ���          */
#define MWNE		47	/*��Ϣ�ȴ�֪ͨ��ֹ          */
#define CWR		48	/*���еȴ����              */
#define CWE		49	/*���еȴ���ֹ              */
#define CHR		50	/*���б������              */
#define CHE		51	/*���б��ֽ�ֹ              */
#define A3WCR		52	/*�����������              */
#define A3WCE		53	/*�������н�ֹ              */
#define CLIRR		54	/*���к���ʶ����ʾ���      */
#define CLIRE		55	/*���к���ʶ����ʾ��ֹ      */
#define CNIRR		56	/*���к���ʶ���������      */
#define CNIRE		57	/*���к���ʶ�����ƽ�ֹ      */
#define CCR		58	/*����绰���              */
#define CCE		59	/*����绰��ֹ              */
#define INTERNETR	60	/*����������ҵ�����        */
#define INTERNETE	61	/*����������ҵ���ֹ	    */

#define	COS		62	/*;COSֵ*/
#define	CRBTE		63	/*;ȡ������*/
#define	ACCOUNTLOCK2E	64	/*;Ƿ�Ѹ���:δ����(������)*/
#define	ACCOUNTLOCK1R	65	/*;Ƿ��ͣ��:������(������)*/
#define	WINCOS6		66	/*;������(PPC)*/
#define	INTERIM2E	67	/*;�������ҵ���޶�*/
#define	USERLOCK2E	68	/*;��ͣ����:δ����(������)*/
#define	INTERIM1E	69	/*;����ҵ���޶�*/
#define	USERLOCK0R	70	/*;����ͣ��:������(������)*/
#define	USERLOCK1R	71	/*;����ͣ��:������(������)*/
#define	WINCOS8		72	/*;������(VPN)*/
#define	INTERIM1R	73	/*;����ҵ���޶�*/
#define	INTERIM0E	74	/*;����ҵ���޶�*/
#define	INTERIM2R	76	/*;�������ҵ���޶�*/
#define	STOLENLOCKR	77	/*;������(������)*/
#define	INTERIM0R	78	/*;����ҵ���޶�*/
#define	CRBTR		79	/*;��������*/
#define	DUPLOCKR	80	/*;������(������)*/
#define	SMPE		81	/*;������ҵ��(������)*/
#define	STOLENLOCKE	82	/*;������(������)*/
#define	ACCOUNTLOCK2R	83	/*;Ƿ��ͣ��:���롢������(������)*/
#define	ACCOUNTLOCK0R	84	/*;Ƿ��ͣ��:������(������)*/
#define	USERLOCK2R	85	/*;����ͣ��:���롢������(������)*/
#define	SMPR		86	/*;������ҵ��(������)*/
#define	DUPLOCKE	87	/*;������(������)*/

#define	LSTCFD		88	/*;�ƶ����ɺ�CFD(�½���)*/
#define	LSTINTERIM	89	/*;��ѯ����ҵ���޶�*/
#define	LSTCFNA		90	/*;�ƶ����ɺ�CFNA(�½���)*/
#define	LSTROAMING	91	/*;ROAMING*/
#define	LSTCFB		92	/*;�ƶ����ɺ�CFB(�½���)*/
#define	LSTINTERNET	93	/*;��ѯINTERNET����*/
#define	LSTWINSVR	94	/*;��ѯ����������*/
#define	INQCODE		95	/*;���뻥��*/
#define	LSTCFU		96	/*;�ƶ����ɺ�CFU(�½���)*/
#define	LSTSMS		97	/*;��ѯ���ŷ���*/
#define	LSTLOCAL	99	/*;LOCAL*/
#define	LSTSUPSVR	100	/*;��ѯ�û�����ҵ��*/

#define	CL0E		101	/*;����ҵ��*/
#define	CL0R		102	/*;����ҵ��*/
#define	PPCE		103	/*;����ҵ��PPC*/
#define	PPCR		104	/*;����ҵ��PPC*/
#define	VPNR		105	/*;����ҵ��VPN*/
#define	VPNE		106	/*;����ҵ��VPN*/
#define	RFCR		107	/*;Զ��ҵ���(������)*/
#define	RFCE		108	/*;Զ��ҵ�����(������)*/
#define	CFSVR0R		109	/*;�ƶ����ɺ�:��æǰת(�½���)*/
#define	CFSVR0E		110	/*;�ƶ����ɺ�:��æǰת(�½���)*/
#define	CFSVR1E		111	/*;�ƶ����ɺ�:��������ǰת(�½���)*/
#define	CFSVR1R		112	/*;�ƶ����ɺ�:��������ǰת(�½���)*/
#define	CFSVR2R		113	/*;�ƶ����ɺ�:��Ӧ��ǰת(�½���)*/
#define	CFSVR2E		114	/*;�ƶ����ɺ�:��Ӧ��ǰת(�½���)*/
#define	CFSVR3E		115	/*;�ƶ����ɺ�:������ǰת(�½���)*/
#define	CFSVR3R		116	/*;�ƶ����ɺ�:������ǰת(�½���)*/
#define	SMP0E		117	/*;����ҵ��(������)*/
#define	SMP1E		118	/*;����ҵ��(������)*/
#define	SMP1R		119	/*;����ҵ��(������)*/



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
