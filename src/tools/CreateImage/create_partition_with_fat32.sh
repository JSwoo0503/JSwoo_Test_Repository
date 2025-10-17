#!/bin/sh

# Force locale language to be set to English. This avoids issues when doing
# text and string processing.
# export LANG=C

# Determine the absolute path to the executable
# EXE will have the PWD removed so we can concatenate with the PWD safely
# If you need 

# 40GB
# TOTAL_SIZE_DEF=40960
# ROOTFS_SIZE_DEF=38912

# 10GB
TOTAL_SIZE_DEF=10240
USERDATA_SIZE_DEF=1024

#
PWD=`pwd`
EXE=`echo $0 | sed s=$PWD==`
EXEPATH="$PWD"/"$EXE"
BOOTFS="bootfs"
ROOTFS="rootfs"
USERDATA="user_data"
CREATEIMAGE="apache6-rootfs-image.wic"
OUTIMAGE=""
PARTITION1=""
PARTITION2=""
PARTITION3=""
PARTITION4=""

# BL Info.
# 0x0200
BL2_SIZE=512
# Offset 8Kbyte
BL2_OFF_SECTOR_NOR=16
# Offset 256Kbyte
BL2_OFF_SECTOR_BAK=512
BL2_IMAGE="APACHE6_EVT0_BL2_aarch32_AP60.bin"

# clear

echo ""
echo ""

usage ()
{
  echo "
 Usage: `basename $1` --bootdir <bootfs> --rootdir <rootfs> --userdir <userdata> --outimage <output name>

 Optional options:
   --bootdir             Directory path for Bootloader
   --rootdir             Directory path for Root filesystem
   --userdir             Directory path for User Data
   --outimage            WIC Image output name
"
  exit 1
}

search_partition ()
{
	PARTITION_DISK=`sudo kpartx -av $CREATEIMAGE | awk '{print $3}'`
	PAR_COUNTER=0

	for DISK in $PARTITION_DISK
	do
		echo "partition  : $DISK "

		if [ $PAR_COUNTER -eq 0 ]
		then
			PARTITION1=$DISK
		elif [ $PAR_COUNTER -eq 1 ]
		then
			PARTITION2=$DISK
		elif [ $PAR_COUNTER -eq 2 ]
		then
			PARTITION3=$DISK
		elif [ $PAR_COUNTER -eq 3 ]
		then
			PARTITION4=$DISK
		else
			echo "\n\n **** Error *** Not found partitions \n\n"
		fi
		
		PAR_COUNTER=$(expr $PAR_COUNTER + 1)
	done

	# (test -z $PARTITION1 || test -z $PARTITION2) && usage $0	
}

AMIROOT=`whoami | awk {'print $1'}`
if [ "$AMIROOT" != "root" ] ; then

	echo "\e[31m > > > > > Must run script with sudo < < < < < \e[0m"	
	usage $0	
fi

################################################################################
# Process command line...
while [ $# -gt 0 ]; do
  case $1 in
    --help | -h)
      usage $0
      ;;
    --bootdir) shift; BOOTFS=$1; shift; ;;
    --rootdir) shift; ROOTFS=$1; shift; ;;
    --userdir) shift; USERDATA=$1; shift; ;;
    --outimage) shift; OUTIMAGE=$1; shift; ;;
    *) copy="$copy $1"; shift; ;;
  esac
done

################################################################################

# (test -z $OUTIMAGE) && usage $0

if [ ! -d "$BOOTFS" ]
then
	echo "The \"bootfs\" directory is required "
    usage $0
	exit
fi
if [ ! -d "$ROOTFS" ]
then
	echo "The \"rootfs\" directory is required "
    usage $0
	exit
fi


if [ -f "$CREATEIMAGE" ]
then
    sudo rm -rf $CREATEIMAGE
fi

if [ -f "$OUTIMAGE" ]
then
    sudo rm -rf $OUTIMAGE
fi

echo "\e[32m ************************************************************ \e[0m"
echo "\e[32m *                This is what creates WIC Image            * \e[0m"
echo "\e[32m ************************************************************ \e[0m"
echo ""
echo ""

# 0:File, 1:Device
OUTIMAGE_TYPE=$(echo "$OUTIMAGE" | grep -E "/dev")

# MiB=1024*1024, MB=1000*1000
sudo truncate -s ${TOTAL_SIZE_DEF}M ${CREATEIMAGE}

