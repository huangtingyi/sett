#!/bin/sh
. $BILLHOME/shell/lib/libcomm.sh
if [ $# != 7 ]; then
	echo "Usage $0 ip usn pwd deletetype filename opppath backuppath"
	exit 1
fi

mypid=$$
ip=$1
username=$2
passwd=$3
deletetype=$4
filename=$5
opppath=$6
backuppath=$7

FTPDELETE=$BILLHOME/work/ftpdelete$mypid.txt
FTPRENAME=$BILLHOME/work/ftprename$mypid.txt

gen_ftp_delete()
{
	cat /dev/null > $FTPDELETE 2>/dev/null
	echo "open $ip"  	>>$FTPDELETE
	echo "user $username $passwd" >>$FTPDELETE
	echo "promp" 	>>$FTPDELETE
	echo "cd $opppath" 	>>$FTPDELETE
	echo "delete $filename"  >>$FTPDELETE
	echo "by"		>>$FTPDELETE
}

gen_ftp_rename()
{
	cat /dev/null > $FTPRENAME 2>/dev/null
	echo "open $ip"  	>>$FTPRENAME
	echo "user $username $passwd" >>$FTPRENAME
	echo "promp" 	>>$FTPRENAME	
	echo "cd $opppath" 	>>$FTPRENAME
	echo "rename $filename $backuppath/$filename"  >>$FTPRENAME
	echo "by"		>>$FTPRENAME
}


##�Զ��ļ�����0 ��ɾ��  1 ɾ��  2 ���ݣ�
if [ $deletetype -eq 1 ]; then 
	gen_ftp_delete
  	cat $FTPDELETE | ftp -n 2>&1 >/dev/null
	if [ $? -ne 0 ]; then 
		printALERT "FTPɾ��$ip��$dir�µ�$filenameʧ��"
		exit 1;
	fi
	rm -f $FTPDELETE
fi
if [ $deletetype -eq 2 ]; then 
	gen_ftp_rename
  	cat $FTPRENAME | ftp -n  2>&1 >/dev/null
	if [ $? -ne 0 ]; then
		printALERT "FTP$ip��$dir�µ�$filename���ݵ�$backuppathʧ��"
		exit 1;
	fi
	rm -f $FTPRENAME
fi

exit 0;
