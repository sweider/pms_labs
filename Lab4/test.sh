#!/bin/bash
op[0]='-'
op[1]='+'
op[2]='*'
op[3]='/'
for i in {0..3}
do
	as=$RANDOM
	bs=$RANDOM
	let "cs = $as ${op[i]} $bs"
        echo EXPECTED: $as${op[i]}$bs = $cs
	echo $as > /proc/a
	echo $bs > /proc/b
	echo ${op[i]} > /proc/op
	res=$(cat /proc/res)
	echo GOT: $res
	if [[ "$res" -eq "$cs" ]]
	then 
		echo TRUE
	else 
		echo FALSE
	fi	
done
