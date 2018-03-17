#ifndef __UPDATA_1X_RET_H
#define __UPDATA_1X_RET_H
/********************文件头******************************************/
struct FirstRecd {   				/*接口文件首记录格式*/
	char record_type[2];	 		/*记录类型    首记录 01*/
	char file_seq[4];                      /*文件序列号  */
	char file_ver[2];                      /*文件版本号  */
	char aaa_syscode[3];                   /*AAA系统代码 */   
	char city_code[3];                     /*城市代码    */
	char created_date[8];                  /*文件产生日期*/
	char first_call_date[8];               /*首次连接日期*/
	char first_call_time[6];               /*首次连接时间*/
	char end_call_date[8];                 /*末次连接日期*/
	char end_call_time[6];                 /*末次连接时间*/
	char all_records[10];                       /*总记录数    */
	char all_durations[10];                    /*总费用      */
	char noused[418];                       /*未用        */
	char sBackSpace1[1];                    /*换行        */
};
#endif
