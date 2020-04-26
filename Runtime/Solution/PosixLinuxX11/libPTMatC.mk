# libPTMatC

include $(CLEAR_VARS)

LOCAL_MODULE := libPTMatC

LOCAL_SRC_FILES:= \
	$(LOCAL_PATH)/../../Private/MatC/MDL/MDLScanner.cpp \
	$(LOCAL_PATH)/../../Private/MatC/MDL/MDLParser.cpp \
	$(LOCAL_PATH)/../../Private/MatC/MDL/MDLFrontend.cpp \
	$(LOCAL_PATH)/../../Private/MatC/MDL/MDLParserForward.cpp \
	$(LOCAL_PATH)/../../Private/MatC/PT_MatC_Stream.cpp \

LOCAL_CFLAGS += -fdiagnostics-format=msvc
LOCAL_CFLAGS += -finput-charset=UTF-8 -fexec-charset=UTF-8
LOCAL_CFLAGS += -fvisibility=hidden
LOCAL_CFLAGS += -DPTMATCAPI=PTEXPORT
	
LOCAL_CPPFLAGS += -std=c++11

LOCAL_LDFLAGS += -finput-charset=UTF-8 -fexec-charset=UTF-8
LOCAL_LDFLAGS += -Wl,--enable-new-dtags # the linker can't recognize the old dtags
LOCAL_LDFLAGS += -Wl,-rpath,/XXXXXX # chrpath can only make path shorter

LOCAL_CPP_FEATURES := exceptions

LOCAL_STATIC_LIBRARIES := libMDLScanner libMDLParser

include $(BUILD_SHARED_LIBRARY)

# libMDLScanner

include $(CLEAR_VARS)

LOCAL_MODULE := libMDLScanner

LOCAL_SRC_FILES:= \
	$(LOCAL_PATH)/../../Private/MatC/MDL/MDLScanner.c \

LOCAL_CFLAGS += -x c #to use C compiler
LOCAL_CFLAGS += -fdiagnostics-format=msvc
LOCAL_CFLAGS += -finput-charset=UTF-8 -fexec-charset=UTF-8
LOCAL_CFLAGS += -fvisibility=hidden
LOCAL_CFLAGS += -DPTMATCAPI=PTEXPORT

include $(BUILD_STATIC_LIBRARY)

# libMDLParser

include $(CLEAR_VARS)

LOCAL_MODULE := libMDLParser

LOCAL_SRC_FILES:= \
	$(LOCAL_PATH)/../../Private/MatC/MDL/MDLParser.c \

LOCAL_CFLAGS += -x c
LOCAL_CFLAGS += -fdiagnostics-format=msvc
LOCAL_CFLAGS += -finput-charset=UTF-8 -fexec-charset=UTF-8
LOCAL_CFLAGS += -fvisibility=hidden
LOCAL_CFLAGS += -DPTMATCAPI=PTEXPORT

include $(BUILD_STATIC_LIBRARY)