#!/bin/sh

###############################################################
##���ܣ�ɾ��/ticket/online/upd�µ����ݣ�����ÿ�����һ��
##ȷ�� /ticket/online/upd�µ��ļ�ʼ�ձ���5��
###############################################################

path="/ticket/online/upd"

find $path -mtime +60 | while read tmp
do
	rm $tmp
done
