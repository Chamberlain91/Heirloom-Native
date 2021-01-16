#!/bin/sh

cmake -H./desktop -B./desktop/build/linux-x64 -G Ninja
ninja -C desktop/build/linux-x64