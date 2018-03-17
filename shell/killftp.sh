#!/bin/sh
. $BILLHOME/shell/lib/libcomm.sh

mypid=$$

killpid=
deadps=
ppid=

##默认时延4分钟
delaySecond=240

ADDTIME=$BILLHOME/bin/addtime

test -f $ADDTIME || errorEXIT "文件 $ADDTIME 不存在"

##临时文件名定义
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

	##如果运行程序超时4分钟
	if [ "$stoptime" -lt "$hosttime" ];then
	        kill -9 $killpid
	        printNORMAL "超时:杀死进程 pid=$killpid" "详细信息 $deadps"
	fi

	##如果运行程序隔天的超过4分钟
	if [ "$runtime" -gt "$hosttime" -a "$mytime" -lt 235600 ];then
	        kill -9 $killpid
	        printNORMAL "超时:杀死进程 pid=$killpid" "详细信息 $deadps"
	fi
	##运行程序父进程没了，也将杀死
        if [ $ppid = "1" ];
        then
	        kill -9 $killpid
	        printNORMAL "孤儿:杀死进程 pid=$killpid" "详细信息 $deadps"
	fi
done

rm $psinfo

exit 0

