#ifndef __UP_BAKE_H__
#define __UP_BACK_H__

#include <strings.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <errno.h>
#include <signal.h>

#define TESTING			/*����ʹ��*/
/*#define XINJIANG		  �½�ʹ��*/
#define	FUJIAN			/*����ʹ��*/

#define MAXRECNUM	100000
#define PATHLEN		101
#define FILENAMELEN	256
#define TICKETBUFSIZE	540

#define	PATH_UP		1	/*�ϴ��ܲ��������ļ�*/
#define	PATH_REPORT	2	/*�ϴ��ܲ��ĸ߶��ļ�*/

#define PATH_GSM	3	/*GSMһ�������ļ�*/
#define PATH_CDMA	4	/*CDMAһ�������ļ�*/
#define	PATH_RETURN	5	/*��ִ�ļ�*/

#define	PATH_WORK	6	/*����ʱĿ¼*/
#define	PATH_BAK	7	/*����Ŀ¼*/
#define PATH_ERR	8	/*һ�����ִ�Ĵ����ļ�*/
#define	PATH_LOG	9	/*������־Ŀ¼*/

/*�����¼�Ĵ����붨��*/
#define ERR_TOO_LATE_REC	-0x01	/*��¼����30�����ϣ�����30�죩*/
#define ERR_FEE_IS_ZERO		-0x02	/*�����м�¼(�Ǻ�ת��¼)�Ļ���Ϊ0*/
#define ERR_DFHM		-0x03	/*C���Է������з������ַ���������*/
#define WARNING_MSID		0x01	/*C���������ε�MSID������46003��ͷ���ó�46003*/
#define WARNING_MSID_LEN	0x02	/*C���������ε�MSIDֻ��10λ������46003*/
#define WARNING_17911		0x03	/*G�����ε�CalledNbr��17911��ͷ,����*/
#define WARNING_CALLEDNBR	0x04	/*G�����εĲ���17911��ͷ��CalledNbr���ȴ���15λ��ȡ��15λ*/

/*ȫ�ֱ���*/
char sLogFile[FILENAMELEN];

/*���ڼ�¼�״�ͨ����ĩ��ͨ��*/
struct call_times{
	char First_gn[15];
	char Last_gn[15];
	char First_gj[15];
	char Last_gj[15];
};

/*�ļ��б�ṹ*/
struct file_list{
	char sFileName[31];
	char sPathOut[PATHLEN];
	struct file_list* pNext;
	
	char sFileOut[31];
	int iSize;
	int iRecCount;
	char sFileDate[15];
};

/*G�����������ϴ����ݵ��׼�¼�ṹ*/
typedef struct _buf_up_cri_head_{
	char RecType[2];	/*��¼����*/
	char FilialeCode[3];	/*ʡ�ֹ�˾����*/
	char FileSymbol[3];	/*�ļ���־*/
	char FileSerial[5];	/*�ļ����к�*/
	char FileVersion[2];	/*�ļ��汾��*/
	char FileDate[8];	/*�ļ���������*/
	char FirstCallDate[8];	/*�״�ͨ������*/
	char FirstCallTime[6];	/*�״�ͨ��ʱ��*/
	char LastCallDate[8];	/*ĩ��ͨ������*/
	char LastCallTime[6];	/*ĩ��ͨ��ʱ��*/
	char RecCount[6];	/*ͨ���ܼ�¼��*/
	char TotalFee[15];	/*�ܻ���*/
	char Reserved[92];	/*δ��*/
	char BackLine[1];	/*�س�*/
	char NewLine[1];	/*����*/
}up_cri_head_buf;

/*G�����������ϴ����ݵ��׼�¼�ṹ*/
typedef struct _buf_up_cii_head_{
	char RecType[2];	/*��¼����*/
	char FilialeCode[3];	/*ʡ�ֹ�˾����*/
	char FileSymbol[3];	/*�ļ���־*/
	char FileSerial[5];	/*�ļ����к�*/
	char FileVersion[2];	/*�ļ��汾��*/
	char FileDate[8];	/*�ļ���������*/
	char FirstCallDate[8];	/*�״�ͨ������*/
	char FirstCallTime[6];	/*�״�ͨ��ʱ��*/
	char LastCallDate[8];	/*ĩ��ͨ������*/
	char LastCallTime[6];	/*ĩ��ͨ��ʱ��*/
	char RecCount[6];	/*ͨ���ܼ�¼��*/
	char TotalFee[15];	/*�ܻ���*/
	char Reserved[77];	/*δ��*/
	char BackLine[1];	/*�س�*/
	char NewLine[1];	/*����*/
}up_cii_head_buf;

/*G�����������ϴ����ݵ���/���м�¼�ṹ*/
typedef struct _buf_up_cri_{
	char RecType[2];	/*��¼����*/
	char InCityCode[3];	/*����ͨ�����д���*/
	char OutCityCode[3];	/*����ͨ�����д���*/
	char Links[6];		/*���ο�*/
	char Reserved[1];	/*δ��*/
	char IMSI[15];		/*IMSI����*/
	char CallingNum[15];	/*���к���*/
	char ChangeFlag[1];	/*�޸�ָʾ*/
	char NumType[1];	/*��������*/
	char NumPick[1];	/*ѡ�ŷ���*/
	char CalledNum[15];	/*���к���*/
	char ServiceType[1];	/*ҵ������*/
	char ServiceCode[2];	/*ҵ����*/
	char ServiceType2[1];	/*˫��ҵ������*/
	char ServiceCode2[2];	/*˫��ҵ����*/
	char ChannelReq[1];	/*Ҫ�������ͨ��*/
	char ChannelUsed[1];	/*ʹ�õ�����ͨ��*/
	char ServiceTrans[1];	/*ҵ��͸����*/
				/*����ҵ���¼�*/
	char FunctionCode1[1];	/*���1*/
	char AppendCode1[2];	/*����ҵ����1*/
	char FunctionCode2[1];	/*���2*/
	char AppendCode2[2];	/*����ҵ����2*/
	char FunctionCode3[1];	/*���3*/
	char AppendCode3[2];	/*����ҵ����3*/
	char FunctionCode4[1];	/*���4*/
	char AppendCode4[2];	/*����ҵ����4*/
	char FunctionCode5[1];	/*���5*/
	char AppendCode5[2];	/*����ҵ����5*/
	char MSC[15];		/*MSC ��ʶ*/
	char LAC[5];		/*LAC*/
	char CellOri_A[5];	/*���ѱ�־*/
	char MobileCode[1];	/*�ƶ��豸�����*/
	char CallDate[8];	/*ͨ������*/
	char CallStartTime[6];	/*ͨ����ʼʱ��*/
	char Duration[6];	/*���ѵ�λ*/
	char DataAmountRef[6];	/*�������ο�*/
	char LandChargeCode[1];	/*��;�Ѵ���*/
	char OtherChargeCode[2];/*�������Ѵ���*/
	char RoamCharge[9];	/*���λ���*/
	char LandCharge[6];	/*��;����*/
	char OtherCharge[6];	/*��������*/
	char ChargeItem[1];	/*�շѵ���Ŀ*/
	char BackLine[1];	/*�س�*/
	char NewLine[1];	/*����*/
}up_cri_buf;

