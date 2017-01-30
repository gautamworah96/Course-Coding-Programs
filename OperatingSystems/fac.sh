#!/bin/bash
echo "Enter the Number"
read n
x=$n

fact=1
while[ $n -ge 1 ]
do
fact=` expr $fact\*$n`
n=` expr $n - 1`
done
echo "Factorial of $x is $fact"