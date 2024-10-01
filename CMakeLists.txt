cmake_minimum_required(VERSION 3.15)
project(backtraderp)


set(EXECPATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBPATH ${PROJECT_SOURCE_DIR}/lib)

set(HEADERPATH ${PROJECT_SOURCE_DIR}/include)
list(APPEND HEADERPATH ${PROJECT_SOURCE_DIR}/comm 
    ${PROJECT_SOURCE_DIR}/external/spdlog
    
    )


add_subdirectory(src)
add_subdirectory(comm)
# add_subdirectory(tests)