#
# Copyright (C) 2013 The Android Open-Source Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

# Common QCOM configuration tools
$(call inherit-product, device/qcom/common/Android.mk)

# Dalvik/HWUI
$(call inherit-product-if-exists, frameworks/native/build/phone-xxhdpi-3072-dalvik-heap.mk)
$(call inherit-product-if-exists, frameworks/native/build/phone-xxhdpi-3072-hwui-memory.mk)

# Screen density
PRODUCT_AAPT_CONFIG := normal
PRODUCT_AAPT_PREF_CONFIG := xxhdpi

# Ramdisk
PRODUCT_PACKAGES += \
    fstab.qcom \
    init.qcom.power.rc \
    init.qcom.rc \
    init.qcom.usb.rc \
    ueventd.qcom.rc \
	set_baseband.sh

PRODUCT_COPY_FILES += \
    device/iuni/u2/rootdir/etc/bin/init.qcom.devwait.sh:$(TARGET_COPY_OUT_VENDOR)/bin/init.qcom.devwait.sh \
    device/iuni/u2/rootdir/etc/bin/init.qcom.devstart.sh:$(TARGET_COPY_OUT_VENDOR)/bin/init.qcom.devstart.sh

PRODUCT_COPY_FILES += \
    frameworks/av/media/libstagefright/data/media_codecs_google_audio.xml:system/etc/media_codecs_google_audio.xml \
    frameworks/av/media/libstagefright/data/media_codecs_google_telephony.xml:system/etc/media_codecs_google_telephony.xml \
    frameworks/av/media/libstagefright/data/media_codecs_google_video.xml:system/etc/media_codecs_google_video.xml \
    device/iuni/u2/media_codecs.xml:system/etc/media_codecs.xml \
    device/iuni/u2/media_profiles.xml:system/etc/media_profiles.xml \
    device/iuni/u2/media_codecs_performance.xml:system/etc/media_codecs_performance.xml

# Config files for touch and input
PRODUCT_COPY_FILES += \
    device/iuni/u2/keylayout/gpio-keys.kl:system/usr/keylayout/gpio-keys.kl \
    device/iuni/u2/keylayout/atmel_mxt_ts.kl:system/usr/keylayout/atmel_mxt_ts.kl \
    device/iuni/u2/keylayout/synaptics_rmi4_i2c.kl:system/usr/keylayout/synaptics_rmi4_i2c.kl

# These are the hardware-specific features
PRODUCT_COPY_FILES += \
    frameworks/native/data/etc/handheld_core_hardware.xml:system/etc/permissions/handheld_core_hardware.xml \
    frameworks/native/data/etc/android.hardware.camera.flash-autofocus.xml:system/etc/permissions/android.hardware.camera.flash-autofocus.xml \
    frameworks/native/data/etc/android.hardware.camera.front.xml:system/etc/permissions/android.hardware.camera.front.xml \
    frameworks/native/data/etc/android.hardware.camera.full.xml:system/etc/permissions/android.hardware.camera.full.xml \
    frameworks/native/data/etc/android.hardware.camera.raw.xml:system/etc/permissions/android.hardware.camera.raw.xml \
    frameworks/native/data/etc/android.hardware.location.gps.xml:system/etc/permissions/android.hardware.location.gps.xml \
    frameworks/native/data/etc/android.hardware.wifi.xml:system/etc/permissions/android.hardware.wifi.xml \
    frameworks/native/data/etc/android.hardware.wifi.direct.xml:system/etc/permissions/android.hardware.wifi.direct.xml \
    frameworks/native/data/etc/android.hardware.sensor.proximity.xml:system/etc/permissions/android.hardware.sensor.proximity.xml \
    frameworks/native/data/etc/android.hardware.sensor.light.xml:system/etc/permissions/android.hardware.sensor.light.xml \
    frameworks/native/data/etc/android.hardware.sensor.gyroscope.xml:system/etc/permissions/android.hardware.sensor.gyroscope.xml \
    frameworks/native/data/etc/android.hardware.sensor.barometer.xml:system/etc/permissions/android.hardware.sensor.barometer.xml \
    frameworks/native/data/etc/android.hardware.sensor.stepcounter.xml:system/etc/permissions/android.hardware.sensor.stepcounter.xml \
    frameworks/native/data/etc/android.hardware.sensor.stepdetector.xml:system/etc/permissions/android.hardware.sensor.stepdetector.xml \
    frameworks/native/data/etc/android.hardware.touchscreen.multitouch.jazzhand.xml:system/etc/permissions/android.hardware.touchscreen.multitouch.jazzhand.xml \
    frameworks/native/data/etc/android.software.sip.voip.xml:system/etc/permissions/android.software.sip.voip.xml \
    frameworks/native/data/etc/android.hardware.usb.accessory.xml:system/etc/permissions/android.hardware.usb.accessory.xml \
    frameworks/native/data/etc/android.hardware.usb.host.xml:system/etc/permissions/android.hardware.usb.host.xml \
    frameworks/native/data/etc/android.hardware.telephony.gsm.xml:system/etc/permissions/android.hardware.telephony.gsm.xml \
    frameworks/native/data/etc/android.hardware.audio.low_latency.xml:system/etc/permissions/android.hardware.audio.low_latency.xml \
    frameworks/native/data/etc/android.hardware.bluetooth_le.xml:system/etc/permissions/android.hardware.bluetooth_le.xml \
    frameworks/native/data/etc/android.hardware.telephony.cdma.xml:system/etc/permissions/android.hardware.telephony.cdma.xml \
    frameworks/native/data/etc/android.hardware.ethernet.xml:system/etc/permissions/android.hardware.ethernet.xml

