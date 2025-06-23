cmake_minimum_required(VERSION 3.10.0)
project(calcProject VERSION 0.1.0 LANGUAGES C CXX)

include(FetchContent)

add_executable(calcProject)

target_sources(calcProject PRIVATE
    src/main.cpp
    src/helpers.cpp
)

FetchContent_Declare(
  mathlib
  SOURCE_DIR ${CMAKE_SOURCE_DIR}/mathlib
)

FetchContent_MakeAvailable(mathlib)

target_link_libraries(calcProject PRIVATE mathlib)