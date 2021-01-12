cmake_minimum_required(VERSION 3.4.1)
project(miniaudio)

add_library(miniaudio SHARED ../src/miniaudio.c ../src/miniaudio/extras/stb_vorbis.c)

target_link_libraries(miniaudio 
    ${log-lib} ${opensles-lib} ${aaudio-lib})