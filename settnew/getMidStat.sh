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

GETMIDSTATTABLE=$BILLHOME/sunsh/bin/getMidStatTable
test -f $GETMIDSTATTABLE || errorEXIT "�ļ� $GETMIDSTATTABLE ������"

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

	echo "���� nohup ִ���м�ͳ�Ƴ��򡣡���"
	nohup $GETMIDSTATTABLE $BillDate STT YD CT >/dev/null &
	nohup $GETMIDSTATTABLE $BillDate STT YD CTC >/dev/null &
	nohup $GETMIDSTATTABLE $BillDate STT YD CRC >/dev/null &
	nohup $GETMIDSTATTABLE $BillDate STT YD CM >/dev/null &
	
	echo "���� nohup ִ���м�ͳ�Ƴ��򡣡���"
	nohup $GETMIDSTATTABLE $BillDate STT GW CT >/dev/null &
	nohup $GETMIDSTATTABLE $BillDate STT GW CTC >/dev/null &
	nohup $GETMIDSTATTABLE $BillDate STT GW CRC >/dev/null &
	nohup $GETMIDSTATTABLE $BillDate STT GW CM >/dev/null &


}
main
exit 0

