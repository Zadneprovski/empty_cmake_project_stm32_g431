cmake_minimum_required(VERSION 3.20)

set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR arm)

set(TOOLCHAIN_PREFIX "C:/Toolchains/gcc-arm-none-eabi-10.3-2021.10/bin")

set(CMAKE_C_COMPILER   ${TOOLCHAIN_PREFIX}/arm-none-eabi-gcc.exe)
set(CMAKE_CXX_COMPILER ${TOOLCHAIN_PREFIX}/arm-none-eabi-g++.exe)
set(CMAKE_ASM_COMPILER ${TOOLCHAIN_PREFIX}/arm-none-eabi-gcc.exe)
set(CMAKE_OBJCOPY ${TOOLCHAIN_PREFIX}/arm-none-eabi-objcopy.exe)
set(CMAKE_SIZE    ${TOOLCHAIN_PREFIX}/arm-none-eabi-size.exe)

project(empty_cmake_project_stm32_g431 LANGUAGES C CXX ASM)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(LINKER_SCRIPT "${CMAKE_CURRENT_SOURCE_DIR}/STM32G431RBTX_FLASH.ld")

file(GLOB_RECURSE PROJECT_SOURCES
    "Core/*.c"
    "Core/*.cpp"
    "Core/*.s"
    "Drivers/*.c"
    "Drivers/*.cpp"
    "Drivers/*.s"
    # Подключение библиотеки
    "../libzm/*.c"
    "../libzm/*.cpp"
)

set(ALL_INCLUDES
    ${CMAKE_CURRENT_SOURCE_DIR}/Core/Inc
    ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/CMSIS/Device/ST/STM32G4xx/Include
    ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/CMSIS/Include
    ${CMAKE_CURRENT_SOURCE_DIR}/../libzm/inc
)

set(PROJECT_DEFINES
    STM32G431xx
)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})

target_sources(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/Core/Startup/startup_stm32g431rbtx.s
)

target_include_directories(${PROJECT_NAME} PRIVATE ${ALL_INCLUDES})
target_compile_definitions(${PROJECT_NAME} PRIVATE ${PROJECT_DEFINES})

target_compile_options(${PROJECT_NAME} PRIVATE
    -mcpu=cortex-m4
    -mfpu=fpv4-sp-d16
    -mfloat-abi=hard
    -mthumb
    -O0
    -Wall
    #-Werror
)

target_link_options(${PROJECT_NAME} PRIVATE
	-T${LINKER_SCRIPT}
    -mcpu=cortex-m4
    -mfpu=fpv4-sp-d16
    -mfloat-abi=hard
    -mthumb
    --specs=nano.specs
    --specs=nosys.specs
    -Wl,--gc-sections
    -static
    -Wl,--start-group
    -lc
    -lm
    -Wl,--end-group
)

set_source_files_properties(
    ${CMAKE_CURRENT_SOURCE_DIR}/Core/Startup/startup_stm32g431rbtx.s
    PROPERTIES
    COMPILE_FLAGS "-x assembler-with-cpp"
)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_SIZE} $<TARGET_FILE:${PROJECT_NAME}>
)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} -O ihex    $<TARGET_FILE:${PROJECT_NAME}> ${PROJECT_NAME}.hex
    COMMAND ${CMAKE_OBJCOPY} -O binary  $<TARGET_FILE:${PROJECT_NAME}> ${PROJECT_NAME}.bin
)
