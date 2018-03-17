#!/bin/sh

if [ "X$APPHOME" = "X" ]; then
APPHOME=/home/bill
HOMEDIR=$APPHOME
fi

SHELLNAME=`basename $0`

###�澯д��澯��־
printALERT()
{
	echo �ű�$SHELLNAME,�澯!ʱ��:`date +"%Y%m%d %H:%M:%S"` ��Ϣ:$@ >>$APPHOME/log/sh.alert.log
	echo �ű�$SHELLNAME,�澯!ʱ��:`date +"%Y%m%d %H:%M:%S"` ��Ϣ:$@ 
}
###һ��澯
printABNORMAL()
{
	echo �ű�$SHELLNAME,�쳣!ʱ��:`date +"%Y%m%d %H:%M:%S"` ��Ϣ:$@ >>$APPHOME/log/sh.abnormal.log
	echo �ű�$SHELLNAME,�쳣!ʱ��:`date +"%Y%m%d %H:%M:%S"` ��Ϣ:$@ 
}
##���ش����˳���־
printERROR()
{
	echo �ű�$SHELLNAME,����!ʱ��:`date +"%Y%m%d %H:%M:%S"` ��Ϣ:$@ >>$APPHOME/log/sh.error.log
	echo �ű�$SHELLNAME,����!ʱ��:`date +"%Y%m%d %H:%M:%S"` ��Ϣ:$@ 
}
##������Ҫ����
printIMPORTANT()
{
	echo �ű�$SHELLNAME,ʱ��:`date +"%Y%m%d %H:%M:%S"` ��Ϣ:$@ >>$APPHOME/log/sh.important.log
	echo �ű�$SHELLNAME,ʱ��:`date +"%Y%m%d %H:%M:%S"` ��Ϣ:$@ 
}
##һ����Ϣ��־
printNORMAL()
{
	echo ʱ��:`date +"%Y%m%d %H:%M:%S"` ��Ϣ:$@ >>$APPHOME/log/$SHELLNAME.log
	echo ʱ��:`date +"%Y%m%d %H:%M:%S"` ��Ϣ:$@ 
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
##���̱�ʶ
getPID()
{
	if [ $# -lt 1 ]; then	return 1; fi
	ps -ef | grep "$1" | grep -v grep | awk '{ print $2}'
}
