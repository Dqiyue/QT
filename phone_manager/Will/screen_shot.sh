#截图保存
mkdir ./img/截图
filename=`date +%s`
adb shell screencap -p | sed 's/\r$//' 
if [ $? -eq 0 ]
then
	adb shell screencap -p | sed 's/\r$//'  > ./img/截图/$filename.png
else	
	echo 1
fi
