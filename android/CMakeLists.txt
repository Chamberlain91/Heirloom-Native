cmake_minimum_required(VERSION 3.4.1)
project(miniaudio)

add_library(miniaudio SHARED ../src/miniaudio.c ../src/miniaudio/extras/stb_vorbis.c)

find_library(opensles-lib OpenSLES)
find_library(aaudio-lib aaudio)
find_library(log-lib log)

target_link_libraries(miniaudio 
    ${log-lib} ${opensles-lib} ${aaudio-lib})