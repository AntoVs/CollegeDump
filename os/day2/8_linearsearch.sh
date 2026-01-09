#!/bin/bash
echo -n "Enter no of elements : "
read n
for (( i=0; i<n; i++ ))
do
    echo -n "Enter elements $((i + 1)): "
    read a[$i]
done
echo -n "Elements in the array are: "
for (( i=0; i<n; i++ ))
do
    echo -n "${a[$i]} "
done
echo
echo -n "Enter the search key: "
read element
flag=0
for (( i=0; i<n; i++ ))
do
    if [ ${a[$i]} -eq $element ]
    then
        flag=1
        break
    fi
done
if [ $flag -eq 1 ]
then
    echo "$element is found in the array"
else
    echo "$element is not found in the array"
fi