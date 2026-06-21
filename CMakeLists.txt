cmake_minimum_required(VERSION 3.15)
project(PlaytestTimer)

# Point to the Geode SDK you downloaded
find_package(Geode REQUIRED)

# Define your mod
add_geode_mod(PlaytestTimer
    SOURCES src/main.cpp
)

