cmake_minimum_required(VERSION "3.12")

project("BigInt")
set (CMAKE_CXX_STANDARD 11)
add_executable("${PROJECT_NAME}" "testing/append_tests.cpp" "BigInt.cpp")