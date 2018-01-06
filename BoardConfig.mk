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
TARGET_OTA_ASSERT_DEVICE := none
TARGET_BOARD_PLATFORM := msm8974
TARGET_BOARD_PLATFORM_GPU := qcom-adreno330

BOARD_KERNEL_BASE := 0x00000000
BOARD_KERNEL_CMDLINE := console=ttyHSL0,115200,n8 androidboot.selinux=permissive androidboot.hardware=qcom androidboot.bootdevice=msm_sdcc.1
BOARD_KERNEL_PAGESIZE := 2048
BOARD_KERNEL_IMAGE_NAME := zImage
BOARD_KERNEL_SEPARATED_DT := true
BOARD_MKBOOTIMG_ARGS := --ramdisk_offset 0x02000000 --kernel_offset 0x00008000
BOARD_DTBTOOL_ARGS := -2
TARGET_KERNEL_ARCH := arm
TARGET_KERNEL_CONFIG := e7_defconfig
TARGET_KERNEL_SOURCE := kernel/gm/e7
TARGET_KERNEL_CROSS_COMPILE_PREFIX := arm-linux-androideabi-

# global
TARGET_SPECIFIC_HEADER_PATH := device/iuni/u2/include
BOARD_USES_QCOM_HARDWARE := true

# Binder API version
TARGET_USES_64_BIT_BINDER := true

# Graphics
USE_OPENGL_RENDERER               := true
TARGET_CONTINUOUS_SPLASH_ENABLED  := true
TARGET_USES_C2D_COMPOSITION       := true
TARGET_USES_ION                   := true
OVERRIDE_RS_DRIVER                := libRSDriver_adreno.so
NUM_FRAMEBUFFER_SURFACE_BUFFERS   := 3
MAX_EGL_CACHE_KEY_SIZE := 12*1024
MAX_EGL_CACHE_SIZE := 2048*1024

# Time Daemon
BOARD_USES_QC_TIME_SERVICES := true
TARGET_POWERHAL_VARIANT             := qcom

# Audio
BOARD_USES_ALSA_AUDIO                      := true
AUDIO_FEATURE_ENABLED_MULTI_VOICE_SESSIONS := true

# Camera
USE_DEVICE_SPECIFIC_CAMERA := true
TARGET_NEEDS_PLATFORM_TEXT_RELOCATIONS := true
TARGET_HAS_LEGACY_CAMERA_HAL1 := true
TARGET_USES_NON_TREBLE_CAMERA := true

# HIDL
DEVICE_MANIFEST_FILE := device/iuni/u2/manifest.xml

# Bluetooth
BOARD_HAVE_BLUETOOTH := true
BOARD_HAVE_BLUETOOTH_QCOM := true
BLUETOOTH_HCI_USE_MCT := true
BOARD_BLUETOOTH_BDROID_BUILDCFG_INCLUDE_DIR := device/iuni/u2/bluetooth


# Wifi
BOARD_HAS_QCOM_WLAN              := true
BOARD_HAS_QCOM_WLAN_SDK          := true
BOARD_WLAN_DEVICE                := qcwcn
BOARD_WPA_SUPPLICANT_DRIVER      := NL80211
BOARD_WPA_SUPPLICANT_PRIVATE_LIB := lib_driver_cmd_qcwcn
BOARD_HOSTAPD_DRIVER             := NL80211
BOARD_HOSTAPD_PRIVATE_LIB        := lib_driver_cmd_qcwcn
PRODUCT_VENDOR_MOVE_ENABLED      := true
TARGET_USES_WCNSS_CTRL           := true
TARGET_USES_QCOM_WCNSS_QMI       := true
TARGET_USES_WCNSS_MAC_ADDR_REV   := true
TARGET_WCNSS_MAC_PREFIX          := e8bba8
WIFI_DRIVER_FW_PATH_STA          := "sta"
WIFI_DRIVER_FW_PATH_AP           := "ap"
WPA_SUPPLICANT_VERSION           := VER_0_8_X

BOARD_BOOTIMAGE_PARTITION_SIZE     := 16777216
BOARD_CACHEIMAGE_FILE_SYSTEM_TYPE := ext4
BOARD_CACHEIMAGE_PARTITION_SIZE    := 536870912
BOARD_PERSISTIMAGE_FILE_SYSTEM_TYPE := ext4
BOARD_PERSISTIMAGE_PARTITION_SIZE  := 33554432
BOARD_RECOVERYIMAGE_PARTITION_SIZE := 22777216
BOARD_SYSTEMIMAGE_PARTITION_SIZE   := 1073741824
BOARD_USERDATAIMAGE_FILE_SYSTEM_TYPE := ext4
BOARD_USERDATAIMAGE_PARTITION_SIZE := 13747929088 # 13747945472 - 16384 for crypto footer
#BOARD_USERDATAIMAGE_PARTITION_SIZE := 3221225472
BOARD_FLASH_BLOCK_SIZE := 131072

TARGET_RECOVERY_FSTAB := device/iuni/u2/rootdir/fstab.qcom

TARGET_RELEASETOOLS_EXTENSIONS := device/iuni/u2

# inherit from the proprietary version
-include vendor/iuni/u2/BoardConfigVendor.mk

# Charger
BOARD_CHARGER_DISABLE_INIT_BLANK := true
BACKLIGHT_PATH := /sys/class/leds/lcd-backlight/brightness

# CM Hardware
TARGET_TAP_TO_WAKE_NODE := "/sys/devices/platform/tp_wake_switch/double_wake"

# Lights
TARGET_PROVIDES_LIBLIGHT := true

# keymaster
TARGET_KEYMASTER_WAIT_FOR_QSEE := true

# selinux
#include device/qcom/sepolicy/legacy-sepolicy.mk
#include device/qcom/sepolicy/sepolicy.mk
BOARD_SEPOLICY_DIRS += device/iuni/u2/sepolicy

#TWRP
TW_USE_TOOLBOX := true
TW_EXCLUDE_SUPERSU := true
TW_THEME := portrait_hdpi
TW_NO_SCREEN_TIMEOUT := true 
TARGET_USERIMAGES_USE_EXT4 := true
BOARD_HAS_NO_REAL_SDCARD := true
TW_NO_USB_STORAGE := true
TW_FLASH_FROM_STORAGE := true
RECOVERY_GRAPHICS_USE_LINELENGTH := true
TARGET_RECOVERY_PIXEL_FORMAT := "RGBX_8888"
TW_BRIGHTNESS_PATH := "/sys/devices/mdp.0/qcom\x2cmdss_fb_primary.148/leds/lcd-backlight/brightness"
TW_MAX_BRIGHTNESS := 255
TW_EXTRA_LANGUAGES := true
#RECOVERY_VARIANT := twrp
BOARD_USE_CUSTOM_RECOVERY_FONT := \"roboto_23x41.h\"
