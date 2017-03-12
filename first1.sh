#!/bin/sh
echo "what's your name?" 
read my_name
echo "$my_name,we will creat a ${my_name}_file for you"
touch ${my_name}_file.txt
for i in 1 2 3 4 5 
do 
	echo "number $i"
done

for i in * 1 2 3 hello 
do 
	echo "i is $i"
done

if [ $my_name = liujie ]
then
	echo tian xia wu di
fi
