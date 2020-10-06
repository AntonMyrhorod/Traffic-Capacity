cmake_minimum_required(VERSION 3.1)

message(STATUS "CMake version: ${CMAKE_VERSION}")

project(
    traffic-capacity
    VERSION 0.0.1
    LANGUAGES CXX
)

# Project targets
set(TARGET ${PROJECT_NAME})

# Local cmake modules
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/cmake)

include(options)

# 3rdParty
#add_subdirectory(3rdparty)

# Sources
add_subdirectory(src)
