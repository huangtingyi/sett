#!/bin/sh
. $BILLHOME/shell/lib/libcomm.sh

find $APPHOME/ctl -mtime +1  | while read tmp
do
	new_name=`basename $tmp`
	if [ $new_name = "shedtsk.txt" ];then continue; fi

	rm $tmp

	printNORMAL "�ɹ���� $tmp �ļ�"
done
find $APPHOME/work -mtime +1 | while read tmp
do
	rm $tmp
	printNORMAL "�ɹ���� $tmp �ļ�"	
done

exit 0

