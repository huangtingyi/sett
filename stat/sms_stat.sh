#!/bin/sh
. $BILLHOME/shell/lib/libcomm.sh
case $# in
	1|2)
	;;
	*)
	echo "Usage $0 stype [YYYYMM]"
	exit 1;
	;;	
esac		
mypid=$$
stype=$1
dealdate=$2



GETTABLENAME=$BILLHOME/shell/"gettablename.sh"
SMSSTAT=$BILLHOME/bin/sms_stat
ADDTIME=$BILLHOME/bin/addtime
##检查基本调用是否存在

test -f $GETTABLENAME || errorEXIT "文件 $GETTABLENAME 不存在"
test -f $SMSSTAT || errorEXIT "文件 $SETTEVD 不存在"
test -f $ADDTIME || errorEXIT "文件 $ADDTIME 不存在"


module=
tempstr=
temp=
year=
month=
yestoday=
tmpdate=
split=
bseq=
flag=
cnt=
tablename=
exprfile=

get_date()
{
	if [ "X$dealdate" = "X" ]; then 
		tmpdate=`date +"%Y%m%d%H%M%S"`
		yestoday=`$ADDTIME $tmpdate -86400`		
		year=`echo $yestoday |  cut -c 1-4`
		month=`echo $yestoday |  cut -c 5-6`
		day=`echo $yestoday | cut -c  7-8`
	else
		year=`echo $dealdate |  cut -c 1-4`
		month=`echo $dealdate |  cut -c 5-6`
		day=`echo $dealdate | cut -c  7-8`
	fi
}
run_sms_stat()
{
	echo "$SMSSTAT $tablename "$wherecause" $stype $billingcycleid "
	tmp=`$SMSSTAT $tablename "$wherecause" $stype $billingcycleid`
	ret=$?;
	if [ $ret -ne 0 ]; then
		printALERT "调用 $SETTEVD  $tablename  错误 $ret";
		exit 1;
	fi
	printNORMAL "统计 $tablename 表成功"
}


main()
{
 ##取得日期	
	get_date
	if [ "X$day" = "X" ]; then 
		wherecause=" WHERE to_char(DEAL_DATE,'yyyymm')='$year$month'"
	else
		wherecause=" WHERE to_char(DEAL_DATE,'yyyymmdd')='$year$month$day'"		
	fi
	billingcycleid=$year$month
 ##取得	base_file
	case $stype in
		P)
			base_file="CDR$year$month$day"
			module="SA1"
			;;
		M)
			base_file="XDC$year$month$day"
			module="SA2"
			;;
		*)
		echo "stype=$stype 有问题!"
		exit 1;
		;;	
	esac		
	area_code="951"
 ## 取得tablename
 	echo "$GETTABLENAME $module $base_file $area_code"
 	tablename=`$GETTABLENAME $module $base_file $area_code`
	ret=$?;
	if [ $ret -ne 0 ]; then
		printALERT "调用 $GETTABLENAME 错误 ";
		exit 1;
	fi
	echo "$tablename"
	#tablename="SMS_STAT"
		
###短信统计
	run_sms_stat
}
main
exit 0
