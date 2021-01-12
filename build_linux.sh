#!/bin/sh

cmake -H./desktop -B./desktop/build/linux -G Ninja
ninja -C desktop/build/linux