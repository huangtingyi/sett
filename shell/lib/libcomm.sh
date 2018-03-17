#!/bin/sh

if [ "X$APPHOME" = "X" ]; then
APPHOME=/home/bill
HOMEDIR=$APPHOME
fi

SHELLNAME=`basename $0`

###告警写入告警日志
printALERT()
{
	echo 脚本$SHELLNAME,告警!时间:`date +"%Y%m%d %H:%M:%S"` 消息:$@ >>$APPHOME/log/sh.alert.log
	echo 脚本$SHELLNAME,告警!时间:`date +"%Y%m%d %H:%M:%S"` 消息:$@ 
}
###一般告警
printABNORMAL()
{
	echo 脚本$SHELLNAME,异常!时间:`date +"%Y%m%d %H:%M:%S"` 消息:$@ >>$APPHOME/log/sh.abnormal.log
	echo 脚本$SHELLNAME,异常!时间:`date +"%Y%m%d %H:%M:%S"` 消息:$@ 
}
##严重错误退出日志
printERROR()
{
	echo 脚本$SHELLNAME,错误!时间:`date +"%Y%m%d %H:%M:%S"` 消息:$@ >>$APPHOME/log/sh.error.log
	echo 脚本$SHELLNAME,错误!时间:`date +"%Y%m%d %H:%M:%S"` 消息:$@ 
}
##进程重要操作
printIMPORTANT()
{
	echo 脚本$SHELLNAME,时间:`date +"%Y%m%d %H:%M:%S"` 消息:$@ >>$APPHOME/log/sh.important.log
	echo 脚本$SHELLNAME,时间:`date +"%Y%m%d %H:%M:%S"` 消息:$@ 
}
##一般消息日志
printNORMAL()
{
	echo 时间:`date +"%Y%m%d %H:%M:%S"` 消息:$@ >>$APPHOME/log/$SHELLNAME.log
	echo 时间:`date +"%Y%m%d %H:%M:%S"` 消息:$@ 
}
alertEXIT()
{
	printALERT $@
	exit 1;
}
errorEXIT()
{
	printERROR $@
	exit 1;
}
##进程标识
getPID()
{
	if [ $# -lt 1 ]; then	return 1; fi
	ps -ef | grep "$1" | grep -v grep | awk '{ print $2}'
}
