cmake_minimum_required(VERSION 3.15)

include_directories(${HEADERPATH})

set(LIBRARY_OUTPUT_PATH ${LIBPATH})

add_library(self_strategy  SHARED ./Strategys.cpp)
# target_link_directories(${LIBPATH})
# target_link_libraries()