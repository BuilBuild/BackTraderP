cmake_minimum_required(VERSION 3.15)

include_directories(${HEADERPATH})

set(LIBRARY_OUTPUT_PATH ${LIBPATH})

link_directories(${LIBPATH})
link_libraries(comm)

add_library(history_replayer ./HistoryReplayer.cpp)