#!/bin/sh

. $BILLHOME/shell/lib/libcomm.sh

if [ $# != 2 ] ; then
	echo usage $0 remove.lst procgrp
	exit 1
fi

REMOVEPARAM=$1
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
filter=
storedays=

FILEBACKUPDATE=$BILLHOME/bin/filebackupdate
FILEMODIFYDATE=$BILLHOME/bin/filemodifydate
DATEDIFF=$BILLHOME/bin/datediff
FILENAMELIST=$BILLHOME/work/removefilename$mypid.lst

test -f $FILEBACKUPDATE || errorEXIT "�ļ� $FILEBACKUPDATE ������"
test -f $FILEMODIFYDATE || errorEXIT "�ļ� $FILEMODIFYDATE ������"
test -f $DATEDIFF || errorEXIT "�ļ� $DATEDIFF ������"
test -d $BILLHOME/work || errorEXIT "�ļ� $BILLHOME/work ������"

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
delete_remove_ctl()
{
	rm -f $FILENAMELIST; 2>/dev/null
}
main()
{
cat $REMOVEPARAM| sed s/#.*$// | while read temp 
do

	if [ X"$temp" = "X" ];then continue; fi
	
	group=`echo "$temp" | awk '{print $1}'`
	if [ $group != $procgrp ];then continue; fi
	
	dir=`echo $temp | awk '{print $2}'`
	filter=`echo $temp | awk '{print $3}' | sed s/\"//g`
	distance=`echo $temp | awk '{print $4}'`
	daterule=`echo $temp | awk '{print $5}'`
	
##����ļ��б�
	cat /dev/null >$FILENAMELIST
	
##��ȡ�ļ������б�
	sourcepath=$dir
        ls -rt $sourcepath/  >$FILENAMELIST
        
	cat $FILENAMELIST | grep -v Bad | while read filename 
	do
		filename=`get_file_name $filename`
		if [ "X$filename" = "X" ]; then break; fi
		
		filename="$sourcepath"/"$filename"
		
		filedate=`$FILEBACKUPDATE $daterule $filename`
						
		if [ "X$filedate" = "X" ];then
			filedate=`$FILEMODIFYDATE $filename`
		fi
		hostdate=`date +%Y%m%d`
		
		storedays=`$DATEDIFF $hostdate $filedate`
				
#������������ݵ����ڣ��򲻱���
		if [ $storedays -le $distance ];then break; fi
		
		rm -f "$filename"
		if [ $? -ne 0 ];then
			printALERT "ɾ���ļ�$filename ʧ��"
			exit 1
		fi
		printNORMAL "�ɹ�ɾ���ļ� $filename"
	done
done
delete_remove_ctl
if [ $? -ne 0 ]; then 
	printALERT "ɾ�� $FILENAMELIST ɾ���Ŀ����ļ�����"
	exit 1;
fi
}
main
exit 0

