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

test -f $xlsname || errorEXIT "文件 $xlsname 不存在"
#test -f $javaname || errorEXIT "文件 $javaname 不存在"
test -f $cvrptname || errorEXIT "文件 $cvrptname 不存在"

msg=
ctlname=
tablename=

#msg=`javac $javaname`

#if [ $? -ne 0 ];then
#	printALERT "编译 $javaname 文件出错 信息:$msg"
#	exit 1;
#fi

cd /home/bill/usr/rpt

msg=`java readxls $xlsname $txtname`

if [ $? -ne 0 ];then
	printALERT "执行 java readxls $xlsname $txtname 出错 信息:$msg"
	exit 1;
fi

msg=`$cvrptname $txtname $type $reportid $settcycle $datname`

if [ $? -ne 0 ];then
	printALERT "执行 $cvrptname $txtname $type $reportid $settcycle $datname 出错 信息:$msg"
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
	printALERT "类型非法 type must in(CT,CM,CU,CRC,CS,CMSMS,CUSMS) "
	exit 1;
	;;
esac

msg=`sqlldr userid=$userid control=$ctlname data=$datname`

if [ $? -ne 0 ];then
	printALERT "执行 sqlldr userid=param/cal control=$ctlname data=$datname 出错 信息:$msg"
	exit 1;
fi

echo "文件 $xlsname 数据成功加载到数据表 $tablename" 中

exit 0
