LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)
LOCAL_SRC_FILES := gn_cam.c
LOCAL_MODULE := libgn_cam
LOCAL_MODULE_TAGS := optional
include $(BUILD_SHARED_LIBRARY)
