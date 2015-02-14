#截图保存
filename=`date +%s`
adb shell screencap -p | sed 's/\r$//'  > ./screen_img/screenshot/$filename.png

