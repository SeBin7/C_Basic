cmake_minimum_required(VERSION 3.16)

project(C_Basic C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


if (MSVC)
  add_compile_options(/W4)
 else()
  add_compile_options(-Wall -Wextra -Wpedantic)

endif()

add_subdirectory(chapters/00_practice)
add_subdirectory(chapters/01_basics)
add_subdirectory(chapters/02_system)
add_subdirectory(chapters/03_optimization)
add_subdirectory(chapters/04_parallel)