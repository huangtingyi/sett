#!/bin/sh
. $BILLHOME/shell/lib/libcomm.sh
if [ $# != 2 ] ; then
	echo "usage $0 module filter"
	exit 1
fi
module=$1
filter=$2
outfilename=

main()
{
	dealdate=`date +%Y%m%d`
	
	case $module in
		pps_sms)
			case $filter in
			C*.2)
				SEQ_CTL=$APPHOME/ctl/pps_sms_s.seq
				S=s
				;;
			[P,U,S]*.2)
				SEQ_CTL=$APPHOME/ctl/pps_sms.seq
				S=x
				;;
			*)
				printALERT  " $filter 非法 "
				exit 1;
				;;
			esac
			outfilename="gsm"$dealdate"_209"$S
			;;

		pps_gsm)
			SEQ_CTL=$APPHOME/ctl/pps_gsm.seq
			S=8
			outfilename="gsm"$dealdate"_209"$S
			;;
		vpn_ram)
			SEQ_CTL=$APPHOME/ctl/vpn_ram.seq
			S=9
			outfilename="ram"$dealdate"_209"$S
			;;
		vpn)
			SEQ_CTL=$APPHOME/ctl/vpn.seq
			S=2
			outfilename="prv"$dealdate"_209"$S
			;;

		*)
			printALERT " $month 非法 "
			exit 1
			;;
	esac

###检查取控制文件是否为空
	seqtmp=`tail -1 $SEQ_CTL`
	if [ X$seqtmp = "X" ];then 
		echo "0000" >> $SEQ_CTL
	fi
###取得当前seq
	seqtmp=`tail -1 $SEQ_CTL`
	if [ X$seqtmp = X"9999" ];then 
		seq="0000"
	else
		seq=`echo $seqtmp+1 | bc`
	fi

	case $seq in
		?)
			seq="000"$seq
			;;
		??)
			seq="00"$seq
			;;
		???)
			seq="0"$seq
			;;
		????)
			;;
		*)
			printALERT "seq= $seq 非法 "
			exit 1
			;;
	esac
	
	outfilename=$outfilename$seq".unl"
	echo $seq >> $SEQ_CTL    	
echo $outfilename
}

main

exit 0
