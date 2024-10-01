cmake_minimum_required(VERSION 3.15)
project(src)

set(EXECUTABLE_OUTPUT_PATH ${EXECPATH})


include_directories(${HEADERPATH})

link_directories(${LIBPATH})
link_libraries(comm)


add_executable(main ./main.cpp)
add_executable(spdlog_test_main ./spdlog_test_main.cpp)





