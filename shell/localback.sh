#!/bin/sh
. $BILLHOME/shell/lib/libcomm.sh
if [ $# != 5 ] ; then
	echo usage $0 oppip  oppuser opppasswd  opppath connstr
	exit 1
fi

mypid=$$
oppip=$1
oppuser=`echo "$2" | sed s/\"//g`
opppasswd=`echo "$3" | sed s/\"//g`
opppath=`echo "$4" | sed s/\"//g`
connstr=$5

OSNAME=`uname -s`
appzip=
suffix=

if [ $OSNAME = "Linux" ];then
	appzip="gzip -f"
	suffix=".gz"
else
	appzip="compress -f"
	suffix=".Z"
fi

day=`date +%Y%m%d`
FTPPUTLIST=$APPHOME/work/ftpput$mypid.txt
localpath=$APPHOME/work
filename=
paramname=param$day.dmp
localname=local$day.tar

if [ ! -d $localpath ]; then
	printALERT "路径$localpath不合法"
	exit 1
fi

ping_oppip()
{
    	result=`/usr/sbin/ping -c 2 $oppip | grep "100%" | wc -l`
        if [ $result -eq 0 ]; then
		printNORMAL "目标IP正常"
        else
		printALERT "目标IP不通！！！！"
		exit 1
        fi
}
gen_ftp_put()
{
	cat /dev/null > $FTPPUTLIST 2>/dev/null
	echo "open $oppip"  	>>$FTPPUTLIST
	echo "user $oppuser $opppasswd" >>$FTPPUTLIST
	echo "prom"		>>$FTPPUTLIST
	echo "bin"		>>$FTPPUTLIST
	echo "cd $opppath" 	>>$FTPPUTLIST
	echo "lcd $localpath" 	>>$FTPPUTLIST
	echo "put $filename"  	>>$FTPPUTLIST
	echo "by"		>>$FTPPUTLIST
}
gen_backfile()
{
	cd $localpath;
	mkdir local;
	cd local;
	mkdir expr;
	cp $BILLHOME/expr/*.expr expr
	mkdir shell;
	cp $BILLHOME/shell/*.sh shell
	cp $BILLHOME/shell/*.in shell
	cp $BILLHOME/shell/*.sql shell
	cp -r $BILLHOME/shell/lib shell/lib
	mkdir ini;
	cp $APPHOME/shell/*.lst ini
	cp $APPHOME/shell/*.ini ini
	cp $APPHOME/shell/*.sql ini
	cp $APPHOME/shell/*.in  ini
	cp $APPHOME/shell/*.sh  ini
	cp $APPHOME/shell/*.ctl  ini
	cp $APPHOME/shell/httpd.conf ini
	cp -r $APPHOME/shell/htdocs ini/htdocs
	cp -r $APPHOME/shell/mo ini/mo
	cd $localpath;
	tar cvf $localname local
	rm -rf local;
	cd $APPHOME/shell

}
delete_tmp_file()
{
	rm -f $FTPPUTLIST; 2>/dev/null
	rm -f $localpath/$paramname"$suffix"; 2>/dev/null
	rm -f $localpath/$localname"$suffix"; 2>/dev/null
}
#####*/
main()
{
cat /dev/null > $FTPPUTLIST 2>/dev/null
#######备份主机是否能通
	ping_oppip
#######备份参数用户
	exp $connstr  FILE=$localpath/$paramname  OWNER=param
	if [ $? -ne 0 ];then
		printALERT "导出参数用户param失败！"
		 exit 1
	fi
#######拷贝一份参数用户文件到veritas备份目录
	mkdir -p $APPHOME/tar/paramdata/$day
	if [ $? -ne 0 ];then
		printALERT "创建目录 $APPHOME/tar/paramdata/$day 失败";
		exit 1;
	fi

	$appzip $localpath/$paramname

	cp $localpath/$paramname"$suffix" $APPHOME/tar/paramdata/$day
	if [ $? -ne 0 ];then
		printALERT "拷贝参数用户文件到veritas备份目录失败";
		exit 1;
	fi
#######生成put命令脚本
	filename=$paramname"$suffix"
	gen_ftp_put
	if [ $? -ne 0 ];then
		printALERT "无法生成 $FTPPUTLIST";
		exit 1;
	fi
#######备份到主机
	cat $FTPPUTLIST | ftp -n 2>&1 >/dev/null
	if [ $? -ne 0 ]; then
		printALERT "$filename 上传 $oppip $opppath 失败"
		exit 1;
	fi
	printNORMAL "$filename 上传 $oppip $opppath 成功！"

#######备份本地配置及公式
	gen_backfile

	$appzip $localpath/$localname

#######拷贝一份本地配置文件到veritas备份目录
	cp $localpath/$localname"$suffix" $APPHOME/tar/paramdata/$day
	if [ $? -ne 0 ];then
		printALERT "拷贝本地配置文件到veritas备份目录失败";
		exit 1;
	fi

#######生成put命令脚本
	filename=$localname"$suffix"
	gen_ftp_put
	if [ $? -ne 0 ];then
		printALERT "无法生成 $FTPPUT";
		exit 1;
	fi
#######备份到主机
	cat $FTPPUTLIST | ftp -n 2>&1 >/dev/null
	if [ $? -ne 0 ]; then
		printALERT "$filename 上传 $oppip $opppath 失败"
		exit 1;
	fi
	printNORMAL "$filename 上传 $oppip $opppath 成功！"

	delete_tmp_file
	if [ $? -ne 0 ]; then
		printALERT "删除 $mypid备份的控制文件错误"
		exit 1;
	fi
}
main
exit 0




