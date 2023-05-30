#! /bin/sh
for i in b c d p f l s
do
	echo "filetype $i:"
	res=`find . -type $i -exec ls {} \;`
	echo "$res" | head -n1 && echo "\n"
done

