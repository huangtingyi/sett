#!/bin/sh

. $BILLHOME/shell/lib/libcomm.sh

if [ $# != 2 ] ; then
	echo usage $0 ceildir.lst procgrp
	exit 1
fi
CEILPARAM=$1
procgrp=$2
mypid=$$
sourcepath=
filter=
count=
group=
curcnt=
filename=
FILENAMELIST=$BILLHOME/work/ceildirfilename$mypid.lst
test -d $BILLHOME/work || errorEXIT "文件 $BILLHOME/work 不存在"


count_file()
{
	i=0
	
	cat $FILENAMELIST | grep -v Bad | while read temp 
	do
		case $temp in
		$filter)
			i=`echo $i + 1 | bc`
		;;
		*)
		;;
		esae
	done
	echo $i
}
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
delete_ceildir_ctl()
{
	rm -f $FILENAMELIST; 2>/dev/null
}
main()
{
cat $CEILPARAM | while read temp 
do
	if [ "X$temp" = "X" ]; then continue; fi
	
	group=`echo "$temp" | awk '{print $1}'`
	if [ $group != $procgrp ];then continue; fi
	
	sourcepath=`echo "$temp" | awk '{print $2}'`
	filter=`echo "$temp" | awk '{print $3}' | sed s/\"//g`
	count=`echo "$temp" | awk '{print $4}'`
	
##清除文件列表
	cat /dev/null >$FILENAMELIST
	
##获取文件处理列表
        ls -rt $sourcepath/  >$FILENAMELIST
        
        curcnt=`count_file`
        
        if [ $count -le $curcnt ];then continue; fi
        
	cat $FILENAMELIST | grep -v Bad | while read filename 
	do
		filename=`get_file_name $filename`
		if [ "X$filename" = "X" ]; then break; fi
		
		filename="$sourcepath"/"$filename"
					
		echo "curcnt=$curcnt count=$count filter=$filter"

		rm -f $filename 2>/dev/null
		if [ $? -ne 0 ]; then
			printALERT "删除文件$filename失败"
		fi
		printNORMAL "删除文件$filename"
		
		curcnt=`echo $curcnt - 1 | bc`
		if [ $curcnt -le $count ]; then break; fi
	done
done
delete_ceildir_ctl
if [ $? -ne 0 ]; then 
	printALERT "删除 $mypid	备份的控制文件错误"
	exit 1;
fi
}
main
exit 0
