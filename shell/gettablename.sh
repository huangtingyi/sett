#!/bin/sh
. $BILLHOME/shell/lib/libcomm.sh
if [ $# != 3 ] ; then
	echo "usage $0 module base_file area"
	exit 1
fi
module=$1
file_name=$2
area=$3
table_name=
month=
day=
realmonth=

DATEDIFF=$BILLHOME/bin/datediff
ADDTIME=$BILLHOME/bin/addtime
test -f $ADDTIME || errorEXIT "文件 $ADDTIME 不存在"
test -f $DATEDIFF || errorEXIT "文件 $DATEDIFF 不存在"

getwday()
{
	storedays=`$DATEDIFF $filedate 19890101`
	`let wday=$storedays%7`
	wday="0$wday"
	case $wday in
		00)
			wday="07"
			;;
		*)
			wday=$wday
			;;
	esac
}

getrealmonth()
{
realmonth=$month
if [ $day -gt 20 ];then
	case $month in
		01)
			realmonth="02"
			;;
		02)
			realmonth="03"
			;;
		03)
			realmonth="04"
			;;
		04)
			realmonth="05"
			;;
		05)
			realmonth="06"
			;;
		06)
			realmonth="07"
			;;
		07)
			realmonth="08"
			;;
		08)
			realmonth="09"
			;;
		09)
			realmonth="10"
			;;
		10)
			realmonth="11"
			;;
		11)
			realmonth="12"
			;;
		12)
			realmonth="01"
			;;
		*)
			printALERT " $month 非法 "
			exit 1
			;;
	esac
