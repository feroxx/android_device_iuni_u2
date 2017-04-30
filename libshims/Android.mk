LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_SRC_FILES := wvm_shim.cpp
LOCAL_SHARED_LIBRARIES := libstagefright_foundation
LOCAL_MODULE := libshim_wvm
LOCAL_MODULE_TAGS := optional
include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_SRC_FILES := \
    bionic/bionic_time_conversions.cpp \
    bionic/pthread_cond.cpp
LOCAL_SHARED_LIBRARIES := libc
LOCAL_MODULE := libshim_c
LOCAL_CLANG := false
LOCAL_CXX_STL := none
LOCAL_SANITIZE := never
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_CLASS := SHARED_LIBRARIES
include $(BUILD_SHARED_LIBRARY)