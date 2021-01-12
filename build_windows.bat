@echo off

cmake -H.\desktop\ -B.\desktop\build\windows -G Ninja
ninja -C desktop\build\windows