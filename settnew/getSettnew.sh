#!/bin/sh
. $BILLHOME/shell/lib/libcomm.sh
. $APPHOME/shell/lib/libconst.sh

case $# in
        0|1)
        ;;
        *)
		echo "usage $0 [BillDate(20130301)]"
		echo "��������Ϊ0ʱ��ȡ��ǰʱ���ǰһ��"
		echo "��������Ϊ1ʱ��ȡ��ǰ��������"
		exit 1
        ;;
esac

mypid=$$
paramCnt=$#
BillDate=$1

ANSETTTREND=$BILLHOME/sunsh/settnew/anSettTrend.sh
test -f $ANSETTTREND || errorEXIT "�ļ� $ANSETTTREND ������"

GETTOP=$BILLHOME/sunsh/settnew/getTop.sh
test -f $GETTOP || errorEXIT "�ļ� $GETTOP ������"

GETUNLSTAT=$BILLHOME/sunsh/settnew/getUnlstat.sh
test -f $GETUNLSTAT || errorEXIT "�ļ� $GETUNLSTAT ������"

GETUNLTICKET=$BILLHOME/sunsh/settnew/getUnlticket.sh
test -f $GETUNLTICKET || errorEXIT "�ļ� $GETUNLTICKET ������"

STATUSERINFO=$BILLHOME/sunsh/settnew01/StatUserInfo.sh
test -f $STATUSERINFO || errorEXIT "�ļ� $STATUSERINFO ������"


ADDTIME=$BILLHOME/bin/addtime
test -f $ADDTIME || errorEXIT "�ļ� $ADDTIME ������"

main()
{

	if [ $paramCnt -eq 0 ];then
		hosttime=`date +%Y%m%d`
		tmpdate=`$ADDTIME $hosttime -86400`
		BillDate=`echo $tmpdate | cut -c 1-8`
	fi
	echo "BillDate=$BillDate"

	echo "ִ�� ���ƽű�����"
	nohup $ANSETTTREND $BillDate >/dev/null &
	
	echo "ִ�� TOP�ű�����"
	nohup $GETTOP LT $BillDate >/dev/null &
	nohup $GETTOP TW $BillDate >/dev/null &
	
	echo "ִ�� �û������ű�����"
	nohup $STATUSERINFO $BillDate >/dev/null &
	
	echo "ִ�� �쳣ͳ�ƽű�����"
	nohup $GETUNLSTAT GW $BillDate >/dev/null &
	$GETUNLSTAT YD $BillDate
	
	##�ȴ��쳣ͳ�ƽ������ȡ�쳣�굥����
	echo "ִ�� ��ȡ�쳣�굥�ű�����"
	nohup $GETUNLTICKET $BillDate GW ALL >/dev/null &
	nohup $GETUNLTICKET $BillDate YD ALL >/dev/null &
}
main
exit 0

