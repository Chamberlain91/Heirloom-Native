@echo off

set NDK_PATH=%ANDROID_NDK%
set ABI=arm64-v8a armeabi-v7a x86 x86_64

for %%a in (%ABI%) do (
    cmake -H.\android\ -B.\android\build\%%a -DANDROID_ABI=%%a -DANDROID_PLATFORM=29 -DANDROID_NDK=%NDK_PATH% -DCMAKE_TOOLCHAIN_FILE=%NDK_PATH%\build\cmake\android.toolchain.cmake -G Ninja
    ninja -C android\build\%%a
)