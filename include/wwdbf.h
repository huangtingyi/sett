#ifndef __WWDBF_H__
#define __WWDBF_H__

struct FDbfHeadStruct
{
	char	cIdentify;	/*�̶�Ϊ0x03*/
	char	sModifyDate[3]; /*���һ���޸�����*/
	char	sRecCnt[4];	/*�ļ���¼��*/
	char	sHeadLen[2];	/*�ļ�ͷ����,��λ��ǰ��λ�ں�,short int*/
	char	sRecLen[2];	/*��¼����,��λ��ǰ��λ�ں�,short int*/
	char	sReserve[20];	/*�̶���0x00*/	
};
struct FDbfFieldStruct
{
	char	sFieldName[11];	/*���������0*/
	char	cFieldType;	/*�ֶ�����'C':�ı�,'N' ��ֵ,������֪��*/
	char	sFieldIndex[4];	/*�̶���0x00*/
	char	cFieldLen;	/*�ֶγ���*/
	char	cPointLen;	/*С��λ��,0x00*/
	char	sReserve[14];	/*�����̶���0x00*/
};

#define DBF_FILE_HEAD_END	0x0D/*�ļ�ͷ����,���������ļ�ͷ������*/
#define	DBF_FILE_RECORD_DELFLAG	0x20/*��¼ɾ����ʶ,�����ڼ�¼������*/
#define DBF_FILE_RECORD_END	0x1A/*�ļ������,�������ڼ�¼������*/


#endif