# WiFi
PRODUCT_COPY_FILES += \
    device/iuni/u2/wifi/WCNSS_cfg.dat:system/etc/firmware/wlan/prima/WCNSS_cfg.dat \
    device/iuni/u2/wifi/WCNSS_qcom_cfg.ini:system/vendor/etc/wifi/WCNSS_qcom_cfg.ini \
    device/iuni/u2/wifi/WCNSS_qcom_wlan_nv.bin:system/etc/firmware/wlan/prima/WCNSS_qcom_wlan_nv.bin

PRODUCT_TAGS += dalvik.gc.type-precise

DEVICE_PACKAGE_OVERLAYS := \
    device/iuni/u2/overlay \
    device/iuni/u2/overlay-lineage

# Offmode Charging
PRODUCT_PACKAGES += \
    charger_res_images

# Data
PRODUCT_PACKAGES += \
    libxml2 \
    librmnetctl \
    libcnefeatureconfig

# BoringSSL compatability wrapper
PRODUCT_PACKAGES += \
    libboringssl-compat

# TextClassifier smart selection model files
PRODUCT_PACKAGES += \
    textclassifier.smartselection.bundle1

PRODUCT_PACKAGES += \
    hostapd.accept \
    hostapd.deny \
    wpa_supplicant.conf \
    wpa_supplicant_overlay.conf \
    p2p_supplicant_overlay.conf

PRODUCT_PACKAGES += \
    android.hardware.wifi@1.0-service \
    wificond \
    wcnss_service \
    wpa_supplicant \
    libwpa_client \
    hostapd
    
# IPv6
PRODUCT_PACKAGES += \
    ebtables \
    libbson \
    libnl_2 \
    ethertypes

# USB HAL
PRODUCT_PACKAGES += \
    android.hardware.usb@1.0-service

# DRM
PRODUCT_PACKAGES += \
    android.hardware.drm@1.0-impl \
    android.hardware.drm@1.0-service

# RenderScript HAL
PRODUCT_PACKAGES += \
    android.hardware.renderscript@1.0-impl

# Power
PRODUCT_PACKAGES += \
    android.hardware.power@1.0-service-qti

# Graphics
PRODUCT_PACKAGES += \
    android.hardware.graphics.allocator@2.0-impl \
    android.hardware.graphics.allocator@2.0-service \
    android.hardware.graphics.composer@2.1-impl \
    android.hardware.graphics.mapper@2.0-impl \
    android.hardware.memtrack@1.0-impl \
    copybit.msm8974 \
    gralloc.msm8974 \
    hwcomposer.msm8974 \
    memtrack.msm8974 \
    liboverlay \
    keystore.msm8974

# Keymaster
PRODUCT_PACKAGES += \
    android.hardware.keymaster@3.0-impl

# Camera
PRODUCT_PACKAGES += \
    android.hardware.camera.provider@2.4-impl-legacy

# Lights
PRODUCT_PACKAGES += \
    android.hardware.light@2.0-impl \
    lights.u2

# RIL
PRODUCT_PACKAGES += \
    android.hardware.radio@1.0-impl

# Configstore
PRODUCT_PACKAGES += \
    android.hardware.configstore@1.0-service

PRODUCT_COPY_FILES += \
    $(LOCAL_PATH)/sensor/_hals.conf:system/vendor/etc/sensors/_hals.conf

# Sensors
PRODUCT_PACKAGES += \
    android.hardware.sensors@1.0-impl \
    sensors.msm8974

# Vibrator
PRODUCT_PACKAGES += \
    android.hardware.vibrator@1.0-impl \
    android.hardware.thermal@1.0-impl

PRODUCT_PACKAGES += \
    android.hardware.audio@2.0-impl \
    android.hardware.audio.effect@2.0-impl \
    audio.a2dp.default \
    audio_policy.msm8974 \
    audio.primary.msm8974 \
    audio.r_submix.default \
    audio.usb.default \
    libaudio-resampler \
    libqcompostprocbundle \
    libqcomvisualizer \
    libqcomvoiceprocessing \
    tinymix

