cmake_minimum_required(VERSION 3.15)


include_directories(${CMAKE_CURRENT_SOURCE_DIR}/DataCSVGet)
set(LIBRARY_OUTPUT_PATH ${LIBPATH})

add_library(data_moker_simu STATIC ./DataCSVGet/DataCSVGet.cpp DataMokerSimu.cpp)
