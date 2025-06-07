set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR arm)

set(TOOLCHAIN_PATH "C:/Toolchains/gcc-arm-none-eabi-10.3-2021.10/bin")

set(CMAKE_C_COMPILER   "${TOOLCHAIN_PATH}/arm-none-eabi-gcc.exe" CACHE PATH "C compiler")
set(CMAKE_CXX_COMPILER "${TOOLCHAIN_PATH}/arm-none-eabi-g++.exe" CACHE PATH "C++ compiler")
set(CMAKE_ASM_COMPILER "${TOOLCHAIN_PATH}/arm-none-eabi-gcc.exe" CACHE PATH "ASM compiler")
set(CMAKE_OBJCOPY      "${TOOLCHAIN_PATH}/arm-none-eabi-objcopy.exe" CACHE PATH "Objcopy tool")
set(CMAKE_SIZE         "${TOOLCHAIN_PATH}/arm-none-eabi-size.exe" CACHE PATH "Size tool")

set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)
