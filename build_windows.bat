@echo off

cmake -H.\desktop\ -B.\desktop\build\win-x64 -G Ninja
ninja -C desktop\build\win-x64