#!/bin/sh

if [ $# -lt 1 ]; then
	echo "Usage $0 file . . ."
	exit 1
fi

for f in "$@" ; do

	mypid=$$
	source_name=$f
	
	if [ -d $source_name ]; then continue; fi

	temp_name=`basename $source_name`.$mypid

	tr -d '\r' < $source_name > $temp_name

	diff $source_name $temp_name

	if [ $? -ne 0 ];then
		echo "$source_name is not unix ascii"
		mv $temp_name $source_name
		exit 1
	fi
	echo "$source_name is unix ascii"
	rm $temp_name
done

echo "all file is ok..."

exit 0

