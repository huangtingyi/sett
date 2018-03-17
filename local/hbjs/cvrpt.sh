#!/bin/sh

. $BILLHOME/shell/lib/libcomm.sh
if [ $# != 5 ]; then
	echo "Usage $0 xlsname type reportid settcycle userid"
	exit 1
fi
xlsname=$1
type=$2
reportid=$3
settcycle=$4
userid=$5

txtname="$xlsname".txt
datname="$xlsname".dat
javaname="readxls.java"
cvrptname="/home/bill/usr/rpt/cvrpt"

test -f $xlsname || errorEXIT "�ļ� $xlsname ������"
#test -f $javaname || errorEXIT "�ļ� $javaname ������"
test -f $cvrptname || errorEXIT "�ļ� $cvrptname ������"

msg=
ctlname=
tablename=

#msg=`javac $javaname`

#if [ $? -ne 0 ];then
#	printALERT "���� $javaname �ļ����� ��Ϣ:$msg"
#	exit 1;
#fi

cd /home/bill/usr/rpt

msg=`java readxls $xlsname $txtname`

if [ $? -ne 0 ];then
	printALERT "ִ�� java readxls $xlsname $txtname ���� ��Ϣ:$msg"
	exit 1;
fi

msg=`$cvrptname $txtname $type $reportid $settcycle $datname`

if [ $? -ne 0 ];then
	printALERT "ִ�� $cvrptname $txtname $type $reportid $settcycle $datname ���� ��Ϣ:$msg"
	exit 1;
fi

case $type in
CT)
	ctlname=settct.ctl
	tablename="SETT_ITEM_CT"
	;;
CM)
	ctlname=settcm.ctl
	tablename="SETT_ITEM_CM"
	;;
CU)
	ctlname=settcu.ctl
	tablename="SETT_ITEM_CU"
	;;
CRC)
	ctlname=settcrc.ctl
	tablename="SETT_ITEM_CRC"
	;;
CS)
	ctlname=settcs.ctl
	tablename="SETT_ITEM_CS"
	;;
CMSMS)
	ctlname=settcmsms.ctl
	tablename="SETT_ITEM_CMSMS"
	;;
CUSMS)
	ctlname=settcusms.ctl
	tablename="SETT_ITEM_CUSMS"
	;;
*)
	printALERT "���ͷǷ� type must in(CT,CM,CU,CRC,CS,CMSMS,CUSMS) "
	exit 1;
	;;
esac

msg=`sqlldr userid=$userid control=$ctlname data=$datname`

if [ $? -ne 0 ];then
	printALERT "ִ�� sqlldr userid=param/cal control=$ctlname data=$datname ���� ��Ϣ:$msg"
	exit 1;
fi

echo "�ļ� $xlsname ���ݳɹ����ص����ݱ� $tablename" ��

exit 0
