cmake_minimum_required(VERSION 3.5)

project(c C)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11 -Wall -Wextra")

add_library(utility STATIC utility.c)
target_include_directories(utility INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(c main.c utility.c)
target_link_libraries(c utility)

enable_testing()
add_subdirectory(tests)