#ifndef __WWDBF_H__
#define __WWDBF_H__

struct FDbfHeadStruct
{
	char	cIdentify;	/*固定为0x03*/
	char	sModifyDate[3]; /*最后一次修改日期*/
	char	sRecCnt[4];	/*文件记录数*/
	char	sHeadLen[2];	/*文件头长度,低位在前高位在后,short int*/
	char	sRecLen[2];	/*记录长度,低位在前高位在后,short int*/
	char	sReserve[20];	/*固定填0x00*/	
};
struct FDbfFieldStruct
{
	char	sFieldName[11];	/*左对齐右填0*/
	char	cFieldType;	/*字段类型'C':文本,'N' 数值,其他不知道*/
	char	sFieldIndex[4];	/*固定填0x00*/
	char	cFieldLen;	/*字段长度*/
	char	cPointLen;	/*小数位数,0x00*/
	char	sReserve[14];	/*保留固定填0x00*/
};

#define DBF_FILE_HEAD_END	0x0D/*文件头结束,不包含在文件头长度中*/
#define	DBF_FILE_RECORD_DELFLAG	0x20/*记录删除标识,包含在记录长度中*/
#define DBF_FILE_RECORD_END	0x1A/*文件体结束,不包含在记录长度中*/


#endif
