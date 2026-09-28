cmake_minimum_required(VERSION 3.20)

project(freertos_learning C)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Windows simulator port
set(FREERTOS_PORT MSVC_MINGW CACHE STRING "" FORCE)

# FreeRTOS configuration
add_library(freertos_config INTERFACE)

target_include_directories(freertos_config SYSTEM
    INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_compile_definitions(freertos_config
    INTERFACE
        projCOVERAGE_TEST=0
)

# FreeRTOS Kernel
add_subdirectory(FreeRTOS-Kernel)

# Application
add_executable(freertos_learning
    src/main.c
    FreeRTOS-Kernel/portable/MemMang/heap_4.c
)

target_include_directories(freertos_learning PRIVATE
    src
)

target_link_libraries(freertos_learning PRIVATE
    freertos_kernel
)