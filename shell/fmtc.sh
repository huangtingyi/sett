#!/bin/sh

if [ $# -lt 1 ]; then
	echo "Usage $0 file . . ."
	exit 1
fi

sed_name="$0".in
if ! test -f $sed_name ; then 
	echo "文件　$sed_name　不存在"
	exit 1
fi

source_name=
temp_name=


for f in "$@" ; do

	mypid=$$
	source_name=$f
	
	if [ -d $source_name ]; then continue; fi

	temp_name=`basename $source_name`.$mypid
	
	case $source_name  in
	*.h|*.c|*.pc)
		;;
	*)	
		echo "file $source_name is not c program"
		continue;
	esac

	sed -f $sed_name $source_name > $temp_name

	diff $source_name $temp_name

	if [ $? -ne 0 ];then
		echo "$source_name is not regular c program "
		mv $temp_name $source_name
		exit 1
	fi
	echo "$source_name is regular c program"
	rm $temp_name
done

echo "all file is ok..."

exit 0

