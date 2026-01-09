#!/bin/bash
echo -n "Enter limit: "
read n
if [ $n -eq 0 ]
then
    echo " nothing to show! "
elif [ $n -eq 1 ]
then
    echo "0"
else
    first=0
    sec=1
    echo -n "$first "
    echo -n "$sec "
    for (( i=3; i<=n; i++ ))
    do
        sum=$((first + sec))
        echo -n "$sum "
        first=$sec
        sec=$sum
    done
fi
echo