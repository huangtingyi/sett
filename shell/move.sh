#!/bin/sh
. $BILLHOME/shell/lib/libcomm.sh
if [ $# != 2 ]; then
	echo "Usage $0 move.ini second"
	exit 1
fi
mypid=$$
MOVEPARAM=$1
second=$2

sourcepath=
targetpath=
filter=
filename=

FILEMODIFYDIFF=$BILLHOME/bin/filemodifydiff

##检查基本调用是否存在
FILENAMELIST=$BILLHOME/work/movefilename$mypid.lst
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
delete_move_ctl()
{
	rm -f $FILENAMELIST; 2>/dev/null
}
main()
{
cat $MOVEPARAM| sed s/#.*$// | while read temp
do
#printALERT "调用prep.sh";
##去掉空行
	if [ X"$temp" = "X" ];then continue; fi

	sourcepath=`echo "$temp" | awk '{print $1}'`
	targetpath=`echo "$temp" | awk '{print $2}'`
	filter=`echo "$temp" | awk '{print $3}' | sed s/\"//g`

##检查目录合法性如果不存在则退出
	test -d $sourcepath || alertEXIT "路径 $sourcepath 不存在"
	test -d $targetpath || alertEXIT "路径 $targetpath 不存在"

##清除预处理文件列表
	cat /dev/null >$FILENAMELIST
##获取文件处理列表
        ls -rt $sourcepath/  >$FILENAMELIST

	cat $FILENAMELIST | grep -v Bad | while read filename 
	do
		filename=`get_file_name $filename`
		if  [ X"$filename" = "X" ];then continue; fi
		[ `$FILEMODIFYDIFF $sourcepath/$filename` -lt $second ] && break;
		
##进行文件备份和改名
		mv $sourcepath/$filename $targetpath/$filename
		[ $? -eq 0 ] || alertEXIT "mv $sourcepath/$filename $targetpath/$filename失败"

		printNORMAL "成功移动文件 $filename 从 $sourcepath 到 $targetpath"
	done
done
delete_move_ctl
if [ $? -ne 0 ]; then 
	printALERT "删除 $mypid 数据移动的控制文件错误"
	exit 1;
fi
}
main
exit 0
