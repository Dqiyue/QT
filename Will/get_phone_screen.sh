mkdir ./img
chmod 777 ./img
adb shell screencap -p | sed 's/\r$//'
if [ $? -eq 0 ]
then
	adb shell screencap -p | sed 's/\r$//' >./img/screencurrent.png
else
	echo 1
fi
