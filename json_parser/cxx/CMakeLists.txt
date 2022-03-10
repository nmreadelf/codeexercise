cmake_minimum_required (VERSION 2.9)
project (leptjson_test CXX)

add_library(leptjson leptjson.cpp)
add_executable(leptjson_test test.cpp)
target_link_libraries(leptjson_test leptjson gtest pthread)