/*G�����������ϴ����ݵ���/���м�¼�ṹ*/
typedef struct _buf_up_cri_x_{
	char RecType[2];	/*��¼����*/
	char InCityCode[3];	/*����ͨ�����д���*/
	char OutCityCode[3];	/*����ͨ�����д���*/
	char Links[6];		/*���ο�*/
	char Reserved[1];	/*δ��*/
	char IMSI[15];		/*IMSI����*/
	char CallingNum[15];	/*���к���*/
	char ChangeFlag[1];	/*�޸�ָʾ*/
	char NumType[1];	/*��������*/
	char NumPick[1];	/*ѡ�ŷ���*/
	char CalledNum[15];	/*���к���*/
	char ServiceType[1];	/*ҵ������*/
	char ServiceCode[2];	/*ҵ����*/
	char ServiceType2[1];	/*˫��ҵ������*/
	char ServiceCode2[2];	/*˫��ҵ����*/
	char ChannelReq[1];	/*Ҫ�������ͨ��*/
	char ChannelUsed[1];	/*ʹ�õ�����ͨ��*/
	char ServiceTrans[1];	/*ҵ��͸����*/
				/*����ҵ���¼�*/
	char FunctionCode1[1];	/*���1*/
	char AppendCode1[2];	/*����ҵ����1*/
	char FunctionCode2[1];	/*���2*/
	char AppendCode2[2];	/*����ҵ����2*/
	char FunctionCode3[1];	/*���3*/
	char AppendCode3[2];	/*����ҵ����3*/
	char FunctionCode4[1];	/*���4*/
	char AppendCode4[2];	/*����ҵ����4*/
	char FunctionCode5[1];	/*���5*/
	char AppendCode5[2];	/*����ҵ����5*/
	char MSC[15];		/*MSC ��ʶ*/
	char LAC[5];		/*LAC*/
	char CellOri_A[5];	/*���ѱ�־*/
	char MobileCode[1];	/*�ƶ��豸�����*/
	char CallDate[8];	/*ͨ������*/
	char CallStartTime[6];	/*ͨ����ʼʱ��*/
	char Duration[6];	/*���ѵ�λ*/
	char DataAmountRef[6];	/*�������ο�*/
	char LandChargeCode[1];	/*��;�Ѵ���*/
	char OtherChargeCode[2];/*�������Ѵ���*/
	char RoamCharge[9];	/*���λ���*/
	char LandCharge[6];	/*��;����*/
	char OtherCharge[6];	/*��������*/
	char ChargeItem[1];	/*�շѵ���Ŀ*/
	char BackLine[1];	/*�س�*/
	char NewLine[1];	/*����*/
	char HotBillingTag[1];	/*hot_billing_tag*/
	char Imei[25];		/*imei*/
	char Reserve2[30];	/*reserve2*/
}up_cri_buf_x;
/*G�����������ϴ����ݵĺ�ת��¼�ṹ*/
typedef struct _buf_up_cri_hz_x_{
	char RecType[2];	/*��¼����*/
	char InCityCode[3];	/*����ͨ�����д���*/
	char OutCityCode[3];	/*����ͨ�����д���*/
	char Links[6];		/*���ο�*/
	char Reserved[1];	/*δ��*/
	char IMSI[15];		/*IMSI����*/
	char CallingNum[15];	/*���к���*/
	char NumB[15];		/*B����*/
	char CalledNum[15];	/*���к���*/
	char FunctionCode[1];	/*���1*/
	char AppendCode[2];	/*����ҵ����1*/
	char Reserved2[9];	/*δ��*/
	char MSC[15];		/*MSC ��ʶ*/
	char LAC[5];		/*LAC*/
	char CellOri_A[5];	/*���ѱ�־*/
	char MobileCode[1];	/*�ƶ��豸�����*/
	char CallDate[8];	/*ͨ������*/
	char CallStartTime[6];	/*ͨ����ʼʱ��*/
	char Duration[6];	/*���ѵ�λ*/
	char Reserved3[31];	/*δ��*/
	char BackLine[1];	/*�س�*/
	char NewLine[1];	/*����*/
	char Imei[25];		/*imei*/
	char Reserve3[51];	/*reserve3*/
}up_cri_hz_buf_x;
/*G�����������ϴ���¼�ṹ*/
typedef struct _buf_up_cii_x_{
	char RecType[2];	/*��¼����*/
	char InCityCode[3];	/*����ͨ�����д���*/
	char OutCityCode[3];	/*����ͨ�����д���*/
	char Links[6];		/*���ο�*/
	char Reserved[1];	/*δ��*/
	char IMSI[15];		/*IMSI����*/
	char CallingNum[15];	/*���к���*/
	char ChangeFlag[1];	/*�޸�ָʾ*/
	char NumType[1];	/*��������*/
	char NumPick[1];	/*ѡ�ŷ���*/
	char CalledNum[15];	/*���к���*/
	char ServiceType[1];	/*ҵ������*/
	char ServiceCode[2];	/*ҵ����*/
	char ServiceType2[1];	/*˫��ҵ������*/
	char ServiceCode2[2];	/*˫��ҵ����*/
	char ChannelReq[1];	/*Ҫ�������ͨ��*/
	char ChannelUsed[1];	/*ʹ�õ�����ͨ��*/
	char ServiceTrans[1];	/*ҵ��͸����*/
				/*����ҵ���¼�*/
	char FunctionCode1[1];	/*���1*/
	char AppendCode1[2];	/*����ҵ����1*/
	char FunctionCode2[1];	/*���2*/
	char AppendCode2[2];	/*����ҵ����2*/
	char FunctionCode3[1];	/*���3*/
	char AppendCode3[2];	/*����ҵ����3*/
	char FunctionCode4[1];	/*���4*/
	char AppendCode4[2];	/*����ҵ����4*/
	char FunctionCode5[1];	/*���5*/
	char AppendCode5[2];	/*����ҵ����5*/
	char MSC[15];		/*MSC ��ʶ*/
	char LAC[5];		/*LAC*/
	char CellOri_A[5];	/*���ѱ�־*/
	char MobileCode[1];	/*�ƶ��豸�����*/
	char CallDate[8];	/*ͨ������*/
	char CallStartTime[6];	/*ͨ����ʼʱ��*/
	char Duration[6];	/*���ѵ�λ*/
	char DataAmountRef[6];	/*�������ο�*/
	char Charges[9];	/*����*/
	char ChargeItem[1];	/*�շѵ���Ŀ*/
	char BackLine[1];	/*�س�*/
	char NewLine[1];	/*����*/
	char Vhe[1];		/*vhe*/
	char InterScpFlag[10];	/*inter_scp_flag*/
	char Reserve2[16];	/*reserve2*/
}up_cii_buf_x;

/*G�����������ϴ����ݵĺ�ת��¼�ṹ*/
typedef struct _buf_up_cri_hz_{
	char RecType[2];	/*��¼����*/
	char InCityCode[3];	/*����ͨ�����д���*/
	char OutCityCode[3];	/*����ͨ�����д���*/
	char Links[6];		/*���ο�*/
	char Reserved[1];	/*δ��*/
	char IMSI[15];		/*IMSI����*/
	char CallingNum[15];	/*���к���*/
	char NumB[15];		/*B����*/
	char CalledNum[15];	/*���к���*/
	char FunctionCode[1];	/*���1*/
	char AppendCode[2];	/*����ҵ����1*/
	char Reserved2[9];	/*δ��*/
	char MSC[15];		/*MSC ��ʶ*/
	char LAC[5];		/*LAC*/
	char CellOri_A[5];	/*���ѱ�־*/
	char MobileCode[1];	/*�ƶ��豸�����*/
	char CallDate[8];	/*ͨ������*/
	char CallStartTime[6];	/*ͨ����ʼʱ��*/
	char Duration[6];	/*���ѵ�λ*/
	char Reserved3[31];	/*δ��*/
	char BackLine[1];	/*�س�*/
	char NewLine[1];	/*����*/
}up_cri_hz_buf;

/*G�����������ϴ����ݵĸ���ҵ���¼�ṹ*/
typedef struct _buf_up_cri_fj_{
	char RecType[2];	/*��¼����*/
	char InCityCode[3];	/*����ͨ�����д���*/
	char OutCityCode[3];	/*����ͨ�����д���*/
	char Links[6];		/*���ο�*/
	char IMSI[15];		/*IMSI����*/
	char CallingNum[15];	/*���к���*/
	char BaseService[15];	/*����ҵ����*/
	char AppendCode[2];	/*����ҵ����*/
	char FunctionCode[1];	/*���*/
	char MSC[15];		/*MSC ��ʶ*/
	char LAC[5];		/*LAC*/
	char CellOri_A[5];	/*���ѱ�־*/
	char MobileCode[1];	/*�ƶ��豸�����*/
	char Reserved[15];	/*δ��*/
	char CallDate[8];	/*ͨ������*/
	char CallStartTime[6];	/*ͨ����ʼʱ��*/
	char TotalCharge[9];	/*����*/
	char ChargeItem[1];	/*�շѵ���Ŀ*/
	char Reserved2[37];	/*δ��*/
	char BackLine[1];	/*�س�*/
	char NewLine[1];	/*����*/
}up_cri_fj_buf;

/*G�����������ϴ����ݵĸ���ҵ���¼�ṹ*/
typedef struct _buf_up_cii_fj_{
	char RecType[2];	/*��¼����*/
	char InCityCode[3];	/*����ͨ�����д���*/
	char OutCityCode[3];	/*����ͨ�����д���*/
	char Links[6];		/*���ο�*/
	char IMSI[15];		/*IMSI����*/
	char CallingNum[15];	/*���к���*/
	char BaseService[15];	/*����ҵ����*/
	char AppendCode[2];	/*����ҵ����*/
	char FunctionCode[1];	/*���*/
	char MSC[15];		/*MSC ��ʶ*/
	char LAC[5];		/*LAC*/
	char CellOri_A[5];	/*���ѱ�־*/
	char MobileCode[1];	/*�ƶ��豸�����*/
	char CalledNum[15];	/*δ��*/
	char CallDate[8];	/*ͨ������*/
	char CallStartTime[6];	/*ͨ����ʼʱ��*/
	char TotalCharge[9];	/*����*/
	char ChargeItem[1];	/*�շѵ���Ŀ*/
	char Reserved2[22];	/*δ��*/
	char BackLine[1];	/*�س�*/
	char NewLine[1];	/*����*/
}up_cii_fj_buf;

