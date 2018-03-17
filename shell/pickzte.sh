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

test -f $PICKPARAM || errorEXIT "文件 $PICKPARAM 不存在"
test -f $PICKCHECK || errorEXIT "文件 $PICKCHECK 不存在"
test -f $PICKLOG || errorEXIT "文件 $PICKLOG 不存在"
test -f $PICKDUP || errorEXIT "文件 $PICKDUP 不存在"

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
#		filter="LYD*"
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
		
	##生成获取文件列表命令
		gen_ftp_nlist
		if [ $? -ne 0 ];then
			printALERT "无法生成 $FTPNLIST";
			exit 1;
		fi

	##获取对端文件列表
		cat $FTPNLIST | ftp -n 2>&1 >/dev/null
		if [ $? -ne 0 ]; then
#			printNORMAL " ftp到采集点 $source  失败"
			continue;
		fi

##如果文件不存在则继续
		[ -f $FILENAMELIST ] || continue;
##如果是不删除的标志，则调用程序对文件列表做预处理,20040827
		if [ $deletetype -eq 0 ];then
			$PICKDUP $source $FILENAMELIST
			if [ $? -ne 0 ];then
				printALERT "调用 $PICKDUP 失败";
				exit 1;
			fi
		fi
##如果文件为空则继续
		size1=`ls -l  "$FILENAMELIST" | awk '{printf $5}'`
		[ $size1 -ne 0 ] || continue;
		

		cat $FILENAMELIST | grep -v Bad | while read filename 
		do
			filename=`get_file_name $filename`

			if [ X"$filename" = "X" ]; then continue; fi

	##对filter和filename相等的情况判断
			case "$filter"  in
				"$filename")
				        continue;
				;;
				*)
				;;
			esac
	##获取文件序号
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
	##采集临时文件
			targetnametemp="$targetname"".pik"
			
	##检查是否重采
			$PICKCHECK $source $filename
			ret=$?
			if [ $ret -lt 0 ]; then
				printALERT "调用 $PICKCHECK 错误 "
				exit 1;
			fi
			if [ $ret -gt 0 ]; then
				##printNORMAL "采集点 $source 无数据" 
			        continue; 
			fi
	
	##获取处理开始时间
			dealbegindate=`date +%Y%m%d%H%M%S`
	
	##取对端文件大小
			FILESIZE=$FILESIZE1
			gen_ftp_size
			if [ $? -ne 0 ];then
				printALERT "无法生成 $FTPSIZE";
				exit 1;
			fi
			cat $FTPSIZE | ftp -n 2>&1 >/dev/null
			[ $? -eq 0 ] || alertEXIT "获取文件$filename字节失败"
			
			sleep 1
			
			FILESIZE=$FILESIZE2
			gen_ftp_size
			if [ $? -ne 0 ];then
				printALERT "无法生成 $FTPSIZE";
				exit 1;
			fi
			cat $FTPSIZE | ftp -n 2>&1 >/dev/null
			[ $? -eq 0 ] || alertEXIT "获取文件$filename字节失败"
			
			size1=`cat $FILESIZE1 | head -1 | awk '{print $5}'`
			size2=`cat $FILESIZE2 | head -1 | awk '{print $5}'`

			if [ "X$size1" != "X" ]; then
				if [ $size1 -ne $size2 ]; then continue; fi
			fi

	###生成获取和删除命令脚本
			gen_ftp_get
			if [ $? -ne 0 ];then
				printALERT "无法生成 $FTPGET";
				exit 1;
			fi
			gen_ftp_delete
			if [ $? -ne 0 ];then
				printALERT "无法生成 $FTPDELETE";
				exit 1;
			fi
			gen_ftp_rename
			if [ $? -ne 0 ];then
				printALERT "无法生成 $FTPRENAME";
				exit 1;
			fi
	##到对端主机获取文件	
			cat $FTPGET | ftp -n 2>&1 >/dev/null
			if [ $? -ne 0 ]; then 
				printALERT "FTP获取$ip的$dir下的$filename失败"
				continue
			fi	
	##如果文件不存在则继续
			[ -f $localpath/$targetnametemp ] || continue;

			if [ "X$size1" = "X" ]; then
				size1=`ls -l  "$localpath/$targetnametemp" | awk '{printf $5}'`
			fi
	##获取处理结束时间
			dealenddate=`date +%Y%m%d%H%M%S`
	##写采集数据库日志		
			msg=`$PICKLOG $source $size1 $filename $dealbegindate $dealenddate $seq`
			ret=$?
			if [ $ret -ne 0 ]; then
				printALERT "调用 $PICKLOG 错误 $ret $msg";
	#删除采集下来的文件
				rm -f $localpath/$targetnametemp >/dev/null
				exit 1;
			fi
	##对端文件处理（0 不删除  1 删除  2 备份）
			if [ $deletetype -eq 1 ]; then 
			  	cat $FTPDELETE | ftp -n 2>&1 >/dev/null
				if [ $? -ne 0 ]; then 
					printALERT "FTP删除 $ip 的 $dir 下的 $targetname 失败"
					return 1
				fi
			fi
			if [ $deletetype -eq 2 ]; then 
			  	cat $FTPRENAME | ftp -n  2>&1 >/dev/null
				if [ $? -ne 0 ]; then 
					printALERT "FTP $ip 的 $dir 下的 $targetname 备份到 $backuppath 失败"
					return 1
				fi
			fi
	##采集临时文件改到输出文件			
			mv $localpath/$targetnametemp $localpath/$targetname
			if [ $? -ne 0 ]; then
				printALERT "移动 mv $localpath/$targetnametemp $localpath/$targetname 失败"
				exit 1;
			fi
			
			printNORMAL "$source 成功采集文件 $filename 为 $targetname 字节$size1"
			###用于监控信息的输出
			echo "时间：$dealenddate  $source 成功采集文件 $filename  为 $targetname 字节$size1 " >>$APPHOME/log/pick.sh.$source.log
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
