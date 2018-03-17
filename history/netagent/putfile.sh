#!/bin/sh

if [ $# != 6 ]; then
	echo "Usage $0 ip usn pwd localpath remotepath filepattern"
	exit 1
fi

BILLHOME=/home/bill
mypid=$$                             

ip=$1
username=$2
passwd=$3
localpath=$4
remotepath=$5
filepattern=$6
                                         
FTPGET=./ftpsendmoni$mypid.txt      
                                
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
main()
{
	
	##���ɻ�ȡ�ļ��б�����
		gen_ftp_put
		if [ $? -ne 0 ];then
			printALERT "�޷����� $FTPPUT";
			exit 1;
		fi
	##��ȡ�Զ��ļ�
		cat $FTPGET | ftp -n 
		if [ $? -ne 0 ]; then 
			echo "�ϴ�$localpath��$filepattern�ļ���$ipʧ��"
			exit 1;
		fi
		#rm $FTPGET
}
main
exit 0