/*G�������ϴ����ݵ���ֵҵ���¼�ṹ*/
typedef struct _buf_up_gsm_zz_{
	char RecType[2];	/*��¼����*/
	char InCityCode[3];	/*����ͨ�����д���*/
	char OutCityCode[3];	/*����ͨ�����д���*/
	char IMSI[15];		/*IMSI����*/
	char CallingNum[15];	/*���к���*/
	char ValueRaiseCode[8];	/*��ֵҵ����*/
	char Duration[6];	/*���ѵ�λ*/
	char CallDate[8];	/*ͨ������*/
	char CallStartTime[6];	/*ͨ����ʼʱ��*/
	char TotalCharge[6];	/*����*/
	char ChargeItem[1];	/*�շѵ���Ŀ*/
	char BackLine[1];	/*�س�*/
	char NewLine[1];	/*����*/
}up_gsm_zz_buf;

/*G�����������ϴ���¼�ṹ*/
typedef struct _buf_up_cii_{
	char RecType[2];	/*��¼����*/
	char InCityCode[3];	/*����ͨ�����д���*/
	char OutCityCode[3];	/*����ͨ�����д���*/
	char Links[6];		/*���ο�*/
	char Reserved[1];	/*δ��*/
	char IMSI[15];		/*IMSI����*/
	char CallingNum[15];	/*���к���*/
	char ChangeFlag[1];	/*�޸�ָʾ*/
	char NumType[1];	/*��������*/
	char NumPick[1];	/*ѡ�ŷ���*/
	char CalledNum[15];	/*���к���*/
	char ServiceType[1];	/*ҵ������*/
	char ServiceCode[2];	/*ҵ����*/
	char ServiceType2[1];	/*˫��ҵ������*/
	char ServiceCode2[2];	/*˫��ҵ����*/
	char ChannelReq[1];	/*Ҫ�������ͨ��*/
	char ChannelUsed[1];	/*ʹ�õ�����ͨ��*/
	char ServiceTrans[1];	/*ҵ��͸����*/
				/*����ҵ���¼�*/
	char FunctionCode1[1];	/*���1*/
	char AppendCode1[2];	/*����ҵ����1*/
	char FunctionCode2[1];	/*���2*/
	char AppendCode2[2];	/*����ҵ����2*/
	char FunctionCode3[1];	/*���3*/
	char AppendCode3[2];	/*����ҵ����3*/
	char FunctionCode4[1];	/*���4*/
	char AppendCode4[2];	/*����ҵ����4*/
	char FunctionCode5[1];	/*���5*/
	char AppendCode5[2];	/*����ҵ����5*/
	char MSC[15];		/*MSC ��ʶ*/
	char LAC[5];		/*LAC*/
	char CellOri_A[5];	/*���ѱ�־*/
	char MobileCode[1];	/*�ƶ��豸�����*/
	char CallDate[8];	/*ͨ������*/
	char CallStartTime[6];	/*ͨ����ʼʱ��*/
	char Duration[6];	/*���ѵ�λ*/
	char DataAmountRef[6];	/*�������ο�*/
	char Charges[9];	/*����*/
	char ChargeItem[1];	/*�շѵ���Ŀ*/
	char BackLine[1];	/*�س�*/
	char NewLine[1];	/*����*/
}up_cii_buf;

/*C�������ϴ����ݵ��׼�¼�ṹ*/
typedef struct _buf_up_cdma_head_{
	char RecType[2];	/*��¼����*/
	char FileDate[6];	/*�ļ���������*/
	char FileSerial[3];	/*�ļ����к�*/
	char FilialeCode[3];	/*ʡ�ִ���*/
	char FileType[3];	/*�ļ�����*/
	char RecVersion[2];	/*��¼�汾��*/
	char BackFlag;	/*��ִ��ʶ*/
	char RefuseReasion[2];	/*�ļ��ܾ�ԭ����*/
	char FileComment;	/*�ļ�����*/
	char BackLine;	/*�س�*/
	char NewLine;	/*����*/
}up_cdma_head_buf;

/*C�����������ϴ����ݵ�β��¼�ṹ*/
typedef struct _buf_up_jri_end_{
	char RecType[2];	/*��¼����*/
	char FileDate[6];	/*�ļ���������*/
	char FileSerial[3];	/*�ļ����к�*/
	char FilialeCode[3];	/*ʡ�ִ���*/
	char FileType[3];	/*�ļ�����*/
	char RecCount[5];	/*�ܼ�¼��*/
	char TotalCharge[12];	/*˰���ܻ���*/
	char RecCount2[5];	/*�ϴ��ܼ�¼��*/
	char TotalCharge2[12];	/*�ϴ�˰���ܻ���*/
	char BackLine;	/*�س�*/
	char NewLine;	/*����*/
}up_jri_end_buf;

/*C�����������ϴ����ݵ�β��¼�ṹ*/
typedef struct _buf_up_jii_end_{
	char RecType[2];	/*��¼����*/
	char FileDate[6];	/*�ļ���������*/
	char FileSerial[3];	/*�ļ����к�*/
	char FilialeCode[3];	/*ʡ�ִ���*/
	char FileType[3];	/*�ļ�����*/
	char RecCount[4];	/*�ܼ�¼��*/
	char TotalCharge[12];	/*˰���ܻ���*/
	char RecCount2[4];	/*�ϴ��ܼ�¼��*/
	char TotalCharge2[12];	/*�ϴ�˰���ܻ���*/
	char BackLine;	/*�س�*/
	char NewLine;	/*����*/
}up_jii_end_buf;

/*C�����������ϴ����ݵļ�¼�ṹ*/
typedef struct _buf_up_jri_{
	char RecType[2];	/*��¼����*/
	char RetCode;	/*������*/
	char ErrCode[2];	/*��¼����ԭ����*/
	char ErrField[3];	/*�����ֶα�ʶ*/
	char MSIDFlag;	/*MSID��ʶ*/
	char MSID[15];		/*MSID*/
	char MSSISDN_MDNLen[2];	/*MSISDN/MDN����*/
	char MSSISDN_MDN[15];	/*MSISDN/MDN*/
	char ESN_IMEIFlag;	/*ESN/IMEI ��ʶ*/
	char ESN_IMEI[19];	/*ESN/IMEI*/
	char CityCode[3];	/*���д���*/
	char TotalCharge[10];	/*˰���ܻ���*/
	char Reserved1;	/*ϵͳ����*/
	char TotalTaxP[10];	/*��ʡ˰��*/
	char Reserved2;	/*ϵͳ����*/
	char TotalTaxL[10];	/*�ܵط�˰��*/
	char Reserved3;	/*ϵͳ����*/
	char CallDate[6];	/*ͨ������*/
	char CallDirect;	/*���з���*/
	char CallFinishFlag;	/*������ɱ�ʶ*/
	char CallStopFlag;	/*������ֹ��ʶ*/
	char OppNumLen[2];	/*�Է����볤��*/
	char OppNum[25];	/*�Է�����*/
	char TempNumLen[2];	/*��ʱ���볤��*/
	char TempNum[15];	/*��ʱ����*/
	char Reserved4[2];	/*ϵͳ����*/
	char CellOri_A[11];	/*���ѱ�ʶ*/
	char MAD[10];		/*MAD*/
	char RoamLinkTime[6];	/*��������ʱ��*/
	char RoamFeeTime[6];	/*���μƷ�ʱ��*/
	char RoamCallTime[6];	/*����ͨ��ʱ��*/
	char RoamFeePeriod[2];	/*���η�����ʼʱ��*/
	char RoamFeeMPeriod;	/*���ζ����ʱ�α�ʶ*/
	char RoamCharge[10];	/*���η�*/
	char Reserved5;	/*ϵͳ����*/
	char OtherChargeFlag[2];/*�������ñ�ʶ*/
	char OtherCharge[10];	/*��������*/
	char Reserved6;	/*ϵͳ����*/
	char Reserved7[13];	/*ϵͳ����*/
	char SpecService[5];	/*�������ʹ��*/
	char OppCity[10];	/*�Է����ڵ�*/
	char OppProvince[3];	/*�Է�����ʡ*/
	char OppNation[3];	/*�Է����ڹ�*/
	char LDLinkTime[6];	/*��;����ʱ��*/
	char LDFeeTime[6];	/*��;�Ʒ�ʱ��*/
	char LDCallTime[6];	/*��;ͨ��ʱ��*/
	char LDFeeDescribe[2];	/*��;�ʷ�����*/
	char LDFeePeriod[2];	/*��;������ʼʱ��*/
	char LandMoreFlag;	/*��;����ʱ�ʶ*/
	char LandCharge[10];	/*��;��*/
	char Reserved8;	/*ϵͳ����*/
	char LandTaxP[10];	/*��;ʡ˰��*/
	char Reserved9;	/*ϵͳ����*/
	char LandTaxL[10];	/*��;����˰*/
	char Reserved10;	/*ϵͳ����*/
	char NetProviderSign[5];/*��;�����ṩ��Ӫ�̱�ʶ*/
	char BackLine;	/*�س�*/
	char NewLine;	/*����*/
}up_jri_buf;

