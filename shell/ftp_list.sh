#!/bin/sh
. $BILLHOME/shell/lib/libcomm.sh
if [ $# != 5 ]; then
	echo "Usage $0 ip usn pwd opppath filter $#"
	exit 1
fi

mypid=$$
ip=$1
username=$2
passwd=$3
opppath=$4
filter=$5

FTPNLIST=$BILLHOME/work/ftpnlist$mypid.txt

gen_ftp_nlist()
{
	cat /dev/null > $FTPNLIST 2>/dev/null
	echo "open $ip"  	>>$FTPNLIST
	echo "user $username $passwd" >>$FTPNLIST
	echo "promp" 	>>$FTPNLIST
	echo "cd $opppath" 	>>$FTPNLIST
	echo "promp"		>>$FTPNLIST	
	echo "dir $filter"	>>$FTPNLIST
	echo "by"		>>$FTPNLIST
}

gen_ftp_nlist
cat $FTPNLIST | ftp -n
if [ $? -ne 0 ]; then
	echo " ftp到采集点失败"
	continue;
fi

rm -f $FTPNLIST
