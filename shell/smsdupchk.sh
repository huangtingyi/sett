#!/bin/sh
. $BILLHOME/shell/lib/libcomm.sh
if [ $# != 2 ]; then
	echo "Usage $0 smsdupchkparam procgrp"
	exit 1
fi
mypid=$$
RATEPARAM=$1
procgrp=$2

group=
source=
filter=
sourcepath=
backuppath=
normalpath=
dupkeypath=
filename=
temp=
byte=
ret=
datadate=
dealbegindate=
dealenddate=
tempname=
targettemp=
failcnt=0
failcnt1=0
tempmsg=
delay=
handlecnt=
cnt=
errcnt=
abnocnt=
billingname=
templateid=
splitstr=
tempstr=
visitcode=
exprfile=
l1=
i=

SMSDUPCHK=$BILLHOME/bin/smsdupchk
FILEMODIFYDIFF=$BILLHOME/bin/filemodifydiff
FILENAMELIST=$APPHOME/work/smsdupchkfilename$mypid.lst

##�����������Ƿ����

test -f $RATEPARAM || errorEXIT "�ļ� $RATEPARAM ������"
test -f $SMSDUPCHK || errorEXIT "�ļ� $SMSDUPCHK ������"
test -f $FILEMODIFYDIFF || errorEXIT "�ļ� $FILEMODIFYDIFF ������"
test -d $APPHOME/work || errorEXIT "�ļ� $APPHOME/work ������"

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
delete_billing_ctl()
{
	rm -f $FILENAMELIST; 2>/dev/null
}
main()
{
cat $RATEPARAM| sed s/#.*$// | while read temp
do
#echo "$temp"
##ȥ������
	if [ X"$temp" = "X" ];then continue; fi
##��ȡ��������
	group=`echo "$temp" | awk '{print $1}'`
	
	if [ $group != $procgrp ];then continue; fi

	source=`echo "$temp" | awk '{print $2}'`
	filter=`echo "$temp" | awk '{print $3}' | sed s/\"//g`
	sourcepath=`echo "$temp" | awk '{print $4}'`
	backuppath=`echo "$temp" | awk '{print $5}'`
	normalpath=`echo "$temp" | awk '{print $6}'`
	dupkeypath=`echo "$temp" | awk '{print $7}'`

##���Ŀ¼�Ϸ���������������˳�
	test -d $sourcepath || alertEXIT "·�� $sourcepath ������"
	test -d $backuppath || alertEXIT "·�� $backuppath ������"
	test -d $normalpath || alertEXIT "·�� $normalpath ������"
	test -d $dupkeypath || alertEXIT "·�� $dupkeypath ������"
	
##��������ļ��б�
	cat /dev/null >$FILENAMELIST
##��ȡ�ļ������б�
        ls -rt $sourcepath/  >$FILENAMELIST

	cat $FILENAMELIST | grep -v Bad | while read filename 
	do
		filename=`get_file_name $filename`
		if  [ X"$filename" = "X" ];then continue; fi
		[ `$FILEMODIFYDIFF $sourcepath/$filename` -lt 60 ] && break;
		
		
		size=`ls -l $sourcepath/$filename | awk '{print $5}'`
		
##ָ���ļ�
		tempname=$sourcepath/$filename.tmp
		mv $sourcepath/$filename $tempname
		if [ $? -ne 0 ]; then
			printALERT "�ƶ� $sourcepath/$filename $tempname ʧ��"
			exit 1;
		fi
		tempmsg=`$SMSDUPCHK  $dupkeypath $tempname  $normalpath`
		if [ $? -ne 0 ];then
			printALERT "���� $tempname �ļ�ʧ��"
			failcnt=`echo $failcnt+1 | bc`
			if [ $failcnt -gt 10 ]; then
				printALERT "�����ļ�ʧ��̫��,����10,�˳�"
				exit 1;
			fi
			continue;
		fi
		#echo "	AAAAAAAAAAAAAAAAAAAAAA"
##�����ļ����ݺ͸���
		mv $normalpath/$filename.tmp  $normalpath/$filename
		[ $? -eq 0 ] || alertEXIT "mv $normalpath/$filename.tmp $normalpath/$filename ʧ��"

		#echo "BBBBBBBBBBBB"
		mv $tempname $backuppath/$filename
		[ $? -eq 0 ] || alertEXIT "mv $tempname $backuppath/$filename ʧ��"
		
		printNORMAL "�ɹ������ļ�$filename"
	done
done
delete_billing_ctl
if [ $? -ne 0 ]; then 
	printALERT "ɾ�� $mypid	�����ļ�����"
	exit 1;
fi
}
main
exit 0
