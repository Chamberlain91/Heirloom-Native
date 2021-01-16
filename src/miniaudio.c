#include <stdio.h>
#include <stdlib.h>

#define STB_VORBIS_NO_STDIO /* .ogg audio */
#define STB_VORBIS_HEADER_ONLY
#include "miniaudio/extras/stb_vorbis.c"

#define DR_FLAC_NO_STDIO
#define DR_FLAC_IMPLEMENTATION
#include "miniaudio/extras/dr_flac.h" /* .flac */

#define DR_MP3_NO_STDIO
#define DR_MP3_IMPLEMENTATION
#include "miniaudio/extras/dr_mp3.h" /* .mp3 */

#define DR_WAV_NO_STDIO
#define DR_WAV_IMPLEMENTATION
#include "miniaudio/extras/dr_wav.h" /* .wav */

#define MA_DLL
#define MA_NO_STDIO
#define MINIAUDIO_IMPLEMENTATION
#include "miniaudio/miniaudio.h" /* Audio System */

// -- miniaudio extensions (used for bindings in csharp) -- //
#define ma_ext_create(t) (t *)ma_malloc(sizeof(t), NULL);

// free structures allocated below
MA_DLL void ma_ext_free(void *ptr) { ma_free(ptr, NULL); }

// allocate the memory needed for a decoder struct
MA_DLL void *ma_ext_alloc_decoder() { return ma_ext_create(ma_decoder); }

// allocate the memory needed for a device struct
MA_DLL void *ma_ext_alloc_device() { return ma_ext_create(ma_device); }

// allocate the memory needed for a device configuration struct
MA_DLL ma_device_config *ma_ext_alloc_device_config(
    ma_device_type deviceType, ma_uint32 sampleRate,
    ma_device_callback_proc dataCallback) {
  ma_device_config *config = ma_ext_create(ma_device_config);
  MA_ZERO_OBJECT(config);

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