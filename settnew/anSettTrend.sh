#!/bin/sh
. $BILLHOME/shell/lib/libcomm.sh
. $APPHOME/shell/lib/libconst.sh

case $# in
        0|1)
        ;;
        *)
		echo "usage $0 [BillDate(20130301)]"
		echo "参数个数为0时，取当前时间的前一天"
		echo "参数个数为1时，取当前参数日期"
		exit 1
        ;;
esac

mypid=$$
paramCnt=$#
BillDate=$1

ANSETTTREND=$BILLHOME/sunsh/bin/anSettTrend
test -f $ANSETTTREND || errorEXIT "文件 $ANSETTTREND 不存在"

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
	##exit 0;

	echo "移网 nohup 执行趋势分析程序。。。"
	nohup $ANSETTTREND $BillDate STT YD CT >/dev/null &
	nohup $ANSETTTREND $BillDate STT YD CTC >/dev/null &
	nohup $ANSETTTREND $BillDate STT YD CRC >/dev/null &
	nohup $ANSETTTREND $BillDate STT YD CM >/dev/null &
	
	echo "固网 nohup 执行趋势分析程序。。。"
	nohup $ANSETTTREND $BillDate STT GW CT >/dev/null &
	nohup $ANSETTTREND $BillDate STT GW CTC >/dev/null &
	nohup $ANSETTTREND $BillDate STT GW CRC >/dev/null &
	nohup $ANSETTTREND $BillDate STT GW CM >/dev/null &

}
main
exit 0

