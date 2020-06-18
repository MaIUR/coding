cmake_minimum_required(VERSION 3.16)
project(coding)

set(CMAKE_CXX_STANDARD 14)

file (GLOB files PTA/*.cpp newcoder/*.cpp leetcode/*.cpp)
foreach (file ${files})
string(REGEX REPLACE ".+/(.+)\\..*" "\\1" exe ${file})
add_executable (${exe} ${file} PTA/Emergency.cpp)
message (\ \ \ \ --\ src/${exe}.cpp\ will\ be\ compiled\ to\ bin/${exe})
endforeach ()