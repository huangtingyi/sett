#######################################################################################
##                          �ļ�����ű� transfile.sh
##       
##transfile.ini ��ʽ  
##���   �ļ�ƥ��  ת������ ԭʼ����·��   ԭʼ���ݱ���·��  �ַ�·��
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

##�����������Ƿ����

test -f $TRANSFILEPARAM || errorEXIT "�ļ� $TRANSFILEPARAM ������"
test -f $FILEMODIFYDIFF || errorEXIT "�ļ� $FILEMODIFYDIFF ������"

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
##ȥ������
	if [ X"$temp" = "X" ];then continue; fi
##��ȡ��������
	group=`echo "$temp" | awk '{print $1}'`
	
	if [ $group != $procgrp ];then continue; fi

	filter=`echo "$temp" | awk '{print $2}' | sed s/\"//g`
	
	transfile="$BINPATH"/`echo "$temp" | awk '{print $3}'`
	sourcepath=`echo "$temp" | awk '{print $4}'`
	backuppath=`echo "$temp" | awk '{print $5}'`
	targetpath=`echo "$temp" | awk '{print $6}'`

##���Ŀ¼�Ϸ���������������˳�
	test -f $transfile || alertEXIT "�ļ� $transfile ������"
	test -d $sourcepath || alertEXIT "·�� $sourcepath ������"
	test -d $backuppath || alertEXIT "·�� $backuppath ������"
	test -d $targetpath || alertEXIT "·�� $targetpath ������"

##��������ļ��б�
	cat /dev/null >$FILENAMELIST
##��ȡ�ļ������б�
        ls -rt $sourcepath/  >$FILENAMELIST

	cat $FILENAMELIST | grep -v Bad | while read filename 
	do
		filename=`get_file_name $filename`
		if  [ X"$filename" = "X" ];then continue; fi
		[ `$FILEMODIFYDIFF $sourcepath/$filename` -lt 60 ] && break;
		
##Ԥ����ָ���ļ�
		tempname=$sourcepath/$filename.tmp
		mv  $sourcepath/$filename $tempname
		if [ $? -ne 0 ]; then
			printALERT "�ƶ� $sourcepath/$filename $tempname ʧ��"
			exit 1;
		fi
		tempmsg=`$transfile $tempname $targetpath`
		if [ $? -ne 0 ];then
			printALERT "ת�� $tempname �ļ�ʧ��"
			failcnt=`echo $failcnt+1 | bc`
			if [ $failcnt -gt 10 ]; then
				printALERT "Ԥ�����ļ�ʧ��̫��,����10,�˳�"
				exit 1;
			fi
			continue;
		fi
##�����ļ�����
		mv $tempname $backuppath/$filename
		if [ $? -ne 0 ]; then
			printALERT "����  $tempname $backuppath/$filename ʧ��"
			exit 1;
		fi
		printNORMAL "�ɹ�ת���ļ� $filename"
	done
done
delete_trans_ctl
if [ $? -ne 0 ]; then 
	printALERT "ɾ�� $mypid	Ԥ����Ŀ����ļ�����"
	exit 1;
fi
}
main
exit 0
