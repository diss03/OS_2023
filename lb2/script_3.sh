#! /bin/sh

if [ $# -lt 1 ]
then
	echo "$0: нет файла"
else
	filename=`ls -lR . | grep "^l" | grep "$1$"`
	echo "res: $filename"
fi
