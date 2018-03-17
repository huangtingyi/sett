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
			
			#先备份一个文件
			cp $filename $bkupdir/$dirname/$basename.tmp
			
			uncompress $filename
			if [ $? -ne 0 ];then
				printALERT "解压文件$filename 错误"
				exit 1
			fi
						
			mv $bkupdir/$dirname/$resfilename $destdir/$resfilename
			if [ $? -ne 0 ];then
				printALERT "移动文件$bkupdir/$dirname/$resfilename到$destdir 错误"
				exit 1
			fi
			
			mv $bkupdir/$dirname/$basename.tmp $filename
			if [ $? -ne 0 ];then
				printALERT "移动文件$bkupdir/$dirname/$basename.tmp到$dirname/$basename 错误"
				exit 1
			fi
						
			printNORMAL "成功恢复文件$bkupdir/$dirname/$resfilename 到$destdir 目录"
		done
	       
       done
	
done

#删除临时文件
rm -rf $DIRNAMELIST 

}
main
exit 0
