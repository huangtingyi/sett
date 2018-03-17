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

test -f $PARAM || errorEXIT "�ļ� $PARAM ������"
                                         
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
		##ȥ������
			if [ X"$temp" = "X" ];then continue; fi
		##�ж��Ƿ��Ǳ����̴���
			group=`echo "$temp" | awk '{print $1}'`
			if [ $group != $procgrp ];then continue; fi		
		##��ȡ��������
			ip=`echo "$temp" | awk '{print $2}'`                  
			username=`echo "$temp" | awk '{print $3}'`
			passwd=`echo "$temp" | awk '{print $4}'`
			oppfile=`echo "$temp" | awk '{print $5}'`
			localfile=`echo "$temp" | awk '{print $6}'`
		##�û�������ʱת��
			if [ X"$passwd" = "Xpasswd" ]; then
				passwd="" 
			fi
		##���ɻ�ȡ�ļ��б�����
			gen_ftp_get
			if [ $? -ne 0 ];then
				printALERT "�޷����� $FTPGET";
				exit 1;
			fi
		##��ȡ�Զ��ļ�
			cat $FTPGET | ftp -n 
			if [ $? -ne 0 ]; then 
				printALERT "FTP��ȡ$ip��$dir�µ�$filenameʧ��"
				continue
			fi
			rm $FTPGET			
		
	done
}
main
exit 0

