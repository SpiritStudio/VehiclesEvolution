#
# Created by SpiritStudio on 04.12.18.
#

cmake_minimum_required(VERSION 3.8)

set(CMAKE_CXX_STANDARD 14)

# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
                 ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
                 EXCLUDE_FROM_ALL)

# The gtest/gtest_main targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
  include_directories("${gtest_SOURCE_DIR}/include")
endif()

include_directories(..)
include_directories(../include)

set(EXECUTABLE_NAME "runTests")
set(TEST_SOURCES "gtest.cpp" "src/Car.cpp" "src/Map.cpp" "src/Utils.cpp")

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/../cmake_modules" ${CMAKE_MODULE_PATH})

find_package(Box2D REQUIRED) # tested on 2.3.1
find_package(SFML 2 REQUIRED COMPONENTS system window graphics network audio) # tested on 2.4.2
find_package(TGUI 0.8 REQUIRED) # tested on 0.8.5

include_directories(${BOX2D_INCLUDE_DIR} ${SFML_INCLUDE_DIR} ${TGUI_INCLUDE_DIR})

add_executable(${EXECUTABLE_NAME} ${TEST_SOURCES} ../src/Physics/Physics.cpp ../src/Physics/Car.cpp ../src/Physics/Map.cpp
        ../src/EvolutionaryAlgorithm/CarParameters.cpp ../src/Graphics/Graphics.cpp
        ../src/EvolutionaryAlgorithm/EvolutionaryAlgorithm.cpp ../src/Graphics/CarGraphics.cpp
        ../src/Graphics/MapGraphics.cpp ../src/Physics/CarBody.cpp ../src/Physics/Wheel.cpp
        ../src/Graphics/GraphicalUserInterface.cpp ../src/Utils.cpp)

target_link_libraries(${EXECUTABLE_NAME}
        gtest
        ${SFML_LIBRARIES}
        ${SFML_DEPENDENCIES}
        ${BOX2D_LIBRARY}
        ${TGUI_LIBRARY}
        pthread)

