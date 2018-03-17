#!/bin/sh

. $BILLHOME/shell/lib/libcomm.sh

if [ $# != 2 ] ; then
	echo usage $0 remove.lst procgrp
	exit 1
fi

TARDIRPARAM=$1
procgrp=$2
group=
mypid=$$
temp=
dir=
sourcepath=
bkupdir=
filename=
count=
filedate=
hostdate=
storedays=
targetname=
prefix=
tempdate=
tempname=

DATEDIFF=$BILLHOME/bin/datediff
FILEMODIFYDATE=$BILLHOME/bin/filemodifydate
FILENAMELIST=$APPHOME/work/tardirfilename$mypid.lst

test -f $DATEDIFF || errorEXIT "�ļ� $DATEDIFF ������"
test -f $FILEMODIFYDATE || errorEXIT "�ļ� $FILEMODIFYDATE ������"
test -d $APPHOME/work || errorEXIT "�ļ� $APPHOME/work ������"


delete_tardir_ctl()
{
	rm -f $FILENAMELIST; 2>/dev/null
}
main()
{
cat $TARDIRPARAM| sed s/#.*$// | while read temp 
do

	if [ X"$temp" = "X" ];then continue; fi
	
	group=`echo "$temp" | awk '{print $1}'`
	if [ $group != $procgrp ];then continue; fi
	
	dir=`echo $temp | awk '{print $2}'`
	distance=`echo $temp | awk '{print $3}'`
	bkupdir=`echo $temp | awk '{print $4}'`
	suppfix=`echo $temp | awk '{print $5}'`
	
	test -d $dir ||continue;
	if [ ! -d $bkupdir ]; then
		mkdir -p $bkupdir 2>/dev/null
#�����Ŀ¼ʧ�����˳�
		if [ $? -ne 0 ]; then 
			printALERT "����Ŀ¼ $bkupdir ����"
			exit 1;
		fi
	fi
	
##����ļ��б�
	cat /dev/null >$FILENAMELIST
	
##��ȡ�ļ������б�
	sourcepath=$dir
        ls -rt $sourcepath/  >$FILENAMELIST
        
	cat $FILENAMELIST | grep -v Bad | while read filename 
	do
		prefix=`basename $sourcepath`
		targetname="$prefix""$filename"."$suppfix".tar
		
		filedate="$filename"
		hostdate=`date +%Y%m%d`

		storedays=`$DATEDIFF $hostdate $filedate`
##���$filename����һ���Ϸ��������򲻴���
		if [ $? -ne 0 ];then continue; fi
			
#������������ݵ����ڣ��򲻱���
		if [ $storedays -le $distance ];then break; fi

		cd $sourcepath || errorEXIT "����Ŀ¼ $sourcepath ʧ��"

		tar cvf $targetname $filename >/dev/null

		if [ $? -ne 0 ];then
			printALERT "ִ������ tar cvf $targetname $filename ʧ��"
			exit 1;
		fi
		tempname="$bkupdir"/"$targetname"
		
		if [ -f $tempname ]; then
			tempdate=`$FILEMODIFYDATE $tempname`
			mv $tempname $tempname.$tempdate || errorEXIT " mv $tempname $tempname.$tempdate ʧ�� "	
		fi
		mv $targetname $bkupdir || errorEXIT " mv $targetname $bkupdir ʧ�� "
		
		rm -rf "$filename" || errorEXIT "ɾ��Ŀ¼ $filename ʧ��"
		
		printNORMAL "�ɹ����Ŀ¼  $sourcepath/$filename �� $bkupdir"
	done
done
delete_tardir_ctl
if [ $? -ne 0 ]; then 
	printALERT "ɾ�� $FILENAMELIST ����Ŀ����ļ�����"
	exit 1;
fi
}
main
exit 0

