#!/bin/sh
. $BILLHOME/shell/lib/libcomm.sh

if [ $# != 3 ]; then
	echo "Usage $0 param procgrp message"
	exit 1
fi

PARAM=$1
procgrp=$2
msg=$3
phone=

main()
{
	cat $PARAM| sed s/#.*$// | while read temp
	do
		##ȥ������
			if [ X"$temp" = "X" ];then continue; fi	
		##�ж��Ƿ��Ǳ����̴���
			group=`echo "$temp" | awk '{print $1}'`
			if [ $group != $procgrp ];then continue; fi
		##���Ͷ���
			phone=`echo "$temp" | awk '{print $2}'`
			$BILLHOME/bin/sendmsg $phone "$msg"	
	done
}
main
exit 0	
