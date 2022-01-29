# CMakeLists.txt
cmake_minimum_required(VERSION 3.5)
project(c_arrays)
add_executable(c_array main.cpp)
target_include_directories(c_array
 PRIVATE
  /home/er/src/boost_1_78_0/)
