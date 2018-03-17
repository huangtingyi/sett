#!/bin/sh
. $BILLHOME/shell/lib/libcomm.sh
if [ $# != 2 ]; then
	echo "Usage $0 smsdupchkparam procgrp"
	exit 1
fi
mypid=$$
RATEPARAM=$1
procgrp=$2

group=
source=
filter=
sourcepath=
backuppath=
normalpath=
dupkeypath=
filename=
temp=
byte=
ret=
datadate=
dealbegindate=
dealenddate=
tempname=
targettemp=
failcnt=0
failcnt1=0
tempmsg=
delay=
handlecnt=
cnt=
errcnt=
abnocnt=
billingname=
templateid=
splitstr=
tempstr=
visitcode=
exprfile=
l1=
i=

SMSDUPCHK=$BILLHOME/bin/smsdupchk
FILEMODIFYDIFF=$BILLHOME/bin/filemodifydiff
FILENAMELIST=$APPHOME/work/smsdupchkfilename$mypid.lst

##检查基本调用是否存在

test -f $RATEPARAM || errorEXIT "文件 $RATEPARAM 不存在"
test -f $SMSDUPCHK || errorEXIT "文件 $SMSDUPCHK 不存在"
test -f $FILEMODIFYDIFF || errorEXIT "文件 $FILEMODIFYDIFF 不存在"
test -d $APPHOME/work || errorEXIT "文件 $APPHOME/work 不存在"

get_file_name()
{
	for i in `echo $@`
	do
		case $i in 
		$filter)
			echo $i
			return 0
			;;
		*)
			;;
		esac
	done
}
delete_billing_ctl()
{
	rm -f $FILENAMELIST; 2>/dev/null
}
main()
{
cat $RATEPARAM| sed s/#.*$// | while read temp
do
#echo "$temp"
##去掉空行
	if [ X"$temp" = "X" ];then continue; fi
##获取基本参数
	group=`echo "$temp" | awk '{print $1}'`
	
	if [ $group != $procgrp ];then continue; fi

	source=`echo "$temp" | awk '{print $2}'`
	filter=`echo "$temp" | awk '{print $3}' | sed s/\"//g`
	sourcepath=`echo "$temp" | awk '{print $4}'`
	backuppath=`echo "$temp" | awk '{print $5}'`
	normalpath=`echo "$temp" | awk '{print $6}'`
	dupkeypath=`echo "$temp" | awk '{print $7}'`

##检查目录合法性如果不存在则退出
	test -d $sourcepath || alertEXIT "路径 $sourcepath 不存在"
	test -d $backuppath || alertEXIT "路径 $backuppath 不存在"
	test -d $normalpath || alertEXIT "路径 $normalpath 不存在"
	test -d $dupkeypath || alertEXIT "路径 $dupkeypath 不存在"
	
##清除批价文件列表
	cat /dev/null >$FILENAMELIST
##获取文件处理列表
        ls -rt $sourcepath/  >$FILENAMELIST

	cat $FILENAMELIST | grep -v Bad | while read filename 
	do
		filename=`get_file_name $filename`
		if  [ X"$filename" = "X" ];then continue; fi
		[ `$FILEMODIFYDIFF $sourcepath/$filename` -lt 60 ] && break;
		
		
		size=`ls -l $sourcepath/$filename | awk '{print $5}'`
		
##指定文件
		tempname=$sourcepath/$filename.tmp
		mv $sourcepath/$filename $tempname
		if [ $? -ne 0 ]; then
			printALERT "移动 $sourcepath/$filename $tempname 失败"
			exit 1;
		fi
		tempmsg=`$SMSDUPCHK  $dupkeypath $tempname  $normalpath`
		if [ $? -ne 0 ];then
			printALERT "批价 $tempname 文件失败"
			failcnt=`echo $failcnt+1 | bc`
			if [ $failcnt -gt 10 ]; then
				printALERT "批价文件失败太多,大于10,退出"
				exit 1;
			fi
			continue;
		fi
		#echo "	AAAAAAAAAAAAAAAAAAAAAA"
##进行文件备份和改名
		mv $normalpath/$filename.tmp  $normalpath/$filename
		[ $? -eq 0 ] || alertEXIT "mv $normalpath/$filename.tmp $normalpath/$filename 失败"

		#echo "BBBBBBBBBBBB"
		mv $tempname $backuppath/$filename
		[ $? -eq 0 ] || alertEXIT "mv $tempname $backuppath/$filename 失败"
		
		printNORMAL "成功处理文件$filename"
	done
done
delete_billing_ctl
if [ $? -ne 0 ]; then 
	printALERT "删除 $mypid	控制文件错误"
	exit 1;
fi
}
main
exit 0
