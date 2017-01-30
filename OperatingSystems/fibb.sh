#!/bin/bash
echo "Enter the number of terms"
read n
a=0
b=1
echo $a
echo $b
for ((i=1;i<=n;i++)); do
    c=` expr $a + $b `
    echo $c
    a=$b
    b=$c
done


