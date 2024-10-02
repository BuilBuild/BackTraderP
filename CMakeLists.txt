cmake_minimum_required(VERSION 3.15)
project(backtraderp)

set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)
# set(CMAKE_CXX_EXTENSIONS OFF)


set(EXECPATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBPATH ${PROJECT_SOURCE_DIR}/lib)

set(HEADERPATH ${PROJECT_SOURCE_DIR}/include)
list(APPEND HEADERPATH ${PROJECT_SOURCE_DIR}/comm 
    ${PROJECT_SOURCE_DIR}/external/spdlog
    ${PROJECT_SOURCE_DIR}/Strategys
    ${PROJECT_SOURCE_DIR}/HistoryReplayer

    )


add_subdirectory(src)
add_subdirectory(comm)
add_subdirectory(HistoryReplayer)
add_subdirectory(Strategys)
add_subdirectory(DataMokerSimu)
# add_subdirectory(tests)