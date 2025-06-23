add_library(mathlib STATIC
  math.cpp
)

target_include_directories(mathlib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})