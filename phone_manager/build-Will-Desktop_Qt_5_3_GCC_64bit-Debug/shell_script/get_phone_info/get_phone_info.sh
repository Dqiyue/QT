#!/bin/bash

phonelink=`adb devices |awk '{if(NR==2){print}}'|grep device`
if [ $? -eq 0 ]
then
	phonetype=`adb shell getprop | grep "ro.product.model" | cut -f2 -d "]" | cut -f2 -d "["`
	a=`adb shell cat /sys/class/power_supply/battery/capacity`
	b=`echo $a|tr -cd '[0-9]'`
	c=$b%
	echo "$phonetype 已连接"
	adb shell screencap -p | sed 's/\r$//' > ./screen_img/currentscreen/currentscreen.png
else
	echo "no"
fi

