#!/bin/sh

. $BILLHOME/shell/lib/libcomm.sh

if [ $# != 2 ] ; then
	echo usage $0 remove.lst procgrp
	exit 1
fi

TARDIRPARAM=$1
procgrp=$2
group=
mypid=$$
temp=
dir=
sourcepath=
bkupdir=
filename=
count=
filedate=
hostdate=
storedays=
targetname=
prefix=
tempdate=
tempname=

DATEDIFF=$BILLHOME/bin/datediff
FILEMODIFYDATE=$BILLHOME/bin/filemodifydate
FILENAMELIST=$APPHOME/work/tardirfilename$mypid.lst

test -f $DATEDIFF || errorEXIT "文件 $DATEDIFF 不存在"
test -f $FILEMODIFYDATE || errorEXIT "文件 $FILEMODIFYDATE 不存在"
test -d $APPHOME/work || errorEXIT "文件 $APPHOME/work 不存在"


delete_tardir_ctl()
{
	rm -f $FILENAMELIST; 2>/dev/null
}
main()
{
cat $TARDIRPARAM| sed s/#.*$// | while read temp 
do

	if [ X"$temp" = "X" ];then continue; fi
	
	group=`echo "$temp" | awk '{print $1}'`
	if [ $group != $procgrp ];then continue; fi
	
	dir=`echo $temp | awk '{print $2}'`
	distance=`echo $temp | awk '{print $3}'`
	bkupdir=`echo $temp | awk '{print $4}'`
	suppfix=`echo $temp | awk '{print $5}'`
	
	test -d $dir ||continue;
	if [ ! -d $bkupdir ]; then
		mkdir -p $bkupdir 2>/dev/null
#如果建目录失败则退出
		if [ $? -ne 0 ]; then 
			printALERT "建立目录 $bkupdir 错误"
			exit 1;
		fi
	fi
	
##清除文件列表
	cat /dev/null >$FILENAMELIST
	
##获取文件处理列表
	sourcepath=$dir
        ls -rt $sourcepath/  >$FILENAMELIST
        
	cat $FILENAMELIST | grep -v Bad | while read filename 
	do
		prefix=`basename $sourcepath`
		targetname="$prefix""$filename"."$suppfix".tar
		
		filedate="$filename"
		hostdate=`date +%Y%m%d`

		storedays=`$DATEDIFF $hostdate $filedate`
##如果$filename不是一个合法的日期则不处理
		if [ $? -ne 0 ];then continue; fi
			
#如果不超过备份的日期，则不备份
		if [ $storedays -le $distance ];then break; fi

		cd $sourcepath || errorEXIT "进入目录 $sourcepath 失败"

		tar cvf $targetname $filename >/dev/null

		if [ $? -ne 0 ];then
			printALERT "执行命令 tar cvf $targetname $filename 失败"
			exit 1;
		fi
		tempname="$bkupdir"/"$targetname"
		
		if [ -f $tempname ]; then
			tempdate=`$FILEMODIFYDATE $tempname`
			mv $tempname $tempname.$tempdate || errorEXIT " mv $tempname $tempname.$tempdate 失败 "	
		fi
		mv $targetname $bkupdir || errorEXIT " mv $targetname $bkupdir 失败 "
		
		rm -rf "$filename" || errorEXIT "删除目录 $filename 失败"
		
		printNORMAL "成功打包目录  $sourcepath/$filename 到 $bkupdir"
	done
done
delete_tardir_ctl
if [ $? -ne 0 ]; then 
	printALERT "删除 $FILENAMELIST 打包的控制文件错误"
	exit 1;
fi
}
main
exit 0

