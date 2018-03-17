#!/bin/sh
. $BILLHOME/shell/lib/libcomm.sh
if [ $# != 7 ]; then
	echo "Usage $0 ip usn pwd opppath localpath filename fileSize"
	exit 1
fi

mypid=$$
ip=$1
username=$2
passwd=$3
opppath=$4
localpath=$5
filename=$6
filesize=$7

FTPSIZE=$BILLHOME/work/ftpsize$mypid.txt
FTPGET=$BILLHOME/work/ftpget$mypid.txt
FILESIZE=$BILLHOME/work/picksize$mypid.lst

gen_ftp_size()
{
	cat /dev/null > $FTPSIZE 2>/dev/null
	cat /dev/null > $FILESIZE 2>/dev/null	
	echo "open $ip"  	>>$FTPSIZE
	echo "user $username $passwd" >>$FTPSIZE
	echo "promp" 	>>$FTPSIZE	
	echo "cd $opppath" 	>>$FTPSIZE
	echo "dir $filename" "$FILESIZE" >>$FTPSIZE
	echo "by"		>>$FTPSIZE
}

gen_ftp_get()
{
	cat /dev/null > $FTPGET 2>/dev/null
	echo "open $ip"  	>>$FTPGET
	echo "user $username $passwd" >>$FTPGET
	echo "promp" 	>>$FTPGET	
	echo "bin"		>>$FTPGET
	echo "cd $opppath" 	>>$FTPGET
	echo "lcd $localpath" 	>>$FTPGET
	echo "get $filename"  	>>$FTPGET
	echo "by"		>>$FTPGET
}


gen_ftp_size
cat $FTPSIZE | ftp -n 2>&1 >/dev/null
[ $? -eq 0 ] || alertEXIT "获取文件$filename字节失败"

size1=`cat $FILESIZE | head -1 | awk '{print $5}'`
if [ "X$size1" != "X" ]; then
	if [ $size1 -ne $filesize ]; then exit -2; fi
else
	echo "$size1,$filesize"
	echo "size";
	exit -2;
fi

gen_ftp_get
cat $FTPGET | ftp -n 2>&1 >/dev/null
if [ $? -ne 0 ]; then
	echo "FTP获取$ip的$opppath下的$filename失败"
	exit -1;
fi

#下载的文件大小不一致？
size1=`ls -l  "$localpath/$filename" | awk '{printf $5}'`
if [ "X$size1" != "X$filesize" ]; then
	echo "downed size"
	exit -3;
fi

##如果遇到压缩的文件则先解压
case $filename in
*.gz)
	gunzip $localpath/$filename
	if [ $? -ne 0 ];then
		printALERT "解压文件 $localpath/$filename 失败"
		exit 1
	fi
	;;
*.Z)
	uncompress $localpath/$filename
	if [ $? -ne 0 ];then
		printALERT "解压文件 $localpath/$filename 失败"
		exit 1
	fi
	;;
*)	:
	;;
esac

rm -f $FTPSIZE
rm -f $FTPGET
rm -f $FILESIZE

exit 0;
