cmake_minimum_required(VERSION 3.15)
project(src)

set(EXECUTABLE_OUTPUT_PATH ${EXECPATH})
include_directories(../comm)
# message(header src ${HEADERPATH})
link_directories(${LIBPATH})
link_libraries(comm)


add_executable(main ./main.cpp)
message(=================== ${CMAKE_CURRENT_SOURCE_DIR}/gtest)
find_package(GoogleTest)




