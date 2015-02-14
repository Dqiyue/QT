#!/bin/bash
rm ./phone_picture
mkdir phone_picture
count=0;
adb pull /sdcard/DCIM  ./phone_picture
adb pull /storage/sdcard0/DCIM  ./phone_picture
adb pull /storage/sdcard1/DCIM  ./phone_picture	
if [ $? -eq 0 ]
then
	chmod 777 -R ./phone_picture 
		files=`ls  ./phone_picture -R|grep -E ".jpg|.png|.gif|.cache"`;
		for i in $files
		do 
			((count++));
		done
		echo $count	
else
	echo 0;
fi
