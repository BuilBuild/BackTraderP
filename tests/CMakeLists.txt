cmake_minimum_required(VERSION 3.15)

project(tests)

# require C++11
# set(CMAKE_CXX_STANDARD 11)
# set(CMAKE_CXX_EXTENSIONS OFF)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)

# set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

set(EXECUTABLE_OUTPUT_PATH ${EXECPATH})



# we will use the network to fetch Google Test sources
# make it possible to disable unit tests when not on network
option(ENABLE_UNIT_TESTS "Enable unit tests" ON)
message(STATUS "Enable testing: ${ENABLE_UNIT_TESTS}")
include(FetchContent)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
# set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

find_package(Boost)

enable_testing()

add_executable(
  hello_test
  hello_test.cc
)
target_link_libraries(
  hello_test
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(hello_test)

