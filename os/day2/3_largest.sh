#!/bin/bash
echo -n "Enter numer 1 :"
read n1
echo -n "Enter numer 2 :"
read n2
if [ $n1 -gt $n2 ]
then
    echo "$n1 is larger"
elif [ $n1 -lt $n2 ]
then
    echo "$n2 is larger"
else
    echo "both are equal"
fi