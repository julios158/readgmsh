cmake_minimum_required(VERSION 2.8)
project(GmshLem)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

#Bring the headers into the project
include_directories(
  ${GmshLem_SOURCE_DIR}/include
)


SET(GmshLem_src
  src/main.cc
  src/read_mesh_file.cc
)

add_executable(GmshLem ${GmshLem_src})
