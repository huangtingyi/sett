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

test -f $PICKPARAM || errorEXIT "文件 $PICKPARAM 不存在"
test -f $PUTCHECK || errorEXIT "文件 $PUTCHECK 不存在"
test -f $PUTLOG || errorEXIT "文件 $PUTLOG 不存在"
test -f $FILEMODIFYDIFF || errorEXIT "文件 $FILEMODIFYDIFF 不存在"
FTPPUT=$APPHOME/work/ftpput$mypid.txt
FTPDELETE=$APPHOME/work/ftpdelete$mypid.txt
FTPRENAME=$APPHOME/work/ftprename$mypid.txt
FILENAMELIST=$APPHOME/work/pickfilename$mypid.lst
ping_oppip()
{
    	result=`/usr/sbin/ping -c 2 $ip | grep "100%" | wc -l`
        if [ $result -ne 0 ]; then
                printALERT "目标IP不通！！！！"
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
	echo "put $tempname"  	>>$FTPPUT
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
	echo "delete $filename"  >>$FTPDELETE
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
delete_ftp_ctl()
{
	rm -f $FTPPUT; 2>/dev/null
	rm -f $FTPDELETE; 2>/dev/null
	rm -f $FTPRENAME; 2>/dev/null
	rm -f $FILENAMELIST; 2>/dev/null
	
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
		ifdelfile=`echo "$temp" | awk '{print $12}'`

	##用户无密码时转换
		if [ X"$passwd" = "Xpasswd" ]; then
			passwd="" 
		fi
	##检查路径的合法性
		test -d $localpath || alertEXIT "路径 $localpath 不存在"
		test -d $backuppath || alertEXIT "路径 $backuppath 不存在"

	##备份主机是否能通	
	ping_oppip    
	##清除预处理文件列表
	cat /dev/null >$FILENAMELIST
	##获取文件处理列表
        ls -rt $localpath/  >$FILENAMELIST

	##如果文件为空则继续
		size1=`ls -l  "$FILENAMELIST" | awk '{printf $5}'`
		[ $size1 -ne 0 ] || continue;
		

		cat $FILENAMELIST | grep -v Bad | while read filename 
		do
			filename=`get_file_name $filename`
			if  [ X"$filename" = "X" ];then continue; fi
			[ `$FILEMODIFYDIFF $localpath/$filename` -lt 60 ] && break;
		
	
			size=`ls -l $localpath/$filename | awk '{print $5}'`
		##检查是否重采
			$PUTCHECK $source $filename
			ret=$?
			if [ $ret -lt 0 ]; then
				printALERT "调用 $PUTCHECK 错误 "
				exit 1;
			fi
			if [ $ret -gt 0 ]; then
				##printNORMAL "采集点 $source 无数据" 
			        continue; 
			fi
	
		##获取文件序号
			seq=`echo $filename | cut -c $seqbegin-$seqend`
		##获取处理开始时间
			dealbegindate=`date +%Y%m%d%H%M%S`

		##指定处理文件
			tempname=$filename
			#mv $localpath/$filename $localpath/$filename
			#if [ $? -ne 0 ]; then
			#	printALERT "移动 $localpath/$filename $localpath/$filename 失败"
			#	exit 1;
			#fi
		
		###生成获取和删除命令脚本
			gen_ftp_put
			if [ $? -ne 0 ];then
				printALERT "无法生成 $FTPPUT";
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
			
		#######是传到目标主机
			cat $FTPPUT | ftp -n 2>&1 >/dev/null
			if [ $? -ne 0 ]; then 
				printALERT "$filename 文件PUT上传到$ip的$opppath下失败"
				failcnt=`echo $failcnt+1 | bc`
				if [ $failcnt -gt 10 ]; then
					printALERT "文件失败太多,大于10,退出"
					exit 1;
				fi
				continue; 
			fi

		##获取处理结束时间
			dealenddate=`date +%Y%m%d%H%M%S`
		##写采集数据库日志		
			$PUTLOG $source $size $filename $dealbegindate $dealenddate $seq
			ret=$?
			if [ $ret -ne 0 ]; then
				printALERT "调用 $PUTLOG 错误 $ret ";
				##入库失败删除对端文件
			  	cat $FTPDELETE | ftp -n 2>&1 >/dev/null
				if [ $? -ne 0 ]; then 
					printALERT "FTP删除$ip的$opppath下的$filename失败"
					return 1
				fi
				exit 1;
			fi
		##对对端文件改名			
			#cat $FTPRENAME | ftp -n  2>&1 >/dev/null
			#if [ $? -ne 0 ]; then 
			#	printALERT "FTP$ip的$dir下的$filename备份到$backuppath失败"
			#	return 1
			#fi
			
		##文件处理（0 不删除  1 删除  2 备份）
			case $ifdelfile in 
			1)
				rm -f $localpath/$filename 2>/dev/null
				[ $? -eq 0 ] || alertEXIT "rm -f $localpath/$filename失败"
				;;
			2)
				mv $localpath/$filename  $backuppath/$filename
				[ $? -eq 0 ] || alertEXIT "mv $tempname $backuppath/$filename失败"
				;;
			*)
				;;
			esac

			printNORMAL "$source 成功传送文件$filename 字节$size"
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
