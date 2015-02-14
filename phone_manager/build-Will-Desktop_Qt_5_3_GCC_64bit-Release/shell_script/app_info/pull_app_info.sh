#!/bin/bash
rm ./app_logo
rm ./uninstalled_maps.txt
mkdir ./app_logo
adb pull /storage/sdcard1/logo ./logo
adb pull /storage/sdcard1/uninstalled_maps.txt ./
