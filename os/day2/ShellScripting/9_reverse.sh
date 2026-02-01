#!/bin/bash
echo -n "Enter a number: "
read num
rev=$(echo $num |rev)
echo "Reversed number is: $rev"