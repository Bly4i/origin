cmake_minimum_required(VERSION 3.20)
project(race)


add_executable(race
    src/main.cpp
    src/DistanceLength.cpp
    src/TS_ground.cpp
    src/TS_air.cpp
    src/TS_all.cpp
)
target_include_directories(race PRIVATE headers)