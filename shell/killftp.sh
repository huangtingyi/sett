#!/bin/sh
. $BILLHOME/shell/lib/libcomm.sh

mypid=$$

killpid=
deadps=
ppid=

##Ĭ��ʱ��4����
delaySecond=240

ADDTIME=$BILLHOME/bin/addtime

test -f $ADDTIME || errorEXIT "�ļ� $ADDTIME ������"

##��ʱ�ļ�������
psinfo=$APPHOME/work/ps$mypid.info

ps -ef | grep "^bill" | grep "ftp -n" > $psinfo

cat $psinfo | while read deadps
do
	ppid=`echo $deadps | awk '{print $3}'`
	
	tmptime=`echo $deadps | awk '{print $5}'`
	
	mytime="`echo $tmptime | cut -c 1-2`""`echo $tmptime | cut -c 4-5`""`echo $tmptime | cut -c 7-8`"
	runtime=`date +"%Y%m%d"`"$mytime"
	hosttime=`date +"%Y%m%d%H%M%S"`	
	stoptime=`$ADDTIME $runtime $delaySecond`

	killpid=`echo $deadps | awk '{print $2}'`

echo "$stoptime $hosttime $runtime"

	##������г���ʱ4����
	if [ "$stoptime" -lt "$hosttime" ];then
	        kill -9 $killpid
	        printNORMAL "��ʱ:ɱ������ pid=$killpid" "��ϸ��Ϣ $deadps"
	fi

	##������г������ĳ���4����
	if [ "$runtime" -gt "$hosttime" -a "$mytime" -lt 235600 ];then
	        kill -9 $killpid
	        printNORMAL "��ʱ:ɱ������ pid=$killpid" "��ϸ��Ϣ $deadps"
	fi
	##���г��򸸽���û�ˣ�Ҳ��ɱ��
        if [ $ppid = "1" ];
        then
	        kill -9 $killpid
	        printNORMAL "�¶�:ɱ������ pid=$killpid" "��ϸ��Ϣ $deadps"
	fi
done

rm $psinfo

exit 0

