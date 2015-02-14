mkdir ./screen_img
adb shell screencap -p | sed 's/\r$//'
if [ $? -eq 0 ]
then
	adb shell screencap -p | sed 's/\r$//' >./img/currentscreen.png
	
fi
