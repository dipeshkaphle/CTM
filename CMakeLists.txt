cmake_minimum_required(VERSION "3.19.2")

project(CTM)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_FLAGS "-Wall -Wpedantic -Wextra -fsanitize=address")

add_executable(main main.cpp)
add_executable(tests tests.cpp)

set_property(TARGET main PROPERTY CXX_STANDARD 20)
set_property(TARGET tests PROPERTY CXX_STANDARD 20)

target_include_directories(main PUBLIC "${PROJECT_SOURCE_DIR}/includes"
                                       "${PROJECT_SOURCE_DIR}/src")

target_include_directories(tests PUBLIC "${PROJECT_SOURCE_DIR}/includes"
                                        "${PROJECT_SOURCE_DIR}/src")
