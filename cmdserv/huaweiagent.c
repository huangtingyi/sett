/*todo:
	OnTimeOutʱ�Ƿ���Ҫ�ж����ʱ��
	�ж�ָ��ɹ�ʧ�ܺ��Ƿ���Ҫ��ջ��壿
	
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <list.h>
#include <wwfile.h>

#include <cmdsupp.h>
#include <intfcmd.h>
#include <wwnet.h>
/*
���ڵĳɹ���Ϣֻ�����֣��ֱ����£�
S0000:CDMA HLR SERVER CONTACTED
S0001:Operate Success
S0002:Login Success
S0003:Exited
*/
#define SCONNECT "S0000"
#define SLOGINED "S0002"
#define SOPERATESUCC "S0001"
#define SEXITED  "S0003"

/*�Ƿ��Ѿ���½*/
int iLogined= 0;

/*������붨��*/
static char asErrCode[200][2][160]=
{
{  "E0012","�﷨����"                                            },
{  "E0015","�������"                                          },
{  "E0019","��ʶ������"                                          },
{  "E0020","�ַ�������(���Ȳ�����)"                              },
{  "E0024","�ָ�������"                                          },
{  "E0025","ָʾ������"                                          },
{  "E0026","����������"                                          },
{  "E0027","����Ĳ���"                                          },
{  "E0028","ȱ�ٲ���"                                            },
{  "E0029","������һ��"                                          },
{  "E0034","ֵ��Χ����"                                          },
{  "E0035","�������Ϣ��Ԫ"                                      },
{  "E0050","�����벼������"                                      },
{  "E1004","ODBδʹ��"                                           },
{  "E1005","ҵ��֧��"                                          },
{  "E2001","IMSI���벻����"                                      },
{  "E2002","MDN���벻����"                                       },
{  "E2003","MDN������δʹ��"                                     },
{  "E2004","��ɾ���ĺ��벻����"                                  },
{  "E2005","hlr���벻����"                                       },
{  "E2006","�û���δ����"                                        },
{  "E2007","IMSI�������"                                        },
{  "E2008","OMC���ݿ����ʧ��"                                   },
{  "E2009","HDB������ʱ,���Ժ����"                              },
{  "E2010","��������ʧ��"                                        },
{  "E2011","ת����������ʧ��"                                    },
{  "E2012","�������߳�ʧ��"                                      },
{  "E2013","������ֹ���"                                        },
{  "E2014","WS���������ݲ���"                                    },
{  "E2015","�û����ݱ����޼�¼"                                  },
{  "E2016","��ʽ��ת������"                                      },
{  "E2017","��������ʧ��"                                        },
{  "E2018","���Ų���ʧ��"                                        },
{  "E2019","��������ʧ��"                                        },
{  "E2020","��������ʧ��"                                        },
{  "E2021","��ѯ��ṹʧ��"                                      },
{  "E2022","��HLRDB��������ʧ��"                                 },
{  "E2023","����ҵ�����ʧ��"                                    },
{  "E2024","����HLRDB��������ʧ��"                               },
{  "E2025","��ѯ����ҵ��ʧ��"                                    },
{  "E2026","��ѯʧ��"                                            },
{  "E2027","�޸�ʧ��"                                            },
{  "E2028","����ʧ��"                                            },
{  "E2029","ɾ��ʧ��"                                            },
{  "E2030","��Ӷ�MSMDNʧ��"                                     },
{  "E2031","ǰת���벻����"                                      },
{  "E2032","����������ʧ��"                                      },
{  "E2033","��ѯ������ʧ��"                                      },
{  "E2034","���ݿ��������������ļ�¼"                            },
{  "E2035","��¼�Ѵ���"                                          },
{  "E2036","PACK��ʧ��"                                          },
{  "E2037","����ʹ�õĺ���δɾ��"                                },
{  "E2038","��������Ŀ��Ӧ����10000"                             },
{  "E2039","��A_keyʧ��"                                         },
{  "E2040","����A_keyʧ��,��ȷ��A_key.dat�ļ��Ƿ����"           },
{  "E2041","�û�����Ԥ�����û�"                                  },
{  "E2042","�����ɹ�(��ע��:��Щ���벻����,������δ��ɾ������)"  },
{  "E2043","�����ɹ�(��ע��:��Щ�����Ѵ���,������δ�����Ӳ���)"  },
{  "E2044","����CANCEL_LOCATIONʧ��"                             },
{  "E2045","����VLR_RESETʧ��"                                   },
{  "E2046","�Ŷμ�û��δʹ�ú���"                                },
{  "E2047","�����ӵĺ�������Ӧ����10000"                         },
{  "E2048","��ɾ���ĺ�������Ӧ����10000"                         },
{  "E2049","�޸�A_key��¼ʧ��"                                   },
{  "E2050","�ú����Ѵ���"                                        },
{  "E2051","���������벻����"                                    },
{  "E2052","X���벻����"                                         },
{  "E2053","�������������Ѵ���"                                  },
{  "E2054","�ò���Ա�Ѵ���"                                      },
{  "E2055","������δ����"                                        },
{  "E2056","��¼������50,����������"                             },
{  "E2057","�����������벻����"                                  },
{  "E2058","���û�����ɾ��"                                      },
{  "E2059","�ò���Ա������"                                      },
{  "E2060","�������"                                            },
{  "E2061","ȡ������������"                                      },
{  "E2062","���ļ�ʧ��"                                        },
{  "E2063","�ú�������ʹ��"                                      },
{  "E2064","IMSI��Ŀ������������"                                },
{  "E2065","�����"                                              },
{  "E2066","û�кŶ�"                                            },
{  "E2067","IMSI��δ����"                                        },
{  "E2068","����δʹ��"                                          },
{  "E2069","�Ѿ��ź�"                                            },
{  "E2070","����Ա������"                                        },
{  "E2071","���ֺ���Խ��,δ������"                               },
{  "E2072","ͬ����hlr�����ͻ"                                   },
{  "E2073","����A_key����ʧ��,����errorA_key.dat�ļ�"          },
{  "E2074","A_key.dat�ļ���"                                     },
{  "E2075","����A_keyȫ��ʧ��,����errorA_key.dat�ļ�"          },
{  "E2076","���سɹ�����ɾ���ļ�ʧ��"                            },
{  "E2077","���ز��ֳɹ���ɾ���ļ�ʧ��"                          },
{  "E2078","����ȫ��ʧ�ܣ�ɾ���ļ�ʧ��"                          },
{  "E2079","�������ڴ����ʧ��,������������"                     },
{  "E2080","����ʧ��"                                            },
{  "E2081","��IMSI������ʹ��"                                    },
{  "E2082","��MDN������ʹ��"                                     },
{  "E2083","���û������޸�"                                      },
{  "E2084","��ѯKCʧ��"                                          },
{  "E2085","HDB���ص�MDN���벻����"                              },
{  "E2086","��ʼ����Դʧ��"                                      },
{  "E2087","HDB���ص�IMSI���벻����"                             },
{  "E2088","����UIMID/ESNʧ��,��ȷ��uimid.dat�ļ��Ƿ����"       },
{  "E2089","uimid.dat�ļ���"                                     },
{  "E2090","����UIMID/ESN����ʧ��,����erroruimid.dat�ļ�"      },
{  "E2091","����UIMID/ESNȫ��ʧ��,����erroruimid.dat�ļ�"      },
{  "E2092","���سɹ�����ɾ���ļ�ʧ��"                            },
{  "E2093","���ز��ֳɹ���ɾ���ļ�ʧ��"                          },
{  "E2094","����ȫ��ʧ�ܣ�ɾ���ļ�ʧ��"                          },
{  "E2095","�޸�UIMID/ESN��¼ʧ��"                               },
{  "E2096","��UIMID/ESNʧ��"                                     },
{  "E2097","ת��UIMID/ESNʧ��"                                   },
{  "E3009","���β�����"                                          },
{  "E3010","�Ƿ��ƶ��豸"                                        },
{  "E3011","����ҵ��֧��"                                      },
{  "E3012","����ҵ��֧��"                                      },
{  "E3013","��������"                                            },
{  "E3014","���б���"                                            },
{  "E3015","ǰתΥ��"                                            },
{  "E3016","CUG�ܾ�"                                             },
{  "E3017","�Ƿ���SS����"                                        },
{  "E3018","SS״̬����"                                          },
{  "E3019","SS��֧��"                                            },
{  "E3020","SSǩԼΥ��"                                          },
{  "E3021","SS������"                                            },
{  "E3035","ϵͳʧЧ"                                            },
{  "E3036","���ݶ�ʧ(HDB�ڲ�����)"                               },
{  "E3037","��Ч����ֵ"                                          },
{  "E3038","����ע��ʧ��"                                        },
{  "E3039","����У��ʧ��"                                        },
{  "E3040","��������"                                            },
{  "E3041","��������"                                            },
{  "E3042","ע�᳥�Գ����涨����"                                },
{  "E3043","��Ŵ���"                                            },
{  "E3044","���ݳ��ȴ���"                                        },
{  "E3045","δ�ҵ����б���״̬"                                  },
{  "E3046","δ�ҵ��û�"                                          },
{  "E3047","������ͬ"                                            },
{  "E3048","IMSI����ʹ��,�����һ���Լ��"                       },
{  "E3049","��Ч�Ĳ���ҵ�����"                                  },
{  "E3050","��Ч�Ĳ���"                                          },
{  "E3051","δ�ҵ���¼"                                          },
{  "E3052","δ֪��Ϣ"                                            },
{  "E3053","ҵ��֧��"                                          },
{  "E3054","��¼�Ѵ���"                                          },
{  "E3055","�Ѿ��ź�"                                            },
{  "E3056","VLR�����û�"                                         },
{  "E3057","����KI�������ݴ���"                                  },
{  "E3058","�û�λ����Ϣδ֪"                                    },
{  "E3059","��Ч�汾��"                                          },
{  "E3060","û��ȱʡ��������"                                    },
{  "E3061","û���ҵ���MSISDN��"                                  },
{  "E3062","��MDN���Ѵ���"                                       },
{  "E3063","��MSISDN��û�г�������"                              },
{  "E3064","�ɹ�"                                                },
{  "E3065","�Ǽ�ʧ��"                                            },
{  "E3066","ǰת��������:����ǰת�����"                         },
{  "E3067","ǰת��������:���������(����������)"                 },
{  "E3068","�������:��Ч�ĺ���"                                 },
{  "E3069","ǰת�������:���������(��������)"                   },
{  "E3070","ǰת��������:����ǰת�����"                         },
{  "E3071","ǰת����Ƿ�"                                        },
{  "E3072","�û�δǩԼ���еȴ�ҵ��"                              },
{  "E3073","ϵͳ��֧�ֺ��еȴ�ҵ��"                              },
{  "E3074","�û�����ҵ��δ�ṩ"                                  },
{  "E3075","�������ṩholdҵ��,����mptyҵ���޷�ʵ��"             },
{  "E3076","�û�û�л���ҵ��"                                    },
{  "E3077","��Ч���û�ģ���"                                    },
{  "E3078","�û�ģ�����ݿ�δ��ʼ��"                              },
{  "E3079","�û�ģ��û�ж���"                                    },
{  "E3080","û��VLR��������"                                     },
{  "E3081","ȱʡģ�岻���޸�"                                    },
{  "E3082","��ȱʡģ�����Ʋ���ΪDEFAULT"                         },
{  "E3083","û�б��������û�"                                    },
{  "E3084","ODBδ����"                                           },
{  "E3085","�û�������"                                          },
{  "E3086","����ʧ�ܣ��������ݿ����"                            },
{  "E3087","HDB��һ�£������¿���"                               },
{  "E3088","MEM��û������"                                       },
{  "E3089","�ڴ治��"                                            },
{  "E3090","��Ӧ��Ϣ���ݶ�ʧ"                                    },
{  "E3091","��������Ϣ��Ӧ"                                      },
{  "E3092","Aoci��Aocc����"                                      },
{  "E3093","�û�û��ǩԼǰת"                                    },
{  "E3094","�û�û��ǩԼ����"                                    },
{  "E3095","û�к��ʵĻ���ҵ��"                                  },
{  "E3096","����ҵ�����ж�Ӧ�Ķ�MSISDN����������"                },
{  "E3104","�������CSI�������Ϸ�"                               },
{  "E3106","HDB���ݿ����ʧ��,�����һ���Լ��"                  },
{  "E3107","HDB�������˳�,������HDB."                            },
{  "E3108","���õ�ģ�����ѱ�ʹ��."                               },
{  "E3109","�û�û��ǩԼ�����ҵ��"                              },
{  "E3110","MDN��ʹ�ã������һ���Լ��."                        },
{  "E3111","�û����ݲ�һ�£������һ���Բ�ѯ."                   },
{  "E3112","�û������������ݿ�"                                  },
{  "E3113","�û�ҵ��û��ǩԼ"                                    },
{  "E3114","ǰת��������:�޺���Ȩ��."                            },
{  "E3115","IMSI�ź�HLR�Ŷβ�ƥ��,������IMSI�Ŷ���Դ."           },
{  "E3116","MDN�ź�HLR�Ŷβ�ƥ��,������MDN�Ŷ���Դ."             },
{  "",""	}
};