/*C�����������ϴ����ݵļ�¼�ṹ*/
typedef struct _buf_up_jii_{
	char RecType[2];	/*��¼����*/
	char RetCode;		/*������*/
	char ErrCode[2];	/*��¼����ԭ����*/
	char ErrField[3];	/*�����ֶα�ʶ*/
	char MSIDFlag;		/*MSID��ʶ*/
	char MSID[15];		/*MSID*/
	char MSSISDN_MDNLen[2];	/*MSISDN/MDN����*/
	char MSSISDN_MDN[15];	/*MSISDN/MDN*/
	char ESN_IMEIFlag;	/*ESN/IMEI ��ʶ*/
	char ESN_IMEI[19];	/*ESN/IMEI*/
	char SID_BID[5];	/*���д����������Ӫ��SID/BID*/
	char TotalCharge[10];	/*˰���ܻ���*/
	char Reserved1;		/*ϵͳ����*/
	char TotalTaxP[10];	/*��ʡ˰��*/
	char Reserved2;	/*ϵͳ����*/
	char TotalTaxL[10];	/*�ܵط�˰��*/
	char Reserved3;	/*ϵͳ����*/
	char CallDate[6];	/*ͨ������*/
	char CallDirect;	/*���з���*/
	char CallFinishFlag;	/*������ɱ�ʶ*/
	char CallStopFlag;	/*������ֹ��ʶ*/
	char OppNumLen[2];	/*�Է����볤��*/
	char OppNum[25];	/*�Է�����*/
	char TempNumLen[2];	/*��ʱ���볤��*/
	char TempNum[15];	/*��ʱ����*/
	char Reserved4[2];	/*ϵͳ����*/
	char CellOri_A[11];	/*���ѱ�ʶ*/
	char TimeZoneFlag[2];	/*ʱ����ʶ*/
	char DSTFlag;	/*����ʱ��daylight saving time����ʶ*/
	char MAD[10];		/*MAD*/
	char RoamLinkTime[6];	/*��������ʱ��*/
	char RoamFeeTime[6];	/*���μƷ�ʱ��*/
	char RoamCallTime[6];	/*����ͨ��ʱ��*/
	char RoamFeePeriod[2];	/*���η�����ʼʱ��*/
	char RoamFeeMPeriod;	/*���ζ����ʱ�α�ʶ*/
	char RoamCharge[10];	/*���η�*/
	char Reserved5;	/*ϵͳ����*/
	char OtherChargeFlag[2];/*�������ñ�ʶ*/
	char OtherCharge[10];	/*��������*/
	char Reserved6;	/*ϵͳ����*/
	char Reserved7[13];	/*ϵͳ����*/
	char NumTextDes[15];	/*������������*/
	char SpecService[5];	/*�������ʹ��*/
	char OppCity[10];	/*�Է����ڵ�*/
	char OppProvince[3];	/*�Է�����ʡ*/
	char OppNation[3];	/*�Է����ڹ�*/
	char LDLinkTime[6];	/*��;����ʱ��*/
	char LDFeeTime[6];	/*��;�Ʒ�ʱ��*/
	char LDCallTime[6];	/*��;ͨ��ʱ��*/
	char LDFeeDescribe[2];	/*��;�ʷ�����*/
	char LDFeePeriod[2];	/*��;������ʼʱ��*/
	char LandMoreFlag;	/*��;����ʱ�ʶ*/
	char LandCharge[10];	/*��;��*/
	char Reserved8;	/*ϵͳ����*/
	char LandTaxP[10];	/*��;��/ʡ˰*/
	char Reserved9;	/*ϵͳ����*/
	char LandTaxL[10];	/*��;���ػ�����˰*/
	char BackLine;	/*�س�*/
	char NewLine;	/*����*/
}up_jii_buf;

/*�߶��ϴ����ݵ��׼�¼�ṹ��G�����ڣ�*/
typedef struct _buf_up_cfi_head_{
	char RecType[2];	/*��¼����*/    
	char FilialeCode[3];	/*ʡ�ֹ�˾����*/
	char Verson[2];		/*�ļ��汾��*/  
	char FileTime[14];	/*�ļ�����ʱ��*/
	char RecCount[6];	/*�ܼ�¼��*/    
	char TotalFee[15];	/*�ܻ���*/      
	char Reserved[14];	/*δ��*/        
	char BackLine;		/*�س�*/        
	char NewLine;		/*����*/        
}up_cfi_head_buf;

/*�߶��ϴ����ݵļ�¼�ṹ��G�����ڣ�*/
typedef struct _buf_up_cfi_{
	char RecType[2];	/*��¼����*/
	char FilialeCode[3];	/*ʡ�ֹ�˾����*/
	char Imsi[15];		/*IMSI*/
	char FirstCallTime[14];	/*�״�ͨ������*/
	char LastCallTime[14];	/*ĩ��ͨ������*/
	char TotalFee[8];	/*ͨ���ܽ��*/
	char BackLine;		/*�س�*/
	char NewLine;		/*����*/
}up_cfi_buf;

/*һ�����C���׼�¼��ʽ*/
typedef struct _c_ticket_head_buf_{
	char sRecType[2];	/*��¼����*/
	char sCityCode[3];	/*���д���*/
	char sFileFlag[4];	/*�ļ���־*/
	char sSerial[4];	/*�ļ����к�*/
	char sVersion[2];	/*�ļ��汾��*/
	char sFileDate[8];	/*�ļ���������*/
	char sFirstCallDate[8];	/*�״�ͨ������*/
	char sFirstCallTime[6];	/*�״�ͨ��ʱ��*/
	char sLastCallDate[8];	/*ĩ��ͨ������*/
	char sLastCallTime[6];	/*ĩ��ͨ��ʱ��*/
	char sTotalRecCount[6];	/*ͨ���ܼ�¼��*/
	char sTotalCharge[15];	/*�ܻ��ѣ��壩*/
	char sRevered[105];	/*δ��*/
	char cNewLine;		/*����*/
}c_ticket_head_buf;

/*һ�����C����¼��ʽ*/
struct FCdmaBillStruct{
	char sCallType[2];	/*��������,����ı�*/ 
	char sCallingNbr[15];	/*�ƷѺ���*/
	char sMinImsi[15];	/*MIN/IMSI��*/
	char sEsn[15];		/*�������к�*/
	char sCalledNbr[21];	/*�Զ˺���*/
	char sTldn[15];		/*��ʱ����Ŀ¼��*/
	char sThirdNbr[21];	/*����������*/
	char sStartTime[14];	/*ͨ����ʼʱ��*/
	char sDuration[6];	/*ͨ��ʱ��*/
	char sSwitchID[10];	/*����������*/
	char sLacA[5];		/*������ʼλ��LAC��*/
	char sCellA[5];	/*������ʼλ�÷��ѣ���վ����*/
	char sLacB[5];		/*�Է���ʼλ��LAC��*/
	char sCellB[5];	/*�Է���ʼλ�÷��ѣ���վ����*/
	char sValueRaise[2];	/*��ֵҵ��*/
	char cEndReason;	/*����ԭ��*/
	char cDeformityFlag;	/*��ȱ��־*/
	char sBaseCharge[8];	/*��������*/
	char sBaseDuration[6];	/*�����Ʒ�ʱ��*/
	char cMoreRateFlag;	/*����ʱ�ʶ*/
	char sLandCharge[8];	/*��;����*/
	char sLandDuration[6];	/*��;�Ʒ�ʱ��*/
	char cLandMoreFlag;	/*��;����ʱ�ʶ*/
	char sInfoCharge[8];	/*��Ϣ����*/
	char sOtherCharge[8];	/*��������*/
	char sCalledCity[3];	/*�Է����ڵ�*/
	char sCalledProvince[3];/*�Է�����ʡ*/
	char sCalledNation[3];	/*�Է����ڹ�*/
	char cLandType;		/*��;����*/
	char cLandNetType;	/*��;������*/
	char cRoamType;		/*��������*/
	char sCallingCity[3];	/*ͨ����*/
	char sUserType[1];
	char sServiceType[3];
	char sServiceCode[4];
};
/*һ�����G����¼��ʽ(�½�)*/
struct XJGsmBillStruct{
	char	sCallType[2];
	char	sCallingNbr[15];
	char	sImsi[15];
	char	sCalledNbr[18];
	char	cFeeItem;
	char	sStartTime[14];
	char	sDuration[6];
	char	sMsc[15];
	char	sLac[5];
	char	sCell_A[5];
	char	sCell_B[5];
	char	sTrunkIn[7];
	char	sTrunkOut[7];
	char	sBelongArea[3];
	char	sCallingArea[3];
	char	sCityIn[3];
	char	sCityOut[3];
	char	cRoamType;
	char	cLandType;
	char	sCallType2[3];
	char	sRoamFee[10];
	char	sLandFee[10];
	char	sAddFee[10];
	char	sOtherFee[10];
	char	sForeignLandFee[10];
	char	sAdditionalFee[10];
	char	sLink[6];
	char	cServiceType;
	char	sServiceCode[2];
	char	sRecType[2];
	char	sBaseCode[15];
	char	cFunctionCode1;
	char	sAppendCode1[2];
	char	cFunctionCode2;
	char	sAppendCode2[2];
	char	cFunctionCode3;
	char	sAppendCode3[2];
	char	cFunctionCode4;
	char	sAppendCode4[2];
	char	cFunctionCode5;
	char	sAppendCode5[2];
	char	sCugId[5];
	char	cIsSameCug;
	char	cModifyFlag;
	char	cNumChoose;
	char	cServiceType2;
	char	sServiceCode2[2];
	char	sNumB[15];
	char	cChannelReq;
	char	cChannelUsed;
	char	cServiceTrans;
	char	sFlowCount[6];
	char	sMsisdn[15];
	char	cCalledNbrType;
	char	cMobileType;
	char	sOtherFeeCode[2];
	char	sValueRaiseCode[8];
	char	cNewLine;
};

