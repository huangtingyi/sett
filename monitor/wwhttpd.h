#ifndef __WWHTTP_H__
#define __WWHTTP_H__

struct HttpRequestStruct{
	char *sMode;		/*����ģʽGET,POST,HEAD��*/
	char *sVersion;		/*http�汾��*/
	char *sFileName;	/*������ļ���url��վ�㿪ʼ����ǰ�������ļ�����*/
	char *sQryStr;		/*��ʾ�ļ������������*/
	char *sPostData;	/*Post��ʽ�ύ������*/
	int  iPostDataLen;	/*Post���ݵĳ���*/
	FILE *fp;		/*Ϊ�������������post�������ݱ�������ʱ�ļ�*/
	struct nvlist *pOptList;/*http��ѡ��������ݳ��ȣ�cookie��,��ʵQuery_StringҲ������Ϊ������*/
	int iOptCnt;
	char *sClientIp;	/*�ͻ���Ip*/
};


struct pipe_fd {
	int r;
	int w;
};

void wwHttpRequest(int iSockFd,char sIpAddr[],char sRequest[],
	int iBuffLen,char *envp[]);
void SendError(int iSockFd,struct HttpRequestStruct *request,int iState);

#ifndef PATH_MAX
#define PATH_MAX 255
#endif

#endif