static struct IAgentStruct *pAgent=NULL;

int OnConnect(struct ClientSockStruct *Socket)
{
	puts("OnConnect");
	return 0;
}
int OnTimeOut(struct ClientSockStruct *Serv)
{
	puts("OnTimeOut");
	return 0;
}
int OnError(struct ClientSockStruct *Serv)
{
	puts("OnError");
	return 0;
}
int OnDisconnect(struct ClientSockStruct *Serv)
{
	puts("OnDisconnect");
	return 0;
}

void GetErrorDescribe(char sErrorCode[],char sErrorDesc[])
{
	int i= 0;
	
	while(strlen(asErrCode[i][0])==5){
		
		/*�ҵ�������*/
		if(strncmp(asErrCode[i][0],sErrorCode,5)==0){
			
			strcpy(sErrorDesc,asErrCode[i][1]);
			
			return;
		}
		
		i++;
	}
	
	strcpy(sErrorDesc,"��������");	
}

void HuaweiDataAvailble(struct ClientSockStruct *Serv,char sData[])
{
	char *pc,sTemp[257];

	/*���ջ�����*/
	if(strlen(CmdResult.sRecvBuf)+strlen(sData)>8192){
		strcpy(Intf.sState,COMMAND_STATE_ERR);
		ProcFailureCmd("���ջ�����");
		return;
	}	
	
	strcat(CmdResult.sRecvBuf,sData);
	/*���δ��ȫ������ȴ�����*/
	if((pc=strchr(sData,0x10))==NULL){
		return;		
	}
	
	/*��½*/
	if(iLogined==false){
		
		if(strncmp(CmdResult.sRecvBuf,SCONNECT,5)==0){
			
			if(strlen(pAgent->sUserName))
				sprintf(sTemp,"%clogin:name=\"%s\",pass=\"%s\";\n%c",
					2,pAgent->sUserName,pAgent->sPassword,3);
			else
				sprintf(sTemp,"%clogin:name=\"%s\";\n%c",
					2,pAgent->sUserName,3);

			SockSendBuf(Serv->iSockFd,sTemp,-1);
			ResetRecvBufAndResult();
			return;		
		}
		
		if(strncmp(CmdResult.sRecvBuf,SLOGINED,5)==0){
			
			iLogined= true;
			ResetRecvBufAndResult();
			return;
		}
	}	
	
	/*�˳���½*/
	if(strncmp(sData,SEXITED,5)==0){
		
		puts("Exited!\n");
		ResetRecvBufAndResult();
		iLogined=false;
		return;
	}
	
	
	
	if(strncmp(CmdResult.sRecvBuf,SOPERATESUCC,5)){
		
		CmdResult.sCmdState[CmdResult.iCurCmd]=CMDSTATE_SUC;
		sprintf(CmdResult.asCmdMsg[CmdResult.iCurCmd],"%sҵ������ɹ�",Intf.sCmdType);

	}
	else if(strstr(CmdResult.sRecvBuf,"=")!= NULL){/*״̬��ѯ,QRYINFO*/
	
		CmdResult.sCmdState[CmdResult.iCurCmd]=CMDSTATE_SUC;
		strcpy(CmdResult.asCmdMsg[CmdResult.iCurCmd],CmdResult.sRecvBuf);
		
	}
	else{
		/*���󣡣�����*/
		GetErrorDescribe(CmdResult.sRecvBuf,sTemp);
		
		sprintf(CmdResult.asCmdMsg[CmdResult.iCurCmd],"%s-%s",
				Intf.sCmdType,sTemp);	
				
		/*
		ע�⣺���ڡ�E3047:������ͬ������ʵ���ϱ����������Ľ����ͬ��
		Ҳ�������ǲ����ɹ���Ӫҵ���ͻ���Ӧ�ð����������ʾ����һ������ɹ�������
		ժ�ԣ���ΪM800 HLR V300R006 Ӫҵ���ӿ�Э��
		*/		
		if(strncmp(CmdResult.sRecvBuf,"E3047",5)==0)
			CmdResult.sCmdState[CmdResult.iCurCmd]=CMDSTATE_SUC;
		else
			CmdResult.sCmdState[CmdResult.iCurCmd]=CMDSTATE_ERR;	
	}
	
	
	
	/*���û���*/
	ResetRecvBufAndResult();
	
	/*������ָ���Ƶ���һ������*/
	CmdResult.iCurCmd++;
	/*�������û�н����ͽ���һ�������ȥ*/
	if(CmdResult.iCurCmd<CmdResult.iCmdCnt){
		
		GetCmd(&Intf,CmdResult.iCurCmd,sTemp);
		SockSendBuf(Serv->iSockFd,sTemp,strlen(sTemp));
		return;
	}
	
	/*��������������Ѿ�������ˣ�
	1.�ж������ִ�н����
	2.���ȴ������е������͵�ִ���������
	3.�����ջ����ϵͳ���Ʊ�����λ
	S*/
	AnalizeCmdResult();
	ProcCmdEnd();
	ResetRecvBufAndResult();
	
	return;

}

