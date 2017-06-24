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

# Build
TARGET_USE_SDCLANG := true

BOARD_KERNEL_BASE := 0x00000000
BOARD_KERNEL_CMDLINE := console=ttyHSL0,115200,n8 androidboot.selinux=permissive androidboot.hardware=qcom msm_rtb.filter=0x37 ehci-hcd.park=3 androidboot.bootdevice=msm_sdcc.1
BOARD_KERNEL_PAGESIZE := 2048
BOARD_KERNEL_SEPARATED_DT := true
BOARD_MKBOOTIMG_ARGS := --ramdisk_offset 0x02000000 --kernel_offset 0x00008000
BOARD_DTBTOOL_ARGS := -2
TARGET_KERNEL_ARCH := arm
TARGET_KERNEL_CONFIG := e7_defconfig
TARGET_KERNEL_SOURCE := kernel/gm/e7

# global
TARGET_SPECIFIC_HEADER_PATH := device/iuni/u2/include
BOARD_USES_QCOM_HARDWARE := true

# Display
USE_OPENGL_RENDERER := true
TARGET_USES_ION := true
HAVE_ADRENO_SOURCE:= false
OVERRIDE_RS_DRIVER:= libRSDriver_adreno.so
NUM_FRAMEBUFFER_SURFACE_BUFFERS := 3
TARGET_FORCE_HWC_FOR_VIRTUAL_DISPLAYS := true
TARGET_HAS_HH_VSYNC_ISSUE := true
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
ORIGINAL_VERSION := true
TARGET_USE_VENDOR_CAMERA_EXT := true
TARGET_HAS_LEGACY_CAMERA_HAL1 := true

# Media
TARGET_USES_MEDIA_EXTENSIONS := true

# RIL
BOARD_GLOBAL_CFLAGS += -DUSE_RIL_VERSION_10
BOARD_GLOBAL_CPPFLAGS += -DUSE_RIL_VERSION_10
TARGET_RIL_VARIANT := caf

# Sensors
TARGET_NEEDS_PLATFORM_TEXT_RELOCATIONS := true

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
BOARD_RECOVERYIMAGE_PARTITION_SIZE := 19977216
BOARD_SYSTEMIMAGE_PARTITION_SIZE   := 1073741824
BOARD_USERDATAIMAGE_FILE_SYSTEM_TYPE := ext4
BOARD_USERDATAIMAGE_PARTITION_SIZE := 13747929088 # 13747945472 - 16384 for crypto footer
#BOARD_USERDATAIMAGE_PARTITION_SIZE := 3221225472
BOARD_FLASH_BLOCK_SIZE := 131072

TARGET_RECOVERY_FSTAB := device/iuni/u2/rootdir/fstab.qcom

TARGET_RELEASETOOLS_EXTENSIONS := device/iuni/u2

# inherit from the proprietary version
-include vendor/iuni/u2/BoardConfigVendor.mk
-include vendor/qcom/binaries/msm8974/graphics/BoardConfigVendor.mk

# Charger
BOARD_CHARGER_ENABLE_SUSPEND := true

# CM Hardware
BOARD_USES_CYANOGEN_HARDWARE := true
TARGET_TAP_TO_WAKE_NODE := "/sys/devices/platform/tp_wake_switch/double_wake"
BOARD_HARDWARE_CLASS := hardware/cyanogen/cmhw

# Enable dex-preoptimization to speed up first boot sequence
ifeq ($(HOST_OS),linux)
  ifeq ($(TARGET_BUILD_VARIANT),user)
    ifeq ($(WITH_DEXPREOPT),)
      WITH_DEXPREOPT := true
    endif
  endif
endif
DONT_DEXPREOPT_PREBUILTS := true

# Lights
TARGET_PROVIDES_LIBLIGHT := true

# keymaster
TARGET_KEYMASTER_WAIT_FOR_QSEE := true

# selinux
include device/qcom/sepolicy/sepolicy.mk

BOARD_SEPOLICY_DIRS += \
    device/iuni/u2/sepolicy

# Recovery: TWRP support
ifeq ($(WITH_TWRP),true)
-include device/iuni/u2/twrp.mk
endif

TARGET_USERIMAGES_USE_EXT4 := true
