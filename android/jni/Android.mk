LOCAL_PATH := $(call my-dir)
APP_PLATFORM := android-22

include $(CLEAR_VARS)

LOCAL_LDLIBS := -llog -ldl -lOpenSLES
LOCAL_MODULE := miniaudio
LOCAL_SRC_FILES := ../../miniaudio.c ../../miniaudio/extras/stb_vorbis.c

include $(BUILD_SHARED_LIBRARY)