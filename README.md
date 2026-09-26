# FreeRTOS Basics

A hands-on project for learning the fundamentals of real-time embedded
software using FreeRTOS.

The project currently runs the FreeRTOS Kernel on Windows using the
MSVC-MinGW simulator port, allowing RTOS concepts to be explored without
physical embedded hardware.

## Objectives

The goal is to progressively explore:

- Tasks and scheduling
- Task priorities and preemption
- Queues
- Semaphores and mutexes
- Software timers
- Event groups
- Task notifications
- Memory management
- Real-time system architecture

The long-term goal is to migrate the concepts developed here to an
STM32-based embedded system.

## Current Implementation

The current version implements two independent FreeRTOS tasks:

- `SensorTask` — executes periodically every 1 second
- `ProcessingTask` — executes periodically every 2 seconds

This initial implementation demonstrates task creation, scheduling,
priorities, and blocking using `vTaskDelay()`.

## Project Structure

    freertos-basics/
    ├── FreeRTOS-Kernel/     # FreeRTOS Git submodule
    ├── src/
    │   ├── main.c
    │   └── FreeRTOSConfig.h
    ├── CMakeLists.txt
    ├── .gitmodules
    ├── .gitignore
    └── README.md

## Requirements

- GCC / MinGW
- CMake
- Git

## Building

Clone the repository including the FreeRTOS submodule:

    git clone --recurse-submodules <repository-url>

Create the build directory:

    mkdir build
    cd build

Configure the project:

    cmake .. -G "MinGW Makefiles"

Build:

    cmake --build .

Run:

    .\freertos_learning.exe

## Roadmap

- [x] FreeRTOS Windows simulator setup
- [x] Basic task creation
- [x] Task priorities
- [x] Periodic task execution
- [ ] Queues
- [ ] Simulated sensor acquisition
- [ ] Processing task
- [ ] Telemetry task
- [ ] Semaphores and mutexes
- [ ] Software timers
- [ ] STM32 migration