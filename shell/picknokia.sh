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
namestr=
filename=
targetname=
temp=
size1=
seqbegin=
seqend=
seqlen=
seq=
ret=
dealbegindate=
dealenddate=
createdate=
deletetype=
tmp=
msg=

PICKCHECK=$BILLHOME/bin/pickcheck
PICKLOG=$BILLHOME/bin/picklog
READTTS=$BILLHOME/bin/readtts
WRITETTT=$BILLHOME/bin/writettt

test -f $PICKPARAM || errorEXIT "�ļ� $PICKPARAM ������"
test -f $PICKCHECK || errorEXIT "�ļ� $PICKCHECK ������"
test -f $PICKLOG || errorEXIT "�ļ� $PICKLOG ������"
test -f $READTTS || errorEXIT "�ļ� $READTTS ������"
test -f $WRITETTT || errorEXIT "�ļ� $WRITETTT ������"

TTS="TTSCOF00.IMG"
TTT="TTTCOF00.IMG"
FTPGET=$APPHOME/work/ftpget$mypid.txt
FTPGETCTRL=$APPHOME/work/ftpgetctrl$mypid.txt
FTPPUTCTRL=$APPHOME/work/ftpputctrl$mypid.txt
FTAMGETLST=$APPHOME/work/ftamget$mypid.lst
TTSLOCAL=$APPHOME/work/$TTS.$mypid
TTTLOCAL=$APPHOME/work/$TTT.$mypid
ERRTXT=$APPHOME/log/errnokia.log
gen_ftp_get()
{
	cat /dev/null > $FTPGET 2>/dev/null
	echo "open $ip"  	>>$FTPGET
	echo "user $username $passwd" >>$FTPGET
	echo "bin"		>>$FTPGET
	echo "cd $opppath" 	>>$FTPGET
	echo "lcd $localpath" 	>>$FTPGET
	echo "get $filename $targetnametemp"  >>$FTPGET
	echo "by"		>>$FTPGET
}
gen_ftp_get_ctrl()
{
	cat /dev/null > $FTPGETCTRL 2>/dev/null
	echo "open $ip"  	>>$FTPGETCTRL
	echo "user $username $passwd" >>$FTPGETCTRL
	echo "bin"		>>$FTPGETCTRL
	echo "prompt"		>>$FTPGETCTRL
	echo "cd $opppath" 	>>$FTPGETCTRL
	echo "get $TTS $TTSLOCAL"	>>$FTPGETCTRL
	echo "get $TTT $TTTLOCAL"	>>$FTPGETCTRL
	echo "by"		>>$FTPGETCTRL
}
gen_ftp_put_ctrl()
{
	cat /dev/null > $FTPPUTCTRL 2>/dev/null
	echo "open $ip"  	>>$FTPPUTCTRL
	echo "user $username $passwd" >>$FTPPUTCTRL
	echo "bin"		>>$FTPPUTCTRL
	echo "prompt"		>>$FTPPUTCTRL
	echo "cd $opppath" 	>>$FTPPUTCTRL
	echo "put $TTTLOCAL $TTT">>$FTPPUTCTRL
	echo "by"		>>$FTPPUTCTRL
}
delete_ftp_ctl()
{
	rm -f $FTPGET; 2>/dev/null
	rm -f $FTPGETCTRL; 2>/dev/null
	rm -f $FTPPUTCTRL; 2>/dev/null
	rm -f $TTSLOCAL; 2>/dev/null
	rm -f $TTTLOCAL; 2>/dev/null
	rm -f $FTAMGETLST; 2>/dev/null
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
		deletetype=`echo "$temp" | awk '{print $12}'`

	##�û�������ʱת��
		if [ X"$passwd" = "Xpasswd" ]; then
			passwd=""
		fi
	##���·���ĺϷ���
		test -d $localpath || alertEXIT "·�� $localpath ������"

	##���ɻ�ȡ�����ļ��������б�
		gen_ftp_get_ctrl
		if [ $? -ne 0 ]; then
			printALERT "���� FTP GETCTRL �ű�ʧ��"
			continue
		fi

	##��ȡ�����������������ļ�
		cat $FTPGETCTRL | ftp -n 2>&1 >/dev/null
		if [ $? -ne 0 ]; then
			printALERT " ftp���ɼ��� $source �ɼ������ļ�ʧ��"
			continue;
		fi
##����ļ��Ƿ��ȡ��,����ļ�������������һ���ɼ���
		test -f $TTSLOCAL || continue;
		test -f $TTTLOCAL || continue;

##����readtts�����ļ��б�
		$READTTS $TTSLOCAL $FTAMGETLST
		if [ $? -ne 0 ];then
			printALERT " ���� readtts ʧ�� $TTSLOCAL $FTAMGETLST $ip"
			$READTTS $TTSLOCAL $FTAMGETLST >"$TTSLOCAL".xxx
			exit 1;
		fi
##���û��Ҫ�ɼ����ļ��б��������һ���ɼ���
		[ -f $FTAMGETLST ] || continue;
##����ļ�Ϊ���������һ���ɼ���
		size1=`ls -l  "$FTAMGETLST" | awk '{printf $5}'`
		[ $size1 -ne 0 ] || continue;

		cat $FTAMGETLST | grep -v Bad | while read namestr
		do
		
			filename=`echo "$namestr" | awk '{print $1}'`
			seq=`echo "$namestr" | awk '{print $3}'`
			createdate=`echo "$namestr" | awk '{print $2}'`

			targetname=$filename.$createdate
			
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
			$PICKCHECK $source $targetname
			ret=$?
			if [ $ret -lt 0 ]; then
				printALERT "���� $PICKCHECK ���� "
				exit 1;
			fi
			if [ $ret -gt 0 ]; then
				##printNORMAL "�ɼ��� $source ������"
				echo "$source $targetname $createdate">>$ERRTXT".$source"
			        continue;
			fi
	##��ȡ����ʼʱ��
			dealbegindate=`date +%Y%m%d%H%M%S`

	###���ɻ�ȡ�ļ�����ű�
			gen_ftp_get
			if [ $? -ne 0 ]; then
				printALERT "����FTP GET�ű�ʧ��"
				continue
			fi
	###���ɽ��޸ĺ��TTT�ļ��ͻؽ������Ľű�
			gen_ftp_put_ctrl
			if [ $? -ne 0 ]; then
				printALERT "����FTP PUT�ű�ʧ��"
				continue
			fi
	##���Զ�������ȡ�ļ�--->ע������ֱ������Ŀ���ļ���
			cat $FTPGET | ftp -n 2>&1 >/dev/null
			if [ $? -ne 0 ]; then
				printALERT "FTP��ȡ$ip��$dir�µ�$filenameʧ��"
				continue
			fi
	##����ļ������������
			[ -f $localpath/$targetnametemp ] || continue;

	#��ȡ�ɼ��ļ����ֽ���
			size1=`ls -l  "$localpath/$targetnametemp" | awk '{printf $5}'`
	##��ȡ�������ʱ��
			dealenddate=`date +%Y%m%d%H%M%S`
	##д�ɼ����ݿ���־
			msg=`$PICKLOG $source $size1 $targetname $dealbegindate $dealenddate $seq`
			ret=$?
			if [ $ret -ne 0 ]; then
				printALERT "���� $PICKLOG ���� $ret $msg";
	#ɾ���ɼ��������ļ�
				rm -f $localpath/$targetnametemp >/dev/null
				exit 1;
			fi
	##һ�����������writettt�޸� TTT�ļ�
			$WRITETTT $seq $createdate $TTTLOCAL
			if [ $? -ne 0 ];then
				printALERT " ���� writettt ʧ��"
				cp $TTTLOCAL $TTTLOCAL".tmp"
				exit 1;
			fi
	##��TTT�ļ��Żؽ�����
			cat $FTPPUTCTRL | ftp -n 2>&1 >/dev/null
			if [ $? -ne 0 ]; then
				printALERT "�� TTT �ļ� �Ż� $ip �� $dir ��ʧ��"
				cp $TTTLOCAL $TTTLOCAL".tmp"
				exit 1;
			fi
	##�ɼ���ʱ�ļ��ĵ�����ļ�			
			mv $localpath/$targetnametemp $localpath/$targetname
			if [ $? -ne 0 ]; then
				printALERT "�ƶ� mv $localpath/$targetnametemp $localpath/$targetname ʧ��"
				exit 1;
			fi
			
			printNORMAL "$source �ɹ��ɼ��ļ� $filename Ϊ $targetname �ֽ� $size1"
	###���ڼ����Ϣ�����
			echo "ʱ�䣺$dealenddate  $source �ɹ��ɼ��ļ�$filename Ϊ $targetname �ֽ� $size1 " >>$APPHOME/log/pick.sh.$source.log
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
