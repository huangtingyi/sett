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
size1=
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
targetnametemp=
tempname=

PICKCHECK=$BILLHOME/bin/pickcheck
PICKLOG=$BILLHOME/bin/picklog
GETS1240FILENAMESH=gets1240filename.sh
test -f $PICKPARAM || errorEXIT "�ļ� $PICKPARAM ������"
test -f $PICKCHECK || errorEXIT "�ļ� $PICKCHECK ������"
test -f $PICKLOG || errorEXIT "�ļ� $PICKLOG ������"

FTPGET=$APPHOME/work/ftpget$mypid.txt
FTPNLIST=$APPHOME/work/ftpnlist$mypid.txt
FILENAMELIST=$APPHOME/work/pickfilename$mypid.lst
FILENAMELIST_a=$APPHOME/work/pickfilenamea$mypid.lst
FILENAMELIST_b=$APPHOME/work/pickfilenameb$mypid.lst
FTPSIZE=$APPHOME/work/ftpsize$mypid.txt
FILESIZE1=$APPHOME/work/picksize1$mypid.lst
FILESIZE2=$APPHOME/work/picksize2$mypid.lst
FILESIZE=

gen_ftp_get()
{
	cat /dev/null > $FTPGET 2>/dev/null
	echo "open $ip"  	>>$FTPGET
	echo "user $username $passwd" >>$FTPGET
	echo "bin"		>>$FTPGET
	echo "lcd $localpath" 	>>$FTPGET
	echo "get $dirfilename  $targetnametemp" 	>>$FTPGET
	echo "by"		>>$FTPGET
}
gen_ftp_nlist()
{
	cat /dev/null > $FTPNLIST 2>/dev/null
	cat /dev/null > $FILENAMELIST 2>/dev/null
	echo "open $ip"  	>>$FTPNLIST
	echo "user $username $passwd" >>$FTPNLIST
	echo "prompt" >>$FTPNLIST 
	echo "dir $opppath" "$FILENAMELIST" >>$FTPNLIST
	echo "by"		>>$FTPNLIST
}
gen_ftp_size()
{
	cat /dev/null > $FTPSIZE 2>/dev/null
	cat /dev/null > $FILESIZE 2>/dev/null	
	echo "open $ip"  	>>$FTPSIZE
	echo "user $username $passwd" >>$FTPSIZE
	echo "dir $dirfilename" "$FILESIZE" >>$FTPSIZE
	echo "by"		>>$FTPSIZE
}
delete_ftp_ctl()
{
	rm -f $FTPGET; 2>/dev/null
	rm -f $FTPNLIST; 2>/dev/null
	rm -f $FILENAMELIST; 2>/dev/null
	rm -f $FILENAMELIST_a; 2>/dev/null
	rm -f $FILENAMELIST_b; 2>/dev/null

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
		filetype=`echo "$temp" | awk '{print $13}'`
		appid=`echo "$temp" | awk '{print $14}'`
		tacheid=`echo "$temp" | awk '{print $15}'`

	##�û�������ʱת��
		if [ X"$passwd" = "Xpasswd" ]; then
			passwd="" 
		fi
	##���·���ĺϷ���
		test -d $localpath || alertEXIT "·�� $localpath ������"
	
	##����FULL��
	##���ɻ�ȡ�ļ��б�����
		gen_ftp_nlist
		if [ $? -ne 0 ];then
			printALERT "�޷����� $FTPNLIST";
			exit 1;
		fi

	##��ȡ�Զ��ļ��б�
		cat $FTPNLIST | ftp -n 2>&1 >/dev/null
		if [ $? -ne 0 ]; then
			continue;
		fi

	##����ļ�������浽�м��ļ�
		if [ -f $FILENAMELIST ]; then
			cat $FILENAMELIST | while read temp
			do
				echo $temp "FULL">> $FILENAMELIST_a 2>/dev/null
			done
		fi

	##����READ��
		opppathtmp=$opppath
		opppath=`echo "$opppathtmp" | sed s/\FULL/READ/g`
	
	##���ɻ�ȡ�ļ��б�����
		gen_ftp_nlist
		if [ $? -ne 0 ];then
			printALERT "�޷����� $FTPNLIST";
			exit 1;
		fi
		
		cat $FTPNLIST | ftp -n 2>&1 >/dev/null
		if [ $? -ne 0 ]; then
			continue;
		fi

##����ļ�������浽�м��ļ�
		if [ -f $FILENAMELIST ]; then
			cat $FILENAMELIST | while read temp
			do
				echo $temp "READ">> $FILENAMELIST_a 2>/dev/null
			done
		fi
		
##����ļ������������
		[ -f $FILENAMELIST_a ] || continue;

		cat $FILENAMELIST_a > $FILENAMELIST 2>/dev/null
		cat /dev/null > $FILENAMELIST_a 2>/dev/null

##����ļ��б��Ƿ��ڿ����ļ���
		cat $FILENAMELIST | while read filename_temp
		do
			dirfile_name=`echo $filename_temp | awk '{print $1}'`
			
			datetemp=`echo $filename_temp | awk '{print $2}'`
			datestr1=`echo $datetemp | cut -c 3-4`
			datestr2=`echo $datetemp | cut -c 6-7`
			datestr3=`echo $datetemp | cut -c 9-10`
			datestr="."$datestr1"$datestr2"$datestr3
			
			file_name=`basename $dirfile_name`
		##��ȡ�ļ����
			seq=`echo $file_name | cut -c $seqbegin-$seqend`
			inseq=`echo $seq | cut -c 3-5`
			file_module=`echo $file_name | cut -c 1-6`

			chkseq="S"$inseq

			chktmp=`$GETS1240FILENAMESH $file_module $source $chkseq`
			ret=$?;
			if [ $ret -ne 0 ]; then
				printALERT "���� $GETS1240FILENAMESH $file_module $source $chkseq ����";
				exit 1;
			fi
			
			chkfilter=`echo $filename_temp | awk '{print $5}'`
			
			if [ X$chkfilter = "XFULL" ];then	
				##FULLĿ¼ȫ��
				chktmp="XX"
			fi			

			if [ X$chktmp = "XOK" ];then	
				##�ļ��Ѳɹ�
				continue;
			fi
			file_seq="F"$inseq
			echo "$dirfile_name $datestr $file_module $file_seq" >> $FILENAMELIST_b
			
			chktemp=`grep $file_module $FILENAMELIST_a`
			if [ X$chktemp = "X" ];then	
				##Ϊ��д���ļ�
				echo "$file_module" >> $FILENAMELIST_a
			fi			
		done

##����Ҫ���вɼ����ļ��б������ļ�ϵ�кŽ�������
		cat /dev/null > $FILENAMELIST 2>/dev/null

		cat $FILENAMELIST_a | while read str_temp
		do
			if [ X$str_temp = "X" ];then continue; fi

			file_module=`echo $str_temp | awk '{print $1}'`

			file_cnt=`grep $file_module $FILENAMELIST_b |wc | awk '{print $1}'`
			
			ctlseq_min=`$GETS1240FILENAMESH $file_module $source`
			ret=$?;
			if [ $ret -ne 0 ]; then
				printALERT "���� $GETS1240FILENAMESH $file_module $source ����";
				exit 1;
			fi
			ctlseq=$ctlseq_min
			
			while [ file_cnt -ne 0 ]; do
				file_seq="F"$ctlseq
				temp=`grep $file_module $FILENAMELIST_b |grep $file_seq`

				if [ X"$temp" != "X" ];then	
					##д���ļ�
					 echo "$temp" >> $FILENAMELIST
				else
					##�Ϻ����ټ���ȡ�ļ�
					 break;
				fi	
				ctlseq=`echo $ctlseq + 1 | bc`
				
				if [ X$ctlseq = X"200"  ];then 
					ctlseq="001"
				fi
				case $ctlseq in
					?)
						ctlseq="00"$ctlseq
						;;
					??)
						ctlseq="0"$ctlseq
						;;
					???)
						;;
				esac
							   
			   	file_cnt=`echo $file_cnt - 1 | bc`
			done			
		done
		
