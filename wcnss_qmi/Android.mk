LOCAL_PATH:= $(call my-dir)

#----------------------------------------------------------------------
# Copy additional target-specific files
#----------------------------------------------------------------------
ifeq ($(strip $(BOARD_HAS_QCOM_WLAN)),true)
include $(CLEAR_VARS)
LOCAL_MODULE           := libwcnss_qmi
LOCAL_MODULE_TAGS      := optional
LOCAL_C_INCLUDES       += hardware/qcom/wlan/wcnss_service
LOCAL_SRC_FILES        := wcnss_client.c
LOCAL_CFLAGS           += -Wall
LOCAL_SHARED_LIBRARIES := libc libcutils libutils liblog libqminvapi
endif
