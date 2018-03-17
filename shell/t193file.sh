#!/bin/sh

. $BILLHOME/shell/lib/libcomm.sh
case $# in
	5|6)
	;;
	*)
	echo usage $0 servicetype  outputdir   provincecode fileseq fileopmode [procdate-YYYYMMDD].     
	exit 1;
	;;	
esac		

servicetype=$1
outputdir=$2
provincecode=$3
fileseq=$4
fileopmode=$5
tmpprocdate=$6



filename=
base_file=
table_name=
module=
GETTABLENAME=$BILLHOME/shell/"gettablename.sh"
T193FILE=$BILLHOME/bin/t193file
ADDTIME=$BILLHOME/bin/addtime
temp=
ret=

test -d $outputdir || errorEXIT "文件 $outputdir 不存在"
test -f $T193FILE || errorEXIT "文件 $T193FILE 不存在"
test -f $ADDTIME || errorEXIT "文件 $ADDTIME 不存在"
test -f $GETTABLENAME || errorEXIT "文件 $GETTABLENAME 不存在"

gen_date()
{
	tmpdate=`date +"%Y%m%d%H%M%S"`
	yestoday=`$ADDTIME $tmpdate -86400`		
	year=`echo $yestoday |  cut -c 1-4`
	month=`echo $yestoday |  cut -c 5-6`
	day=`echo $yestoday | cut -c  7-8`
}

main()
{
	
	module="193"
	area_code=931

	if [  -n "${tmpprocdate:-}" ];then 
	   	procdate=$tmpprocdate
	   	base_file="GSRHJF"$tmpprocdate"000000.B"
	    else
	   	gen_date
   		procdate=$year$month$day
   		base_file="GSRHJF"$year$month$day"000000.B"
	fi	
	
	
	
	##初始话表名字  
		
		table_name=`$GETTABLENAME $module $base_file $area_code`
		ret=$?;
		if [ $ret -ne 0 ]; then
			printALERT "调用 $GETTABLENAME 错误 ";
			exit 1;
		fi
	
	echo "$T193FILE $servicetype $outputdir $provincecode $fileseq $fileopmode  $table_name $procdate "
	temp=`$T193FILE $servicetype $outputdir $provincecode $fileseq $fileopmode  $table_name $procdate`
	ret=$?;
	if [ $ret -ne 0 ]; then
		printALERT "调用 $T193FILE  错误 $ret";
		exit 1;
	fi
	
	chmod 666 $outputdir/*
	printNORMAL "$temp"	
}
main
exit 0
