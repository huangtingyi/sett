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
targetname=
temp=
size1=
size2=
seqbegin=
seqend=
seqlen=
seq=
ret=
createdate=
dealbegindate=
dealenddate=
deletetype=   
tmp=
msg=

PICKCHECK=$BILLHOME/bin/pickcheck
PICKLOG=$BILLHOME/bin/picklog
PICKDUP=$BILLHOME/bin/pickdup

test -f $PICKPARAM || errorEXIT "�ļ� $PICKPARAM ������"
test -f $PICKCHECK || errorEXIT "�ļ� $PICKCHECK ������"
test -f $PICKLOG || errorEXIT "�ļ� $PICKLOG ������"
test -f $PICKDUP || errorEXIT "�ļ� $PICKDUP ������"

FTPGET=$APPHOME/work/ftpget$mypid.txt
FTPDELETE=$APPHOME/work/ftpdelete$mypid.txt
FTPRENAME=$APPHOME/work/ftprename$mypid.txt
FTPNLIST=$APPHOME/work/ftpnlist$mypid.txt
FTPSIZE=$APPHOME/work/ftpsize$mypid.txt
FILENAMELIST=$APPHOME/work/pickfilename$mypid.lst
FILESIZE1=$APPHOME/work/picksize1$mypid.lst
FILESIZE2=$APPHOME/work/picksize2$mypid.lst
FILESIZE=

