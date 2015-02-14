#!/bin/bash
a=`adb shell cat /sys/class/power_supply/battery/capacity`
if [ $? -eq 0 ]
then 
	b=`echo $a|tr -cd '[0-9]'`
	c=$b
	echo $c
else
	echo 0

fi
