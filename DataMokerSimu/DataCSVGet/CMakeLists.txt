cmake_minimum_required(VERSION 3.15)
project(DataCSVGet)

set(CMAKE_CXX_STANDARD 17)

set(EXECUTABLE_OUTPUT_PATH ${EXECPATH})

set(LIBRARY_OUTPUT_PATH ${LIBPATH})
add_library(data_csv_get STATIC DataCSVGet.cpp)

add_executable(data_get main.cpp)