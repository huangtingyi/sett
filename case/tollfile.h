#ifndef __TOLLFILE_H__
#define __TOLLFILE_H__

struct TollFileStatStruct
{
	char	sVisitAreaCode[10];
	char	sOppAreaCode[10];
	
	int	i301TotalCallNum;
	int	i301TotalDuration;
	int	i301TotalTollFee;
	
	int	i302TotalCallNum;
	int	i302TotalDuration;
	int	i302TotalTollFee;
	
	int	i303TotalCallNum;
	int	i303TotalDuration;
	int	i303TotalTollFee;
	
	int	i304TotalCallNum;
	int	i304TotalDuration;
	int	i304TotalTollFee;
	int	i304TotalRoamFee;
	
	int	i305TotalCallNum;
	int	i305TotalDuration;
	int	i305TotalTollFee;
	
	char	sMinStartTime[15];
	char	sMaxStartTime[15];
	
	int	iTotalRecCnt;
	int	iTotalFee;	
}; 

struct StatAllStruct
{
	int i301StatAllDuration;
	int i301StatAllCallNum;
	int i301StatAllTollFee;
	                       
	int i302StatAllDuration;
	int i302StatAllCallNum;
	int i302StatAllTollFee; 
	                      
	int i303StatAllDuration;
	int i303StatAllCallNum;
	int i303StatAllTollFee;  
	                     
	int i304StatAllDuration;
	int i304StatAllCallNum;
	int i304StatAllTollFee;
	int i304StatAllRoamFee; 
	 
	int i305StatAllDuration;
	int i305StatAllCallNum;
	int i305StatAllTollFee;
	
	int iStalAllRecCnt; 
	int iStatAllFee;
	
	char sFirstStartTime[15];  
	char sLastStartTime[15];   
};

/*������¼�ṹ����*/
struct TollFileBodyStruct{

	char    sVisitCityCode[5];	/*����ͨ�����д���*/
	char    sOutCityCode[5];	/*����ͨ�����д���*/
	char    sTollFee1[11];		/*��;���ѣ�1��*/
	char    sCallNum1[11];		/*��;���ѣ�1��*/
	char    sDuration1[11];		/*���д�����1��*/
	char    sTollFee2[11];		/*ͨ��ʱ����2��*/
	char    sCallNum2[11];		/*���д�����2��*/
	char    sDuration2[11];		/*ͨ��ʱ����2��*/
	char    sTollFee3[11];		/*��;���ѣ�3��*/
	char    sCallNum3[11];		/*���д�����3��*/
	char    sDuration3[11];		/*ͨ��ʱ����3��*/
	char    sTollFee4[11];		/*��;���ѣ�4��*/
	char	sLocalFee4[11];		/*�����л��ѣ�4��*/	
	char    sCallNum4[11];		/*���д�����4��*/
	char    sDuration4[11];		/*ͨ��ʱ����4��*/
	char    sTollFee5[11];		/*��;���ѣ�5��*/
	char    sCallNum5[11];		/*���д�����5��*/
	char    sDuration5[11];		/*ͨ��ʱ����5��*/
};



/*�����ļ�ͷ��¼�ṹ����*/
struct TollFileHeadStruct{

	char    sFileType[3];		/*��¼����*/
	char    sCompanyCode[4];	/*ʡ�ֹ�˾����*/
	char    sFileFlag[4];		/*�ļ���־*/
	char    sFileSeq[6];		/*�ļ����к�*/
	char    sFileVersion[3];	/*�ļ��汾��*/
	char    sFileCreateDate[9];	/*�ļ���������*/
	char    sBeginDate[9];		/*�״�ͨ������*/	
	char	sBeginTime[9];		/*�״�ͨ��ʱ��*/
	char    sEndDate[9];		/*ĩ��ͨ������*/
	char 	sEndTime[9];		/*ĩ��ͨ��ʱ��*/	
	char    sTotalRecord[7];	/*�ܼ�¼��*/
	char    sTotalFee[16];		/*�ܻ���*/
	char	sUnUsedSpace[95];	/*δ��*/

};


/*�����ļ�β�ṹ����*/
struct TollFileTailStruct{

	char    sUnusedSpace[7];		/*�� ��*/	
	char    sTotalTollFee1[11];		/*�ܳ�;���ѣ�1�� */
	char    sTotalCallNum1[11];		/*�ܺ��д�����1�� */
	char    sTotalDuration1[11];		/*��ͨ��ʱ����1�� */
	char    sTotalTollFee2[11];		/*�ܳ�;���ѣ�2�� */
	char    sTotalCallNum2[11];		/*�ܺ��д�����2�� */
	char    sTotalDuration2[11];		/*��ͨ��ʱ����2�� */
	char    sTotalTollFee3[11];		/*�ܳ�;���ѣ�3�� */
	char    sTotalCallNum3[11];		/*�ܺ��д�����3�� */
	char    sTotalDuration3[11];		/*��ͨ��ʱ����3�� */
	char    sTotalTollFee4[11];		/*�ܳ�;���ѣ�4�� */
	char	sTotalLocalFee4[11];		/*�ܳ����л���(4) */        
	char    sTotalCallNum4[11];		/*�ܺ��д�����4�� */
	char    sTotalDuration4[11]; 		/*��ͨ��ʱ����4�� */
	char    sTotalTollFee5[11];		/*�ܳ�;���ѣ�5�� */
	char    sTotalCallNum5[11];		/*�ܺ��д�����5�� */
	char    sTotalDuration5[11]; 		/*��ͨ��ʱ����5��*/ 
                                        
};
#endif
