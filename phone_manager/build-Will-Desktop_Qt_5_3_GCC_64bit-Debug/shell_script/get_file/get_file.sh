#!/bin/bash

adb shell
cd data/app
echo "app:"
ls 
exit
adb remount
adb shell
cd system/app
echo "system-app:"
ls
exit
