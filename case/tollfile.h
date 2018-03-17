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

/*单个记录结构申明*/
struct TollFileBodyStruct{

	char    sVisitCityCode[5];	/*入联通网城市代码*/
	char    sOutCityCode[5];	/*出联通网城市代码*/
	char    sTollFee1[11];		/*长途话费（1）*/
	char    sCallNum1[11];		/*长途话费（1）*/
	char    sDuration1[11];		/*呼叫次数（1）*/
	char    sTollFee2[11];		/*通话时长（2）*/
	char    sCallNum2[11];		/*呼叫次数（2）*/
	char    sDuration2[11];		/*通话时长（2）*/
	char    sTollFee3[11];		/*长途话费（3）*/
	char    sCallNum3[11];		/*呼叫次数（3）*/
	char    sDuration3[11];		/*通话时长（3）*/
	char    sTollFee4[11];		/*长途话费（4）*/
	char	sLocalFee4[11];		/*出网市话费（4）*/	
	char    sCallNum4[11];		/*呼叫次数（4）*/
	char    sDuration4[11];		/*通话时长（4）*/
	char    sTollFee5[11];		/*长途话费（5）*/
	char    sCallNum5[11];		/*呼叫次数（5）*/
	char    sDuration5[11];		/*通话时长（5）*/
};



/*单个文件头记录结构申明*/
struct TollFileHeadStruct{

	char    sFileType[3];		/*记录类型*/
	char    sCompanyCode[4];	/*省分公司代码*/
	char    sFileFlag[4];		/*文件标志*/
	char    sFileSeq[6];		/*文件序列号*/
	char    sFileVersion[3];	/*文件版本号*/
	char    sFileCreateDate[9];	/*文件产生日期*/
	char    sBeginDate[9];		/*首次通话日期*/	
	char	sBeginTime[9];		/*首次通话时间*/
	char    sEndDate[9];		/*末次通话日期*/
	char 	sEndTime[9];		/*末次通话时间*/	
	char    sTotalRecord[7];	/*总记录数*/
	char    sTotalFee[16];		/*总话费*/
	char	sUnUsedSpace[95];	/*未用*/

};


/*单个文件尾结构申明*/
struct TollFileTailStruct{

	char    sUnusedSpace[7];		/*空 格*/	
	char    sTotalTollFee1[11];		/*总长途话费（1） */
	char    sTotalCallNum1[11];		/*总呼叫次数（1） */
	char    sTotalDuration1[11];		/*总通话时长（1） */
	char    sTotalTollFee2[11];		/*总长途话费（2） */
	char    sTotalCallNum2[11];		/*总呼叫次数（2） */
	char    sTotalDuration2[11];		/*总通话时长（2） */
	char    sTotalTollFee3[11];		/*总长途话费（3） */
	char    sTotalCallNum3[11];		/*总呼叫次数（3） */
	char    sTotalDuration3[11];		/*总通话时长（3） */
	char    sTotalTollFee4[11];		/*总长途话费（4） */
	char	sTotalLocalFee4[11];		/*总出网市话费(4) */        
	char    sTotalCallNum4[11];		/*总呼叫次数（4） */
	char    sTotalDuration4[11]; 		/*总通话时长（4） */
	char    sTotalTollFee5[11];		/*总长途话费（5） */
	char    sTotalCallNum5[11];		/*总呼叫次数（5） */
	char    sTotalDuration5[11]; 		/*总通话时长（5）*/ 
                                        
};
#endif
