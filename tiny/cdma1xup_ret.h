#ifndef __UPDATA_1X_RET_H
#define __UPDATA_1X_RET_H
/********************�ļ�ͷ******************************************/
struct FirstRecd {   				/*�ӿ��ļ��׼�¼��ʽ*/
	char record_type[2];	 		/*��¼����    �׼�¼ 01*/
	char file_seq[4];                      /*�ļ����к�  */
	char file_ver[2];                      /*�ļ��汾��  */
	char aaa_syscode[3];                   /*AAAϵͳ���� */   
	char city_code[3];                     /*���д���    */
	char created_date[8];                  /*�ļ���������*/
	char first_call_date[8];               /*�״���������*/
	char first_call_time[6];               /*�״�����ʱ��*/
	char end_call_date[8];                 /*ĩ����������*/
	char end_call_time[6];                 /*ĩ������ʱ��*/
	char all_records[10];                       /*�ܼ�¼��    */
	char all_durations[10];                    /*�ܷ���      */
	char noused[418];                       /*δ��        */
	char sBackSpace1[1];                    /*����        */
};
#endif
