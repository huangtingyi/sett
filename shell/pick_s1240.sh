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
test -f $PICKPARAM || errorEXIT "文件 $PICKPARAM 不存在"
test -f $PICKCHECK || errorEXIT "文件 $PICKCHECK 不存在"
test -f $PICKLOG || errorEXIT "文件 $PICKLOG 不存在"

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
		filetype=`echo "$temp" | awk '{print $13}'`
		appid=`echo "$temp" | awk '{print $14}'`
		tacheid=`echo "$temp" | awk '{print $15}'`

	##用户无密码时转换
		if [ X"$passwd" = "Xpasswd" ]; then
			passwd="" 
		fi
	##检查路径的合法性
		test -d $localpath || alertEXIT "路径 $localpath 不存在"
	
	##先找FULL的
	##生成获取文件列表命令
		gen_ftp_nlist
		if [ $? -ne 0 ];then
			printALERT "无法生成 $FTPNLIST";
			exit 1;
		fi

	##获取对端文件列表
		cat $FTPNLIST | ftp -n 2>&1 >/dev/null
		if [ $? -ne 0 ]; then
			continue;
		fi

	##如果文件存在则存到中间文件
		if [ -f $FILENAMELIST ]; then
			cat $FILENAMELIST | while read temp
			do
				echo $temp "FULL">> $FILENAMELIST_a 2>/dev/null
			done
		fi

	##再找READ的
		opppathtmp=$opppath
		opppath=`echo "$opppathtmp" | sed s/\FULL/READ/g`
	
	##生成获取文件列表命令
		gen_ftp_nlist
		if [ $? -ne 0 ];then
			printALERT "无法生成 $FTPNLIST";
			exit 1;
		fi
		
		cat $FTPNLIST | ftp -n 2>&1 >/dev/null
		if [ $? -ne 0 ]; then
			continue;
		fi

##如果文件存在则存到中间文件
		if [ -f $FILENAMELIST ]; then
			cat $FILENAMELIST | while read temp
			do
				echo $temp "READ">> $FILENAMELIST_a 2>/dev/null
			done
		fi
		
##如果文件不存在则继续
		[ -f $FILENAMELIST_a ] || continue;

		cat $FILENAMELIST_a > $FILENAMELIST 2>/dev/null
		cat /dev/null > $FILENAMELIST_a 2>/dev/null

##检查文件列表是否在控制文件中
		cat $FILENAMELIST | while read filename_temp
		do
			dirfile_name=`echo $filename_temp | awk '{print $1}'`
			
			datetemp=`echo $filename_temp | awk '{print $2}'`
			datestr1=`echo $datetemp | cut -c 3-4`
			datestr2=`echo $datetemp | cut -c 6-7`
			datestr3=`echo $datetemp | cut -c 9-10`
			datestr="."$datestr1"$datestr2"$datestr3
			
			file_name=`basename $dirfile_name`
		##获取文件序号
			seq=`echo $file_name | cut -c $seqbegin-$seqend`
			inseq=`echo $seq | cut -c 3-5`
			file_module=`echo $file_name | cut -c 1-6`

			chkseq="S"$inseq

			chktmp=`$GETS1240FILENAMESH $file_module $source $chkseq`
			ret=$?;
			if [ $ret -ne 0 ]; then
				printALERT "调用 $GETS1240FILENAMESH $file_module $source $chkseq 错误";
				exit 1;
			fi
			
			chkfilter=`echo $filename_temp | awk '{print $5}'`
			
			if [ X$chkfilter = "XFULL" ];then	
				##FULL目录全采
				chktmp="XX"
			fi			

			if [ X$chktmp = "XOK" ];then	
				##文件已采过
				continue;
			fi
			file_seq="F"$inseq
			echo "$dirfile_name $datestr $file_module $file_seq" >> $FILENAMELIST_b
			
			chktemp=`grep $file_module $FILENAMELIST_a`
			if [ X$chktemp = "X" ];then	
				##为空写到文件
				echo "$file_module" >> $FILENAMELIST_a
			fi			
		done

