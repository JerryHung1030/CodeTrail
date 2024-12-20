# CMakeLists.txt
cmake_minimum_required(VERSION 3.10)
project(word_count)

set(CMAKE_CXX_STANDARD 11)

# 主程式
add_executable(word_count src/word_count.cpp)

# 測試
enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(test_word_count src/test_word_count.cpp)
target_link_libraries(test_word_count ${GTEST_LIBRARIES} pthread)

add_test(NAME WordCountTest COMMAND test_word_count)
