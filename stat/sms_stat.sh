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
##�����������Ƿ����

test -f $GETTABLENAME || errorEXIT "�ļ� $GETTABLENAME ������"
test -f $SMSSTAT || errorEXIT "�ļ� $SETTEVD ������"
test -f $ADDTIME || errorEXIT "�ļ� $ADDTIME ������"


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
		printALERT "���� $SETTEVD  $tablename  ���� $ret";
		exit 1;
	fi
	printNORMAL "ͳ�� $tablename ��ɹ�"
}


main()
{
 ##ȡ������	
	get_date
	if [ "X$day" = "X" ]; then 
		wherecause=" WHERE to_char(DEAL_DATE,'yyyymm')='$year$month'"
	else
		wherecause=" WHERE to_char(DEAL_DATE,'yyyymmdd')='$year$month$day'"		
	fi
	billingcycleid=$year$month
 ##ȡ��	base_file
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
		echo "stype=$stype ������!"
		exit 1;
		;;	
	esac		
	area_code="951"
 ## ȡ��tablename
 	echo "$GETTABLENAME $module $base_file $area_code"
 	tablename=`$GETTABLENAME $module $base_file $area_code`
	ret=$?;
	if [ $ret -ne 0 ]; then
		printALERT "���� $GETTABLENAME ���� ";
		exit 1;
	fi
	echo "$tablename"
	#tablename="SMS_STAT"
		
###����ͳ��
	run_sms_stat
}
main
exit 0
