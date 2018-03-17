#!/bin/sh
. $BILLHOME/shell/lib/libcomm.sh
if [ $# != 2 ]; then
	echo "Usage $0 param procgrp"
	exit 1
fi
mypid=$$
PARAM=$1
procgrp=$2


group=
failcnt=

type=
sourcepath=
backpath=
workpath=
targetpath=
filter=
delay=
msg=

CDMAUPDATA=$BILLHOME/bin/updata_intf

main()
{
cat $PARAM| sed s/#.*$// | while read temp
do
#printALERT "调用prep.sh";
##去掉空行
	if [ X"$temp" = "X" ];then continue; fi
##获取基本参数
	group=`echo "$temp" | awk '{print $1}'`
	
	if [ $group != $procgrp ];then continue; fi
	
	type=`echo "$temp" | awk '{print $2}'`
	sourcepath=`echo "$temp" | awk '{print $3}'`
	backpath=`echo "$temp" | awk '{print $4}'`
	workpath=`echo "$temp" | awk '{print $5}'`
	targetpath=`echo "$temp" | awk '{print $6}'`
	filter=`echo "$temp" | awk '{print $7}'`
	delay=`echo "$temp" | awk '{print $8}'`
	citycode=`echo "$temp" | awk '{print $9}'`	
	echo $CDMAUPDATA $type $sourcepath $backpath $workpath $targetpath $filter $delay $citycode
	msg=`$CDMAUPDATA $type $sourcepath $backpath $workpath $targetpath $filter $delay $citycode`         
	if [ $? -ne 0 ];then
		printALERT "处理失败！$msg $sourcepath "
		failcnt=`echo $failcnt+1 | bc`
		if [ $failcnt -gt 10 ]; then
			printALERT "失败太多,大于10,退出"
			exit 1;
		fi
		continue;
	fi
	printNORMAL "处理完成! $sourcepath,$msg"	                          
	
done
}
main;
exit 0
