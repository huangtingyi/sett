#!/bin/sh

. $BILLHOME/shell/lib/libcomm.sh

if [ $# != 2 ] ; then
	echo usage $0 backup.lst procgrp
	exit 1
fi

BACKUPPARAM=$1
procgrp=$2
group=
mypid=$$
temp=
dir=
sourcepath=
limit=
daterule=
filename=
count=
filedate=
hostdate=
bkupdir=
filter=
storedays=

FILEBACKUPDATE=$BILLHOME/bin/filebackupdate
FILEMODIFYDATE=$BILLHOME/bin/filemodifydate
DATEDIFF=$BILLHOME/bin/datediff
FILENAMELIST=$APPHOME/work/backupfilename$mypid.lst

test -f $FILEBACKUPDATE || errorEXIT "文件 $FILEBACKUPDATE 不存在"
test -f $FILEMODIFYDATE || errorEXIT "文件 $FILEMODIFYDATE 不存在"
test -f $DATEDIFF || errorEXIT "文件 $DATEDIFF 不存在"
test -d $APPHOME/work || errorEXIT "文件 $APPHOME 不存在"
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
delete_backup_ctl()
{
	rm -f $FILENAMELIST; 2>/dev/null
}
main()
{
cat $BACKUPPARAM| sed s/#.*$// | while read temp 
do

	if [ X"$temp" = "X" ];then continue; fi
	
	group=`echo "$temp" | awk '{print $1}'`
	if [ $group != $procgrp ];then continue; fi
	
	dir=`echo $temp | awk '{print $2}'`
	filter=`echo $temp | awk '{print $3}' | sed s/\"//g`
	distance=`echo $temp | awk '{print $4}'`
	daterule=`echo $temp | awk '{print $5}'`
	bkupdir=`echo $temp | awk '{print $6}'`
	
##清除文件列表
	cat /dev/null >$FILENAMELIST
	
##获取文件处理列表
	sourcepath=$dir
        ls -rt $sourcepath/  >$FILENAMELIST
        
	cat $FILENAMELIST | grep -v Bad | while read filename 
	do
		filename=`get_file_name $filename`
		if [ "X$filename" = "X" ]; then continue; fi
		
		filename="$sourcepath"/"$filename"
		
		filedate=`$FILEBACKUPDATE $daterule $filename`
						
		if [ "X$filedate" = "X" ];then
			filedate=`$FILEMODIFYDATE $filename`
		fi
		hostdate=`date +%Y%m%d`
		
		storedays=`$DATEDIFF $hostdate $filedate`
				
#如果不超过备份的日期，则不备份
		if [ $storedays -le 0 ]; then continue; fi
		if [ $storedays -le $distance ];then break; fi
		
		if [ ! -d $bkupdir/$filedate ];	then
			mkdir -p $bkupdir/$filedate 2>/dev/null
#如果建目录失败则退出
			if [ $? -ne 0 ]; then 
				printALERT "建立目录$bkupdir/$filedate错误"
				break;
			fi
		fi
#字节数为零的文件只移动一下
		size1=`ls -l  "$filename" | awk '{printf $5}'`
		if [ $size1 -lt 50 ]; then 
			mv $filename $bkupdir/$filedate
			continue;
		fi
		
###判断是否已经压缩，如果压缩了则直接备份，否则则压缩了后备份
		case $filename in
		*.gz|*.Z|*.tar*)
			mv $filename $bkupdir/$filedate
			if [ $? -ne 0 ];then
				printALERT "移动文件$filename到$bkupdir/$filedate错误"
				exit 1
			fi
			;;
		*)
			compress $filename
			if [ $? -ne 0 ];then
				printALERT "压缩文件 $filename 错误"
				exit 1
			fi
			
			mv $filename.Z $bkupdir/$filedate
			if [ $? -ne 0 ];then
				printALERT "移动文件 $filename.Z 到 $bkupdir/$filedate 错误"
				exit 1
			fi
			;;
		esac
		printNORMAL "成功备份文件 $filename 到 $bkupdir/$filedate 目录"
	done
done
delete_backup_ctl
if [ $? -ne 0 ]; then 
	printALERT "删除 $FILENAMELIST	备份的控制文件错误"
	exit 1;
fi
}
main
exit 0

