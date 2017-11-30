#!/system/bin/sh

# grep the modem partition for baseband version and set it
if strings /firmware/image/modem.b21 | grep "^NBW" >> /dev/null; then
        # "iuni" | "IUNI" | "u810" | "U810" | "U2" | "u2"
        setprop gsm.version.baseband `strings /firmware/image/modem.b21 | grep "^NBW" | head -1`
fi
