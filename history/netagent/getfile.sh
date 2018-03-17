#!/bin/sh

if [ $# != 7 ]; then
	echo "Usage $0 action ip usn pwd localpath remotepath filepattern"
	exit 1
fi

BILLHOME=/home/bill
mypid=$$                             

ip=$2
action=$1
echo $action
username=$3
passwd=$4
localpath=$5
remotepath=$6
filepattern=$7
                                         
FTPGET=./ftpgetmoni$mypid.txt      
FTPNLIST=$FTPGET
FILENAMELIST=./ftp138list.txt
                                
gen_ftp_get()                    
{                                
	cat /dev/null > $FTPGET 2>/dev/null
	echo "open $ip"  	>>$FTPGET
	echo "user $username $passwd" >>$FTPGET
	echo "bin"		>>$FTPGET
	echo "prompt"	        >>$FTPGET
	echo "cd $remotepath"   >>$FTPGET
	echo "lcd $localpath"   >>$FTPGET
	echo "mget $filepattern"  	>>$FTPGET	
	echo "by"		>>$FTPGET
}

gen_ftp_put()                    
{                                
	cat /dev/null > $FTPGET 2>/dev/null
	echo "open $ip"  	>>$FTPGET
	echo "user $username $passwd" >>$FTPGET
	echo "bin"		>>$FTPGET
	echo "prompt"	        >>$FTPGET
	echo "cd $remotepath"   >>$FTPGET
	echo "lcd $localpath"   >>$FTPGET
	echo "mput $filepattern"  >>$FTPGET	
	echo "by"		>>$FTPGET
}

gen_ftp_list()
{
	if [ X"$filepattern" = "X" ];then filepattern="."; fi
	if [ X"$filepattern" = "X*" ];then filepattern="."; fi
	
	cat /dev/null > $FTPNLIST 2>/dev/null
	cat /dev/null > $FILENAMELIST 2>/dev/null
	echo "open $ip"  	>>$FTPNLIST
	echo "user $username $passwd" >>$FTPNLIST
	echo "prompt"  	>>$FTPNLIST	
	echo "cd $remotepath" 	>>$FTPNLIST
	echo "dir ." "$FILENAMELIST" >>$FTPNLIST
	echo "by"		>>$FTPNLIST
}

main()
{
	
	##生成获取文件列表命令
		if [ $action = "get" ];then
			gen_ftp_get
		fi
		if [ $action = "put" ];then
			gen_ftp_put
		fi		
		if [ $action = "list" ];then
			gen_ftp_list
		fi			
		if [ $? -ne 0 ];then
			printALERT "无法生成 $FTPGET";
			exit 1;
		fi
	##获取对端文件
		cat $FTPGET | ftp -n 
		if [ $? -ne 0 ]; then 
			printALERT "FTP获取$ip的$dir下的$filename失败"
		fi
		if [ $action = "list" ];then
			echo $FILENAMELIST
			touch a$mypid.txt
			cat $FILENAMELIST | awk '{print $1"~~~"$9}'>>a$mypid.txt
			mv a$mypid.txt $FILENAMELIST
		fi				
		rm $FTPGET
}
main
exit 0

