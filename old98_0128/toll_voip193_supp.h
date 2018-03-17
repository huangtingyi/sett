#ifndef __TOLLVOIP193_H__
#define __TOLLVOIP193_H__

/*�����ļ�ͷ��¼�ṹ����*/
struct FileHeadStruct{

	char    sType[3];		/*��¼����*/
	char    sCompanyCode[4];	/*ʡ�ֹ�˾����*/
	char    sFileType[4];		/*�ļ���־*/
	char    sFileSeq[4];		/*�ļ����к�*/
	char    sFileVersion[3];	/*�ļ��汾��*/
	char    sFileCreateDate[9];	/*�ļ���������*/
	char    sTotalRecord[7];	/*�ܼ�¼��*/
	char    sTotalFee[16];		/*�ܻ���*/
	char	sSpace[55];		/*�ո�*/

};
/*Toll�ļ����¼�ṹ����*/
struct TollRecordStruct{

	struct TollRecordStruct *pNext;

	char	sInCityCode[5];		/*����ͨ�����д���*/
	char	sOutCityCode[5];	/*����ͨ�����д���*/
	int	iTollFee1;		/*��;����(1)*/
	int	iDuration1;		/*��;ʱ��(1)*/
	int	iCnt1;			/*���д���(1)*/
	int	iTollFee2;		/*��;����(2)*/
	int	iDuration2;		/*��;ʱ��(2)*/
	int	iCnt2;			/*���д���(2)*/
	int	iTollFee3;		/*��;����(3)*/
	int	iDuration3;		/*��;ʱ��(3)*/
	int	iCnt3;			/*���д���(3)*/
};
/*Voip193�ļ����¼�ṹ����*/
struct Voip193RecordStruct{

	struct Voip193RecordStruct *pNext;

	char	sInCityCode[5];		/*����ͨ�����д���*/
	char	sOutCityCode[5];	/*����ͨ�����д���*/
	int	iTollFee1;		/*��;����(1)*/
	int	iDuration1;		/*��;ʱ��(1)*/
	int	iCnt1;			/*���д���(1)*/
	int	iTollFee2;		/*��;����(2)*/
	int	iDuration2;		/*��;ʱ��(2)*/
	int	iCnt2;			/*���д���(2)*/
	int	iTollFee3;		/*��;����(3)*/
	int	iDuration3;		/*��;ʱ��(3)*/
	int	iCnt3;			/*���д���(3)*/
	int	iTollFee4;		/*��;����(1)*/
	int	iDuration4;		/*��;ʱ��(1)*/
	int	iCnt4;			/*���д���(1)*/
	int	iTollFee5;		/*��;����(2)*/
	int	iDuration5;		/*��;ʱ��(2)*/
	int	iCnt5;			/*���д���(2)*/
	int	iTollFee6;		/*��;����(3)*/
	int	iDuration6;		/*��;ʱ��(3)*/
	int	iCnt6;			/*���д���(3)*/
};

/*����ṹ��������*/
struct MobCalledStatStructOut{

#ifndef MOB_CALLED_STAT_BUFLEN_OUT
#define MOB_CALLED_STAT_BUFLEN_OUT		300
#endif

	struct MobCalledStatStructOut *pNext;

	int iCurPos;
	int iRecordCnt;
	char sTableName[31];
		/* �������� */
	char    asCallingAreaCode[MOB_CALLED_STAT_BUFLEN_OUT][10];
		/* �������� */
	char    asCalledAreaCode[MOB_CALLED_STAT_BUFLEN_OUT][10];
		/* �������� */
	char    asCallingType[MOB_CALLED_STAT_BUFLEN_OUT][2];
		/* �������� */
	char    asCalledType[MOB_CALLED_STAT_BUFLEN_OUT][2];
		/* ��;�� */
	char    asTollFee[MOB_CALLED_STAT_BUFLEN_OUT][13];
		/* �Ʒ�ʱ�� */
	char    asTollSec[MOB_CALLED_STAT_BUFLEN_OUT][13];
		/* �������� */
	int     aiCnt[MOB_CALLED_STAT_BUFLEN_OUT];
		/* �����·� */
	char    asSettMonth[MOB_CALLED_STAT_BUFLEN_OUT][7];
		/* �������� */
	char    asDealDate[MOB_CALLED_STAT_BUFLEN_OUT][15];
};

/* ����ṹ��������*/
struct MobCalledStatStructIn{

#ifndef MOB_CALLED_STAT_BUFLEN_IN
#define MOB_CALLED_STAT_BUFLEN_IN		300
#endif

	struct MobCalledStatStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* ����Ϊ��ʡ�û� */
	char    asCallingAreaCode[MOB_CALLED_STAT_BUFLEN_IN][10];
		/* ����Ϊʡ���û�����VISIT_AREA_CODEͳ�� */
	char    asCalledAreaCode[MOB_CALLED_STAT_BUFLEN_IN][10];
		/* 'G':G����,'C':C��,'X' :������Ӫ�� */
	char    asCallingType[MOB_CALLED_STAT_BUFLEN_IN][2];
		/* 'G':G����,'C':C��,'X' :������Ӫ�� */
	char    asCalledType[MOB_CALLED_STAT_BUFLEN_IN][2];
		/* ��;�� */
	char    asTollFee[MOB_CALLED_STAT_BUFLEN_IN][13];
		/* 6���ۼ� */
	char    asTollSec[MOB_CALLED_STAT_BUFLEN_IN][13];
		/* ���д��� */
	int     aiCnt[MOB_CALLED_STAT_BUFLEN_IN];
		/* ͳ���·� */
	char    asSettMonth[MOB_CALLED_STAT_BUFLEN_IN][7];
		/* ����ʱ�� */
	char    asDealDate[MOB_CALLED_STAT_BUFLEN_IN][15];
};


