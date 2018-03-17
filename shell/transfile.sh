#######################################################################################
##                          文件分离脚本 transfile.sh
##       
##transfile.ini 格式  
##组号   文件匹配  转换程序 原始数据路径   原始数据备份路径  分发路径
########################################################################################

#!/bin/sh
. $BILLHOME/shell/lib/libcomm.sh
if [ $# != 2 ]; then
	echo "Usage $0 transfile.ini procgrp"
	exit 1
fi
mypid=$$
TRANSFILEPARAM=$1
procgrp=$2
    


group=
filter=
transfile=
sourcepath=
backuppath=
targetpath=
filename=
temp=
ret=
failcnt=0
tempmsg=
tempname=

BINPATH=$BILLHOME/bin/
FILEMODIFYDIFF=$BILLHOME/bin/filemodifydiff

##检查基本调用是否存在

test -f $TRANSFILEPARAM || errorEXIT "文件 $TRANSFILEPARAM 不存在"
test -f $FILEMODIFYDIFF || errorEXIT "文件 $FILEMODIFYDIFF 不存在"

FILENAMELIST=$BILLHOME/work/tranname$mypid.lst
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
delete_trans_ctl()
{
	rm -f $FILENAMELIST; 2>/dev/null
}
main()
{
cat $TRANSFILEPARAM| sed s/#.*$// | while read temp
do
##去掉空行
	if [ X"$temp" = "X" ];then continue; fi
##获取基本参数
	group=`echo "$temp" | awk '{print $1}'`
	
	if [ $group != $procgrp ];then continue; fi

	filter=`echo "$temp" | awk '{print $2}' | sed s/\"//g`
	
	transfile="$BINPATH"/`echo "$temp" | awk '{print $3}'`
	sourcepath=`echo "$temp" | awk '{print $4}'`
	backuppath=`echo "$temp" | awk '{print $5}'`
	targetpath=`echo "$temp" | awk '{print $6}'`

##检查目录合法性如果不存在则退出
	test -f $transfile || alertEXIT "文件 $transfile 不存在"
	test -d $sourcepath || alertEXIT "路径 $sourcepath 不存在"
	test -d $backuppath || alertEXIT "路径 $backuppath 不存在"
	test -d $targetpath || alertEXIT "路径 $targetpath 不存在"

##清除处理文件列表
	cat /dev/null >$FILENAMELIST
##获取文件处理列表
        ls -rt $sourcepath/  >$FILENAMELIST

	cat $FILENAMELIST | grep -v Bad | while read filename 
	do
		filename=`get_file_name $filename`
		if  [ X"$filename" = "X" ];then continue; fi
		[ `$FILEMODIFYDIFF $sourcepath/$filename` -lt 60 ] && break;
		
##预处理指定文件
		tempname=$sourcepath/$filename.tmp
		mv  $sourcepath/$filename $tempname
		if [ $? -ne 0 ]; then
			printALERT "移动 $sourcepath/$filename $tempname 失败"
			exit 1;
		fi
		tempmsg=`$transfile $tempname $targetpath`
		if [ $? -ne 0 ];then
			printALERT "转换 $tempname 文件失败"
			failcnt=`echo $failcnt+1 | bc`
			if [ $failcnt -gt 10 ]; then
				printALERT "预处理文件失败太多,大于10,退出"
				exit 1;
			fi
			continue;
		fi
##进行文件备份
		mv $tempname $backuppath/$filename
		if [ $? -ne 0 ]; then
			printALERT "备份  $tempname $backuppath/$filename 失败"
			exit 1;
		fi
		printNORMAL "成功转换文件 $filename"
	done
done
delete_trans_ctl
if [ $? -ne 0 ]; then 
	printALERT "删除 $mypid	预处理的控制文件错误"
	exit 1;
fi
}
main
exit 0
