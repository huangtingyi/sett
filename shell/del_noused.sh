#!/bin/sh

###############################################################
##功能：删除/ticket/work/noused下的数据，建议每20分钟调度一次
###############################################################

path="/ticket/work/noused"
ls $path | while read tmp
do
	rm $path/$tmp
done