/*�����ṹ����*/
struct MobCalledStatStruct{

	struct MobCalledStatStruct *pNext;
	char    sCallingAreaCode[10];		/* ����Ϊ��ʡ�û� */
	char    sCalledAreaCode[10];		/* ����Ϊʡ���û�����VISIT_AREA_CODEͳ�� */
	char    sCallingType[2];		/* 'G':G����,'C':C��,'X' :������Ӫ�� */
	char    sCalledType[2];		/* 'G':G����,'C':C��,'X' :������Ӫ�� */
	char    sTollFee[13];		/* ��;�� */
	char    sTollSec[13];		/* 6���ۼ� */
	int     iCnt;		/* ���д��� */
	char    sSettMonth[7];		/* ͳ���·� */
	char    sDealDate[15];		/* ����ʱ�� */
	struct MobCalledStatStruct *pLoadNext;
};

/* ����ṹ��������*/
struct DataCallingStatStructIn{

#ifndef DATA_CALLING_STAT_BUFLEN_IN
#define DATA_CALLING_STAT_BUFLEN_IN		300
#endif

	struct DataCallingStatStructIn *pNext;

	int iBufEmpty;
	int iCurPos;
	int iFetchRecNum;
	int iEndFlag;
	int iRecCnt;
	int iFirstFlag;
	char sTableName[31];
	char sCondition[1024];
		/* ����Ϊ��ʡ�û� */
	char    asCallingAreaCode[DATA_CALLING_STAT_BUFLEN_IN][10];
		/* ����Ϊʡ���û�����VISIT_AREA_CODEͳ�� */
	char    asCalledAreaCode[DATA_CALLING_STAT_BUFLEN_IN][10];
		/* 'G':G����,'C':C��,'X' :������Ӫ�� */
	char    asCallingType[DATA_CALLING_STAT_BUFLEN_IN][2];
		/* 'G':G����,'C':C��,'X' :������Ӫ�� */
	char    asCalledType[DATA_CALLING_STAT_BUFLEN_IN][2];
		/* 'I':VOIP,'1':193 */
	char    asCallingNetType[DATA_CALLING_STAT_BUFLEN_IN][2];
		/* CARD:'ʡ�ַ��п���ҵ��',LINE:'����ר��ҵ��' */
	char    asServiceType[DATA_CALLING_STAT_BUFLEN_IN][5];
		/* ��;�� */
	char    asTollFee[DATA_CALLING_STAT_BUFLEN_IN][13];
		/* 6���ۼ� */
	char    asTollSec[DATA_CALLING_STAT_BUFLEN_IN][13];
		/* ���д��� */
	int     aiCnt[DATA_CALLING_STAT_BUFLEN_IN];
		/* ͳ���·� */
	char    asSettMonth[DATA_CALLING_STAT_BUFLEN_IN][7];
		/* ����ʱ�� */
	char    asDealDate[DATA_CALLING_STAT_BUFLEN_IN][15];
};


/*�����ṹ����*/
struct DataCallingStatStruct{

	struct DataCallingStatStruct *pNext;
	char    sCallingAreaCode[10];		/* ����Ϊ��ʡ�û� */
	char    sCalledAreaCode[10];		/* ����Ϊʡ���û�����VISIT_AREA_CODEͳ�� */
	char    sCallingType[2];		/* 'G':G����,'C':C��,'X' :������Ӫ�� */
	char    sCalledType[2];		/* 'G':G����,'C':C��,'X' :������Ӫ�� */
	char    sCallingNetType[2];		/* 'I':VOIP,'1':193 */
	char    sServiceType[5];		/* CARD:'ʡ�ַ��п���ҵ��',LINE:'����ר��ҵ��' */
	char    sTollFee[13];		/* ��;�� */
	char    sTollSec[13];		/* 6���ۼ� */
	int     iCnt;		/* ���д��� */
	char    sSettMonth[7];		/* ͳ���·� */
	char    sDealDate[15];		/* ����ʱ�� */
	struct DataCallingStatStruct *pLoadNext;
};

int EGetDataCallingStatToStruct(struct DataCallingStatStruct *p,
	struct DataCallingStatStructIn *pSource);
int EGetMobCalledStatToStruct(struct MobCalledStatStruct *p,
	struct MobCalledStatStructIn *pSource);
void mvitem_voip193recordstruct(struct DataCallingStatStruct *pi,
	struct Voip193RecordStruct *po);
void mvitem_tollrecordstruct(struct MobCalledStatStruct *pi,
	struct TollRecordStruct *po);
int GenCityCode(char sAreaCode[],char sCityCode[]);	
/*Voip193�ļ����¼�ṹ����*/
struct DVoip193RecordStruct{

	struct DVoip193RecordStruct *pNext;

	char	sInCityCode[5];		/*����ͨ�����д���*/
	char	sOutCityCode[5];	/*����ͨ�����д���*/
	int	iTollFee1;		/*��;����(1)*/
	int	iDuration1;		/*��;ʱ��(1)*/
	int	iCnt1;			/*���д���(1)*/
	int	iTollFee2;		/*��;����(2)*/
	int	iDuration2;		/*��;ʱ��(2)*/
	int	iCnt2;			/*���д���(2)*/
	int	iTollFee3;		/*��;����(3)*/
	int	iDuration3;		/*��;ʱ��(3)*/
	int	iCnt3;			/*���д���(3)*/
};

	
#endif