gen_ftp_get()
{
	cat /dev/null > $FTPGET 2>/dev/null
	echo "open $ip"  	>>$FTPGET
	echo "user $username $passwd" >>$FTPGET
	echo "bin"		>>$FTPGET
	echo "cd $opppath" 	>>$FTPGET
	echo "lcd $localpath" 	>>$FTPGET
	echo "get $filename $targetnametemp" 	>>$FTPGET
	echo "by"		>>$FTPGET
}
gen_ftp_nlist()
{
	cat /dev/null > $FTPNLIST 2>/dev/null
	cat /dev/null > $FILENAMELIST 2>/dev/null
	echo "open $ip"  	>>$FTPNLIST
	echo "user $username $passwd" >>$FTPNLIST
	echo "cd $opppath" 	>>$FTPNLIST
	echo "prompt" >>$FTPNLIST 
	echo "ls $filter" "$FILENAMELIST" >>$FTPNLIST
	echo "by"		>>$FTPNLIST
}
gen_ftp_size()
{
	cat /dev/null > $FTPSIZE 2>/dev/null
	cat /dev/null > $FILESIZE 2>/dev/null	
	echo "open $ip"  	>>$FTPSIZE
	echo "user $username $passwd" >>$FTPSIZE
	echo "cd $opppath" 	>>$FTPSIZE
	echo "dir $filename" "$FILESIZE" >>$FTPSIZE
	echo "by"		>>$FTPSIZE
}
gen_ftp_delete()
{
	cat /dev/null > $FTPDELETE 2>/dev/null
	echo "open $ip"  	>>$FTPDELETE
	echo "user $username $passwd" >>$FTPDELETE
	echo "cd $opppath" 	>>$FTPDELETE
	echo "delete $filename"  >>$FTPDELETE
	echo "by"		>>$FTPDELETE
}
gen_ftp_rename()
{
	cat /dev/null > $FTPRENAME 2>/dev/null
	echo "open $ip"  	>>$FTPRENAME
	echo "user $username $passwd" >>$FTPRENAME
	echo "cd $opppath" 	>>$FTPRENAME
	echo "rename $filename $backuppath/$filename"  >>$FTPRENAME
	echo "by"		>>$FTPRENAME
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
delete_ftp_ctl()
{
	rm -f $FTPGET; 2>/dev/null
	rm -f $FTPDELETE; 2>/dev/null
	rm -f $FTPRENAME; 2>/dev/null
	rm -f $FTPNLIST; 2>/dev/null
	rm -f $FTPSIZE; 2>/dev/null
	rm -f $FILENAMELIST; 2>/dev/null
	rm -f $FILESIZE1; 2>/dev/null
	rm -f $FILESIZE2; 2>/dev/null
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
#		filter="LYD*"
		seqbegin=`echo "$temp" | awk '{print $10}'`
		seqlen=`echo "$temp" | awk '{print $11}'`
		seqend=`echo $seqbegin+$seqlen-1 | bc`
		deletetype=`echo "$temp" | awk '{print $12}'`

	##�û�������ʱת��
		if [ X"$passwd" = "Xpasswd" ]; then
			passwd="" 
		fi
	##���·���ĺϷ���
		test -d $localpath || alertEXIT "·�� $localpath ������"
		
	##���ɻ�ȡ�ļ��б�����
		gen_ftp_nlist
		if [ $? -ne 0 ];then
			printALERT "�޷����� $FTPNLIST";
			exit 1;
		fi

	##��ȡ�Զ��ļ��б�
		cat $FTPNLIST | ftp -n 2>&1 >/dev/null
		if [ $? -ne 0 ]; then
#			printNORMAL " ftp���ɼ��� $source  ʧ��"
			continue;
		fi

##����ļ������������
		[ -f $FILENAMELIST ] || continue;
##����ǲ�ɾ���ı�־������ó�����ļ��б���Ԥ����,20040827
		if [ $deletetype -eq 0 ];then
			$PICKDUP $source $FILENAMELIST
			if [ $? -ne 0 ];then
				printALERT "���� $PICKDUP ʧ��";
				exit 1;
			fi
		fi
##����ļ�Ϊ�������
		size1=`ls -l  "$FILENAMELIST" | awk '{printf $5}'`
		[ $size1 -ne 0 ] || continue;
		

		cat $FILENAMELIST | grep -v Bad | while read filename 
		do
			filename=`get_file_name $filename`

			if [ X"$filename" = "X" ]; then continue; fi

	##��filter��filename��ȵ�����ж�
			case "$filter"  in
				"$filename")
				        continue;
				;;
				*)
				;;
			esac
	##��ȡ�ļ����
			seq=`echo $filename | cut -c $seqbegin-$seqend`
			if [ $seqlen -eq 2 ]; then
				seq="00""$seq"
			fi
			createdate=`date +%Y%m%d%H%M%S`

			case $source in
			LZDG01|LZDG11)
				targetname="LA"`echo $createdate | cut -c 1-12`."$seq"
				;;
			LZDG02|LZDG12)
				targetname="LB"`echo $createdate | cut -c 1-12`."$seq"
				;;
			LZDG03|LZDG13)
				targetname="LC"`echo $createdate | cut -c 1-12`."$seq"
				;;
			JYDG01|JYDG11)
				targetname="JY"`echo $createdate | cut -c 1-12`."$seq"
				;;
			JYDG02|JYDG12)
				targetname="JYB"`echo $createdate | cut -c 1-12`."$seq"
				;;
			TSDG01|TSDG11)
				targetname="TA"`echo $createdate | cut -c 1-14`."$seq"
				;;
			PLDG01|PLDG11)
				targetname="PA"`echo $createdate | cut -c 1-14`."$seq"
				;;
			*)
				targetname="$filename"
				;;
			esac
	##�ɼ���ʱ�ļ�
			targetnametemp="$targetname"".pik"
			
	##����Ƿ��ز�
			$PICKCHECK $source $filename
			ret=$?
			if [ $ret -lt 0 ]; then
				printALERT "���� $PICKCHECK ���� "
				exit 1;
			fi
			if [ $ret -gt 0 ]; then
				##printNORMAL "�ɼ��� $source ������" 
			        continue; 
			fi
	
	##��ȡ����ʼʱ��
			dealbegindate=`date +%Y%m%d%H%M%S`
	
	##ȡ�Զ��ļ���С
			FILESIZE=$FILESIZE1
			gen_ftp_size
			if [ $? -ne 0 ];then
				printALERT "�޷����� $FTPSIZE";
				exit 1;
			fi
			cat $FTPSIZE | ftp -n 2>&1 >/dev/null
			[ $? -eq 0 ] || alertEXIT "��ȡ�ļ�$filename�ֽ�ʧ��"
			
			sleep 1
			
			FILESIZE=$FILESIZE2
			gen_ftp_size
			if [ $? -ne 0 ];then
				printALERT "�޷����� $FTPSIZE";
				exit 1;
			fi
			cat $FTPSIZE | ftp -n 2>&1 >/dev/null
			[ $? -eq 0 ] || alertEXIT "��ȡ�ļ�$filename�ֽ�ʧ��"
			
			size1=`cat $FILESIZE1 | head -1 | awk '{print $5}'`
			size2=`cat $FILESIZE2 | head -1 | awk '{print $5}'`

			if [ "X$size1" != "X" ]; then
				if [ $size1 -ne $size2 ]; then continue; fi
			fi

	###���ɻ�ȡ��ɾ������ű�
			gen_ftp_get
			if [ $? -ne 0 ];then
				printALERT "�޷����� $FTPGET";
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
	##���Զ�������ȡ�ļ�	
			cat $FTPGET | ftp -n 2>&1 >/dev/null
			if [ $? -ne 0 ]; then 
				printALERT "FTP��ȡ$ip��$dir�µ�$filenameʧ��"
				continue
			fi	
	##����ļ������������
			[ -f $localpath/$targetnametemp ] || continue;

			if [ "X$size1" = "X" ]; then
				size1=`ls -l  "$localpath/$targetnametemp" | awk '{printf $5}'`
			fi
	##��ȡ�������ʱ��
			dealenddate=`date +%Y%m%d%H%M%S`
	##д�ɼ����ݿ���־		
			msg=`$PICKLOG $source $size1 $filename $dealbegindate $dealenddate $seq`
			ret=$?
			if [ $ret -ne 0 ]; then
				printALERT "���� $PICKLOG ���� $ret $msg";
	#ɾ���ɼ��������ļ�
				rm -f $localpath/$targetnametemp >/dev/null
				exit 1;
			fi
	##�Զ��ļ�����0 ��ɾ��  1 ɾ��  2 ���ݣ�
			if [ $deletetype -eq 1 ]; then 
			  	cat $FTPDELETE | ftp -n 2>&1 >/dev/null
				if [ $? -ne 0 ]; then 
					printALERT "FTPɾ�� $ip �� $dir �µ� $targetname ʧ��"
					return 1
				fi
			fi
			if [ $deletetype -eq 2 ]; then 
			  	cat $FTPRENAME | ftp -n  2>&1 >/dev/null
				if [ $? -ne 0 ]; then 
					printALERT "FTP $ip �� $dir �µ� $targetname ���ݵ� $backuppath ʧ��"
					return 1
				fi
			fi
	##�ɼ���ʱ�ļ��ĵ�����ļ�			
			mv $localpath/$targetnametemp $localpath/$targetname
			if [ $? -ne 0 ]; then
				printALERT "�ƶ� mv $localpath/$targetnametemp $localpath/$targetname ʧ��"
				exit 1;
			fi
			
			printNORMAL "$source �ɹ��ɼ��ļ� $filename Ϊ $targetname �ֽ�$size1"
			###���ڼ����Ϣ�����
			echo "ʱ�䣺$dealenddate  $source �ɹ��ɼ��ļ� $filename  Ϊ $targetname �ֽ�$size1 " >>$APPHOME/log/pick.sh.$source.log
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
