#!/bin/bash
echo "Enter two Nos"
read a
read b
echo "Enter Operator"
read op
if [ $op = "+" ] 
	then s=` expr $a + $b `
	echo $s
elif [ $op = "-" ]
	then s=` expr $a - $b`
	echo $s
elif [ $op = "x" ]
	then s=` expr $a \* $b`
	echo $s
elif [ $op = "/" ]
	then s=` expr $a / $b`
	echo $s
fi
