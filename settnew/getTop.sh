#!/bin/sh
. $BILLHOME/shell/lib/libcomm.sh
. $APPHOME/shell/lib/libconst.sh

case $# in
        1|2)
        ;;
        *)
		echo "usage $0 Type [BillDate(20130301)]"
		echo "����Type˵����LT:����,TW:����"
		echo "��������Ϊ1ʱ��BillDateȡ��ǰʱ���ǰһ��"
		echo "��������Ϊ2ʱ��BillDateȡ��ǰ��������"
		exit 1
        ;;
esac

mypid=$$
paramCnt=$#
Type=$1
BillDate=$2

GETTOP=$BILLHOME/sunsh/bin/getUserTopInfo
test -f $GETTOP || errorEXIT "�ļ� $GETTOP ������"

ADDTIME=$BILLHOME/bin/addtime
test -f $ADDTIME || errorEXIT "�ļ� $ADDTIME ������"

main()
{

	if [ $paramCnt -eq 1 ];then
		hosttime=`date +%Y%m%d`
		tmpdate=`$ADDTIME $hosttime -86400`
		BillDate=`echo $tmpdate | cut -c 1-8`
	fi
	echo "BillDate=$BillDate"
	
	if [ X"$Type" = "XLT" ];then

		echo "���� nohup ִ��TOP����ͳ�Ƴ��򡣡���"
		
		nohup $GETTOP $BillDate YD >/dev/null &
	
		echo "���� nohup ִ��TOP����ͳ�Ƴ��򡣡���"
		nohup $GETTOP $BillDate GW >/dev/null &
		
	elif [ X"$Type" = "XTW" ];then
		echo "���� nohup ִ��TOP����ͳ�Ƴ��򡣡���"
		
		nohup $GETTOP $BillDate YD CM >/dev/null &
		nohup $GETTOP $BillDate YD CT >/dev/null &
		nohup $GETTOP $BillDate YD CTC >/dev/null &
		nohup $GETTOP $BillDate YD CRC >/dev/null &
		
		echo "���� nohup ִ��TOP����ͳ�Ƴ��򡣡���"
		nohup $GETTOP $BillDate GW CM >/dev/null &
		nohup $GETTOP $BillDate GW CT >/dev/null &
		nohup $GETTOP $BillDate GW CTC >/dev/null &
		nohup $GETTOP $BillDate GW CRC >/dev/null &
		
	else
		echo "�������󣡣���"
	fi
}
main
exit 0

