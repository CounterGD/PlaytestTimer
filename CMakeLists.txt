cmake_minimum_required(VERSION 3.15)
project(PlaytestTimer)

# Point to the Geode SDK you downloaded
set(Geode_DIR "$ENV{HOME}/geode-sdk/cmake")
find_package(Geode REQUIRED)

# Define your mod
add_geode_mod(PlaytestTimer
    SOURCES src/main.cpp
    VERSION 1.0.0
    # This automatically handles the Geode-specific build requirements
)

