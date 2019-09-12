/* -- stb vorbis -- */
#define STB_VORBIS_NO_STDIO /* .ogg audio */
#define STB_VORBIS_HEADER_ONLY
#include "miniaudio/extras/stb_vorbis.c"

/* -- dr. soft miniaudio -- */
#define DR_FLAC_IMPLEMENTATION
#include "miniaudio/extras/dr_flac.h" /* .flac */

#define DR_MP3_IMPLEMENTATION
#include "miniaudio/extras/dr_mp3.h" /* .mp3 */

#define DR_WAV_IMPLEMENTATION
#include "miniaudio/extras/dr_wav.h" /* .wav */

#define MA_NO_STDIO
#define MINIAUDIO_IMPLEMENTATION
#include "miniaudio/miniaudio.h" /* Audio System */

#include <stdio.h>

// -- miniaudio extensions (used for bindings in csharp) -- //
#define ma_ext_create(t) (t *)ma_aligned_malloc(sizeof(t), MA_SIMD_ALIGNMENT);

// free structures allocated below
void ma_ext_free(void *ptr) { return ma_aligned_free(ptr); }

// allocate the memory needed for a decoder struct
void *ma_ext_alloc_decoder() { return ma_ext_create(ma_decoder); }

// allocate the memory needed for a device struct
void *ma_ext_alloc_device() { return ma_ext_create(ma_device); }

// allocate the memory needed for a device configuration struct
ma_device_config *ma_ext_alloc_device_config(ma_device_type deviceType, ma_uint32 sampleRate, ma_device_callback_proc dataCallback)
{
    ma_device_config *config = ma_ext_create(ma_device_config);
    ma_zero_object(config);

    // Configure device type and callback
    config->dataCallback = dataCallback;
    config->deviceType = deviceType;

    // Configure to use stereo signed 16 bit audio
    config->sampleRate = sampleRate;
    config->playback.format = ma_format_s16;
    config->playback.channels = 2;
    config->capture.format = ma_format_s16;
    config->capture.channels = 2;

    return config;
}