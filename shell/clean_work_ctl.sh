#!/bin/sh
. $BILLHOME/shell/lib/libcomm.sh

find $APPHOME/ctl -mtime +1  | while read tmp
do
	new_name=`basename $tmp`
	if [ $new_name = "shedtsk.txt" ];then continue; fi

	rm $tmp

	printNORMAL "成功清除 $tmp 文件"
done
find $APPHOME/work -mtime +1 | while read tmp
do
	rm $tmp
	printNORMAL "成功清除 $tmp 文件"	
done

exit 0

