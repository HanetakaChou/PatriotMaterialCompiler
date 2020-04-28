# libPTMatC

include $(CLEAR_VARS)

LOCAL_MODULE := libPTMatC

LOCAL_SRC_FILES:= \
	$(LOCAL_PATH)/../../Private/MatC/MDL/MDLScannerCXX.cpp \
	$(LOCAL_PATH)/../../Private/MatC/MDL/MDLParserCXX.cpp \
	$(LOCAL_PATH)/../../Private/MatC/MDL/MDLFrontend.cpp \
	$(LOCAL_PATH)/../../Private/MatC/MDL/MDLParserForward.cpp \

LOCAL_CFLAGS += -fdiagnostics-format=msvc
LOCAL_CFLAGS += -finput-charset=UTF-8 -fexec-charset=UTF-8
LOCAL_CFLAGS += -fvisibility=hidden
LOCAL_CFLAGS += -DPTMATCAPI=PTEXPORT
	
LOCAL_CPPFLAGS += -std=c++11

LOCAL_LDFLAGS += -Wl,--enable-new-dtags # the linker can't recognize the old dtags
LOCAL_LDFLAGS += -Wl,-rpath,/XXXXXX # chrpath can only make path shorter

LOCAL_STATIC_LIBRARIES := libPTMatC-CXX-Exceptions libPTMatC-C

include $(BUILD_SHARED_LIBRARY)

# libPTMatC-CXX-Exceptions

include $(CLEAR_VARS)

LOCAL_MODULE := libPTMatC-CXX-Exceptions

LOCAL_SRC_FILES:= \
	$(LOCAL_PATH)/../../Private/MatC/MDL/MDLScannerCXX.cpp \
	$(LOCAL_PATH)/../../Private/MatC/MDL/MDLParserCXX.cpp \

LOCAL_CFLAGS += -fdiagnostics-format=msvc
LOCAL_CFLAGS += -finput-charset=UTF-8 -fexec-charset=UTF-8
LOCAL_CFLAGS += -fvisibility=hidden
LOCAL_CFLAGS += -DPTMATCAPI=PTEXPORT

LOCAL_CPPFLAGS += -std=c++11

LOCAL_CPP_FEATURES := exceptions

include $(BUILD_STATIC_LIBRARY)

# libPTMatC-C

include $(CLEAR_VARS)

LOCAL_MODULE := libPTMatC-C

LOCAL_SRC_FILES:= \
	$(LOCAL_PATH)/../../Private/MatC/MDL/MDLScannerLex.c \
	$(LOCAL_PATH)/../../Private/MatC/MDL/MDLParserYacc.c \

LOCAL_CFLAGS += -fdiagnostics-format=msvc
LOCAL_CFLAGS += -finput-charset=UTF-8 -fexec-charset=UTF-8
LOCAL_CFLAGS += -fvisibility=hidden
LOCAL_CFLAGS += -DPTMATCAPI=PTEXPORT

LOCAL_CFLAGS += -x c # to use the C compiler
LOCAL_CFLAGS += -std=c99

include $(BUILD_STATIC_LIBRARY)
