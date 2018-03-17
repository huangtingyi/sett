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

test -f $FILEBACKUPDATE || errorEXIT "�ļ� $FILEBACKUPDATE ������"
test -f $FILEMODIFYDATE || errorEXIT "�ļ� $FILEMODIFYDATE ������"
test -f $DATEDIFF || errorEXIT "�ļ� $DATEDIFF ������"
test -d $APPHOME/work || errorEXIT "�ļ� $APPHOME ������"
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
	
##����ļ��б�
	cat /dev/null >$FILENAMELIST
	
##��ȡ�ļ������б�
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
				
#������������ݵ����ڣ��򲻱���
		if [ $storedays -le 0 ]; then continue; fi
		if [ $storedays -le $distance ];then break; fi
		
		if [ ! -d $bkupdir/$filedate ];	then
			mkdir -p $bkupdir/$filedate 2>/dev/null
#�����Ŀ¼ʧ�����˳�
			if [ $? -ne 0 ]; then 
				printALERT "����Ŀ¼$bkupdir/$filedate����"
				break;
			fi
		fi
#�ֽ���Ϊ����ļ�ֻ�ƶ�һ��
		size1=`ls -l  "$filename" | awk '{printf $5}'`
		if [ $size1 -lt 50 ]; then 
			mv $filename $bkupdir/$filedate
			continue;
		fi
		
###�ж��Ƿ��Ѿ�ѹ�������ѹ������ֱ�ӱ��ݣ�������ѹ���˺󱸷�
		case $filename in
		*.gz|*.Z|*.tar*)
			mv $filename $bkupdir/$filedate
			if [ $? -ne 0 ];then
				printALERT "�ƶ��ļ�$filename��$bkupdir/$filedate����"
				exit 1
			fi
			;;
		*)
			compress $filename
			if [ $? -ne 0 ];then
				printALERT "ѹ���ļ� $filename ����"
				exit 1
			fi
			
			mv $filename.Z $bkupdir/$filedate
			if [ $? -ne 0 ];then
				printALERT "�ƶ��ļ� $filename.Z �� $bkupdir/$filedate ����"
				exit 1
			fi
			;;
		esac
		printNORMAL "�ɹ������ļ� $filename �� $bkupdir/$filedate Ŀ¼"
	done
done
delete_backup_ctl
if [ $? -ne 0 ]; then 
	printALERT "ɾ�� $FILENAMELIST	���ݵĿ����ļ�����"
	exit 1;
fi
}
main
exit 0

