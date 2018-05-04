cmake_minimum_required(VERSION 2.8)
project(GmshLem)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

#Bring the headers into the project
include_directories(
  ${GmshLem_SOURCE_DIR}/include
)

#Can manually add the sources using the set command as follows:
#set(SOURCES src/mainapp.cpp src/Student.cpp)

#However, the file(GLOB...) allows for wildcard additions:
SET(GmshLem_src
  src/main.cc
)

add_executable(GmshLem ${GmshLem_src})