# Bluetooth
PRODUCT_PACKAGES += \
    libbt-vendor \
    android.hardware.bluetooth@1.0-impl

# for audio.primary.msm8974
PRODUCT_PACKAGES += \
    libtinyalsa \
    libtinycompress \
    tinymix \
    tinyplay \
    tinycap \
    tinypcminfo \
    libtinyxml \
    libtinyxml2

# Media & Audio
PRODUCT_PACKAGES += \
    libc2dcolorconvert \
    libOmxAacEnc \
    libOmxAmrEnc \
    libOmxCore \
    libOmxEvrcEnc \
    libOmxQcelp13Enc \
    libOmxVdec \
    libOmxVenc \
    libstagefrighthw 

# sensors
PRODUCT_COPY_FILES += \
    device/iuni/u2/sensor/sap.conf:system/etc/sap.conf \
    device/iuni/u2/sensor/sensor_def_qcomdev.conf:system/etc/sensor_def_qcomdev.conf

# MSM IPC Router security configuration
PRODUCT_COPY_FILES += \
    device/iuni/u2/sec_config:system/etc/sec_config

PRODUCT_COPY_FILES += \
    device/iuni/u2/audio/audio_effects.conf:system/vendor/etc/audio_effects.conf \
    device/iuni/u2/audio/audio_policy.conf:system/vendor/etc/audio_policy.conf \
    device/iuni/u2/audio/mixer_paths.xml:system/vendor/etc/mixer_paths.xml \
    device/iuni/u2/audio/mixer_paths_auxpcm.xml:system/vendor/etc/mixer_paths_auxpcm.xml
    
# GPS configuration
PRODUCT_COPY_FILES += \
    device/iuni/u2/gps.conf:system/etc/gps.conf

# Seccomp
PRODUCT_COPY_FILES += \
    $(LOCAL_PATH)/configs/mediacodec.policy:system/vendor/etc/seccomp_policy/mediacodec.policy \
    $(LOCAL_PATH)/configs/mediaextractor.policy:system/vendor/etc/seccomp_policy/mediaextractor.policy

# bluetooth
PRODUCT_PROPERTY_OVERRIDES += \
     qcom.bluetooth.soc=smd \
     ro.bluetooth.hfp.ver=1.7 \
     ro.qualcomm.bt.hci_transport=smd \
     ro.bluetooth.dun=false \
     ro.bluetooth.sap=false

# Graphics
PRODUCT_PROPERTY_OVERRIDES += \
    ro.opengles.version=196608 \
    persist.hwc.mdpcomp.enable=true \
    debug.hwui.use_buffer_age=false \
    persist.media.treble_omx=false \
    camera.disable_treble=true

# QMI
PRODUCT_PROPERTY_OVERRIDES += \
    persist.data.netmgrd.qos.enable=true \
    rild.libpath=/vendor/lib/libril-qc-qmi-1.so \
    ro.use_data_netmgrd=true \
    ro.telephony.default_network=3 \
    persist.radio.apm_sim_not_pwdn=1 \
    persist.radio.add_power_save=1 \
    ro.telephony.call_ring.multiple=0 \
    persist.data.qmi.adb_logmask=0 \
    ro.qualcomm.cabl=0

#For internal sdcard
PRODUCT_DEFAULT_PROPERTY_OVERRIDES += \
    ro.vold.primary_physical=1
    
PRODUCT_PROPERTY_OVERRIDES += \
    drm.service.enabled=true

PRODUCT_PROPERTY_OVERRIDES += \
    wifi.interface=wlan0

# qcom
PRODUCT_PROPERTY_OVERRIDES += \
    camera2.portability.force_api=1 \
    media.stagefright.legacyencoder=true \
    media.stagefright.less-secure=true

# Enable AAC 5.1 output
PRODUCT_PROPERTY_OVERRIDES += \
    media.aac_51_output_enabled=true

# Audio Configuration
PRODUCT_PROPERTY_OVERRIDES += \
    ro.qc.sdk.audio.audience=true \
    persist.audio.fluence.voicecall=true \
    audio.offload.buffer.size.kb=32 \
    audio.offload.gapless.enabled=true \
    use.voice.path.for.pcm.voip=true \
    av.offload.enable=false \
    av.streaming.offload.enable=false \
    audio.offload.pcm.16bit.enable=true \
    audio.offload.multiple.enabled=false

# QC Perf
PRODUCT_PROPERTY_OVERRIDES += \
    ro.vendor.extension_library=/vendor/lib/libqti-perfd-client.so

# gps
#system prop for switching gps driver to qmi
PRODUCT_PROPERTY_OVERRIDES += \
    persist.gps.qmienabled=true \
    persist.timed.enable=true \
    persist.cne.feature=1

PRODUCT_PROPERTY_OVERRIDES += \
    ro.build.selinux=1 \
    ro.sf.lcd_density=480