##����ļ�Ϊ�������
cat $FILENAMELIST
		size1=`ls -l  "$FILENAMELIST" | awk '{printf $5}'`
		[ $size1 -ne 0 ] || continue;
		
		
		cat $FILENAMELIST | grep -v Bad | while read tempstr
		do
			
			if [ X"$tempstr" = "X" ]; then continue; fi
			
			dirfilename=`echo $tempstr | awk '{print $1}'`
			datestr=`echo $tempstr | awk '{print $2}'`
			filename=`basename $dirfilename`
			
		##��ȡ�ļ����
			seq=`echo $filename | cut -c $seqbegin-$seqend`

			inseq=`echo $seq | cut -c 3-5`
			file_module=`echo $filename | cut -c 1-6`

			insseqstr="I"$inseq

			filename=$filename"$datestr"
		##�ɼ���ʱ�ļ�
			targetnametemp="s1240"$filename".pik"

		##����Ƿ��ز�--���������
		##	$PICKCHECK $source $filename
		##	ret=$?
		##	if [ $ret -lt 0 ]; then
		##		printALERT "���� $PICKCHECK ���� "
		##		exit 1;
		##	fi
		##	if [ $ret -gt 0 ]; then
		##		##printNORMAL "�ɼ��� $source ������" 
		##	        continue; 
		##	fi

				
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
			
			size1=`cat $FILESIZE1 | head -1 | awk '{print $4}'`
			size2=`cat $FILESIZE2 | head -1 | awk '{print $4}'`

			if [ "X$size1" != "X" ]; then
				if [ $size1 != $size2 ]; then continue; fi
			fi

			sizechk=`echo $size2 *2048 | bc`

		###���ɻ�ȡ����ű�
			gen_ftp_get
			if [ $? -ne 0 ];then
				printALERT "�޷����� $FTPGET";
				exit 1;
			fi

		##���Զ�������ȡ�ļ�	
			cat $FTPGET | ftp -n 2>&1 >/dev/null
			if [ $? -ne 0 ]; then 
				printALERT "FTP��ȡ$ip��$dir�µ�$filenameʧ��"
				continue
			fi
			size1=`ls -l  "$localpath/$targetnametemp" | awk '{printf $5}'`
		##�����ļ��ֽ��������ļ��б�һ�����˳�
			if [ $sizechk -ne $size1 ];then
				rm -f $localpath/$targetnametemp >/dev/null
				exit 1;
			fi			
			
			
		##��ȡ�������ʱ��
			dealenddate=`date +%Y%m%d%H%M%S`
		##д�ɼ����ݿ���־
		##echo "$PICKLOG $source $size1 $filename $dealbegindate $dealenddate $seq $filetype $tacheid $appid"
			$PICKLOG $source $size1 $filename $dealbegindate $dealenddate $seq $filetype $tacheid $appid
			ret=$?
			if [ $ret -ne 0 ]; then
				printALERT "���� $PICKLOG ���� $ret ";
	
				rm -f $localpath/$targetnametemp >/dev/null
				exit 1;
			fi

		##�Ѳɼ��ɹ����ļ���д������ļ���
			instmp=`$GETS1240FILENAMESH $file_module $source $insseqstr`
			ret=$?;
			if [ $ret -ne 0 ]; then
				printALERT "���� $GETS1240FILENAMESH $file_module $source $insseqstr ����";
	
				rm -f $localpath/$targetnametemp >/dev/null
				exit 1;
			fi

			mv $localpath/$targetnametemp $localpath/$filename
			if [ $? -ne 0 ]; then
				printALERT "�ƶ� mv $localpath/$targetnametemp $localpath/$filename ʧ��"
				exit 1;
			fi


			printNORMAL "$source �ɹ��ɼ��ļ�$filename �ֽ�$size1"
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
