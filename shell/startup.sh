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
	errorEXIT "环境变量 $BILLHOME 不存在！"
fi

if [ "X$APPHOME" = "X" ]; then
	errorEXIT "环境变量 $APPHOME 不存在！"
fi

##检查文件权限
test -f $PARAM_SUPP	|| errorEXIT "文件 $PARAM_SUPP 不存在!"
test -f $SHEDTSK_BIN	|| errorEXIT "文件 $SHEDTSK_BIN 不存在!"
test -f $SRV 		|| errorEXIT "文件 $SRV 不存在!"
test -f $BILL_INI 	|| errorEXIT "文件 $BILL_INI 不存在!"
test -f $SHEDTSK_LST 	|| errorEXIT "文件 $SHEDTSK_LST 不存在!"
test -d $LOG 		|| errorEXIT "目录 $LOG 不存在!"
test -d $WORK 		|| errorEXIT "目录 $WORK 不存在!"
test -d $CTL 		|| errorEXIT "目录 $CTL 不存在!"

test -x $PARAM_SUPP	|| errorEXIT "文件 $PARAM_SUPP 不可执行!"
test -x $SHEDTSK_BIN	|| errorEXIT "文件 $SHEDTSK_BIN 不可执行!"
test -x $SRV 		|| errorEXIT "文件 $SRV 不可执行!"
test -r $BILL_INI 	|| errorEXIT "文件 $BILL_INI 不可读!"
test -r $SHEDTSK_LST 	|| errorEXIT "文件 $SHEDTSK_LST 不可读!"

main()
{
	$PARAM_SUPP
	if [ $? -ne 0 ]; then
		errorEXIT "程序$PARAM_SUPP执行失败！"
	fi

	cd $APPHOME/shell
	nohup shedtsk shedtsk.lst >/dev/null &
	nohup srvd httpd.conf >/dev/null &
}
main
exit 0
