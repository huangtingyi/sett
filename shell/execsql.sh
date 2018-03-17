#!/bin/sh
. $BILLHOME/shell/lib/libcomm.sh

if [ $# != 2 ] ; then
	echo usage $0 connstr sqlfile
	exit 1
fi

connstr=$1
sqlfile=$2

test -f $sqlfile || alertEXIT "�ļ� $sqlfile ������"

sqlplus $connstr <<EOF
@$sqlfile
quit;
exit 0;
