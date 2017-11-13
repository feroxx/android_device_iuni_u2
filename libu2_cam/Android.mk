LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)
LOCAL_SRC_FILES := u2_cam.cpp
LOCAL_SHARED_LIBRARIES := libutils libcutils
LOCAL_MODULE := libu2_cam
LOCAL_MODULE_TAGS := optional
include $(BUILD_SHARED_LIBRARY)
