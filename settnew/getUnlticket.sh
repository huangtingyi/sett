#!/bin/sh
. $BILLHOME/shell/lib/libcomm.sh
. $APPHOME/shell/lib/libconst.sh

if [ $# != 3 ] ; then
	echo "Usage $0 BillDate[YYYYMM] NetWork Type"
	echo "NetWork说明：固网：GW，移网：YD"
	echo "Type说明：全部：ALL，高额：GE，超长：CC，超频：CP"
	exit 1;
fi

mypid=$$
BillDate=$1
network=$2
Type=$3
connstr=
month=
unlsqlfile=

sqlsed=$APPHOME/work/sql$mypid.sed
sqlfile=$APPHOME/work/sqlfile.$mypid
sqlfilework=$APPHOME/work/sqlfilework.$mypid

ADDTIME=$BILLHOME/bin/addtime
test -f $ADDTIME || errorEXIT "文件 $ADDTIME 不存在"


gensedcmd()
{
        rm -f $sqlsed
        echo "s/@NETWORK@/$network/g;		">>$sqlsed
        echo "s/@MONTH@/$month/g;		">>$sqlsed
        echo "s/@BILLDATE@/$BillDate/g;		">>$sqlsed
  
        
}
delete_temfile()
{
	rm -f $sqlfile
	rm -f $sqlfile.in
	rm -f $sqlsed
}
main()
{
	printNORMAL "开始抽取异常详单表。。。"
	
	connstr=$dataconnstr
	month=`echo $BillDate | cut -c 5-6`
	echo "BillDate=$BillDate,month=$month"

	if [ X"$Type" = "XALL" ];then
		unlsqlfile=$BILLHOME/sunsh/settnew/UnlTicket.sql
		
	elif [ X"$Type" = "XGE" ];then
		unlsqlfile=$BILLHOME/sunsh/settnew/UnlTicketGe.sql
		
	elif [ X"$Type" = "XCC" ];then
		unlsqlfile=$BILLHOME/sunsh/settnew/UnlTicketCc.sql
		
	elif [ X"$Type" = "XCP" ];then
		unlsqlfile=$BILLHOME/sunsh/settnew/UnlTicketCp.sql
		
	else
		printALERT "参数有误,BillDate=$BillDate,NetWork=$network,Type=$Type"
	fi
	
	test -f $unlsqlfile || errorEXIT "文件 $unlsqlfile 不存在"
	
	cat $unlsqlfile >"$sqlfile".in
	gensedcmd
	sed -f $sqlsed "$sqlfile".in > $sqlfilework
	
	##cat $sqlfilework
	
	##echo "$BILLHOME/shell/execsql.sh $connstr  $sqlfilework"
	$BILLHOME/shell/execsql.sh $connstr  $sqlfilework >/dev/null
		
	delete_temfile
	
	printNORMAL "抽取异常详单表完成！"
}
main
exit 0

