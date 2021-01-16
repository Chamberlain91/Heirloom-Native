#include <stdio.h>
#include <stdlib.h>

#define STB_VORBIS_NO_STDIO /* .ogg */
#define STB_VORBIS_HEADER_ONLY
#include "miniaudio/extras/stb_vorbis.c"

#define DR_MP3_NO_STDIO
#define DR_MP3_IMPLEMENTATION
#include "miniaudio/extras/dr_mp3.h" /* .mp3 */

#define DR_WAV_NO_STDIO
#define DR_WAV_IMPLEMENTATION
#include "miniaudio/extras/dr_wav.h" /* .wav */

// Extras for C# integration

void* alloc_mp3_struct() { return malloc(sizeof(drmp3)); }

void* alloc_wav_struct() { return malloc(sizeof(drwav)); }

int drwav_get_pcm_frame_count(drwav* wav) { return wav->totalPCMFrameCount; }

void free_struct(void* ptr) { return free(ptr); }