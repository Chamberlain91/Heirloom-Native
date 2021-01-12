CC = gcc

# Detect OS
ifeq ($(OS),Windows_NT) 
    detected_OS := Windows
else
    detected_OS := $(shell uname)
endif

.PHONY: all os miniaudio

# Builds everything
all: miniaudio

# Prints detected OS
os:
	@echo "OS '$(detected_OS)'"

MINIAUDIO = miniaudio.c miniaudio/extras/stb_vorbis.c

# Windows
ifeq ($(detected_OS),Windows)

miniaudio: miniaudio.dll

miniaudio.dll: $(MINIAUDIO)
	gcc -fPIC -O3 -shared -o $@ $^

endif

# Linux
ifeq ($(detected_OS),Linux)

miniaudio: libminiaudio.so

libminiaudio.so: $(MINIAUDIO)
	gcc -fPIC -O3 -shared -o $@ $^

endif

# OSX (Darwin)
ifeq ($(detected_OS),Darwin)

miniaudio: libminiaudio.dylib

libminiaudio.dylib: $(MINIAUDIO)
	gcc -fPIC -O3 -shared -o $@ $^

endif