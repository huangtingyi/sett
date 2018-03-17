#!/bin/sh
. $BILLHOME/shell/lib/libcomm.sh
if [ $# != 1 ] ; then
	echo usage $0 taskfile
	exit 1
fi

MYNAME=`basename $0`
MYPID=$$
MYTIME=

TASKFILE=$1
##������̱�ʶ�Լ���������ʱ�䣬����Ψһȷ��һ������
cur=0
pre=0
preoff=0
curoff=0
taskid=
timespan=
offset=
force=
taskcmd=

taskpid=
tasktime=
taskctlfile=
lasttime=

##��ǰϵͳ��ʱ������
nowDate=
nowYear=
nowMon=
nowDay=
nowHour=
nowMin=
nowSec=
##��ǰϵͳ��ʱ������
curYear=
curMon=
curDay=
curHour=
curMin=
curSec=

startflag=

if [ `ps -ef | grep $0 | grep $1 | grep -v grep | wc -l` -gt 1 ];then
	echo `ps -ef | grep $0 | grep $1 | grep -v grep`
	echo "�����Ѿ�����."
	exit 1
fi
getnowDATE()
{
	nowDate=`date +"%Y%m%d%H%M%S"`
	nowYear=`echo $nowDate | cut -c 1-4`
	nowMon=`echo $nowDate | cut -c 5-6`
	nowDay=`echo $nowDate | cut -c 7-8`
	nowHour=`echo $nowDate | cut -c 9-10`
	nowMin=`echo $nowDate | cut -c 11-12`
	nowSec=`echo $nowDate | cut -c 13-13`
	case $nowSec in
		0|1|2)
			nowSec=0;
		;;
		*)
			nowSec=1;
		;;
	esac
}
getcurDATE()
{
	curYear=`echo "$timespan" | sed "s/\./ /g" | awk '{print $1}`
	curMon=`echo "$timespan" | sed "s/\./ /g" | awk '{print $2}`
	curDay=`echo "$timespan" | sed "s/\./ /g" | awk '{print $3}`
	curHour=`echo "$offset" | sed "s/\./ /g" | awk '{print $1}`
	curMin=`echo "$offset" | sed "s/\./ /g" | awk '{print $2}`
	curSec=`echo "$offset" | sed "s/\./ /g" | awk '{print $3}`
	if [ "X$curSec" = "X" ]; then 
		curSec=0;
	else
		curSec=`echo $curSec%2 | bc`
	fi
}
equalTIME()
{
	source=$1
	target=$2

	[ "X$target" = "X" -o "X$target" = "Xx" ] && return 0;
	
	target=`echo $target | sed "s/\|/ /g"`

	for item in $target 
	do
		if [ $source -eq $item ]; then return 0; fi;
	done
	return 1;
}
equalSTART()
{	
	equalTIME $nowYear $curYear
	if [ $? -ne 0 ]; then
		echo "1";
		return;
	fi
	equalTIME $nowMon $curMon
	if [ $? -ne 0 ]; then
		echo "1";
		return;
	fi
	equalTIME $nowDay $curDay
	if [ $? -ne 0 ]; then
		echo "1";
		return;
	fi
	equalTIME $nowHour $curHour
	if [ $? -ne 0 ]; then
		echo "1";
		return;
	fi
	equalTIME $nowMin $curMin
	if [ $? -ne 0 ]; then
		echo "1";
		return;
	fi
	equalTIME $nowSec $curSec
	if [ $? -ne 0 ]; then
		echo "1";
		return;
	fi
	echo "0";
}
getPIDTIME()
{
	temppid=$1
	ps -ef | grep -v grep | grep "$temppid" | while read temp
	do
		if [ $temppid -eq `echo $temp | awk '{print $2}'` ]; then
			echo $temp | awk '{print $5}'
			break;
		fi		
	done
}
writePINFO()
{
	temptaskid=$1
	temptaskpid=$2
	temptasktime=$3
	echo $temptaskid $temptaskpid $temptasktime >$taskctlfile
}
readPPID()
{
	cat $taskctlfile | head -1 | awk '{print $2}'	
}
readPTIME()
{
	cat $taskctlfile | head -1 | awk '{print $3}'
}
readPTSKID()
{
	cat $taskctlfile | head -1 | awk '{print $1}'
}
startupTASK()
{
	printNORMAL "���� $taskcmd"
	nohup $taskcmd >/dev/null &
	taskpid=$!
	tasktime=`getPIDTIME $taskpid`
	if [ "X$tasktime" != "X" ];then
		printNORMAL "���� $taskid $taskcmd �ɹ�"
	else
		printNORMAL "���� $taskid $taskcmd"
	fi
	writePINFO $taskid $taskpid $tasktime
}
sleeptime()
{
	while [ 1 = 1 ];do
		sleep 1;
		second=`date +"%S"`
		if [ `echo "$second % 30 " | bc` -le 1 ];then break; fi
	done
	getnowDATE
}
main()
{
taskctlfile="$APPHOME"/ctl/"$MYNAME".txt
MYTIME=`getPIDTIME $MYPID`
writePINFO $MYNAME $MYPID $MYTIME

printNORMAL "�������ȳɹ�"

while [ 1 -eq 1 ]
do
cat $TASKFILE| sed s/#.*$// | while read temp 
do
	if [ "X$temp" = "X" ]; then continue; fi

		taskid=`echo "$temp" | sed 's/,/ /g' | awk '{print $1}'`
		timespan=`echo "$temp" | sed 's/,/ /g' | awk '{print $2}'`
		offset=`echo "$temp" | sed 's/,/ /g' | awk '{print $3}'`
		force=`echo "$temp" | sed 's/,/ /g' | sed 's/:/ /g' | awk '{print $4}'`
		taskcmd=`echo "$temp" |  sed 's/.*://'`
	
	taskctlfile="$APPHOME"/ctl/"$taskid".txt

##��ģʽ����������
	startflag="false";
	
	if [ `echo $timespan | grep "\." | wc -l` -eq 0 ];then
##��ģʽ��������

		preoff=`echo $pre-$pre/$timespan*$timespan | bc`
		curoff=`echo $cur-$cur/$timespan*$timespan | bc`
#echo -- $timespan $offset $preoff $offset $curoff ---- $cur $pre

		[ $pre -ne 0 ] && [ $offset -ge $preoff ] && [ $offset -le $curoff ] && startflag="true";

	else
##��ģʽ����������
		getcurDATE
		if [ `equalSTART` = "0" ]; then
			startflag="true";
		fi	
	fi

	if [ "$startflag" = "true" ]; then
	
##��������ļ�������������֮
		if [ ! -f $taskctlfile ];then
			startupTASK
			continue;
		fi

###�������Ѿ�ͣ���򲻴���
		if [ `readPTSKID` = "stopped" ];then continue; fi
		
###������Ҫ�����ͣ����ͣ��
		if [ `readPTSKID` = "stop" ];then
			printNORMAL "���� $taskid ���������ֹͣ"
			writePINFO "stopped" "stopped" "stopped"
			continue
		fi

###������Ҫ���������������
		if [ `readPTSKID` = "start" ];then
			printNORMAL "���� $taskid �������������"
			startupTASK
			continue
		fi

		taskpid=`readPPID`
		tasktime=`getPIDTIME $taskpid`

##������̲�����������
		if [ "X$tasktime" = "X" ];then
			startupTASK
			continue	
		fi
		lasttime=`readPTIME`
##������̱�ʶ�ѱ�ʹ��������
		if [ "$tasktime" != "$lasttime" ];then
			startupTASK
			continue	
		fi
##�����Ҫǿ������������
		if [ $force -eq 0 ];then
			printNORMAL "���� $taskid $taskcmd���г�ʱ,�޷�����"
			continue;
		fi

##ɱ���̲�����
		printNORMAL "���� $taskid $taskcmd���г�ʱ�������"
		kill -9 $taskpid
		startupTASK		
	fi
done

sleeptime

pre=$cur;
cur=`echo $nowHour*360+$nowMin*6+$nowSec*3 | bc`

#echo $nowHour*360+$nowMin*6+$nowSec*3 -----------$cur --------------

taskctlfile="$APPHOME"/ctl/"$MYNAME".txt
if [ `readPTSKID` = "stop" ]; then
	printNORMAL "�ӵ��˳��ź�,�����˳�"
	break;
fi

done
}
main
exit 0
