#!/bin/sh
. $BILLHOME/shell/lib/libcomm.sh
. $APPHOME/shell/lib/libconst.sh

case $# in
        1|2)
        ;;
        *)
		echo "usage $0 NetWork [BillDate(20130301)]"
		echo "NetWork˵����������GW��������YD"
		echo "��������Ϊ1ʱ��BillDateȡ��ǰʱ���ǰһ��"
		echo "��������Ϊ2ʱ��BillDateȡ��ǰ��������"
		exit 1
        ;;
esac

mypid=$$
paramCnt=$#
NetWork=$1
BillDate=$2
Type=

GETUNUNSAL=$BILLHOME/sunsh/bin/getUnlStatTable
test -f $GETUNUNSAL || errorEXIT "�ļ� $GETUNUNSAL ������"

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
	
	
	if [ X"$NetWork" = "XYD" ];then
		printNORMAL "����ִ���쳣��������ͳ�Ƴ��򡣡���"
		
	elif [ X"$NetWork" = "XGW" ];then
		printNORMAL "����ִ���쳣��������ͳ�Ƴ��򡣡���"

	else
		printALERT "��������,BillDate=$BillDate,Type=$Type"
	fi
	
	$GETUNUNSAL $BillDate STT $NetWork
	
	printNORMAL "�쳣��������ͳ�Ƴ�����ɣ�"
}
main
exit 0