/*����ṹ��������*/
struct VisitGsmupCriStructOut{

#ifndef VISIT_GSMUP_CRI_02_BUFLEN_OUT
#define VISIT_GSMUP_CRI_02_BUFLEN_OUT		300
#endif

	struct VisitGsmupCriStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
	char    asRecordType[VISIT_GSMUP_CRI_02_BUFLEN_OUT][3];
	char    asInCityCode[VISIT_GSMUP_CRI_02_BUFLEN_OUT][4];
	char    asOutCityCode[VISIT_GSMUP_CRI_02_BUFLEN_OUT][4];
	char	asScpFlagID[VISIT_GSMUP_CRI_02_BUFLEN_OUT][2];
	char    asLinkRef[VISIT_GSMUP_CRI_02_BUFLEN_OUT][6];
	char    asReserve1[VISIT_GSMUP_CRI_02_BUFLEN_OUT][2];
	char    asImsi[VISIT_GSMUP_CRI_02_BUFLEN_OUT][16];
	char    asMsisdn[VISIT_GSMUP_CRI_02_BUFLEN_OUT][26];
	char    asModifyTag[VISIT_GSMUP_CRI_02_BUFLEN_OUT][2];
	char    asNbrType[VISIT_GSMUP_CRI_02_BUFLEN_OUT][2];
	char    asNbrPlan[VISIT_GSMUP_CRI_02_BUFLEN_OUT][2];
	char    asOtherParty[VISIT_GSMUP_CRI_02_BUFLEN_OUT][26];
	char    asServiceType[VISIT_GSMUP_CRI_02_BUFLEN_OUT][2];
	char    asServiceCode[VISIT_GSMUP_CRI_02_BUFLEN_OUT][3];
	char    asDupServiceType[VISIT_GSMUP_CRI_02_BUFLEN_OUT][2];
	char    asDupServiceCode[VISIT_GSMUP_CRI_02_BUFLEN_OUT][3];
	char    asAckChannel[VISIT_GSMUP_CRI_02_BUFLEN_OUT][2];
	char    asUseChannel[VISIT_GSMUP_CRI_02_BUFLEN_OUT][2];
	char    asTransparentFlag[VISIT_GSMUP_CRI_02_BUFLEN_OUT][2];
	char    asAct1[VISIT_GSMUP_CRI_02_BUFLEN_OUT][2];
	char    asCode1[VISIT_GSMUP_CRI_02_BUFLEN_OUT][3];
	char    asAct2[VISIT_GSMUP_CRI_02_BUFLEN_OUT][2];
	char    asCode2[VISIT_GSMUP_CRI_02_BUFLEN_OUT][3];
	char    asAct3[VISIT_GSMUP_CRI_02_BUFLEN_OUT][2];
	char    asCode3[VISIT_GSMUP_CRI_02_BUFLEN_OUT][3];
	char    asAct4[VISIT_GSMUP_CRI_02_BUFLEN_OUT][2];
	char    asCode4[VISIT_GSMUP_CRI_02_BUFLEN_OUT][3];
	char    asAct5[VISIT_GSMUP_CRI_02_BUFLEN_OUT][2];
	char    asCode5[VISIT_GSMUP_CRI_02_BUFLEN_OUT][3];
	char    asMsc[VISIT_GSMUP_CRI_02_BUFLEN_OUT][16];
	char    asLac[VISIT_GSMUP_CRI_02_BUFLEN_OUT][6];
	char    asCellID[VISIT_GSMUP_CRI_02_BUFLEN_OUT][6];
	char    asServType[VISIT_GSMUP_CRI_02_BUFLEN_OUT][2];
	char    asStartDate[VISIT_GSMUP_CRI_02_BUFLEN_OUT][9];
	char    asStartTime[VISIT_GSMUP_CRI_02_BUFLEN_OUT][7];
	char    asPayUnit[VISIT_GSMUP_CRI_02_BUFLEN_OUT][7];
	char    asFlowRef[VISIT_GSMUP_CRI_02_BUFLEN_OUT][7];
	char    asTollCode[VISIT_GSMUP_CRI_02_BUFLEN_OUT][2];
	char    asOtherCode[VISIT_GSMUP_CRI_02_BUFLEN_OUT][3];
	char    asRoamFee[VISIT_GSMUP_CRI_02_BUFLEN_OUT][10];
	char    asTollFee[VISIT_GSMUP_CRI_02_BUFLEN_OUT][7];
	char    asOtherFee[VISIT_GSMUP_CRI_02_BUFLEN_OUT][7];
	char    asPayItem[VISIT_GSMUP_CRI_02_BUFLEN_OUT][2];
	char    asSystemType[VISIT_GSMUP_CRI_02_BUFLEN_OUT][2];
	char    asRateIndication[VISIT_GSMUP_CRI_02_BUFLEN_OUT][2];
	char    asHotBillingTag[VISIT_GSMUP_CRI_02_BUFLEN_OUT][2];
	char    asImei[VISIT_GSMUP_CRI_02_BUFLEN_OUT][26];
	char    asReserve2[VISIT_GSMUP_CRI_02_BUFLEN_OUT][31];
	char	asSourceID[VISIT_GSMUP_CRI_02_BUFLEN_OUT][41];
};


/* ����ṹ��������*/
struct VisitGsmupCriStructIn{

#ifndef VISIT_GSMUP_CRI_02_BUFLEN_IN
#define VISIT_GSMUP_CRI_02_BUFLEN_IN		300
#endif

