#!/bin/sh

. $BILLHOME/shell/lib/libcomm.sh

if [ $# != 1 ] ;
then
	echo "Usage: $0 title"
	exit 1
fi

title=$1
incpath=$BILLHOME/srv/include
msg=
file_name=
base_name=
ori_def=

if [ ! -d $incpath ] ; then incpath=$BILLHOME/src/include; fi

test -d $incpath || errorEXIT "Ä¿Â¼ $incpath ²»´æÔÚ"

grep "$title" $incpath/* | while read msg
do
	file_name=`echo $msg | sed s/:.*$//`
	base_name=`basename $file_name`
	ori_def=`echo $msg | sed 's/^.*://'`

	echo $base_name
	echo $ori_def
done








