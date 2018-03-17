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

test -f $PICKPARAM || errorEXIT "文件 $PICKPARAM 不存在"
test -f $PICKCHECK || errorEXIT "文件 $PICKCHECK 不存在"
test -f $PICKLOG || errorEXIT "文件 $PICKLOG 不存在"
test -f $READTTS || errorEXIT "文件 $READTTS 不存在"
test -f $WRITETTT || errorEXIT "文件 $WRITETTT 不存在"

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
	##去掉空行
		if [ X"$temp" = "X" ];then continue; fi
	##判断是否是本进程处理
		group=`echo "$temp" | awk '{print $1}'`
		if [ $group != $procgrp ];then continue; fi

	##获取基本参数
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

	##用户无密码时转换
		if [ X"$passwd" = "Xpasswd" ]; then
			passwd=""
		fi
	##检查路径的合法性
		test -d $localpath || alertEXIT "路径 $localpath 不存在"

	##生成获取控制文件的命令列表
		gen_ftp_get_ctrl
		if [ $? -ne 0 ]; then
			printALERT "生成 FTP GETCTRL 脚本失败"
			continue
		fi

	##获取交换机的两个控制文件
		cat $FTPGETCTRL | ftp -n 2>&1 >/dev/null
		if [ $? -ne 0 ]; then
			printALERT " ftp到采集点 $source 采集控制文件失败"
			continue;
		fi
##检查文件是否获取到,如果文件不存在则处理下一个采集点
		test -f $TTSLOCAL || continue;
		test -f $TTTLOCAL || continue;

##调用readtts生成文件列表
		$READTTS $TTSLOCAL $FTAMGETLST
		if [ $? -ne 0 ];then
			printALERT " 调用 readtts 失败 $TTSLOCAL $FTAMGETLST $ip"
			$READTTS $TTSLOCAL $FTAMGETLST >"$TTSLOCAL".xxx
			exit 1;
		fi
##如果没有要采集的文件列表则继续下一个采集点
		[ -f $FTAMGETLST ] || continue;
##如果文件为空则继续下一个采集点
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
	##采集临时文件
			targetnametemp="$targetname"".pik"
		
	##检查是否重采
			$PICKCHECK $source $targetname
			ret=$?
			if [ $ret -lt 0 ]; then
				printALERT "调用 $PICKCHECK 错误 "
				exit 1;
			fi
			if [ $ret -gt 0 ]; then
				##printNORMAL "采集点 $source 无数据"
				echo "$source $targetname $createdate">>$ERRTXT".$source"
			        continue;
			fi
	##获取处理开始时间
			dealbegindate=`date +%Y%m%d%H%M%S`

	###生成获取文件命令脚本
			gen_ftp_get
			if [ $? -ne 0 ]; then
				printALERT "生成FTP GET脚本失败"
				continue
			fi
	###生成将修改后的TTT文件送回交换机的脚本
			gen_ftp_put_ctrl
			if [ $? -ne 0 ]; then
				printALERT "生成FTP PUT脚本失败"
				continue
			fi
	##到对端主机获取文件--->注意这里直接生成目标文件了
			cat $FTPGET | ftp -n 2>&1 >/dev/null
			if [ $? -ne 0 ]; then
				printALERT "FTP获取$ip的$dir下的$filename失败"
				continue
			fi
	##如果文件不存在则继续
			[ -f $localpath/$targetnametemp ] || continue;

	#获取采集文件的字节数
			size1=`ls -l  "$localpath/$targetnametemp" | awk '{printf $5}'`
	##获取处理结束时间
			dealenddate=`date +%Y%m%d%H%M%S`
	##写采集数据库日志
			msg=`$PICKLOG $source $size1 $targetname $dealbegindate $dealenddate $seq`
			ret=$?
			if [ $ret -ne 0 ]; then
				printALERT "调用 $PICKLOG 错误 $ret $msg";
	#删除采集下来的文件
				rm -f $localpath/$targetnametemp >/dev/null
				exit 1;
			fi
	##一切正常后调用writettt修改 TTT文件
			$WRITETTT $seq $createdate $TTTLOCAL
			if [ $? -ne 0 ];then
				printALERT " 调用 writettt 失败"
				cp $TTTLOCAL $TTTLOCAL".tmp"
				exit 1;
			fi
	##将TTT文件放回交换机
			cat $FTPPUTCTRL | ftp -n 2>&1 >/dev/null
			if [ $? -ne 0 ]; then
				printALERT "将 TTT 文件 放回 $ip 的 $dir 下失败"
				cp $TTTLOCAL $TTTLOCAL".tmp"
				exit 1;
			fi
	##采集临时文件改到输出文件			
			mv $localpath/$targetnametemp $localpath/$targetname
			if [ $? -ne 0 ]; then
				printALERT "移动 mv $localpath/$targetnametemp $localpath/$targetname 失败"
				exit 1;
			fi
			
			printNORMAL "$source 成功采集文件 $filename 为 $targetname 字节 $size1"
	###用于监控信息的输出
			echo "时间：$dealenddate  $source 成功采集文件$filename 为 $targetname 字节 $size1 " >>$APPHOME/log/pick.sh.$source.log
		done
	done

	delete_ftp_ctl
	if [ $? -ne 0 ]; then
		printALERT "删除 $mypid采集的控制文件错误"
		exit 1;
	fi
}
main
exit 0
