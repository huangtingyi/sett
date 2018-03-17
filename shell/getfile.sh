#!/bin/sh
. $BILLHOME/shell/lib/libcomm.sh

if [ $# != 2 ]; then
	echo "Usage $0 pickparam procgrp"
	exit 1
fi

BILLHOME=/home/bill
mypid=$$                             
PARAM=$1
procgrp=$2

ip=                     
username=
passwd=
oppfile=
localfile=

test -f $PARAM || errorEXIT "文件 $PARAM 不存在"
                                         
FTPGET=$BILLHOME/log/ftpgetmoni$mypid.txt      
                                
gen_ftp_get()                    
{                                
	cat /dev/null > $FTPGET 2>/dev/null
	echo "open $ip"  	>>$FTPGET
	echo "user $username $passwd" >>$FTPGET
	echo "bin"		>>$FTPGET
	echo "get $oppfile $localfile"  	>>$FTPGET
	echo "delete $oppfile"		>>$FTPGET	
	echo "by"		>>$FTPGET
}
main()
{
	cat $PARAM| sed s/#.*$// | while read temp
	do
		##去掉空行
			if [ X"$temp" = "X" ];then continue; fi
		##判断是否是本进程处理
			group=`echo "$temp" | awk '{print $1}'`
			if [ $group != $procgrp ];then continue; fi		
		##获取基本参数
			ip=`echo "$temp" | awk '{print $2}'`                  
			username=`echo "$temp" | awk '{print $3}'`
			passwd=`echo "$temp" | awk '{print $4}'`
			oppfile=`echo "$temp" | awk '{print $5}'`
			localfile=`echo "$temp" | awk '{print $6}'`
		##用户无密码时转换
			if [ X"$passwd" = "Xpasswd" ]; then
				passwd="" 
			fi
		##生成获取文件列表命令
			gen_ftp_get
			if [ $? -ne 0 ];then
				printALERT "无法生成 $FTPGET";
				exit 1;
			fi
		##获取对端文件
			cat $FTPGET | ftp -n 
			if [ $? -ne 0 ]; then 
				printALERT "FTP获取$ip的$dir下的$filename失败"
				continue
			fi
			rm $FTPGET			
		
	done
}
main
exit 0

