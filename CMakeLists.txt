cmake_minimum_required(VERSION 3.10)
project(platformer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SDL3 REQUIRED)

include_directories(${SDL3_INCLUDE_DIRS})

add_executable(platformer 
    src/core/main.cpp
    src/player/player.cpp
)

target_link_libraries(platformer ${SDL3_LIBRARIES}) 