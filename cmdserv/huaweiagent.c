/*todo:
	OnTimeOut时是否需要判断命令超时。
	判断指令成功失败后是否需要清空缓冲？
	
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
现在的成功消息只有四种，分别如下：
S0000:CDMA HLR SERVER CONTACTED
S0001:Operate Success
S0002:Login Success
S0003:Exited
*/
#define SCONNECT "S0000"
#define SLOGINED "S0002"
#define SOPERATESUCC "S0001"
#define SEXITED  "S0003"

/*是否已经登陆*/
int iLogined= 0;

/*错误代码定义*/
static char asErrCode[200][2][160]=
{
{  "E0012","语法错误"                                            },
{  "E0015","命令不存在"                                          },
{  "E0019","标识符错误"                                          },
{  "E0020","字符串错误(长度不符等)"                              },
{  "E0024","分隔符错误"                                          },
{  "E0025","指示符错误"                                          },
{  "E0026","参数名错误"                                          },
{  "E0027","多余的参数"                                          },
{  "E0028","缺少参数"                                            },
{  "E0029","参数不一致"                                          },
{  "E0034","值范围超出"                                          },
{  "E0035","错误的信息单元"                                      },
{  "E0050","需输入布尔变量"                                      },
{  "E1004","ODB未使用"                                           },
{  "E1005","业务不支持"                                          },
{  "E2001","IMSI号码不可用"                                      },
{  "E2002","MDN号码不可用"                                       },
{  "E2003","MDN号码尚未使用"                                     },
{  "E2004","待删除的号码不存在"                                  },
{  "E2005","hlr号码不可用"                                       },
{  "E2006","用户尚未开户"                                        },
{  "E2007","IMSI号码错误"                                        },
{  "E2008","OMC数据库操作失败"                                   },
{  "E2009","HDB操作超时,请稍候操作"                              },
{  "E2010","过虑数据失败"                                        },
{  "E2011","转换开户数据失败"                                    },
{  "E2012","创建子线程失败"                                      },
{  "E2013","网络出现故障"                                        },
{  "E2014","WS传来的数据不对"                                    },
{  "E2015","用户数据表中无记录"                                  },
{  "E2016","格式化转换出错"                                      },
{  "E2017","补卡操作失败"                                        },
{  "E2018","换号操作失败"                                        },
{  "E2019","开户操作失败"                                        },
{  "E2020","销户操作失败"                                        },
{  "E2021","查询表结构失败"                                      },
{  "E2022","向HLRDB发送数据失败"                                 },
{  "E2023","补充业务操作失败"                                    },
{  "E2024","处理HLRDB返回数据失败"                               },
{  "E2025","查询补充业务失败"                                    },
{  "E2026","查询失败"                                            },
{  "E2027","修改失败"                                            },
{  "E2028","增加失败"                                            },
{  "E2029","删滁失败"                                            },
{  "E2030","添加多MSMDN失败"                                     },
{  "E2031","前转号码不可用"                                      },
{  "E2032","设置主参数失败"                                      },
{  "E2033","查询主参数失败"                                      },
{  "E2034","数据库中无满足条件的记录"                            },
{  "E2035","记录已存在"                                          },
{  "E2036","PACK表失败"                                          },
{  "E2037","正在使用的号码未删除"                                },
{  "E2038","批处理数目不应大于10000"                             },
{  "E2039","读A_key失败"                                         },
{  "E2040","加载A_key失败,请确认A_key.dat文件是否存在"           },
{  "E2041","用户不是预付费用户"                                  },
{  "E2042","操作成功(请注意:有些号码不存在,对它们未做删除操作)"  },
{  "E2043","操作成功(请注意:有些号码已存在,对它们未做增加操作)"  },
{  "E2044","发送CANCEL_LOCATION失败"                             },
{  "E2045","发送VLR_RESET失败"                                   },
{  "E2046","号段间没有未使用号码"                                },
{  "E2047","欲增加的号码数不应超过10000"                         },
{  "E2048","欲删除的号码数不应超过10000"                         },
{  "E2049","修改A_key记录失败"                                   },
{  "E2050","该号码已存在"                                        },
{  "E2051","接入网号码不可用"                                    },
{  "E2052","X号码不可用"                                         },
{  "E2053","该行政区号码已存在"                                  },
{  "E2054","该操作员已存在"                                      },
{  "E2055","主参数未设置"                                        },
{  "E2056","记录数已满50,不能再增加"                             },
{  "E2057","该行政区号码不存在"                                  },
{  "E2058","该用户不能删除"                                      },
{  "E2059","该操作员不存在"                                      },
{  "E2060","密码错误"                                            },
{  "E2061","取环境变量错误"                                      },
{  "E2062","打开文件失败"                                        },
{  "E2063","该号码正在使用"                                      },
{  "E2064","IMSI数目超出空闲容量"                                },
{  "E2065","段溢出"                                              },
{  "E2066","没有号段"                                            },
{  "E2067","IMSI号未销户"                                        },
{  "E2068","号码未使用"                                          },
{  "E2069","已经放号"                                            },
{  "E2070","操作员不存在"                                        },
{  "E2071","部分号码越界,未被加入"                               },
{  "E2072","同虚拟hlr号码冲突"                                   },
{  "E2073","加载A_key部分失败,请检查errorA_key.dat文件"          },
{  "E2074","A_key.dat文件空"                                     },
{  "E2075","加载A_key全部失败,请检查errorA_key.dat文件"          },
{  "E2076","加载成功，但删除文件失败"                            },
{  "E2077","加载部分成功，删除文件失败"                          },
{  "E2078","加载全部失败，删除文件失败"                          },
{  "E2079","服务器内存分配失败,请重启服务器"                     },
{  "E2080","操作失败"                                            },
{  "E2081","此IMSI号码已使用"                                    },
{  "E2082","此MDN号码已使用"                                     },
{  "E2083","该用户不能修改"                                      },
{  "E2084","查询KC失败"                                          },
{  "E2085","HDB返回的MDN号码不可用"                              },
{  "E2086","初始化资源失败"                                      },
{  "E2087","HDB返回的IMSI号码不可用"                             },
{  "E2088","加载UIMID/ESN失败,请确认uimid.dat文件是否存在"       },
{  "E2089","uimid.dat文件空"                                     },
{  "E2090","加载UIMID/ESN部分失败,请检查erroruimid.dat文件"      },
{  "E2091","加载UIMID/ESN全部失败,请检查erroruimid.dat文件"      },
{  "E2092","加载成功，但删除文件失败"                            },
{  "E2093","加载部分成功，删除文件失败"                          },
{  "E2094","加载全部失败，删除文件失败"                          },
{  "E2095","修改UIMID/ESN记录失败"                               },
{  "E2096","读UIMID/ESN失败"                                     },
{  "E2097","转换UIMID/ESN失败"                                   },
{  "E3009","漫游不允许"                                          },
{  "E3010","非法移动设备"                                        },
{  "E3011","承载业务不支持"                                      },
{  "E3012","电信业务不支持"                                      },
{  "E3013","其它错误"                                            },
{  "E3014","呼叫闭锁"                                            },
{  "E3015","前转违例"                                            },
{  "E3016","CUG拒绝"                                             },
{  "E3017","非法的SS操作"                                        },
{  "E3018","SS状态错误"                                          },
{  "E3019","SS不支持"                                            },
{  "E3020","SS签约违例"                                          },
{  "E3021","SS不兼容"                                            },
{  "E3035","系统失效"                                            },
{  "E3036","数据丢失(HDB内部错误)"                               },
{  "E3037","无效数据值"                                          },
{  "E3038","口令注册失败"                                        },
{  "E3039","口令校验失败"                                        },
{  "E3040","其它错误"                                            },
{  "E3041","其它错误"                                            },
{  "E3042","注册偿试超过规定次数"                                },
{  "E3043","表号错误"                                            },
{  "E3044","数据长度错误"                                        },
{  "E3045","未找到呼叫闭锁状态"                                  },
{  "E3046","未找到用户"                                          },
{  "E3047","设置相同"                                            },
{  "E3048","IMSI已在使用,请进行一致性检查"                       },
{  "E3049","无效的补充业务代码"                                  },
{  "E3050","无效的参数"                                          },
{  "E3051","未找到记录"                                          },
{  "E3052","未知信息"                                            },
{  "E3053","业务不支持"                                          },
{  "E3054","记录已存在"                                          },
{  "E3055","已经放号"                                            },
{  "E3056","VLR中无用户"                                         },
{  "E3057","加密KI配置数据错误"                                  },
{  "E3058","用户位置信息未知"                                    },
{  "E3059","无效版本号"                                          },
{  "E3060","没有缺省承载能力"                                    },
{  "E3061","没有找到此MSISDN号"                                  },
{  "E3062","此MDN号已存在"                                       },
{  "E3063","主MSISDN号没有承载能力"                              },
{  "E3064","成功"                                                },
{  "E3065","登记失败"                                            },
{  "E3066","前转地区限制:不能前转到外国"                         },
{  "E3067","前转号码限制:必须带区号(不带国家码)"                 },
{  "E3068","号码错误:无效的号码"                                 },
{  "E3069","前转号码错误:必须带区号(带国家码)"                   },
{  "E3070","前转地区限制:不能前转到外地"                         },
{  "E3071","前转号码非法"                                        },
{  "E3072","用户未签约呼叫等待业务"                              },
{  "E3073","系统不支持呼叫等待业务"                              },
{  "E3074","用户此项业务未提供"                                  },
{  "E3075","请首先提供hold业务,否则mpty业务无法实现"             },
{  "E3076","用户没有基本业务"                                    },
{  "E3077","无效的用户模板号"                                    },
{  "E3078","用户模板数据库未初始化"                              },
{  "E3079","用户模板没有定义"                                    },
{  "E3080","没有VLR区域限制"                                     },
{  "E3081","缺省模板不能修改"                                    },
{  "E3082","非缺省模板名称不能为DEFAULT"                         },
{  "E3083","没有被监听的用户"                                    },
{  "E3084","ODB未启用"                                           },
{  "E3085","用户已上锁"                                          },
{  "E3086","开户失败，插入数据库错误"                            },
{  "E3087","HDB不一致，请重新开户"                               },
{  "E3088","MEM板没有连接"                                       },
{  "E3089","内存不足"                                            },
{  "E3090","响应消息数据丢失"                                    },
{  "E3091","非期望消息响应"                                      },
{  "E3092","Aoci与Aocc互斥"                                      },
{  "E3093","用户没有签约前转"                                    },
{  "E3094","用户没有签约闭锁"                                    },
{  "E3095","没有合适的基本业务"                                  },
{  "E3096","承载业务已有对应的多MSISDN，请先销户"                },
{  "E3104","所输入的CSI参数不合法"                               },
{  "E3106","HDB数据库操作失败,请进行一致性检查"                  },
{  "E3107","HDB已正常退出,请重启HDB."                            },
{  "E3108","设置的模板名已被使用."                               },
{  "E3109","用户没有签约免打扰业务"                              },
{  "E3110","MDN已使用，请进行一致性检查."                        },
{  "E3111","用户数据不一致，请进行一致性查询."                   },
{  "E3112","用户语音邮箱数据空"                                  },
{  "E3113","用户业务没有签约"                                    },
{  "E3114","前转地区限制:无呼叫权限."                            },
{  "E3115","IMSI号和HLR号段不匹配,请增加IMSI号段资源."           },
{  "E3116","MDN号和HLR号段不匹配,请增加MDN号段资源."             },
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
		
		/*找到，返回*/
		if(strncmp(asErrCode[i][0],sErrorCode,5)==0){
			
			strcpy(sErrorDesc,asErrCode[i][1]);
			
			return;
		}
		
		i++;
	}
	
	strcpy(sErrorDesc,"其它错误");	
}

