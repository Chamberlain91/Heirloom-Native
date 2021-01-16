cmake_minimum_required(VERSION 3.4.1)

project(decoder)

set(CMAKE_BUILD_TYPE Release)
# set(CMAKE_POSITION_INDEPENDENT_CODE ON)
# set(MAKE_WINDOWS_EXPORT_ALL_SYMBOLS TRUE)
# set(BUILD_SHARED_LIBS TRUE)

add_library(decoder SHARED ../src/decoder.c ../src/miniaudio/extras/stb_vorbis.c)