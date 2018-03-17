
#!/bin/sh
. $BILLHOME/shell/lib/libcomm.sh
. $APPHOME/shell/lib/libconst.sh

if [ $# != 1 ] ; then
	echo "Usage $0 billmonth(20121201) stype. "
	exit 1;
fi

mypid=$$
syearmonth=$1
stype=$2

sqlsed=$APPHOME/work/sql$mypid.sed
sqlfile=$APPHOME/work/sqlfile.$mypid
sqlfilework=$APPHOME/work/sqlfilework.$mypid


delete_temfile()
{
	rm -f $sqlfile.in 
	rm -f $sqlfilework 
	rm -f $sqlsed
}


main()
{
	echo `date +"StartTime:%Y%m%d%H%M%S"`
	
	$BILLHOME/wufl/bin/settcontrolall $syearmonth $stype >/dev/null
	
	if [ $? -ne 0 ];then
		printALERT "���� setttcontrolall $syearmonth ͳ��ʧ��!"
		exit 1
	fi
	
    	echo `date +"EndTime:%Y%m%d%H%M%S"` 
    	
	echo "����[$syearmonth] ͳ������ ���."
	return 0;
}
main
exit 0

