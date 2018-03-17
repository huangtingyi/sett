#!/bin/sh
. $BILLHOME/shell/lib/libcomm.sh
if [ $# != 2 -a $# != 3 ] ; then
	echo "usage $0 module source_id  strseq[I+seq,S+seq]"
	exit 1
fi
module=$1
source_id=$2
temp=$3

inseq=
seleseq=
outstr=
evert_cnt=1
DATEDIFF=$BILLHOME/bin/datediff
test -f $DATEDIFF || errorEXIT "�ļ� $DATEDIFF ������"

if [ X$temp != "X" ];then 
	str_temp=`echo $temp | cut -c 1-1`
	if [ X$str_temp = "XI" ];then 
		inseq=`echo $temp | cut -c 2-4`
	fi
	if [ X$str_temp = "XS" ];then 
		seleseq=`echo $temp | cut -c 2-4`
	fi
fi		

outfileseq=

main()
{
	dealdate=`date +%Y%m%d`
	
	###chk	module	
	case $module in
	CDR101|CDR201)
		;;
	*)
		printALERT  " $module �Ƿ�,���s1240���������Ƿ���CDR���� "
		exit 1;
		;;
	esac

	SEQ_CTL=$APPHOME/ctl/$module"."$source_id".seq"

	if [ ! -f $SEQ_CTL ];	then
		echo "F000 $dealdate $evert_cnt" > $SEQ_CTL 
		if [ $? -ne 0 ]; then 
			printALERT "�����ļ� $SEQ_CTL ����"
			exit 1;
			break;
		fi
	fi	
	
###���ȡ�����ļ��Ƿ�Ϊ��
	seqtmp=`tail -1 $SEQ_CTL`
	seqtmp=`echo $seqtmp | awk '{print $1}'` 
	if [ X$seqtmp = "X" ];then 
		echo "F000 $dealdate $evert_cnt" > $SEQ_CTL
	fi
###ȡ�õ�ǰseq
	seqstr=`tail -1 $SEQ_CTL`
	seqtmp=`echo $seqstr | awk '{print $1}'` 
	seqtmp=`echo $seqtmp | cut -c 2-4`
	evert_cnt1=`echo $seqstr | awk '{print $3}'` 

	if [ X$seqtmp = X"200"  ];then 
		seq="001"
		evert_cnt=`echo $evert_cnt1+1 | bc`
	else
		seq=`echo $seqtmp+1 | bc`
		evert_cnt=$evert_cnt1
	fi
	case $seq in
		?)
			seq="00"$seq
			;;
		??)
			seq="0"$seq
			;;
		???)
			;;
		*)
			printALERT "seq= $seq �Ƿ� "
			exit 1
			;;
	esac
###������ѯ��seleseq �Ƿ��ڿ����ļ��� 

	if [ X$seleseq != "X" ];then 
		outstr="XX"
		seqtmp=`tail -1 $SEQ_CTL`
		evert_cnt_chk=`echo $seqtmp | awk '{print $3}'` 
		evert_cnt_chk1=`echo $evert_cnt_chk - 1 | bc`

                grep "F"$seleseq $SEQ_CTL | while read seqtmp
                do
                	if [ X"$seqtmp" = "X" ]; then
                		outstr="XX"
                	fi
                	
                	filedate=`echo $seqtmp | awk '{print $2}'`
			storedays=`$DATEDIFF $dealdate $filedate`
			evert_cnta=`echo $seqtmp | awk '{print $3}'` 
		##evert_cntaΪ���η�ת
			if [ $evert_cnta -eq $evert_cnt_chk ]; then
				outstr="OK"
				break;
			fi
                ##evert_cntaΪ�ϴη�ת
      			if [ $evert_cnta -eq $evert_cnt_chk1 ]; then
      				if [ $seleseq -gt $seq ]; then
					outstr="OK"
					break;
				fi
			fi
          
                done
                        		
               	echo $outstr
		exit 0
		
	fi
###inseqд������ļ�
	if [ X$inseq != "X" ];then
		
		if [ $inseq = $seq ];then
			inseqstr="F"$inseq
			echo $inseqstr $dealdate $evert_cnt >> $SEQ_CTL
			exit 0
		else
			printALERT "inseq= $inseq �Ƿ�,������ļ�ȡ���� $seq ��һ�� "
			exit 1;
		fi
	fi
	outfileseq=$seq

echo $outfileseq
}

main

exit 0
