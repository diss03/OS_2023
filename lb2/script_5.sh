#! /bin/bash

mkdir test_dir
echo "New directory have been created:">res5.txt
echo "STAT RES:">>res5.txt
du test_dir -bhs>>res5.txt

for ((i=1;i<10;i++))
do
	touch ./test_dir/test_file$i.txt
	echo "Some simbols for 25 bytes">>./test_dir/test_file$i.txt
	echo "test_file$i.txt have been created:">>res5.txt
	du test_dir -bhs>>res5.txt
done

for ((i=1;i<10;i++))
do
	rm ./test_dir/test_file$i.txt
done

echo "test_files have been delited:">>res5.txt
du test_dir -bhs>>res5.txt

for ((i=1;i<10;i++))
do
	mkdir ./test_dir/test_subdir$i
	echo "Subdir test_subdir$i have been created:">>res5.txt
	du test_dir -bhs>>res5.txt
done

for ((i=1;i<10;i++))
do
	rmdir ./test_dir/test_subdir$i
done

echo "Subdir test_subdir have been delited:">>res5.txt
du test_dir -bhs>>res5.txt

rmdir ./test_dir

