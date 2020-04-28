# https://developer.android.com/ndk/guides/android_mk

LOCAL_PATH:= $(call my-dir)

# libLLVM-8

include $(CLEAR_VARS)

LOCAL_MODULE := libLLVM-8

ifeq (x86_64,$(TARGET_ARCH))
LOCAL_SRC_FILES := $(LOCAL_PATH)/../../../ThirdParty/PosixLinuxX11/Bionic-Redistributable/lib64/libLLVM-8.so
endif

ifeq (x86,$(TARGET_ARCH))
LOCAL_SRC_FILES := $(LOCAL_PATH)/../../../ThirdParty/PosixLinuxX11/Bionic-Redistributable/lib/libLLVM-8.so
endif

include $(PREBUILT_SHARED_LIBRARY) # ndk-build will strip the so

include $(LOCAL_PATH)/PTMatC-Test.mk

include $(LOCAL_PATH)/libPTMatC.mk
