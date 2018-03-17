#!/bin/sh
. $BILLHOME/shell/lib/libcomm.sh
. $APPHOME/shell/lib/libconst.sh

case $# in
        0|1)
        ;;
        *)
		echo "usage $0 [BillDate(20130301)]"
		echo "��������Ϊ0ʱ��BillDateȡ��ǰʱ���ǰһ��"
		echo "��������Ϊ1ʱ��BillDateȡ��ǰ��������"
		exit 1
        ;;
esac

mypid=$$
paramCnt=$#
BillDate=$1

GETUNUNSAL=$BILLHOME/sunsh/bin/getUnlStatTable
test -f $GETUNUNSAL || errorEXIT "�ļ� $GETUNUNSAL ������"

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
	
	echo "���� nohup ִ�� �쳣��������ͳ�Ƴ��򡣡���"
	nohup $GETUNUNSAL $BillDate STT YD >/dev/null &
	
	echo "���� nohup ִ�� �쳣��������ͳ�Ƴ��򡣡���"
	nohup $GETUNUNSAL $BillDate STT GW >/dev/null &
		
	

}
main
exit 0

