#!/bin/sh
. $BILLHOME/shell/lib/libcomm.sh
. $APPHOME/shell/lib/libconst.sh

case $# in
        1|2)
        ;;
        *)
		echo "usage $0 Type [BillDate(20130301)]"
		echo "参数Type说明：LT:本网,TW:他网"
		echo "参数个数为1时，BillDate取当前时间的前一天"
		echo "参数个数为2时，BillDate取当前参数日期"
		exit 1
        ;;
esac

mypid=$$
paramCnt=$#
Type=$1
BillDate=$2

GETTOP=$BILLHOME/sunsh/bin/getUserTopInfo
test -f $GETTOP || errorEXIT "文件 $GETTOP 不存在"

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
	
	if [ X"$Type" = "XLT" ];then

		echo "移网 nohup 执行TOP本网统计程序。。。"
		
		nohup $GETTOP $BillDate YD >/dev/null &
	
		echo "固网 nohup 执行TOP本网统计程序。。。"
		nohup $GETTOP $BillDate GW >/dev/null &
		
	elif [ X"$Type" = "XTW" ];then
		echo "移网 nohup 执行TOP他网统计程序。。。"
		
		nohup $GETTOP $BillDate YD CM >/dev/null &
		nohup $GETTOP $BillDate YD CT >/dev/null &
		nohup $GETTOP $BillDate YD CTC >/dev/null &
		nohup $GETTOP $BillDate YD CRC >/dev/null &
		
		echo "固网 nohup 执行TOP他网统计程序。。。"
		nohup $GETTOP $BillDate GW CM >/dev/null &
		nohup $GETTOP $BillDate GW CT >/dev/null &
		nohup $GETTOP $BillDate GW CTC >/dev/null &
		nohup $GETTOP $BillDate GW CRC >/dev/null &
		
	else
		echo "参数错误！！！"
	fi
}
main
exit 0

