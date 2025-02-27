cmake_minimum_required(VERSION 3.20)
project(race)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)


set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_library(racelib SHARED
    src/TS_air.cpp
    src/TS_all.cpp
    src/TS_ground.cpp
)

target_include_directories(racelib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/headers
)

add_executable(race src/main.cpp)
target_link_libraries(race PRIVATE racelib)