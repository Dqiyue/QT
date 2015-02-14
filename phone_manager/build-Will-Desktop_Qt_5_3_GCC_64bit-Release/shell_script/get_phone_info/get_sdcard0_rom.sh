#!/bin/bash
unit_sdcar0used=M
unit_sdcard0all=M

unit_sdcard0all=`adb shell df /storage/sdcard0 | grep sdcard0 | awk  '{if(NR==1){print $2}}' | tr -cd '[A-Z]'`
unit_sdcar0used=`adb shell df /storage/sdcard0 | grep sdcard0 | awk  '{if(NR==1){print $3}}' | tr -cd '[A-Z]'`	
romsdcard0all=`adb shell df /storage/sdcard0 | grep sdcard0 | awk  '{if(NR==1){print $2}}' | tr -cd '[0-9.]'`
romsdcard0use=`adb shell df /storage/sdcard0 | grep sdcard0 | awk  '{if(NR==1){print $3}}' | tr -cd '[0-9.]'`
if test $unit_sdcard0all = "G"
then
	romsdcard0all=`expr $romsdcard0all \* 1024`
fi
if test $unit_sdcar0used = "G"
then
	romsdcard0use=`expr $romsdcard0use \* 1024`
fi

romsdcard0_us=`echo "scale=2;($romsdcard0use/$romsdcard0all)*100 "| bc -l`

if [ ! -n "$romsdcard0all" ]
then
	echo 0
else
	echo "$romsdcard0_us"
fi
