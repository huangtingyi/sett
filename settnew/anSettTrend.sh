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

ANSETTTREND=$BILLHOME/sunsh/bin/anSettTrend
test -f $ANSETTTREND || errorEXIT "�ļ� $ANSETTTREND ������"

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
	##exit 0;

	echo "���� nohup ִ�����Ʒ������򡣡���"
	nohup $ANSETTTREND $BillDate STT YD CT >/dev/null &
	nohup $ANSETTTREND $BillDate STT YD CTC >/dev/null &
	nohup $ANSETTTREND $BillDate STT YD CRC >/dev/null &
	nohup $ANSETTTREND $BillDate STT YD CM >/dev/null &
	
	echo "���� nohup ִ�����Ʒ������򡣡���"
	nohup $ANSETTTREND $BillDate STT GW CT >/dev/null &
	nohup $ANSETTTREND $BillDate STT GW CTC >/dev/null &
	nohup $ANSETTTREND $BillDate STT GW CRC >/dev/null &
	nohup $ANSETTTREND $BillDate STT GW CM >/dev/null &

}
main
exit 0

