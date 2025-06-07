@echo off
setlocal

set TOOLCHAIN=C:\Toolchains\gcc-arm-none-eabi-10.3-2021.10\bin
set PATH=%TOOLCHAIN%;%PATH%

if exist build (
    rmdir /s /q build
)
mkdir build
cd build

cmake .. -G "Ninja" ^
  -DCMAKE_TOOLCHAIN_FILE=../arm-none-eabi.cmake

cmake --build .

pause