cat << END | fdisk $CREATEIMAGE
n
p
1

+128M
n
p
2

+${USERDATA_SIZE_DEF}M
n
p
3



t
1
c
a
1
w
END
 
search_partition

# 
# Mounting Partition
# 
export MNT_BOOTFS=$PWD/tmp/bootfs
export MNT_ROOTFS=$PWD/tmp/rootfs
export MNT_USERDIR=$PWD/tmp/userdata
export DEVICE_PART1=/dev/mapper/$PARTITION1
export DEVICE_PART2=/dev/mapper/$PARTITION2
export DEVICE_PART3=/dev/mapper/$PARTITION3

echo " "
echo "Format filesystem with VFAT "
sudo mkfs.vfat -F 32 -n "boot" $DEVICE_PART1

echo " "
echo "Format filesystem with EXT4 for userdata"
sudo mkfs.ext4 -L "userdata" $DEVICE_PART2

echo " "
echo "Format filesystem with EXT4 for rootfs"
sudo mkfs.ext4 -L "root" $DEVICE_PART3

echo " "
echo "Mounting Filesystem.. "

if [ -d $BOOTFS ]
then
	sudo mkdir -p $MNT_BOOTFS
  	sudo mount $DEVICE_PART1 $MNT_BOOTFS

  	echo ""
  	echo "Copying bootfs to partition #1"
  	sudo rsync -ah --info=progress2 $BOOTFS/* $MNT_BOOTFS/

  	sudo umount $MNT_BOOTFS
	sudo rm -rf $MNT_BOOTFS
fi

if [ -d $ROOTFS ]
then
	sudo mkdir -p $MNT_ROOTFS
  	sudo mount $DEVICE_PART3 $MNT_ROOTFS

  	echo ""
  	echo "Copying rootfs to partition #3"
  	sudo rsync -ah --info=progress2 $ROOTFS/* $MNT_ROOTFS/

	# mount swap partition in fstab
	# UUID_NAME=$(sudo blkid -s UUID -o value $DEVICE_PART3)
	# echo "UUID=$UUID_NAME	swap	swap	defaults	0	0" >> $MNT_ROOTFS/etc/fstab

	# mount userdata partition in fstab
	if [ -d $USERDATA ]
	then		
		UUID_NAME=$(sudo blkid -s UUID -o value $DEVICE_PART2)
		echo "UUID=$UUID_NAME	/userdata	ext4	defaults	0	0" >> $MNT_ROOTFS/etc/fstab
	fi

  	sudo umount $MNT_ROOTFS
	sudo rm -rf $MNT_ROOTFS
fi

if [ -d $USERDATA ]
then
	sudo mkdir -p $MNT_USERDIR
  	sudo mount $DEVICE_PART2 $MNT_USERDIR

  	echo ""
  	echo "Copying rootfs to partition #2"
  	sudo rsync -ah --info=progress2 $USERDATA/* $MNT_USERDIR/

  	sudo umount $MNT_USERDIR
	sudo rm -rf $MNT_USERDIR
fi


if [ -d $PWD/tmp ]
then
	echo ""
	sudo rm -rf $PWD/tmp
	echo ""
fi

echo ""
echo "Partition create done..."
echo ""
sync
sync

if [ -f $BOOTFS/$BL2_IMAGE ]
then
	echo ""
	echo "\e[32m Copy to BL2 !!! \e[0m"	
	sudo dd if=${BOOTFS}/${BL2_IMAGE} of=${CREATEIMAGE} bs=512 conv=notrunc seek=${BL2_OFF_SECTOR_NOR} count=${BL2_SIZE} status=progress
	sudo dd if=${BOOTFS}/${BL2_IMAGE} of=${CREATEIMAGE} bs=512 conv=notrunc seek=${BL2_OFF_SECTOR_BAK} count=${BL2_SIZE} status=progress
fi

#sudo losetup -d xxx
sudo kpartx -dv $PWD/$CREATEIMAGE > /dev/null

if [ ! -z "$OUTIMAGE_TYPE" ]
then
	echo ""
	echo "\e[32m Write to device !!! \e[0m"
	sudo dd if=${CREATEIMAGE} of=${OUTIMAGE} bs=1MiB count=$TOTAL_SIZE_DEF status=progress	
fi

echo ""
echo "\e[32m Synchronization !!! \e[0m"
echo ""
sync
sync
echo "\e[32m Completed !!! \e[0m"
echo ""