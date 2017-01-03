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
#

TARGET_CPU_ABI := armeabi-v7a
TARGET_CPU_ABI2 := armeabi
TARGET_ARCH := arm
TARGET_ARCH_VARIANT := armv7-a-neon
TARGET_CPU_VARIANT := krait

TARGET_BOOTLOADER_BOARD_NAME := u2
TARGET_OTA_ASSERT_DEVICE := iuni,IUNI,u810,U810,U2,u2
TARGET_BOARD_PLATFORM := msm8974
TARGET_BOARD_PLATFORM_GPU := qcom-adreno330

BOARD_KERNEL_SEPARATED_DT := true
BOARD_KERNEL_CMDLINE := console=ttyHSL0,115200,n8 androidboot.selinux=permissive androidboot.hardware=qcom user_debug=22 msm_rtb.filter=0x37 ehci-hcd.park=3 androidboot.bootdevice=msm_sdcc.1
BOARD_KERNEL_BASE := 0x00000000
BOARD_KERNEL_PAGESIZE := 2048
BOARD_CUSTOM_BOOTIMG_MK := device/iuni/u2/mkbootimg.mk

# global
TARGET_SPECIFIC_HEADER_PATH := device/iuni/u2/include
BOARD_USES_QCOM_HARDWARE := true
TARGET_USES_QCOM_BSP := true

# Display
TARGET_QCOM_DISPLAY_VARIANT := caf-msm8974
USE_OPENGL_RENDERER := true
TARGET_USES_ION := true
TARGET_USES_C2D_COMPOSITION := true
OVERRIDE_RS_DRIVER := libRSDriver_adreno.so

# Time Daemon
BOARD_USES_QC_TIME_SERVICES := true

# Media
TARGET_QCOM_MEDIA_VARIANT := caf-msm8974
TARGET_ENABLE_QC_AV_ENHANCEMENTS := true

# audio
BOARD_USES_ALSA_AUDIO := true
TARGET_QCOM_AUDIO_VARIANT := caf-msm8974
AUDIO_FEATURE_DISABLED_HWDEP_CAL := true
AUDIO_FEATURE_ENABLED_COMPRESS_VOIP := true
AUDIO_FEATURE_ENABLED_EXTN_FORMATS := true
AUDIO_FEATURE_ENABLED_EXTN_POST_PROC := true
AUDIO_FEATURE_ENABLED_FLUENCE := true
AUDIO_FEATURE_ENABLED_HFP := true
#AUDIO_FEATURE_ENABLED_PCM_OFFLOAD := true
#AUDIO_FEATURE_ENABLED_FLAC_OFFLOAD := true
AUDIO_FEATURE_ENABLED_PROXY_DEVICE := true
AUDIO_FEATURE_ENABLED_USBAUDIO := true
AUDIO_FEATURE_ENABLED_COMPRESS_CAPTURE := true
AUDIO_FEATURE_ENABLED_INCALL_MUSIC := true

# Camera
USE_CAMERA_STUB := true

TARGET_RIL_VARIANT := caf
BOARD_GLOBAL_CFLAGS += -DUSE_RIL_VERSION_10
BOARD_GLOBAL_CPPFLAGS += -DUSE_RIL_VERSION_10

# Bluetooth
BOARD_HAVE_BLUETOOTH := true
BOARD_HAVE_BLUETOOTH_QCOM := true
BLUETOOTH_HCI_USE_MCT := true
BOARD_BLUETOOTH_BDROID_BUILDCFG_INCLUDE_DIR := device/iuni/u2/bluetooth

# Wifi
BOARD_HAS_QCOM_WLAN := true
BOARD_WLAN_DEVICE := qcwcn
WPA_SUPPLICANT_VERSION := VER_0_8_X
BOARD_WPA_SUPPLICANT_DRIVER := NL80211
BOARD_WPA_SUPPLICANT_PRIVATE_LIB := lib_driver_cmd_$(BOARD_WLAN_DEVICE)
BOARD_HOSTAPD_DRIVER := NL80211
BOARD_HOSTAPD_PRIVATE_LIB := lib_driver_cmd_$(BOARD_WLAN_DEVICE)
WIFI_DRIVER_FW_PATH_STA := "sta"
WIFI_DRIVER_FW_PATH_AP := "ap"
WIFI_DRIVER_MODULE_PATH := "/system/lib/modules/wlan.ko"
WIFI_DRIVER_MODULE_NAME := "wlan"
TARGET_USES_QCOM_WCNSS_QMI       := true
TARGET_PROVIDES_WCNSS_QMI        := true
TARGET_USES_WCNSS_MAC_ADDR_REV   := true

MAX_EGL_CACHE_KEY_SIZE := 12*1024
MAX_EGL_CACHE_SIZE := 2048*1024

# fix this up by examining /proc/mtd on a running device
BOARD_MKBOOTIMG_ARGS := --ramdisk_offset 0x02000000 --kernel_offset 0x00008000

BOARD_BOOTIMAGE_PARTITION_SIZE     := 16777216
BOARD_CACHEIMAGE_PARTITION_SIZE    := 536870912
BOARD_PERSISTIMAGE_PARTITION_SIZE  := 33554432
BOARD_RECOVERYIMAGE_PARTITION_SIZE := 18777216
BOARD_SYSTEMIMAGE_PARTITION_SIZE   := 1073741824
BOARD_USERDATAIMAGE_PARTITION_SIZE := 13747929088 # 13747945472 - 16384 for crypto footer
#BOARD_USERDATAIMAGE_PARTITION_SIZE := 3221225472
BOARD_FLASH_BLOCK_SIZE := 131072

TARGET_RECOVERY_FSTAB := device/iuni/u2/rootdir/fstab.qcom

TARGET_RELEASETOOLS_EXTENSIONS := device/iuni/u2

# inherit from the proprietary version
-include vendor/gm/e7/BoardConfigVendor.mk

# charger
BOARD_CHARGER_DISABLE_INIT_BLANK := true
HEALTHD_FORCE_BACKLIGHT_CONTROL := true
HEALTHD_BACKLIGHT_ON_LEVEL := 125

# power hal
TARGET_PROVIDES_POWERHAL := true

# keymaster
TARGET_KEYMASTER_WAIT_FOR_QSEE := true

# selinux
include device/qcom/sepolicy/sepolicy.mk

BOARD_SEPOLICY_DIRS += \
    device/iuni/u2/sepolicy
    
#TWRP
TW_THEME := portrait_hdpi
TW_NO_SCREEN_TIMEOUT := true 
TARGET_USERIMAGES_USE_EXT4 := true
TW_FLASH_FROM_STORAGE := true
#TW_INCLUDE_JB_CRYPTO := true
RECOVERY_GRAPHICS_USE_LINELENGTH := true
TARGET_RECOVERY_PIXEL_FORMAT := "RGBX_8888"
TW_EXTRA_LANGUAGES := true
# The real path for this is /sys/devices/mdp.0/qcom,cmdss_fb_primary.148/leds/lcd-backlight/brightness but the comma doesn't compile correctly
TW_BRIGHTNESS_PATH := "/sys/devices/mdp.0/qcom\x2cmdss_fb_primary.148/leds/lcd-backlight/brightness"
TW_MAX_BRIGHTNESS := 255
BOARD_USE_CUSTOM_RECOVERY_FONT := \"roboto_23x41.h\"
