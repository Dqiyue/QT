#!/bin/bash
#手机连接情况
a=`adb devices |awk '{if(NR==2){print}}'|grep device`
if [ $? -eq 0 ]
then
	echo "0"
else
	echo "1"
fi
exit 0
