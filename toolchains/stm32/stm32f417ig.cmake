cmake_minimum_required(VERSION 2.8)
cmake_policy(SET CMP0011 NEW)

set(AVERSIVE_TOOLCHAIN_TARGET "stm32f417ig" CACHE STRING "")
set(AVERSIVE_TOOLCHAIN_STM32F417IG 1 CACHE STRING "")
include("${CMAKE_CURRENT_LIST_DIR}/stm32f417.cmake")

set(STM32F417IG_FLAGS "-DAVERSIVE_TOOLCHAIN_STM32F417IG")
set(STM32F417IG_LINKER_FLAGS "-T${CMAKE_CURRENT_LIST_DIR}/linker/STM32F417IGHx_FLASH.ld --specs=nosys.specs")

set(CMAKE_C_FLAGS      "${CMAKE_C_FLAGS} ${STM32F417IG_FLAGS}" CACHE STRING "")
set(CMAKE_CXX_FLAGS    "${CMAKE_CXX_FLAGS} ${STM32F417IG_FLAGS}" CACHE STRING "")
set(CMAKE_ASM_FLAGS    "${CMAKE_ASM_FLAGS} ${STM32F417IG_FLAGS}" CACHE STRING "")

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${STM32F417IG_LINKER_FLAGS}" CACHE STRING "")

unset(STM32F417IG_FLAGS)
