# Set the minimum required version of CMake
cmake_minimum_required(VERSION 3.0)

# Create a new project
project(leetcode)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# GTest suite
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
FetchContent_MakeAvailable(googletest)
enable_testing()

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/structures/)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/solutions/)

add_executable(
  check_test_cases
  ${CMAKE_CURRENT_SOURCE_DIR}/check_test_cases.cpp
)

target_link_libraries(
  check_test_cases
  gtest_main
  stdc++fs
)

install(
  TARGETS check_test_cases
  EXPORT tests
  DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}
)

include(GoogleTest)
gtest_discover_tests(check_test_cases)

