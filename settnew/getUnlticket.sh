#!/bin/sh
. $BILLHOME/shell/lib/libcomm.sh
. $APPHOME/shell/lib/libconst.sh

if [ $# != 3 ] ; then
	echo "Usage $0 BillDate[YYYYMM] NetWork Type"
	echo "NetWork˵����������GW��������YD"
	echo "Type˵����ȫ����ALL���߶GE��������CC����Ƶ��CP"
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
test -f $ADDTIME || errorEXIT "�ļ� $ADDTIME ������"


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
	printNORMAL "��ʼ��ȡ�쳣�굥������"
	
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
		printALERT "��������,BillDate=$BillDate,NetWork=$network,Type=$Type"
	fi
	
	test -f $unlsqlfile || errorEXIT "�ļ� $unlsqlfile ������"
	
	cat $unlsqlfile >"$sqlfile".in
	gensedcmd
	sed -f $sqlsed "$sqlfile".in > $sqlfilework
	
	##cat $sqlfilework
	
	##echo "$BILLHOME/shell/execsql.sh $connstr  $sqlfilework"
	$BILLHOME/shell/execsql.sh $connstr  $sqlfilework >/dev/null
		
	delete_temfile
	
	printNORMAL "��ȡ�쳣�굥����ɣ�"
}
main
exit 0

