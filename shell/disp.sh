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

##�����������Ƿ����
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
#printALERT "����prep.sh";
##ȥ������
	if [ X"$temp" = "X" ];then continue; fi
	
	group=`echo "$temp" | awk '{print $1}'`
	if [ $group != $procgrp ];then continue; fi
	
	sourcepath=`echo "$temp" | awk '{print $2}'`
	filter=`echo "$temp" | awk '{print $3}' | sed s/\"//g`
	targetpath1=`echo "$temp" | awk '{print $4}'`
	targetpath2=`echo "$temp" | awk '{print $5}'`
	targetpath3=`echo "$temp" | awk '{print $6}'`
	targetpath4=`echo "$temp" | awk '{print $7}'`

##���Ŀ¼�Ϸ���������������˳�
	test -d $sourcepath || alertEXIT "·�� $sourcepath ������"
	

##���Ԥ�����ļ��б�
	cat /dev/null >$FILENAMELIST
##��ȡ�ļ������б�
        ls -lrt $sourcepath/  >$FILENAMELIST
##echo "this is one"
	cat $FILENAMELIST | grep -v Bad | while read filename 
	do
		filename=`get_file_name $filename`
		if  [ X"$filename" = "X" ];then continue; fi
		[ `$FILEMODIFYDIFF $sourcepath/$filename` -lt $second ] && break;
		
##�����ļ����ݺ͸���
##echo "this is two $filename $sourcepath"

		if [ -d $targetpath1 ]; then
			cp $sourcepath/$filename $targetpath1/
			[ $? -eq 0 ] || alertEXIT "cp $sourcepath/$filename $targetpath1 ʧ��"
		fi
		if [ -d $targetpath2 ]; then
			cp $sourcepath/$filename $targetpath2/
			[ $? -eq 0 ] || alertEXIT "cp $sourcepath/$filename $targetpath2 ʧ��"
		fi
		if [ -d $targetpath3 ]; then
			cp $sourcepath/$filename $targetpath3/
			[ $? -eq 0 ] || alertEXIT "cp $sourcepath/$filename $targetpath3 ʧ��"
		fi
		if [ -d $targetpath4 ]; then
			cp $sourcepath/$filename $targetpath4/
			[ $? -eq 0 ] || alertEXIT "cp $sourcepath/$filename $targetpath4 ʧ��"
		fi
		rm -f $sourcepath/$filename
		[ $? -eq 0 ] || alertEXIT "rm -f $sourcepath/$filename ʧ��"
		printNORMAL "�ɹ��ƶ��ļ� $filename �� $sourcepath"
	done
done
delete_prep_ctl
if [ $? -ne 0 ]; then 
	printALERT "ɾ�� $mypid	Ԥ����Ŀ����ļ�����"
	exit 1;
fi
}
main
exit 0
