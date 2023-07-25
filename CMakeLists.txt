cmake_minimum_required(VERSION 3.14)

project(libCPP_Algebra LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(libCPP_Algebra SHARED
  libCPP_Algebra_global.h
  algebra.cpp
  algebra.h
)

target_compile_definitions(libCPP_Algebra PRIVATE LIBCPP_ALGEBRA_LIBRARY)
