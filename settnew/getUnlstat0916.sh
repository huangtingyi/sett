#!/bin/sh
. $BILLHOME/shell/lib/libcomm.sh
. $APPHOME/shell/lib/libconst.sh

case $# in
        0|1)
        ;;
        *)
		echo "usage $0 [BillDate(20130301)]"
		echo "参数个数为0时，BillDate取当前时间的前一天"
		echo "参数个数为1时，BillDate取当前参数日期"
		exit 1
        ;;
esac

mypid=$$
paramCnt=$#
BillDate=$1

GETUNUNSAL=$BILLHOME/sunsh/bin/getUnlStatTable
test -f $GETUNUNSAL || errorEXIT "文件 $GETUNUNSAL 不存在"

ADDTIME=$BILLHOME/bin/addtime
test -f $ADDTIME || errorEXIT "文件 $ADDTIME 不存在"

main()
{

	if [ $paramCnt -eq 0 ];then
		hosttime=`date +%Y%m%d`
		tmpdate=`$ADDTIME $hosttime -86400`
		BillDate=`echo $tmpdate | cut -c 1-8`
	fi
	echo "BillDate=$BillDate"
	
	echo "移网 nohup 执行 异常话单语音统计程序。。。"
	nohup $GETUNUNSAL $BillDate STT YD >/dev/null &
	
	echo "固网 nohup 执行 异常话单语音统计程序。。。"
	nohup $GETUNUNSAL $BillDate STT GW >/dev/null &
		
	

}
main
exit 0