	struct VisitGsmupCriStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
	char    asRecordType[VISIT_GSMUP_CRI_02_BUFLEN_IN][3];
	char    asInCityCode[VISIT_GSMUP_CRI_02_BUFLEN_IN][4];
	char    asOutCityCode[VISIT_GSMUP_CRI_02_BUFLEN_IN][4];
	char	asScpFlagID[VISIT_GSMUP_CRI_02_BUFLEN_IN][2];
	char    asLinkRef[VISIT_GSMUP_CRI_02_BUFLEN_IN][6];
	char    asReserve1[VISIT_GSMUP_CRI_02_BUFLEN_IN][2];
	char    asImsi[VISIT_GSMUP_CRI_02_BUFLEN_IN][16];
	char    asMsisdn[VISIT_GSMUP_CRI_02_BUFLEN_IN][26];
	char    asModifyTag[VISIT_GSMUP_CRI_02_BUFLEN_IN][2];
	char    asNbrType[VISIT_GSMUP_CRI_02_BUFLEN_IN][2];
	char    asNbrPlan[VISIT_GSMUP_CRI_02_BUFLEN_IN][2];
	char    asOtherParty[VISIT_GSMUP_CRI_02_BUFLEN_IN][26];
	char    asServiceType[VISIT_GSMUP_CRI_02_BUFLEN_IN][2];
	char    asServiceCode[VISIT_GSMUP_CRI_02_BUFLEN_IN][3];
	char    asDupServiceType[VISIT_GSMUP_CRI_02_BUFLEN_IN][2];
	char    asDupServiceCode[VISIT_GSMUP_CRI_02_BUFLEN_IN][3];
	char    asAckChannel[VISIT_GSMUP_CRI_02_BUFLEN_IN][2];
	char    asUseChannel[VISIT_GSMUP_CRI_02_BUFLEN_IN][2];
	char    asTransparentFlag[VISIT_GSMUP_CRI_02_BUFLEN_IN][2];
	char    asAct1[VISIT_GSMUP_CRI_02_BUFLEN_IN][2];
	char    asCode1[VISIT_GSMUP_CRI_02_BUFLEN_IN][3];
	char    asAct2[VISIT_GSMUP_CRI_02_BUFLEN_IN][2];
	char    asCode2[VISIT_GSMUP_CRI_02_BUFLEN_IN][3];
	char    asAct3[VISIT_GSMUP_CRI_02_BUFLEN_IN][2];
	char    asCode3[VISIT_GSMUP_CRI_02_BUFLEN_IN][3];
	char    asAct4[VISIT_GSMUP_CRI_02_BUFLEN_IN][2];
	char    asCode4[VISIT_GSMUP_CRI_02_BUFLEN_IN][3];
	char    asAct5[VISIT_GSMUP_CRI_02_BUFLEN_IN][2];
	char    asCode5[VISIT_GSMUP_CRI_02_BUFLEN_IN][3];
	char    asMsc[VISIT_GSMUP_CRI_02_BUFLEN_IN][16];
	char    asLac[VISIT_GSMUP_CRI_02_BUFLEN_IN][6];
	char    asCellID[VISIT_GSMUP_CRI_02_BUFLEN_IN][6];
	char    asServType[VISIT_GSMUP_CRI_02_BUFLEN_IN][2];
	char    asStartDate[VISIT_GSMUP_CRI_02_BUFLEN_IN][9];
	char    asStartTime[VISIT_GSMUP_CRI_02_BUFLEN_IN][7];
	char    asPayUnit[VISIT_GSMUP_CRI_02_BUFLEN_IN][7];
	char    asFlowRef[VISIT_GSMUP_CRI_02_BUFLEN_IN][7];
	char    asTollCode[VISIT_GSMUP_CRI_02_BUFLEN_IN][2];
	char    asOtherCode[VISIT_GSMUP_CRI_02_BUFLEN_IN][3];
	char    asRoamFee[VISIT_GSMUP_CRI_02_BUFLEN_IN][10];
	char    asTollFee[VISIT_GSMUP_CRI_02_BUFLEN_IN][7];
	char    asOtherFee[VISIT_GSMUP_CRI_02_BUFLEN_IN][7];
	char    asPayItem[VISIT_GSMUP_CRI_02_BUFLEN_IN][2];
	char    asSystemType[VISIT_GSMUP_CRI_02_BUFLEN_IN][2];
	char    asRateIndication[VISIT_GSMUP_CRI_02_BUFLEN_IN][2];
	char    asHotBillingTag[VISIT_GSMUP_CRI_02_BUFLEN_IN][2];
	char    asImei[VISIT_GSMUP_CRI_02_BUFLEN_IN][26];
	char    asReserve2[VISIT_GSMUP_CRI_02_BUFLEN_IN][41];
	char	asSourceID[VISIT_GSMUP_CRI_02_BUFLEN_IN][31];
};


/*�����ṹ����*/
struct VisitGsmupCriStruct{

	struct VisitGsmupCriStruct *pNext;
	char    sRecordType[3];
	char    sInCityCode[4];
	char    sOutCityCode[4];
	char	sScpFlagID[2];
	char    sLinkRef[6];
	char    sReserve1[2];
	char    sImsi[16];
	char    sMsisdn[26];
	char    sModifyTag[2];
	char    sNbrType[2];
	char    sNbrPlan[2];
	char    sOtherParty[26];
	char    sServiceType[2];
	char    sServiceCode[3];
	char    sDupServiceType[2];
	char    sDupServiceCode[3];
	char    sAckChannel[2];
	char    sUseChannel[2];
	char    sTransparentFlag[2];
	char    sAct1[2];
	char    sCode1[3];
	char    sAct2[2];
	char    sCode2[3];
	char    sAct3[2];
	char    sCode3[3];
	char    sAct4[2];
	char    sCode4[3];
	char    sAct5[2];
	char    sCode5[3];
	char    sMsc[16];
	char    sLac[6];
	char    sCellID[6];
	char    sServType[2];
	char    sStartDate[9];
	char    sStartTime[7];
	char    sPayUnit[7];
	char    sFlowRef[7];
	char    sTollCode[2];
	char    sOtherCode[3];
	char    sRoamFee[10];
	char    sTollFee[7];
	char    sOtherFee[7];
	char    sPayItem[2];
	char    sSystemType[2];
	char    sRateIndication[2];
	char    sHotBillingTag[2];
	char    sImei[26];
	char    sReserve2[31];
	char	sSourceID[41];
	struct VisitGsmupCriStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
struct FVisitGsmupCriStruct{

	char    sRecordType[2];
	char    sInCityCode[3];
	char    sOutCityCode[3];
	char    sLinkRef[6];
	char    sReserve1[1];
	char    sImsi[15];
	char    sMsisdn[25];
	char    sModifyTag[1];
	char    sNbrType[1];
	char    sNbrPlan[1];
	char    sOtherParty[25];
	char    sServiceType[1];
	char    sServiceCode[2];
	char    sDupServiceType[1];
	char    sDupServiceCode[2];
	char    sAckChannel[1];
	char    sUseChannel[1];
	char    sTransparentFlag[1];
	char    sAct1[1];
	char    sCode1[2];
	char    sAct2[1];
	char    sCode2[2];
	char    sAct3[1];
	char    sCode3[2];
	char    sAct4[1];
	char    sCode4[2];
	char    sAct5[1];
	char    sCode5[2];
	char    sMsc[15];
	char    sLac[5];
	char    sCellID[5];
	char    sServType[1];
	char    sStartDate[8];
	char    sStartTime[6];
	char    sPayUnit[6];
	char    sFlowRef[6];
	char    sTollCode[1];
	char    sOtherCode[2];
	char    sRoamFee[9];
	char    sTollFee[6];
	char    sOtherFee[6];
	char    sPayItem[1];
	char    sSystemType[1];
	char    sRateIndication[1];
	char    sHotBillingTag[1];
	char    sImei[25];
	char    sReserve2[30];
	char	sSourceID[40];
};

/*�������ݽṹ����д��VISIT_GSMUP_CRI_02*/
int EInsertStructToVisitGsmupCri(struct VisitGsmupCriStruct *p,
	int iInsertFlag,struct VisitGsmupCriStructOut *pTarget);

/*����ṹ��������*/
struct VisitGsmupCricfStructOut{

#ifndef VISIT_GSMUP_CRICF_02_BUFLEN_OUT
#define VISIT_GSMUP_CRICF_02_BUFLEN_OUT		300
#endif

	struct VisitGsmupCricfStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
	char    asRecordType[VISIT_GSMUP_CRICF_02_BUFLEN_OUT][3];
	char    asInCityCode[VISIT_GSMUP_CRICF_02_BUFLEN_OUT][4];
	char    asOutCityCode[VISIT_GSMUP_CRICF_02_BUFLEN_OUT][4];
	char	asScpFlagID[VISIT_GSMUP_CRICF_02_BUFLEN_OUT][2];
	char    asLinkRef[VISIT_GSMUP_CRICF_02_BUFLEN_OUT][6];
	char    asReserve1[VISIT_GSMUP_CRICF_02_BUFLEN_OUT][2];
	char    asImsi[VISIT_GSMUP_CRICF_02_BUFLEN_OUT][16];
	char    asThirdParty[VISIT_GSMUP_CRICF_02_BUFLEN_OUT][26];
	char    asMsisdn[VISIT_GSMUP_CRICF_02_BUFLEN_OUT][26];
	char    asOtherParty[VISIT_GSMUP_CRICF_02_BUFLEN_OUT][26];
	char    asServiceType[VISIT_GSMUP_CRICF_02_BUFLEN_OUT][2];
	char    asServiceCode[VISIT_GSMUP_CRICF_02_BUFLEN_OUT][3];
	char    asReserve2[VISIT_GSMUP_CRICF_02_BUFLEN_OUT][10];
	char    asMsc[VISIT_GSMUP_CRICF_02_BUFLEN_OUT][16];
	char    asLac[VISIT_GSMUP_CRICF_02_BUFLEN_OUT][6];
	char    asCellID[VISIT_GSMUP_CRICF_02_BUFLEN_OUT][6];
	char    asServType[VISIT_GSMUP_CRICF_02_BUFLEN_OUT][2];
	char    asStartDate[VISIT_GSMUP_CRICF_02_BUFLEN_OUT][9];
	char    asStartTime[VISIT_GSMUP_CRICF_02_BUFLEN_OUT][7];
	char    asPayUnit[VISIT_GSMUP_CRICF_02_BUFLEN_OUT][7];
	char    asSystemType[VISIT_GSMUP_CRICF_02_BUFLEN_OUT][2];
	char    asRateIndication[VISIT_GSMUP_CRICF_02_BUFLEN_OUT][2];
	char    asHotBillingTag[VISIT_GSMUP_CRICF_02_BUFLEN_OUT][2];
	char    asImei[VISIT_GSMUP_CRICF_02_BUFLEN_OUT][26];
	char    asReserve3[VISIT_GSMUP_CRICF_02_BUFLEN_OUT][52];
	char	asSourceID[VISIT_GSMUP_CRICF_02_BUFLEN_OUT][41];
};


/* ����ṹ��������*/
struct VisitGsmupCricfStructIn{

#ifndef VISIT_GSMUP_CRICF_02_BUFLEN_IN
#define VISIT_GSMUP_CRICF_02_BUFLEN_IN		300
#endif

