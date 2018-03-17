#!/bin/sh
. $BILLHOME/shell/lib/libcomm.sh
if [ $# != 7 ]; then
	echo "Usage $0 ip usn pwd opppath targetpath filename fileSize"
	exit 1
fi

mypid=$$
ip=$1
username=$2
passwd=$3
opppath=$4
targetpath=$5
filename=$6
filesize=$7

FTPSIZE=$BILLHOME/work/ftpsize$mypid.txt
FTPPUT=$BILLHOME/work/FTPPUT$mypid.txt
FILESIZE=$BILLHOME/work/picksize$mypid.lst

gen_ftp_size()
{
	cat /dev/null > $FTPSIZE 2>/dev/null
	cat /dev/null > $FILESIZE 2>/dev/null	
	echo "open $ip"  	>>$FTPSIZE
	echo "user $username $passwd" >>$FTPSIZE
	echo "promp" 	>>$FTPSIZE	
	echo "cd $targetpath" 	>>$FTPSIZE
	echo "dir $filename" "$FILESIZE" >>$FTPSIZE
	echo "by"		>>$FTPSIZE
}

gen_ftp_put()
{
	cat /dev/null > $FTPPUT 2>/dev/null
	echo "open $ip"  	>>$FTPPUT
	echo "user $username $passwd" >>$FTPPUT
	echo "promp" 	>>$FTPPUT	
	echo "bin"		>>$FTPPUT
	echo "lcd $opppath" 	>>$FTPPUT
	echo "cd $targetpath" 	>>$FTPPUT
	echo "put $filename"  	>>$FTPPUT
	echo "by"		>>$FTPPUT
}


gen_ftp_put
cat $FTPPUT | ftp -n 2>&1 >/dev/null
if [ $? -ne 0 ]; then
	echo "FTP上传$opppath下的$filename失败"
	exit -1;
fi

gen_ftp_size
cat $FTPSIZE | ftp -n 2>&1 >/dev/null
[ $? -eq 0 ] || alertEXIT "获取文件$filename字节失败"

#文件大小不一致？
size1=`cat $FILESIZE | head -1 | awk '{print $5}'`
if [ "X$size1" != "X" ]; then
	if [ $size1 -ne $filesize ]; then exit -2; fi
else
	exit -2;
fi

rm -f $FTPSIZE
rm -f $FTPPUT
rm -f $FILESIZE

exit 0;
