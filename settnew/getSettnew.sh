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

ANSETTTREND=$BILLHOME/sunsh/settnew/anSettTrend.sh
test -f $ANSETTTREND || errorEXIT "文件 $ANSETTTREND 不存在"

GETTOP=$BILLHOME/sunsh/settnew/getTop.sh
test -f $GETTOP || errorEXIT "文件 $GETTOP 不存在"

GETUNLSTAT=$BILLHOME/sunsh/settnew/getUnlstat.sh
test -f $GETUNLSTAT || errorEXIT "文件 $GETUNLSTAT 不存在"

GETUNLTICKET=$BILLHOME/sunsh/settnew/getUnlticket.sh
test -f $GETUNLTICKET || errorEXIT "文件 $GETUNLTICKET 不存在"

STATUSERINFO=$BILLHOME/sunsh/settnew01/StatUserInfo.sh
test -f $STATUSERINFO || errorEXIT "文件 $STATUSERINFO 不存在"


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

	echo "执行 趋势脚本程序"
	nohup $ANSETTTREND $BillDate >/dev/null &
	
	echo "执行 TOP脚本程序"
	nohup $GETTOP LT $BillDate >/dev/null &
	nohup $GETTOP TW $BillDate >/dev/null &
	
	echo "执行 用户分析脚本程序"
	nohup $STATUSERINFO $BillDate >/dev/null &
	
	echo "执行 异常统计脚本程序"
	nohup $GETUNLSTAT GW $BillDate >/dev/null &
	$GETUNLSTAT YD $BillDate
	
	##等待异常统计结束后抽取异常详单数据
	echo "执行 抽取异常详单脚本程序"
	nohup $GETUNLTICKET $BillDate GW ALL >/dev/null &
	nohup $GETUNLTICKET $BillDate YD ALL >/dev/null &
}
main
exit 0

