#!/bin/sh
. $BILLHOME/shell/lib/libcomm.sh
. $APPHOME/shell/lib/libconst.sh

case $# in
        1|2)
        ;;
        *)
		echo "usage $0 NetWork [BillDate(20130301)]"
		echo "NetWork说明：固网：GW，移网：YD"
		echo "参数个数为1时，BillDate取当前时间的前一天"
		echo "参数个数为2时，BillDate取当前参数日期"
		exit 1
        ;;
esac

mypid=$$
paramCnt=$#
NetWork=$1
BillDate=$2
Type=

GETUNUNSAL=$BILLHOME/sunsh/bin/getUnlStatTable
test -f $GETUNUNSAL || errorEXIT "文件 $GETUNUNSAL 不存在"

ADDTIME=$BILLHOME/bin/addtime
test -f $ADDTIME || errorEXIT "文件 $ADDTIME 不存在"

main()
{

	if [ $paramCnt -eq 1 ];then
		hosttime=`date +%Y%m%d`
		tmpdate=`$ADDTIME $hosttime -86400`
		BillDate=`echo $tmpdate | cut -c 1-8`
	fi
	echo "BillDate=$BillDate"
	
	
	if [ X"$NetWork" = "XYD" ];then
		printNORMAL "移网执行异常话单语音统计程序。。。"
		
	elif [ X"$NetWork" = "XGW" ];then
		printNORMAL "固网执行异常话单语音统计程序。。。"

	else
		printALERT "参数有误,BillDate=$BillDate,Type=$Type"
	fi
	
	$GETUNUNSAL $BillDate STT $NetWork
	
	printNORMAL "异常话单语音统计程序完成！"
}
main
exit 0

