cmake_minimum_required(VERSION 3.15)
project(src)

set(EXECUTABLE_OUTPUT_PATH ${EXECPATH})


include_directories(
    ${HEADERPATH}
    ../DataMokerSimu/DataCSVGet
    ../DataMokerSimu
    )

link_directories(${LIBPATH})
link_libraries(comm)
link_libraries(history_replayer)

add_executable(main ./main.cpp)
add_executable(spdlog_test_main ./spdlog_test_main.cpp)

add_executable(csv_get_test ./data_csv_get_test.cpp)
target_link_libraries(csv_get_test PUBLIC data_moker_simu)

target_link_libraries(main PUBLIC self_strategy)




