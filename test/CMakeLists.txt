#
# Created by SpiritStudio on 04.12.18.
#

cmake_minimum_required(VERSION 2.6)

set(GTEST_LIBRARIES "${PROJECT_SOURCE_DIR}/../lib/libgtest.a"
        "${PROJECT_SOURCE_DIR}/../lib/libgtest_main.a")

include_directories(.)
include_directories(..)
include_directories(../include)

# Link runTests with what we want to test and the GTest
add_executable(runTests gtest.cpp)

target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)