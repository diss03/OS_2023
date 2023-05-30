#! /bin/bash

mkdir test_dir
cd test_dir

for ((i=0;i<=1100;i++))
do
	mkdir dir$i
	cd dir$i
done

cd ..

for ((i=1100;i>=0;i--))
do
        rmdir dir$i
	cd ..
done
