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
	printALERT "·��$localpath���Ϸ�"
	exit 1
fi

ping_oppip()
{
    	result=`/usr/sbin/ping -c 2 $oppip | grep "100%" | wc -l`
        if [ $result -eq 0 ]; then
		printNORMAL "Ŀ��IP����"
        else
		printALERT "Ŀ��IP��ͨ��������"
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
#######���������Ƿ���ͨ
	ping_oppip
#######���ݲ����û�
	exp $connstr  FILE=$localpath/$paramname  OWNER=param
	if [ $? -ne 0 ];then
		printALERT "���������û�paramʧ�ܣ�"
		 exit 1
	fi
#######����һ�ݲ����û��ļ���veritas����Ŀ¼
	mkdir -p $APPHOME/tar/paramdata/$day
	if [ $? -ne 0 ];then
		printALERT "����Ŀ¼ $APPHOME/tar/paramdata/$day ʧ��";
		exit 1;
	fi

	$appzip $localpath/$paramname

	cp $localpath/$paramname"$suffix" $APPHOME/tar/paramdata/$day
	if [ $? -ne 0 ];then
		printALERT "���������û��ļ���veritas����Ŀ¼ʧ��";
		exit 1;
	fi
#######����put����ű�
	filename=$paramname"$suffix"
	gen_ftp_put
	if [ $? -ne 0 ];then
		printALERT "�޷����� $FTPPUTLIST";
		exit 1;
	fi
#######���ݵ�����
	cat $FTPPUTLIST | ftp -n 2>&1 >/dev/null
	if [ $? -ne 0 ]; then
		printALERT "$filename �ϴ� $oppip $opppath ʧ��"
		exit 1;
	fi
	printNORMAL "$filename �ϴ� $oppip $opppath �ɹ���"

#######���ݱ������ü���ʽ
	gen_backfile

	$appzip $localpath/$localname

#######����һ�ݱ��������ļ���veritas����Ŀ¼
	cp $localpath/$localname"$suffix" $APPHOME/tar/paramdata/$day
	if [ $? -ne 0 ];then
		printALERT "�������������ļ���veritas����Ŀ¼ʧ��";
		exit 1;
	fi

#######����put����ű�
	filename=$localname"$suffix"
	gen_ftp_put
	if [ $? -ne 0 ];then
		printALERT "�޷����� $FTPPUT";
		exit 1;
	fi
#######���ݵ�����
	cat $FTPPUTLIST | ftp -n 2>&1 >/dev/null
	if [ $? -ne 0 ]; then
		printALERT "$filename �ϴ� $oppip $opppath ʧ��"
		exit 1;
	fi
	printNORMAL "$filename �ϴ� $oppip $opppath �ɹ���"

	delete_tmp_file
	if [ $? -ne 0 ]; then
		printALERT "ɾ�� $mypid���ݵĿ����ļ�����"
		exit 1;
	fi
}
main
exit 0




