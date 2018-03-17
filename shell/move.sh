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

##�����������Ƿ����
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
#printALERT "����prep.sh";
##ȥ������
	if [ X"$temp" = "X" ];then continue; fi

	sourcepath=`echo "$temp" | awk '{print $1}'`
	targetpath=`echo "$temp" | awk '{print $2}'`
	filter=`echo "$temp" | awk '{print $3}' | sed s/\"//g`

##���Ŀ¼�Ϸ���������������˳�
	test -d $sourcepath || alertEXIT "·�� $sourcepath ������"
	test -d $targetpath || alertEXIT "·�� $targetpath ������"

##���Ԥ�����ļ��б�
	cat /dev/null >$FILENAMELIST
##��ȡ�ļ������б�
        ls -rt $sourcepath/  >$FILENAMELIST

	cat $FILENAMELIST | grep -v Bad | while read filename 
	do
		filename=`get_file_name $filename`
		if  [ X"$filename" = "X" ];then continue; fi
		[ `$FILEMODIFYDIFF $sourcepath/$filename` -lt $second ] && break;
		
##�����ļ����ݺ͸���
		mv $sourcepath/$filename $targetpath/$filename
		[ $? -eq 0 ] || alertEXIT "mv $sourcepath/$filename $targetpath/$filenameʧ��"

		printNORMAL "�ɹ��ƶ��ļ� $filename �� $sourcepath �� $targetpath"
	done
done
delete_move_ctl
if [ $? -ne 0 ]; then 
	printALERT "ɾ�� $mypid �����ƶ��Ŀ����ļ�����"
	exit 1;
fi
}
main
exit 0
