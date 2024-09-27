cmake_minimum_required(VERSION 3.15)
project(comm)


# 搜索源文件
aux_source_directory(./ SRC)
# 搜索头文件目录
include_directories(${HEADERPATH})
# 指定静态库生成路径
set(LIBRARY_OUTPUT_PATH ${LIBPATH})


add_library(comm STATIC ${SRC})

# add_subdirectory(../rapidcsv)