void HuaweiDataAvailble(struct ClientSockStruct *Serv,char sData[])
{
	char *pc,sTemp[257];

	/*接收缓冲满*/
	if(strlen(CmdResult.sRecvBuf)+strlen(sData)>8192){
		strcpy(Intf.sState,COMMAND_STATE_ERR);
		ProcFailureCmd("接收缓冲满");
		return;
	}	
	
	strcat(CmdResult.sRecvBuf,sData);
	/*结果未完全返回则等待返回*/
	if((pc=strchr(sData,0x10))==NULL){
		return;		
	}
	
	/*登陆*/
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
	
	/*退出登陆*/
	if(strncmp(sData,SEXITED,5)==0){
		
		puts("Exited!\n");
		ResetRecvBufAndResult();
		iLogined=false;
		return;
	}
	
	
	
	if(strncmp(CmdResult.sRecvBuf,SOPERATESUCC,5)){
		
		CmdResult.sCmdState[CmdResult.iCurCmd]=CMDSTATE_SUC;
		sprintf(CmdResult.asCmdMsg[CmdResult.iCurCmd],"%s业务操作成功",Intf.sCmdType);

	}
	else if(strstr(CmdResult.sRecvBuf,"=")!= NULL){/*状态查询,QRYINFO*/
	
		CmdResult.sCmdState[CmdResult.iCurCmd]=CMDSTATE_SUC;
		strcpy(CmdResult.asCmdMsg[CmdResult.iCurCmd],CmdResult.sRecvBuf);
		
	}
	else{
		/*错误！！！！*/
		GetErrorDescribe(CmdResult.sRecvBuf,sTemp);
		
		sprintf(CmdResult.asCmdMsg[CmdResult.iCurCmd],"%s-%s",
				Intf.sCmdType,sTemp);	
				
		/*
		注意：对于“E3047:设置相同”错误，实际上表明和期望的结果相同，
		也可以算是操作成功，营业厅客户端应该把这个错误提示当作一个命令成功操作。
		摘自：华为M800 HLR V300R006 营业厅接口协议
		*/		
		if(strncmp(CmdResult.sRecvBuf,"E3047",5)==0)
			CmdResult.sCmdState[CmdResult.iCurCmd]=CMDSTATE_SUC;
		else
			CmdResult.sCmdState[CmdResult.iCurCmd]=CMDSTATE_ERR;	
	}
	
	
	
	/*重置缓冲*/
	ResetRecvBufAndResult();
	
	/*将命令指针移到下一个命令*/
	CmdResult.iCurCmd++;
	/*如果命令没有结束就将下一个命令发过去*/
	if(CmdResult.iCurCmd<CmdResult.iCmdCnt){
		
		GetCmd(&Intf,CmdResult.iCurCmd,sTemp);
		SockSendBuf(Serv->iSockFd,sTemp,strlen(sTemp));
		return;
	}
	
	/*如果到这里命令已经都完毕了，
	1.判定命令的执行结果；
	2.将等待链表中的命令送到执行完毕链表；
	3.将接收缓冲等系统控制变量复位
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
/*连接共享内存*/
	if(ConnectCmdShmAndInitMem()<0){
		printf("连接共享内存失败.\n");
		return -1;
	}
/*检查参数SwitchID的合法性*/	
	if((pAgent=GetShmAgent(iSwitchID))==NULL){
		printf("SwitchID=%d在共享内存中不存在.\n",iSwitchID);
		return -1;
	}
/*用获得的参数初始化InitClientSocket控制结构*/
	InitClientSocket(&Serv,pAgent->sIp,pAgent->iPort,30);
/*设置处理的外置函数*/	
	Serv.OnConnect=	OnConnect;
	Serv.OnTimeOut=	OnTimeOut;
	Serv.OnError=	OnError;
	Serv.ProcCmd=	OnProcCmd;
	Serv.OnDataRecv= 	OnDataRecv;
	Serv.OnDisconnect= 	OnDisconnect;

	ClientSockProcMain(&Serv);
	
	return 0;
}
