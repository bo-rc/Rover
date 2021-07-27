#!/bin/bash -xe

# source: https://github.com/IntelRealSense/librealsense/blob/master/scripts/libuvc_installation.sh

#Locally suppress stderr to avoid raising not relevant messages
exec 3>&2
exec 2> /dev/null
con_dev=$(ls /dev/video* | wc -l)
exec 2>&3

if [ $con_dev -ne 0 ];
then
	echo -e "\e[32m"
	read -p "Remove all RealSense cameras attached. Hit any key when ready"
	echo -e "\e[0m"
fi

lsb_release -a
echo "Kernel version $(uname -r)"
sudo apt-get update
cd ~/
sudo rm -rf ./librealsense_build
mkdir librealsense_build && cd librealsense_build

if [ $(sudo swapon --show | wc -l) -eq 0 ];
then
	echo "No swapon - setting up 1Gb swap file"
	sudo fallocate -l 2G /swapfile
	sudo chmod 600 /swapfile
	sudo mkswap /swapfile
	sudo swapon /swapfile
	sudo swapon --show
fi

echo Installing Librealsense-required dev packages
sudo apt-get install git cmake libssl-dev freeglut3-dev libusb-1.0-0-dev pkg-config libgtk-3-dev unzip -y
rm -f ./v2.39.0.zip

wget https://github.com/IntelRealSense/librealsense/archive/v2.39.0.zip
unzip ./v2.39.0.zip -d .
cd ./librealsense-2.39.0

echo Install udev-rules
sudo cp config/99-realsense-libusb.rules /etc/udev/rules.d/ 
sudo udevadm control --reload-rules && sudo udevadm trigger 
mkdir build && cd build
cmake -D CMAKE_BUILD_TYPE=“Release” -D FORCE_LIBUVC=ON -D BUILD_PYTHON_BINDINGS=ON -D BUILD_EXAMPLES=OFF -D BUILD_GRAPHICAL_EXAMPLES=OFF -D BUILD_EASYLOGGINGPP=OFF -D BUILD_GLSL_EXTENSIONS=OFF -D BUILD_SHARED_LIBS=ON ..
make -j4
sudo make install
echo -e "\e[92m\n\e[1mLibrealsense script completed.\n\e[0m"



