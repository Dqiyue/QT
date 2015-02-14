#!/bin/bash
phonetype=`adb shell getprop | grep "ro.product.model" | cut -f2 -d "]" | cut -f2 -d "["`
a=`adb shell cat /sys/class/power_supply/battery/capacity`
b=`echo $a|tr -cd '[0-9]'`
c=$b%
unit_datausr=M
unit_dataall=M
unit_sysusr=M
unit_sysall=M
unitdataall=`adb shell df /data | grep data | awk  '{if(NR==1){print $2}}' | tr -cd '[A-Z]'`
unitdatausr=`adb shell df /data | grep data | awk  '{if(NR==1){print $3}}' | tr -cd '[A-Z]'`	
romdataall=`adb shell df /data | grep data | awk  '{if(NR==1){print $2}}' | tr -cd '[0-9.]'`
romdatause=`adb shell df /data | grep data | awk  '{if(NR==1){print $3}}' | tr -cd '[0-9.]'`
if test $unitdataall = "G"
then
	romdataall=`expr $romdataall \* 1024`
fi
if test $unitdatausr = "G"
then
	romdatause=`expr $romdatause \* 1024`
fi
romdataus=`echo "scale=1;$romdatause/$romdataall*100 "| bc -l`
romdataus=$romdataus%

unitsysall=`adb shell df /system | grep system | awk  '{if(NR==2){print $2}}' | tr -cd '[A-Z]'`
unitsysusr=`adb shell df /system | grep system | awk  '{if(NR==2){print $3}}' | tr -cd '[A-Z]'`
romsysall=`adb shell df /system | grep system | awk 'NR==2{print $2} '| tr -cd '[0-9.]'`
romsysuse=`adb shell df /system | grep system | awk 'NR==2{print $3} '| tr -cd '[0-9.]'`
if test $unitsysall = "G"
then
	romsysall=`expr $romsysall \* 1024`
fi
if test $unitsysusr = "G"
then
	romsysuse=`expr $romsysuse \* 1024`
fi
romsysus=`echo "scale=1;$romsysuse/$romsysall*100 "| bc -l`
romsysus=$romsysus%
phonelink=`adb devices |awk '{if(NR==2){print}}'|grep device`
if [ $? -eq 0 ]
then
	echo "手机连接:已连接"
else
	echo "手机连接:未连接"
fi
sysversion=`adb shell getprop | grep "build.display" | cut -f2 -d "]" | cut -f2 -d "["`
operator=`adb shell getprop gsm.operator.alpha`
if [ $? -eq 0 ]
then
	echo "运营商:$operator"
else
	echo "运营商:未找到"
fi
if [ ! -n "$sysversion" ]
then
	echo "系统版本:未找到"
else
	echo "系统版本:$sysversion"
fi
if [ ! -n "$phonetype" ]
then
	echo "手机型号:未找到"
else
	echo "手机型号:$phonetype"
fi
if [ ! -n "$romdataall" ]
then
	echo "ROM用户:未找到"
else
	echo "ROM用户:$romdataall$unit_dataall"
	echo "$romdataus已用"
fi
if [ ! -n "$romsysall" ]
then
	echo "ROM系统:未找到"
else
	echo "ROM系统:$romsysall$unit_sysall"
	echo "$romsysus已用"
fi
if [ ! -n "$c" ]
then
	echo "电池电量:未找到"
else
	echo "电池电量:$c"
fi
