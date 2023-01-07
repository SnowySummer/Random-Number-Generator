cmake_minimum_required(VERSION 3.16.3)

set(CMAKE_C_COMPILER "gcc")

project(qlib_rng)


add_library(${PROJECT_NAME}
    src/rng.c
)


add_executable(test test/test.c)
target_link_libraries(test ${PROJECT_NAME})
target_include_directories(test PUBLIC src)