	struct VisitGsmupCricfStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
	char    asRecordType[VISIT_GSMUP_CRICF_02_BUFLEN_IN][3];
	char    asInCityCode[VISIT_GSMUP_CRICF_02_BUFLEN_IN][4];
	char    asOutCityCode[VISIT_GSMUP_CRICF_02_BUFLEN_IN][4];
	char	asScpFlagID[VISIT_GSMUP_CRICF_02_BUFLEN_IN][2];
	char    asLinkRef[VISIT_GSMUP_CRICF_02_BUFLEN_IN][6];
	char    asReserve1[VISIT_GSMUP_CRICF_02_BUFLEN_IN][2];
	char    asImsi[VISIT_GSMUP_CRICF_02_BUFLEN_IN][16];
	char    asThirdParty[VISIT_GSMUP_CRICF_02_BUFLEN_IN][26];
	char    asMsisdn[VISIT_GSMUP_CRICF_02_BUFLEN_IN][26];
	char    asOtherParty[VISIT_GSMUP_CRICF_02_BUFLEN_IN][26];
	char    asServiceType[VISIT_GSMUP_CRICF_02_BUFLEN_IN][2];
	char    asServiceCode[VISIT_GSMUP_CRICF_02_BUFLEN_IN][3];
	char    asReserve2[VISIT_GSMUP_CRICF_02_BUFLEN_IN][10];
	char    asMsc[VISIT_GSMUP_CRICF_02_BUFLEN_IN][16];
	char    asLac[VISIT_GSMUP_CRICF_02_BUFLEN_IN][6];
	char    asCellID[VISIT_GSMUP_CRICF_02_BUFLEN_IN][6];
	char    asServType[VISIT_GSMUP_CRICF_02_BUFLEN_IN][2];
	char    asStartDate[VISIT_GSMUP_CRICF_02_BUFLEN_IN][9];
	char    asStartTime[VISIT_GSMUP_CRICF_02_BUFLEN_IN][7];
	char    asPayUnit[VISIT_GSMUP_CRICF_02_BUFLEN_IN][7];
	char    asSystemType[VISIT_GSMUP_CRICF_02_BUFLEN_IN][2];
	char    asRateIndication[VISIT_GSMUP_CRICF_02_BUFLEN_IN][2];
	char    asHotBillingTag[VISIT_GSMUP_CRICF_02_BUFLEN_IN][2];
	char    asImei[VISIT_GSMUP_CRICF_02_BUFLEN_IN][26];
	char    asReserve3[VISIT_GSMUP_CRICF_02_BUFLEN_IN][52];
	char	asSourceID[VISIT_GSMUP_CRICF_02_BUFLEN_IN][41];
};


/*�����ṹ����*/
struct VisitGsmupCricfStruct{

	struct VisitGsmupCricfStruct *pNext;
	char    sRecordType[3];
	char    sInCityCode[4];
	char    sOutCityCode[4];
	char	sScpFlagID[2];
	char    sLinkRef[6];
	char    sReserve1[2];
	char    sImsi[16];
	char    sThirdParty[26];
	char    sMsisdn[26];
	char    sOtherParty[26];
	char    sServiceType[2];
	char    sServiceCode[3];
	char    sReserve2[10];
	char    sMsc[16];
	char    sLac[6];
	char    sCellID[6];
	char    sServType[2];
	char    sStartDate[9];
	char    sStartTime[7];
	char    sPayUnit[7];
	char    sSystemType[2];
	char    sRateIndication[2];
	char    sHotBillingTag[2];
	char    sImei[26];
	char    sReserve3[52];
	char	sSourceID[41];
	struct VisitGsmupCricfStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
struct FVisitGsmupCricfStruct{

	char    sRecordType[2];
	char    sInCityCode[3];
	char    sOutCityCode[3];
	char    sLinkRef[6];
	char    sReserve1[1];
	char    sImsi[15];
	char    sThirdParty[25];
	char    sMsisdn[25];
	char    sOtherParty[25];
	char    sServiceType[1];
	char    sServiceCode[2];
	char    sReserve2[9];
	char    sMsc[15];
	char    sLac[5];
	char    sCellID[5];
	char    sServType[1];
	char    sStartDate[8];
	char    sStartTime[6];
	char    sPayUnit[6];
	char    sSystemType[1];
	char    sRateIndication[1];
	char    sHotBillingTag[1];
	char    sImei[25];
	char    sReserve3[51];
	char	sSourceID[40];
};

/*�������ݽṹ����д��VISIT_GSMUP_CRICF_02*/
int EInsertStructToVisitGsmupCricf(struct VisitGsmupCricfStruct *p,
	int iInsertFlag,struct VisitGsmupCricfStructOut *pTarget);

/*����ṹ��������*/
struct VisitGsmupCiiStructOut{

#ifndef VISIT_GSMUP_CII_02_BUFLEN_OUT
#define VISIT_GSMUP_CII_02_BUFLEN_OUT		300
#endif

	struct VisitGsmupCiiStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
	char    asRecordType[VISIT_GSMUP_CII_02_BUFLEN_OUT][3];
	char    asInCityCode[VISIT_GSMUP_CII_02_BUFLEN_OUT][4];
	char    asOutCityCode[VISIT_GSMUP_CII_02_BUFLEN_OUT][4];
	char    asLinkRef[VISIT_GSMUP_CII_02_BUFLEN_OUT][7];
	char    asReserve1[VISIT_GSMUP_CII_02_BUFLEN_OUT][2];
	char    asImsi[VISIT_GSMUP_CII_02_BUFLEN_OUT][16];
	char    asMsisdn[VISIT_GSMUP_CII_02_BUFLEN_OUT][26];
	char    asModifyTag[VISIT_GSMUP_CII_02_BUFLEN_OUT][2];
	char    asNbrType[VISIT_GSMUP_CII_02_BUFLEN_OUT][2];
	char    asNbrPlan[VISIT_GSMUP_CII_02_BUFLEN_OUT][2];
	char    asOtherParty[VISIT_GSMUP_CII_02_BUFLEN_OUT][26];
	char    asServiceType[VISIT_GSMUP_CII_02_BUFLEN_OUT][2];
	char    asServiceCode[VISIT_GSMUP_CII_02_BUFLEN_OUT][3];
	char    asDupServiceType[VISIT_GSMUP_CII_02_BUFLEN_OUT][2];
	char    asDupServiceCode[VISIT_GSMUP_CII_02_BUFLEN_OUT][3];
	char    asAckChannel[VISIT_GSMUP_CII_02_BUFLEN_OUT][2];
	char    asUseChannel[VISIT_GSMUP_CII_02_BUFLEN_OUT][2];
	char    asTransparentFlag[VISIT_GSMUP_CII_02_BUFLEN_OUT][2];
	char    asAct1[VISIT_GSMUP_CII_02_BUFLEN_OUT][2];
	char    asCode1[VISIT_GSMUP_CII_02_BUFLEN_OUT][3];
	char    asAct2[VISIT_GSMUP_CII_02_BUFLEN_OUT][2];
	char    asCode2[VISIT_GSMUP_CII_02_BUFLEN_OUT][3];
	char    asAct3[VISIT_GSMUP_CII_02_BUFLEN_OUT][2];
	char    asCode3[VISIT_GSMUP_CII_02_BUFLEN_OUT][3];
	char    asAct4[VISIT_GSMUP_CII_02_BUFLEN_OUT][2];
	char    asCode4[VISIT_GSMUP_CII_02_BUFLEN_OUT][3];
	char    asAct5[VISIT_GSMUP_CII_02_BUFLEN_OUT][2];
	char    asCode5[VISIT_GSMUP_CII_02_BUFLEN_OUT][3];
	char    asMsc[VISIT_GSMUP_CII_02_BUFLEN_OUT][16];
	char    asLac[VISIT_GSMUP_CII_02_BUFLEN_OUT][6];
	char    asCellID[VISIT_GSMUP_CII_02_BUFLEN_OUT][6];
	char    asServType[VISIT_GSMUP_CII_02_BUFLEN_OUT][2];
	char    asStartDate[VISIT_GSMUP_CII_02_BUFLEN_OUT][9];
	char    asStartTime[VISIT_GSMUP_CII_02_BUFLEN_OUT][7];
	char    asPayUnit[VISIT_GSMUP_CII_02_BUFLEN_OUT][7];
	char    asFlowRef[VISIT_GSMUP_CII_02_BUFLEN_OUT][7];
	char    asFee[VISIT_GSMUP_CII_02_BUFLEN_OUT][10];
	char    asPayItem[VISIT_GSMUP_CII_02_BUFLEN_OUT][2];
	char    asSystemType[VISIT_GSMUP_CII_02_BUFLEN_OUT][2];
	char    asRateIndication[VISIT_GSMUP_CII_02_BUFLEN_OUT][2];
	char    asHotBillingTag[VISIT_GSMUP_CII_02_BUFLEN_OUT][2];
	char    asVhe[VISIT_GSMUP_CII_02_BUFLEN_OUT][2];
	char    asInterScpFlag[VISIT_GSMUP_CII_02_BUFLEN_OUT][11];
	char    asReserve2[VISIT_GSMUP_CII_02_BUFLEN_OUT][17];
	char	asSourceID[VISIT_GSMUP_CII_02_BUFLEN_OUT][41];
};


/* ����ṹ��������*/
struct VisitGsmupCiiStructIn{

#ifndef VISIT_GSMUP_CII_02_BUFLEN_IN
#define VISIT_GSMUP_CII_02_BUFLEN_IN		300
#endif

