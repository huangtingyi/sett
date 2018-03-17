#!/bin/sh

. $BILLHOME/shell/lib/libcomm.sh


logline=$2
PROCEDFILELOG=$1


main ()
{



##�ж���־�ļ���С,���������ָ������,����ļ�
if [ -f $PROCEDFILELOG ] ; then
	linecnt=`wc -l $PROCEDFILELOG | awk '{print $1}'`
	if [ $linecnt -gt $logline ] ; then
		flush_file_log
	fi  
fi


}


flush_file_log()
{
	$tmpfile=$PROCEDFILELOG.tmp
	echo "mv $PROCEDFILELOG $tmpfile"
	mv $PROCEDFILELOG $tmpfile
	tail -1 $tmpfile > $PROCEDFILELOG
	rm $tmpfile
}

main

exit 0
