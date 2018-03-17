#!/bin/sh
. $BILLHOME/shell/lib/libcomm.sh
if [ $# != 3 ]; then
	echo "Usage $0 disp.ini second procgrp"
	exit 1
fi
mypid=$$
DISPPARAM=$1
second=$2
procgrp=$3

group=
sourcepath=
targetpath1=
targetpath2=
targetpath3=
targetpath4=
filter=
filename=

FILEMODIFYDIFF=$BILLHOME/bin/filemodifydiff

##检查基本调用是否存在
FILENAMELIST=$APPHOME/work/prepfilename$mypid.lst
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
delete_prep_ctl()
{
	rm -f $FILENAMELIST; 2>/dev/null
}
main()
{
cat $DISPPARAM| sed s/#.*$// | while read temp
do
#printALERT "调用prep.sh";
##去掉空行
	if [ X"$temp" = "X" ];then continue; fi
	
	group=`echo "$temp" | awk '{print $1}'`
	if [ $group != $procgrp ];then continue; fi
	
	sourcepath=`echo "$temp" | awk '{print $2}'`
	filter=`echo "$temp" | awk '{print $3}' | sed s/\"//g`
	targetpath1=`echo "$temp" | awk '{print $4}'`
	targetpath2=`echo "$temp" | awk '{print $5}'`
	targetpath3=`echo "$temp" | awk '{print $6}'`
	targetpath4=`echo "$temp" | awk '{print $7}'`

##检查目录合法性如果不存在则退出
	test -d $sourcepath || alertEXIT "路径 $sourcepath 不存在"
	

##清除预处理文件列表
	cat /dev/null >$FILENAMELIST
##获取文件处理列表
        ls -lrt $sourcepath/  >$FILENAMELIST
##echo "this is one"
	cat $FILENAMELIST | grep -v Bad | while read filename 
	do
		filename=`get_file_name $filename`
		if  [ X"$filename" = "X" ];then continue; fi
		[ `$FILEMODIFYDIFF $sourcepath/$filename` -lt $second ] && break;
		
##进行文件备份和改名
##echo "this is two $filename $sourcepath"

		if [ -d $targetpath1 ]; then
			cp $sourcepath/$filename $targetpath1/
			[ $? -eq 0 ] || alertEXIT "cp $sourcepath/$filename $targetpath1 失败"
		fi
		if [ -d $targetpath2 ]; then
			cp $sourcepath/$filename $targetpath2/
			[ $? -eq 0 ] || alertEXIT "cp $sourcepath/$filename $targetpath2 失败"
		fi
		if [ -d $targetpath3 ]; then
			cp $sourcepath/$filename $targetpath3/
			[ $? -eq 0 ] || alertEXIT "cp $sourcepath/$filename $targetpath3 失败"
		fi
		if [ -d $targetpath4 ]; then
			cp $sourcepath/$filename $targetpath4/
			[ $? -eq 0 ] || alertEXIT "cp $sourcepath/$filename $targetpath4 失败"
		fi
		rm -f $sourcepath/$filename
		[ $? -eq 0 ] || alertEXIT "rm -f $sourcepath/$filename 失败"
		printNORMAL "成功移动文件 $filename 从 $sourcepath"
	done
done
delete_prep_ctl
if [ $? -ne 0 ]; then 
	printALERT "删除 $mypid	预处理的控制文件错误"
	exit 1;
fi
}
main
exit 0
