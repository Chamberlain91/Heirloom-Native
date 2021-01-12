# Heirloom Native Libraries

Build project for native libraries used by Heirloom.

**Note:** These scripts assume Ninja build system is available. Additionally, these scripts require an environment variable named `ANDROID_NDK` to be pointed to the specific NDK directory such as `path/to/android/ndk/21.3.6528147/`.

### Build for Windows
```bat
./build_windows.bat
```

### Build for Linux
```sh
./build_linux.sh
```

### Build for Android
The script for building Android assumes the SDK/NDK is running on a Windows platform.
```bat
./build_android.bat
```

## TODO

* Statically link GLFW and rename project so the lib is named `Heirloom.Native.dll`