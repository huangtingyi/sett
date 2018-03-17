#ifndef __WWHTTP_H__
#define __WWHTTP_H__

struct HttpRequestStruct{
	char *sMode;		/*请求模式GET,POST,HEAD等*/
	char *sVersion;		/*http版本号*/
	char *sFileName;	/*请求的文件名url从站点开始到？前结束的文件名。*/
	char *sQryStr;		/*请示文件？后面的内容*/
	char *sPostData;	/*Post方式提交的数据*/
	int  iPostDataLen;	/*Post数据的长度*/
	FILE *fp;		/*为处理大数据量的post将其内容保存至临时文件*/
	struct nvlist *pOptList;/*http的选项，包括内容长度，cookie等,其实Query_String也可以做为引子项*/
	int iOptCnt;
	char *sClientIp;	/*客户端Ip*/
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
