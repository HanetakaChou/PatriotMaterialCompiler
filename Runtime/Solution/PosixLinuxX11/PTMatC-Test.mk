# PTMatC-Test

include $(CLEAR_VARS)

LOCAL_MODULE := PTMatC-Test

LOCAL_SRC_FILES:= \
	$(LOCAL_PATH)/../../main.cpp \

#	$(LOCAL_PATH)/../../Private/MatC/llvm_ops.bc.cpp \

LOCAL_CFLAGS += -fdiagnostics-format=msvc
LOCAL_CFLAGS += -finput-charset=UTF-8 -fexec-charset=UTF-8
LOCAL_CFLAGS += -fvisibility=hidden

LOCAL_CPPFLAGS += -std=c++11

LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../../ThirdParty/PosixLinuxX11/Bionic-Redistributable/include/

LOCAL_LDFLAGS += -finput-charset=UTF-8 -fexec-charset=UTF-8
LOCAL_LDFLAGS += -Wl,--enable-new-dtags # the linker can't recognize the old dtags
LOCAL_LDFLAGS += -Wl,-rpath,/XXXXXX # chrpath can only make path shorter

LOCAL_SHARED_LIBRARIES := libPTMatC libLLVM-8

include $(BUILD_EXECUTABLE)