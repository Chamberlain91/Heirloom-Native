cmake_minimum_required(VERSION 3.4.1)

project(miniaudio)

set(CMAKE_BUILD_TYPE Release)
# set(CMAKE_POSITION_INDEPENDENT_CODE ON)
# set(MAKE_WINDOWS_EXPORT_ALL_SYMBOLS TRUE)
# set(BUILD_SHARED_LIBS TRUE)

add_library(miniaudio SHARED ../src/miniaudio.c ../src/miniaudio/extras/stb_vorbis.c)

target_link_libraries(miniaudio)