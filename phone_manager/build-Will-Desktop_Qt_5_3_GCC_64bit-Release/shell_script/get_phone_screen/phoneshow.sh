#!/bin/bash
adb shell screencap -p | sed 's/\r$//' >./screen_img/currentscreen/currentscreen.png

