#!/bin/sh

. $BILLHOME/shell/lib/libcomm.sh

if [ $# != 1 ] ; then
	echo usage $0 listfile
	exit 1
fi

RESTOREPARAM=$1

temp=
daterule=
filename=
bkupdir=
destdir=
filter=

DIRNAMELIST=$0.d.tmp

main()
{
cat $RESTOREPARAM| sed s/#.*$// | while read temp 
do

	if [ X"$temp" = "X" ];then continue; fi
	
	bkupdir=`echo $temp | awk '{print $1}'`	
	destdir=`echo $temp | awk '{print $2}'`
	#filter=`echo $temp | awk '{print $2}' | sed s/\"//g`	
	
	ls -l $bkupdir | sed -n '/^d./p' |sed -e 's/^d.* //' >$DIRNAMELIST
	
       cat $DIRNAMELIST | grep -v Bad | while read dirname
       do

               if  [ X"$dirname" = "X" ];then break; fi
                                           
               for filename in  `find $bkupdir/$dirname/ -name "*.Z" -print`               
	       do
		
			if [ "X$filename" = "X" ]; then break; fi
			
			basename=`basename $filename`
			resfilename=`echo $basename | sed -e 's/.Z//'`
			
			#�ȱ���һ���ļ�
			cp $filename $bkupdir/$dirname/$basename.tmp
			
			uncompress $filename
			if [ $? -ne 0 ];then
				printALERT "��ѹ�ļ�$filename ����"
				exit 1
			fi
						
			mv $bkupdir/$dirname/$resfilename $destdir/$resfilename
			if [ $? -ne 0 ];then
				printALERT "�ƶ��ļ�$bkupdir/$dirname/$resfilename��$destdir ����"
				exit 1
			fi
			
			mv $bkupdir/$dirname/$basename.tmp $filename
			if [ $? -ne 0 ];then
				printALERT "�ƶ��ļ�$bkupdir/$dirname/$basename.tmp��$dirname/$basename ����"
				exit 1
			fi
						
			printNORMAL "�ɹ��ָ��ļ�$bkupdir/$dirname/$resfilename ��$destdir Ŀ¼"
		done
	       
       done
	
done

#ɾ����ʱ�ļ�
rm -rf $DIRNAMELIST 

}
main
exit 0