int OnDataRecv(struct ClientSockStruct *Serv,char sData[],int iLen)
{
	HuaweiDataAvailble(Serv,sData);
	puts(sData);
	return 0;
}

int OnProcCmd(struct ClientSockStruct *Serv)
{
	puts("onProcCmd");	
	GetShmCmdSend(Serv->iSockFd);
	return 0;
}

int main(int argc,char *argv[])
{ 
	int iSwitchID;
	struct ClientSockStruct Serv;
	
	if(argc!=2){
		printf("Usage %s switchid.\n",argv[0]);
		return -1;
	}
	Intf.iSwitchID=iSwitchID=atoi(argv[1]);
/*���ӹ����ڴ�*/
	if(ConnectCmdShmAndInitMem()<0){
		printf("���ӹ����ڴ�ʧ��.\n");
		return -1;
	}
/*������SwitchID�ĺϷ���*/	
	if((pAgent=GetShmAgent(iSwitchID))==NULL){
		printf("SwitchID=%d�ڹ����ڴ��в�����.\n",iSwitchID);
		return -1;
	}
/*�û�õĲ�����ʼ��InitClientSocket���ƽṹ*/
	InitClientSocket(&Serv,pAgent->sIp,pAgent->iPort,30);
/*���ô�������ú���*/	
	Serv.OnConnect=	OnConnect;
	Serv.OnTimeOut=	OnTimeOut;
	Serv.OnError=	OnError;
	Serv.ProcCmd=	OnProcCmd;
	Serv.OnDataRecv= 	OnDataRecv;
	Serv.OnDisconnect= 	OnDisconnect;

	ClientSockProcMain(&Serv);
	
	return 0;
}
