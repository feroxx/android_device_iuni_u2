#!/system/bin/sh

product=`getprop ro.build.product`
# grep the modem partition for baseband version and set it
case "$product" in
        "u2")
        setprop gsm.version.baseband `strings /firmware/image/modem.mdt | grep "^NBW" | head -1`
        ;;
esac
