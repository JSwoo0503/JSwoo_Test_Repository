echo "======================================="
echo " Build maskROM USB FWDN "
echo "======================================="
 gcc -o maskrom_usb_fwdn usb_fwdn.c -lusb-1.0

 echo " FW Download Usage: maskrom_usb_fwdn ./bl2.bin "