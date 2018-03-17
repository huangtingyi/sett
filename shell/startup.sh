#!/bin/sh
. $BILLHOME/shell/lib/libcomm.sh

PARAM_SUPP=$APPHOME/bin/param_supp
SHEDTSK_BIN=$BILLHOME/bin/shedtsk
SRV=$APPHOME/bin/srv
BILL_INI=$APPHOME/shell/bill.ini
SHEDTSK_LST=$APPHOME/shell/shedtsk.lst
LOG=$APPHOME/log
WORK=$APPHOME/work
CTL=$APPHOME/ctl

if [ "X$BILLHOME" = "X" ]; then
	errorEXIT "�������� $BILLHOME �����ڣ�"
fi

if [ "X$APPHOME" = "X" ]; then
	errorEXIT "�������� $APPHOME �����ڣ�"
fi

##����ļ�Ȩ��
test -f $PARAM_SUPP	|| errorEXIT "�ļ� $PARAM_SUPP ������!"
test -f $SHEDTSK_BIN	|| errorEXIT "�ļ� $SHEDTSK_BIN ������!"
test -f $SRV 		|| errorEXIT "�ļ� $SRV ������!"
test -f $BILL_INI 	|| errorEXIT "�ļ� $BILL_INI ������!"
test -f $SHEDTSK_LST 	|| errorEXIT "�ļ� $SHEDTSK_LST ������!"
test -d $LOG 		|| errorEXIT "Ŀ¼ $LOG ������!"
test -d $WORK 		|| errorEXIT "Ŀ¼ $WORK ������!"
test -d $CTL 		|| errorEXIT "Ŀ¼ $CTL ������!"

test -x $PARAM_SUPP	|| errorEXIT "�ļ� $PARAM_SUPP ����ִ��!"
test -x $SHEDTSK_BIN	|| errorEXIT "�ļ� $SHEDTSK_BIN ����ִ��!"
test -x $SRV 		|| errorEXIT "�ļ� $SRV ����ִ��!"
test -r $BILL_INI 	|| errorEXIT "�ļ� $BILL_INI ���ɶ�!"
test -r $SHEDTSK_LST 	|| errorEXIT "�ļ� $SHEDTSK_LST ���ɶ�!"

main()
{
	$PARAM_SUPP
	if [ $? -ne 0 ]; then
		errorEXIT "����$PARAM_SUPPִ��ʧ�ܣ�"
	fi

	cd $APPHOME/shell
	nohup shedtsk shedtsk.lst >/dev/null &
	nohup srvd httpd.conf >/dev/null &
}
main
exit 0
