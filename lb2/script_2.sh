#!/bin/sh

if [ $# -lt 1 ]
then
	echo "$0: нет файла"
else
	filename=$1
	inode=`ls -i $filename | cut -c 1-18`
	ls -lRi / | grep $inode > hardlinks.txt
fi

