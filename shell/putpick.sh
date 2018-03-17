#!/bin/sh
. $BILLHOME/shell/lib/libcomm.sh
if [ $# != 2 ]; then
	echo "Usage $0 pickparam procgrp"
	exit 1
fi
mypid=$$
PICKPARAM=$1
procgrp=$2

ip=
username=
passwd=
opppath=
localpath=
backuppath=
filter=
group=
source=
filename=
temp=
size=
size2=
seqbegin=
seqend=
seqlen=
seq=
ret=
dealbegindate=
dealenddate=
deletetype=   
tmp=

PUTCHECK=$BILLHOME/bin/putcheck
PUTLOG=$BILLHOME/bin/putlog
FILEMODIFYDIFF=$BILLHOME/bin/filemodifydiff

test -f $PICKPARAM || errorEXIT "�ļ� $PICKPARAM ������"
test -f $PUTCHECK || errorEXIT "�ļ� $PUTCHECK ������"
test -f $PUTLOG || errorEXIT "�ļ� $PUTLOG ������"
test -f $FILEMODIFYDIFF || errorEXIT "�ļ� $FILEMODIFYDIFF ������"
FTPPUT=$APPHOME/work/ftpput$mypid.txt
FTPDELETE=$APPHOME/work/ftpdelete$mypid.txt
FTPRENAME=$APPHOME/work/ftprename$mypid.txt
FILENAMELIST=$APPHOME/work/pickfilename$mypid.lst
FTPSIZE=$APPHOME/work/ftpsize$mypid.txt
FILESIZE=$APPHOME/work/picksize$mypid.lst

ping_oppip()
{
    	result=`/usr/sbin/ping -c 2 $ip | grep "100%" | wc -l`
        if [ $result -ne 0 ]; then
                printALERT "Ŀ��IP��ͨ��������"
                exit 1
        fi
}
gen_ftp_put()
{
	cat /dev/null > $FTPPUT 2>/dev/null
	echo "open $ip"  	>>$FTPPUT
	echo "user $username $passwd" >>$FTPPUT
	echo "prom"		>>$FTPPUT
	echo "bin"		>>$FTPPUT
	echo "cd $opppath" 	>>$FTPPUT
	echo "lcd $localpath" 	>>$FTPPUT
	echo "put $filename $tempname"  >>$FTPPUT
	echo "by"		>>$FTPPUT
}
get_file_name()
{
	for i in `echo $@`
	do
		case $i in 
		$filter)
			echo $i
			return 0
			;;
		*)
			;;
		esac
	done
}
gen_ftp_delete()
{
	cat /dev/null > $FTPDELETE 2>/dev/null
	echo "open $ip"  	>>$FTPDELETE
	echo "user $username $passwd" >>$FTPDELETE
	echo "cd $opppath" 	>>$FTPDELETE
	echo "delete $tempname"  >>$FTPDELETE
	echo "by"		>>$FTPDELETE
}
gen_ftp_rename()
{
	cat /dev/null > $FTPRENAME 2>/dev/null
	echo "open $ip"  	>>$FTPRENAME
	echo "user $username $passwd" >>$FTPRENAME
	echo "prom"		>>$FTPRENAME
	echo "cd $opppath" 	>>$FTPRENAME
	echo "rename $tempname $filename"  >>$FTPRENAME
	echo "by"		>>$FTPRENAME
}
gen_ftp_size()
{
	cat /dev/null > $FTPSIZE 2>/dev/null
	cat /dev/null > $FILESIZE 2>/dev/null	
	echo "open $ip"  	>>$FTPSIZE
	echo "user $username $passwd" >>$FTPSIZE
	echo "prompt"		>>$FTPSIZE
	echo "cd $opppath" 	>>$FTPSIZE
	echo "dir $tempname" "$FILESIZE" >>$FTPSIZE
	echo "by"		>>$FTPSIZE
}
delete_ftp_ctl()
{
	rm -f $FTPPUT; 2>/dev/null
	rm -f $FTPDELETE; 2>/dev/null
	rm -f $FTPRENAME; 2>/dev/null
	rm -f $FTPSIZE; 2>/dev/null
	rm -f $FILENAMELIST; 2>/dev/null
	rm -f $FILESIZE; 2>/dev/null
}
main()
{       
	cat $PICKPARAM| sed s/#.*$// | while read temp
	do
	##ȥ������
		if [ X"$temp" = "X" ];then continue; fi
	##�ж��Ƿ��Ǳ����̴���
		group=`echo "$temp" | awk '{print $1}'`
		if [ $group != $procgrp ];then continue; fi

	##��ȡ��������
		source=`echo "$temp" | awk '{print $2}'`
		opppath=`echo "$temp" | awk '{print $3}'`
		localpath=`echo "$temp" | awk '{print $4}'`
		backuppath=`echo "$temp" | awk '{print $5}'`
		ip=`echo "$temp" | awk '{print $6}'`
		username=`echo "$temp" | awk '{print $7}'`
		passwd=`echo "$temp" | awk '{print $8}'`
		filter=`echo "$temp" | awk '{print $9}' | sed s/\"//g`
		seqbegin=`echo "$temp" | awk '{print $10}'`
		seqlen=`echo "$temp" | awk '{print $11}'`
		seqend=`echo $seqbegin+$seqlen-1 | bc`
		ifdelfile=`echo "$temp" | awk '{print $12}'`
		filetype=`echo "$temp" | awk '{print $13}'`
		appid=`echo "$temp" | awk '{print $14}'`
		tacheid=`echo "$temp" | awk '{print $15}'`
		
	##�û�������ʱת��
		if [ X"$passwd" = "Xpasswd" ]; then
			passwd="" 
		fi
	##���·���ĺϷ���
		test -d $localpath || alertEXIT "·�� $localpath ������"
		test -d $backuppath || alertEXIT "·�� $backuppath ������"

	##���������Ƿ���ͨ	
	ping_oppip    
	##���Ԥ�����ļ��б�
	cat /dev/null >$FILENAMELIST
	##��ȡ�ļ������б�
        ls -rt $localpath/  >$FILENAMELIST

	##����ļ�Ϊ�������
		size1=`ls -l  "$FILENAMELIST" | awk '{printf $5}'`
		[ $size1 -ne 0 ] || continue;
		

		cat $FILENAMELIST | grep -v Bad | while read filename 
		do
			filename=`get_file_name $filename`
			if  [ X"$filename" = "X" ];then continue; fi
			[ `$FILEMODIFYDIFF $localpath/$filename` -lt 60 ] && break;
		
	
			size=`ls -l $localpath/$filename | awk '{print $5}'`
		##����Ƿ��ز�
			$PUTCHECK $source $filename
			ret=$?
			if [ $ret -lt 0 ]; then
				printALERT "���� $PUTCHECK ���� "
				exit 1;
			fi
			if [ $ret -gt 0 ]; then
				##printNORMAL "�ɼ��� $source ������" 
			        continue; 
			fi
	
		##��ȡ�ļ����
			seq=`echo $filename | cut -c $seqbegin-$seqend`
		##��ȡ����ʼʱ��
			dealbegindate=`date +%Y%m%d%H%M%S`

		##ָ�������ļ�
			tempname=$filename.tmp
		
		###���ɻ�ȡ��ɾ������ű�
			gen_ftp_put
			if [ $? -ne 0 ];then
				printALERT "�޷����� $FTPPUT";
				exit 1;
			fi
			gen_ftp_delete
			if [ $? -ne 0 ];then
				printALERT "�޷����� $FTPDELETE";
				exit 1;
			fi
			gen_ftp_rename
			if [ $? -ne 0 ];then
				printALERT "�޷����� $FTPRENAME";
				exit 1;
			fi
			gen_ftp_size
			if [ $? -ne 0 ];then
				printALERT "�޷����� $FTPSIZE";
				exit 1;
			fi

		#######�Ǵ���Ŀ������
			cat $FTPPUT | ftp -n 2>&1 >/dev/null
			if [ $? -ne 0 ]; then 
				printALERT "$filename �ļ�PUT�ϴ���$ip��$opppath��ʧ��"
				failcnt=`echo $failcnt+1 | bc`
				if [ $failcnt -gt 10 ]; then
					printALERT "�ļ�ʧ��̫��,����10,�˳�"
					exit 1;
				fi
				continue; 
			fi
		######ȡһ�¶Զ��ļ����ֽ���
			cat $FTPSIZE | ftp -n 2>&1 >/dev/null
			[ $? -eq 0 ] || alertEXIT "��ȡ�ļ� $tempname �ֽ�ʧ��"
		######ȡһ�¶Զ˵��ļ��ֽںͱ��ص��ļ��ֽ�
			size2=`cat $FILESIZE | head -1 | awk '{print $5}'`
		######������ߵ��ļ��ֽ�����һ���򽫶Զ��ļ�ɾ��,����..
			if [ "$size" != "$size2" ]; then
			######���Զ���ʱ�ļ��޸Ļ���
			  	cat $FTPDELETE | ftp -n 2>&1 >/dev/null
				if [ $? -ne 0 ]; then 
					printALERT "FTPɾ��$ip��$opppath�µ�$filenameʧ��"
					return 1
				fi
				continue;
			fi
		######�ԶԶ��ļ�����			
			cat $FTPRENAME | ftp -n  2>&1 >/dev/null
			if [ $? -ne 0 ]; then 
				printALERT "FTP$ip��$dir�µ�$filename���ݵ�$backuppathʧ��"
				return 1
			fi

		##��ȡ�������ʱ��
			dealenddate=`date +%Y%m%d%H%M%S`
		##д�ɼ����ݿ���־,��Ϊ��¼��־�������������,����쳣����..		
			$PUTLOG $source $size1 $filename $dealbegindate $dealenddate $seq $filetype $tacheid $appid
			ret=$?
			if [ $ret -ne 0 ]; then
				printALERT "���� $PUTLOG ���� $ret ";
			fi
			
		##�ļ�����0 ��ɾ��  1 ɾ��  2 ���ݣ�
			case $ifdelfile in 
			1)
				rm -f $localpath/$filename 2>/dev/null
				[ $? -eq 0 ] || alertEXIT "rm -f $localpath/$filename.tmpʧ��"
				;;
			2)
				mv $localpath/$filename  $backuppath/$filename
				[ $? -eq 0 ] || alertEXIT "mv $tempname $backuppath/$filenameʧ��"
				;;
			*)
				;;
			esac

			printNORMAL "$source �ɹ������ļ�$filename �ֽ�$size"
		done
	done
	
	delete_ftp_ctl
	if [ $? -ne 0 ]; then 
		printALERT "ɾ�� $mypid�ɼ��Ŀ����ļ�����"
		exit 1;
	fi
}
main
exit 0
