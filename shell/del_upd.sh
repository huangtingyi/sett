#!/bin/sh

###############################################################
##功能：删除/ticket/online/upd下的数据，建议每天调度一次
##确保 /ticket/online/upd下的文件始终保留5天
###############################################################

path="/ticket/online/upd"

find $path -mtime +60 | while read tmp
do
	rm $tmp
done