	struct VisitGsmupCiiStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
	char    asRecordType[VISIT_GSMUP_CII_02_BUFLEN_IN][3];
	char    asInCityCode[VISIT_GSMUP_CII_02_BUFLEN_IN][4];
	char    asOutCityCode[VISIT_GSMUP_CII_02_BUFLEN_IN][4];
	char    asLinkRef[VISIT_GSMUP_CII_02_BUFLEN_IN][7];
	char    asReserve1[VISIT_GSMUP_CII_02_BUFLEN_IN][2];
	char    asImsi[VISIT_GSMUP_CII_02_BUFLEN_IN][16];
	char    asMsisdn[VISIT_GSMUP_CII_02_BUFLEN_IN][26];
	char    asModifyTag[VISIT_GSMUP_CII_02_BUFLEN_IN][2];
	char    asNbrType[VISIT_GSMUP_CII_02_BUFLEN_IN][2];
	char    asNbrPlan[VISIT_GSMUP_CII_02_BUFLEN_IN][2];
	char    asOtherParty[VISIT_GSMUP_CII_02_BUFLEN_IN][26];
	char    asServiceType[VISIT_GSMUP_CII_02_BUFLEN_IN][2];
	char    asServiceCode[VISIT_GSMUP_CII_02_BUFLEN_IN][3];
	char    asDupServiceType[VISIT_GSMUP_CII_02_BUFLEN_IN][2];
	char    asDupServiceCode[VISIT_GSMUP_CII_02_BUFLEN_IN][3];
	char    asAckChannel[VISIT_GSMUP_CII_02_BUFLEN_IN][2];
	char    asUseChannel[VISIT_GSMUP_CII_02_BUFLEN_IN][2];
	char    asTransparentFlag[VISIT_GSMUP_CII_02_BUFLEN_IN][2];
	char    asAct1[VISIT_GSMUP_CII_02_BUFLEN_IN][2];
	char    asCode1[VISIT_GSMUP_CII_02_BUFLEN_IN][3];
	char    asAct2[VISIT_GSMUP_CII_02_BUFLEN_IN][2];
	char    asCode2[VISIT_GSMUP_CII_02_BUFLEN_IN][3];
	char    asAct3[VISIT_GSMUP_CII_02_BUFLEN_IN][2];
	char    asCode3[VISIT_GSMUP_CII_02_BUFLEN_IN][3];
	char    asAct4[VISIT_GSMUP_CII_02_BUFLEN_IN][2];
	char    asCode4[VISIT_GSMUP_CII_02_BUFLEN_IN][3];
	char    asAct5[VISIT_GSMUP_CII_02_BUFLEN_IN][2];
	char    asCode5[VISIT_GSMUP_CII_02_BUFLEN_IN][3];
	char    asMsc[VISIT_GSMUP_CII_02_BUFLEN_IN][16];
	char    asLac[VISIT_GSMUP_CII_02_BUFLEN_IN][6];
	char    asCellID[VISIT_GSMUP_CII_02_BUFLEN_IN][6];
	char    asServType[VISIT_GSMUP_CII_02_BUFLEN_IN][2];
	char    asStartDate[VISIT_GSMUP_CII_02_BUFLEN_IN][9];
	char    asStartTime[VISIT_GSMUP_CII_02_BUFLEN_IN][7];
	char    asPayUnit[VISIT_GSMUP_CII_02_BUFLEN_IN][7];
	char    asFlowRef[VISIT_GSMUP_CII_02_BUFLEN_IN][7];
	char    asFee[VISIT_GSMUP_CII_02_BUFLEN_IN][10];
	char    asPayItem[VISIT_GSMUP_CII_02_BUFLEN_IN][2];
	char    asSystemType[VISIT_GSMUP_CII_02_BUFLEN_IN][2];
	char    asRateIndication[VISIT_GSMUP_CII_02_BUFLEN_IN][2];
	char    asHotBillingTag[VISIT_GSMUP_CII_02_BUFLEN_IN][2];
	char    asVhe[VISIT_GSMUP_CII_02_BUFLEN_IN][2];
	char    asInterScpFlag[VISIT_GSMUP_CII_02_BUFLEN_IN][11];
	char    asReserve2[VISIT_GSMUP_CII_02_BUFLEN_IN][17];
	char	asSourceID[VISIT_GSMUP_CII_02_BUFLEN_IN][41];
};


/*�����ṹ����*/
struct VisitGsmupCiiStruct{

	struct VisitGsmupCiiStruct *pNext;
	char    sRecordType[3];
	char    sInCityCode[4];
	char    sOutCityCode[4];
	char    sLinkRef[7];
	char    sReserve1[2];
	char    sImsi[16];
	char    sMsisdn[26];
	char    sModifyTag[2];
	char    sNbrType[2];
	char    sNbrPlan[2];
	char    sOtherParty[26];
	char    sServiceType[2];
	char    sServiceCode[3];
	char    sDupServiceType[2];
	char    sDupServiceCode[3];
	char    sAckChannel[2];
	char    sUseChannel[2];
	char    sTransparentFlag[2];
	char    sAct1[2];
	char    sCode1[3];
	char    sAct2[2];
	char    sCode2[3];
	char    sAct3[2];
	char    sCode3[3];
	char    sAct4[2];
	char    sCode4[3];
	char    sAct5[2];
	char    sCode5[3];
	char    sMsc[16];
	char    sLac[6];
	char    sCellID[6];
	char    sServType[2];
	char    sStartDate[9];
	char    sStartTime[7];
	char    sPayUnit[7];
	char    sFlowRef[7];
	char    sFee[10];
	char    sPayItem[2];
	char    sSystemType[2];
	char    sRateIndication[2];
	char    sHotBillingTag[2];
	char    sVhe[2];
	char    sInterScpFlag[11];
	char    sReserve2[17];
	char	sSourceID[41];
	struct VisitGsmupCiiStruct *pLoadNext;
};


/*�����ļ��ṹ����*/
struct FVisitGsmupCiiStruct{

	char    sRecordType[2];
	char    sInCityCode[3];
	char    sOutCityCode[3];
	char    sLinkRef[6];
	char    sReserve1[1];
	char    sImsi[15];
	char    sMsisdn[25];
	char    sModifyTag[1];
	char    sNbrType[1];
	char    sNbrPlan[1];
	char    sOtherParty[25];
	char    sServiceType[1];
	char    sServiceCode[2];
	char    sDupServiceType[1];
	char    sDupServiceCode[2];
	char    sAckChannel[1];
	char    sUseChannel[1];
	char    sTransparentFlag[1];
	char    sAct1[1];
	char    sCode1[2];
	char    sAct2[1];
	char    sCode2[2];
	char    sAct3[1];
	char    sCode3[2];
	char    sAct4[1];
	char    sCode4[2];
	char    sAct5[1];
	char    sCode5[2];
	char    sMsc[15];
	char    sLac[5];
	char    sCellID[5];
	char    sServType[1];
	char    sStartDate[8];
	char    sStartTime[6];
	char    sPayUnit[6];
	char    sFlowRef[6];
	char    sFee[9];
	char    sPayItem[1];
	char    sSystemType[1];
	char    sRateIndication[1];
	char    sHotBillingTag[1];
	char    sVhe[1];
	char    sInterScpFlag[10];
	char    sReserve2[16];
	char 	sSourceID[40];
};

/*�������ݽṹ����д��VISIT_GSMUP_CII_02*/
int EInsertStructToVisitGsmupCii(struct VisitGsmupCiiStruct *p,
	int iInsertFlag,struct VisitGsmupCiiStructOut *pTarget);


#endif

