#!/bin/bash
echo -n "Enter limit :"
read n
for(( i=1; i<n; i=i+2 ))
do
	echo -n "$i "
done
echo