##对需要进行采集的文件列表按控制文件系列号进行排序
		cat /dev/null > $FILENAMELIST 2>/dev/null

		cat $FILENAMELIST_a | while read str_temp
		do
			if [ X$str_temp = "X" ];then continue; fi

			file_module=`echo $str_temp | awk '{print $1}'`

			file_cnt=`grep $file_module $FILENAMELIST_b |wc | awk '{print $1}'`
			
			ctlseq_min=`$GETS1240FILENAMESH $file_module $source`
			ret=$?;
			if [ $ret -ne 0 ]; then
				printALERT "调用 $GETS1240FILENAMESH $file_module $source 错误";
				exit 1;
			fi
			ctlseq=$ctlseq_min
			
			while [ file_cnt -ne 0 ]; do
				file_seq="F"$ctlseq
				temp=`grep $file_module $FILENAMELIST_b |grep $file_seq`

				if [ X"$temp" != "X" ];then	
					##写到文件
					 echo "$temp" >> $FILENAMELIST
				else
					##断号则不再继续取文件
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
		
##如果文件为空则继续
cat $FILENAMELIST
		size1=`ls -l  "$FILENAMELIST" | awk '{printf $5}'`
		[ $size1 -ne 0 ] || continue;
		
		
		cat $FILENAMELIST | grep -v Bad | while read tempstr
		do
			
			if [ X"$tempstr" = "X" ]; then continue; fi
			
			dirfilename=`echo $tempstr | awk '{print $1}'`
			datestr=`echo $tempstr | awk '{print $2}'`
			filename=`basename $dirfilename`
			
		##获取文件序号
			seq=`echo $filename | cut -c $seqbegin-$seqend`

			inseq=`echo $seq | cut -c 3-5`
			file_module=`echo $filename | cut -c 1-6`

			insseqstr="I"$inseq

			filename=$filename"$datestr"
		##采集临时文件
			targetnametemp="s1240"$filename".pik"

		##检查是否重采--不处理这个
		##	$PICKCHECK $source $filename
		##	ret=$?
		##	if [ $ret -lt 0 ]; then
		##		printALERT "调用 $PICKCHECK 错误 "
		##		exit 1;
		##	fi
		##	if [ $ret -gt 0 ]; then
		##		##printNORMAL "采集点 $source 无数据" 
		##	        continue; 
		##	fi

				
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
			
			size1=`cat $FILESIZE1 | head -1 | awk '{print $4}'`
			size2=`cat $FILESIZE2 | head -1 | awk '{print $4}'`

			if [ "X$size1" != "X" ]; then
				if [ $size1 != $size2 ]; then continue; fi
			fi

			sizechk=`echo $size2 *2048 | bc`

		###生成获取命令脚本
			gen_ftp_get
			if [ $? -ne 0 ];then
				printALERT "无法生成 $FTPGET";
				exit 1;
			fi

		##到对端主机获取文件	
			cat $FTPGET | ftp -n 2>&1 >/dev/null
			if [ $? -ne 0 ]; then 
				printALERT "FTP获取$ip的$dir下的$filename失败"
				continue
			fi
			size1=`ls -l  "$localpath/$targetnametemp" | awk '{printf $5}'`
		##本地文件字节数据与文件列表不一致则退出
			if [ $sizechk -ne $size1 ];then
				rm -f $localpath/$targetnametemp >/dev/null
				exit 1;
			fi			
			
			
		##获取处理结束时间
			dealenddate=`date +%Y%m%d%H%M%S`
		##写采集数据库日志
		##echo "$PICKLOG $source $size1 $filename $dealbegindate $dealenddate $seq $filetype $tacheid $appid"
			$PICKLOG $source $size1 $filename $dealbegindate $dealenddate $seq $filetype $tacheid $appid
			ret=$?
			if [ $ret -ne 0 ]; then
				printALERT "调用 $PICKLOG 错误 $ret ";
	
				rm -f $localpath/$targetnametemp >/dev/null
				exit 1;
			fi

		##把采集成功的文件号写入控制文件中
			instmp=`$GETS1240FILENAMESH $file_module $source $insseqstr`
			ret=$?;
			if [ $ret -ne 0 ]; then
				printALERT "调用 $GETS1240FILENAMESH $file_module $source $insseqstr 错误";
	
				rm -f $localpath/$targetnametemp >/dev/null
				exit 1;
			fi

			mv $localpath/$targetnametemp $localpath/$filename
			if [ $? -ne 0 ]; then
				printALERT "移动 mv $localpath/$targetnametemp $localpath/$filename 失败"
				exit 1;
			fi


			printNORMAL "$source 成功采集文件$filename 字节$size1"
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
