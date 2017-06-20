#
# Copyright (C) YuqiaoZhang
# 
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU Lesser General Public License as published
# by the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
# 
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU Lesser General Public License for more details.
# 
# You should have received a copy of the GNU Lesser General Public License
# along with this program.  If not, see <https://www.gnu.org/licenses/>.
#

# https://developer.android.com/ndk/guides/android_mk

LOCAL_PATH:= $(call my-dir)

# libpt_matc

include $(CLEAR_VARS)

LOCAL_MODULE := libpt_matc

LOCAL_SRC_FILES:= \
	$(abspath $(LOCAL_PATH)/../../src)/pt_matc_mdl_scanner_cxx.cpp \
	$(abspath $(LOCAL_PATH)/../../src)/pt_matc_mdl_parser_cxx.cpp \
	$(abspath $(LOCAL_PATH)/../../src)/pt_matc_mdl_frontend.cpp \
	$(abspath $(LOCAL_PATH)/../../src)/pt_matc_mdl_parser_forward.cpp \

LOCAL_CFLAGS += -fdiagnostics-format=msvc
LOCAL_CFLAGS += -finput-charset=UTF-8 -fexec-charset=UTF-8
LOCAL_CFLAGS += -fvisibility=hidden
LOCAL_CFLAGS += -DPT_MATC_ATTR=PT_EXPORT
	
LOCAL_CPPFLAGS += -std=c++11

LOCAL_LDFLAGS += -finput-charset=UTF-8 -fexec-charset=UTF-8
LOCAL_LDFLAGS += -Wl,--enable-new-dtags # the linker can't recognize the old dtags
LOCAL_LDFLAGS += -Wl,-rpath,XORIGIN # chrpath can only make path shorter # fix me: define the $ORIGIN correctly in the Linux_X11.mk
LOCAL_LDFLAGS += -Wl,--version-script,$(abspath $(LOCAL_PATH))/pt_matc.def

LOCAL_STATIC_LIBRARIES := libpt_matc_cxx_exceptions libpt_matc_c

LOCAL_EXPORT_C_INCLUDES := $(abspath $(LOCAL_PATH)/../../include) 

include $(BUILD_SHARED_LIBRARY)

# libpt_matc_cxx_exceptions

include $(CLEAR_VARS)

LOCAL_MODULE := libpt_matc_cxx_exceptions

LOCAL_SRC_FILES:= \
	$(abspath $(LOCAL_PATH)/../../src)/pt_matc_mdl_scanner_cxx.cpp \
	$(abspath $(LOCAL_PATH)/../../src)/pt_matc_mdl_parser_cxx.cpp \

LOCAL_CFLAGS += -fdiagnostics-format=msvc
LOCAL_CFLAGS += -finput-charset=UTF-8 -fexec-charset=UTF-8
LOCAL_CFLAGS += -fvisibility=hidden
LOCAL_CFLAGS += -DPT_MATC_ATTR=PT_EXPORT

LOCAL_CPPFLAGS += -std=c++11

LOCAL_CPP_FEATURES := exceptions

include $(BUILD_STATIC_LIBRARY)

# libpt_matc_c

include $(CLEAR_VARS)

LOCAL_MODULE := libpt_matc_c

LOCAL_SRC_FILES:= \
	$(abspath $(LOCAL_PATH)/../../src)/pt_matc_mdl_scanner_lex.c \
	$(abspath $(LOCAL_PATH)/../../src)/pt_matc_mdl_parser_yacc.c \

LOCAL_CFLAGS += -fdiagnostics-format=msvc
LOCAL_CFLAGS += -finput-charset=UTF-8 -fexec-charset=UTF-8
LOCAL_CFLAGS += -fvisibility=hidden
LOCAL_CFLAGS += -DPT_MATC_ATTR=PT_EXPORT

LOCAL_CFLAGS += -x c # to use the C compiler
LOCAL_CFLAGS += -std=c99

include $(BUILD_STATIC_LIBRARY)

# examples / matc_test

include $(CLEAR_VARS)

LOCAL_MODULE := pt_matc_test

LOCAL_SRC_FILES:= \
	$(abspath $(LOCAL_PATH)/../../examples/matc_test)/main.cpp \

LOCAL_CFLAGS += -fdiagnostics-format=msvc
LOCAL_CFLAGS += -finput-charset=UTF-8 -fexec-charset=UTF-8
LOCAL_CFLAGS += -fvisibility=hidden

LOCAL_CPPFLAGS += -std=c++11

LOCAL_LDFLAGS += -finput-charset=UTF-8 -fexec-charset=UTF-8
LOCAL_LDFLAGS += -Wl,--enable-new-dtags # the linker can't recognize the old dtags
LOCAL_LDFLAGS += -Wl,-rpath,XORIGIN # chrpath can only make path shorter
LOCAL_LDFLAGS += -Wl,--version-script,$(abspath $(LOCAL_PATH))/pt_matc_test.def

LOCAL_SHARED_LIBRARIES := libpt_matc

include $(BUILD_EXECUTABLE)