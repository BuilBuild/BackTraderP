cmake_minimum_required(VERSION 3.15)
project(backtraderp)


set(EXECPATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBPATH ${PROJECT_SOURCE_DIR}/lib)
set(HEADERPATH ${PROJECT_SOURCE_DIR}/include
            ${PROJECT_SOURCE_DIR}/comm
    )
# list(APPEND HEADERPATH ${PROJECT_SOURCE_DIR}/comm)

message(headerpath ${HEADERPATH})


set(HEADERPATH comm)

add_subdirectory(src)
add_subdirectory(comm)
add_subdirectory(rapidcsv)
add_subdirectory(gtest)
add_subdirectory(rapidjson)