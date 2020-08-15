#!bin/bash

read filename
read str
num=`expr length $filename`
num2=`expr length $str`
echo $num
echo $num2
if ((num >= num2 ))
then
    result=`expr $num - $num2`
else
    result=`expr $num2 - $num`
fi
size=`wc -c < $filename`
echo $size
result=`expr $result \* $size`
echo "Result is $result"
