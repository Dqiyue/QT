#!/bin/bash
unit_sdcard1used=M
unit_sdcard1all=M

unit_sdcard1all=`adb shell df /storage/sdcard1 | grep sdcard1 | awk  '{if(NR==1){print $2}}' | tr -cd '[A-Z]'`
unit_sdcard1used=`adb shell df /storage/sdcard1 | grep sdcard1 | awk  '{if(NR==1){print $3}}' | tr -cd '[A-Z]'`	
romsdcard1all=`adb shell df /storage/sdcard1 | grep sdcard1 | awk  '{if(NR==1){print $2}}' | tr -cd '[0-9.]'`
romsdcard1use=`adb shell df /storage/sdcard1 | grep sdcard1 | awk  '{if(NR==1){print $3}}' | tr -cd '[0-9.]'`
if test $unit_sdcard1all = "G"
then
	romsdcard1all=`expr $romsdcard1all \* 1024`
fi
if test $unit_sdcard1used = "G"
then
	romsdcard1use=`expr $romsdcard1use \* 1024`
fi

romsdcard1_us=`echo "scale=2;($romsdcard1use/$romsdcard1all)*100 "| bc -l`

if [ ! -n "$romsdcard1all" ]
then
	echo 0
else
	echo "$romsdcard1_us"
fi
