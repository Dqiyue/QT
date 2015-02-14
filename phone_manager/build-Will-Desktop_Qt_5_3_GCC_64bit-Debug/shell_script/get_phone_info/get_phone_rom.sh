#!/bin/bash
unit_datausr=M
unit_dataall=M

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

if [ ! -n "$romdataall" ]
then
	echo 0
else
	echo "$romdataus"
fi

