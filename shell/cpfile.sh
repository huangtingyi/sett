#!/bin/sh

. $BILLHOME/shell/lib/libcomm.sh

if [ $# != 3 ] ;
then
	echo "Usage: $0 source_path target_path filter"
	exit 1
fi

PATH=/usr/bin:/bin:/usr/sbin

SOURCE_PATH=$1
TARGET_PATH=$2
FILTER=`echo "$3" | sed s/\"//g`

main()
{
	for source_file in `/bin/find $SOURCE_PATH/ -name "$FILTER" -print`
	do
		base_file=`basename $source_file`
		target_file="$TARGET_PATH/$base_file"
#		echo "source_file=$source_file"
#		echo "target_file=$target_file"
		if [ ! -f $target_file ] ; then 
			printNORMAL "copy $source_file to $target_file" 
			cp $source_file $target_file
		fi;
	done
}

main

exit 0

