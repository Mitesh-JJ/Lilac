device=/dev/ttyUSB0
mount_src=~/Projects/Arduino
mount_dst=/home/ubuntu/Workspace

docker run \
	-i -t \
	--name=arduino-dev \
	--group-add dialout \
	--device=$device \
	--mount type=bind,source=$mount_src,target=$mount_dst \
	ubuntu bash