fi
}
main()
{
case $module in
	STC|STG)
		month=`echo $file_name | cut  -c 11-12`
		monthup=`echo $file_name | cut  -c 6-7`
		day=`echo $file_name | cut -c 13-14`
		getrealmonth
		case $file_name in
		*.[B,C])
			if [ "$module" = "STC" ]; then
				table_name=CDMA_TICKET_"$month"
			else
				table_name=GSM_TICKET_"$month"
			fi
			;;
		CQT*.1|[C,J]*O*.1)
			if [ "$module" = "STC" ]; then
				table_name=CDMA_TICKET_OUT_"$monthup"
			else
				table_name=GSM_TICKET_OUT_"$monthup"
			fi
			;;
		[C,J]RIT*.1)
			monthup=`echo $file_name | cut  -c 7-8`
			if [ "$module" = "STC" ]; then
				table_name=CDMA_TICKET_OUT_"$monthup"
			else
				table_name=GSM_TICKET_OUT_"$monthup"
			fi
			;;						
		*.a)
			if [ "$module" = "STC" ]; then
				table_name=CDMA_ERR_TICKET
			else
				table_name=GSM_ERR_TICKET
			fi
			;;
		*)
			printALERT  " $file_name 非法 "
			exit 1;
			;;
		esac
		;;
	TYZ)
		case $file_name in
		CDMAD*[C,R,S,T]*.AVL)
			month=`echo $file_name | cut  -c 16-17`
			day=`echo $file_name | cut -c 18-19`
			getrealmonth
			table_name=CDMA_TICKET_RATE_"$month"
			;;
		CDMAD*[D,I]*.AVL)
			month=`echo $file_name | cut  -c 16-17`
			day=`echo $file_name | cut -c 18-19`
			getrealmonth
			table_name=CDMA_OUT_RATE_"$month"
			;;
		2000*.AVL|0000*.req|200*.req)
			month=`echo $file_name | cut  -c 9-10`
			day=`echo $file_name | cut -c 11-12`
			getrealmonth
			table_name=CDMA1X_TICKET_RATE_"$month"
			;;
		???[C,R,S,T]*.AVL)
			month=`echo $file_name | cut  -c 15-16`
			day=`echo $file_name | cut -c 17-18`
			getrealmonth
			table_name=GSM_TICKET_RATE_"$month"
			;;
		???[D,I]*.AVL)
			month=`echo $file_name | cut  -c 15-16`
			day=`echo $file_name | cut -c 17-18`
			getrealmonth
			table_name=GSM_OUT_RATE_"$month"
			;;

		SMGXD*.087)
			month=`echo $file_name | cut  -c 11-12`
			day=`echo $file_name | cut -c 13-14`
			getrealmonth
			table_name=SMSP_TICKET_RATE_"$month"
			;;
		XD*.087)
			month=`echo $file_name | cut  -c 8-9`
			day=`echo $file_name | cut -c 10-11`
			getrealmonth
			table_name=SMS_TICKET_RATE_"$month"
			;;
		BILL193*.AVL)
			month=`echo $file_name | cut  -c 12-13`
			day=`echo $file_name | cut -c 14-15`
			getrealmonth
			table_name=RHJF_TICKET_RATE_"$month"
			;;
		*)
			printALERT  " $file_name 非法 "
			exit 1;
			;;
		esac
		;;
	TZB)
		case $file_name in
		CBI*.087|QRI*.087|JRI*.087|JII*.087)
			month=`echo $file_name | cut  -c 6-7`
			day=`echo $file_name | cut -c 8-9`
			getrealmonth
			table_name=VISIT_IN_CDMA_"$month"
			;;
		CDMA1X*.AVL)
			month=`echo $file_name | cut  -c 13-14`
			day=`echo $file_name | cut -c 15-16`
			getrealmonth
			table_name=VISIT_IN_CDMA1X_"$month"
			;;
		TCDMA1X*.AVL)
			month=`echo $file_name | cut  -c 14-15`
			day=`echo $file_name | cut -c 16-17`
			getrealmonth
			table_name=VISIT_IN_CDMA1X_"$month"
			;;
		GBI*.087|TRI*.087|CRI*.087|CII*.087)
			month=`echo $file_name | cut  -c 6-7`
			day=`echo $file_name | cut -c 8-9`
			getrealmonth
			table_name=VISIT_IN_GSM_"$month"
			;;
		*)
			printALERT  " $file_name 非法 "
			exit 1;
			;;
		esac
		;;
		
        PRE)
		filedate=`echo $file_name | cut  -c 7-14`
		month=`echo $file_name | cut  -c 11-12`    
		#getwday
		table_name=PREP_TICKET_"$month"
                ;;
        TLL)
		month=`echo $file_name | cut  -c 11-12`
		table_name=TLL_TICKET_"$month"
                ;;
        CDX)
		month=`echo $file_name | cut  -c 5-6`
		table_name=CDMA1X_TICKET_"$month"
                ;;                
        SMS)
		case $file_name in
		PTPF*.SMT.BIL.[0,3]|UNFT*.SMC.BIL.[0,3])
			month=`echo $file_name | cut  -c 9-10`
			table_name=SMS_TICKET_"$month"
			;;
		PTP*.SMM.BIL.[0,3]|SMC*SMG.BIL.[0,3])
			month=`echo $file_name | cut  -c 8-9`
			table_name=SMS_TICKET_"$month"
			;;
		CDR*.SMP.BIL.[0,3])
			month=`echo $file_name | cut  -c 8-9`
			table_name=SMSP_TICKET_"$month"
			;;			
		CL*.SMP.BIL.[0,3])
			month=`echo $file_name | cut  -c 7-8`
			table_name=SMSP_TICKET_"$month"
			;;
		*)
			printALERT  " $file_name 非法 "
			exit 1;
			;;
		esac
		;;
        MUP)
		case $file_name in
		CDR*.MUP.BIL.[G,C])
			month=`echo $file_name | cut  -c 8-9`
			table_name=SMSUP_TICKET_"$month"
			;;
		CL*.MUP.BIL.[G,C])
			month=`echo $file_name | cut  -c 7-8`
			table_name=SMSUP_TICKET_"$month"
			;;
		*)
			printALERT  " $file_name 非法 "
			exit 1;
			;;
		esac
		;;
        193)
 		month=`echo $file_name | cut  -c 11-12`
		day=`echo $file_name | cut -c 13-14`
		getrealmonth
		case $file_name in
		*.B)
			table_name=RHJF_TICKET_"$month"
		;;
		*.a)
			table_name=RHJF_ERR_TICKET
		;;
		*)
			printALERT  " $file_name 非法 "
			exit 1;
			;;
		esac
		;;
	CEP)
		table_name=CDMA_ERR_RATE_VIT_TICKET
		;;
	GEP)
		table_name=GSM_ERR_RATE_VIT_TICKET
		;;
	CRR)
		table_name=CDMA_ERR_RATE_TICKET
		;;
	GRR)
		table_name=GSM_ERR_RATE_TICKET
		;;
	OMG|OMC)
		table_name=SMS_TICKET_OLD
		;;
	193O)
		table_name="T193_TICKET_OLD"
		;;
	GCR|GST)
		table_name=GSM_RATE_OLD
		;;
	XOX)
		table_name=CDMA1X_TICKET_OLD_INTF
		;;
        XOI)
                table_name=CDMA1X_TICKET_UP_INTF
                ;;
	*)
		printALERT  " $module 非法 "
		exit 1;
		;;
esac

echo $table_name
}

main

exit 0
