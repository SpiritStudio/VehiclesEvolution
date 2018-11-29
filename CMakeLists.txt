#
# Created by SpiritStudio on 28.11.18.
#

cmake_minimum_required(VERSION 3.12)
project(VehiclesEvolution)

include_directories(.)
include_directories(include)

set(CMAKE_CXX_STANDARD 14)

# Define sources and executable
set(EXECUTABLE_NAME "VehiclesEvolution")

add_executable(${EXECUTABLE_NAME}
        src/main.cpp src/Physics/Physics.cpp src/Physics/Car.cpp src/Physics/Map.cpp
        src/EvolutionaryAlgorithm/CarParameters.cpp src/Graphics/Graphics.cpp src/Physics/PhysicsObserver.cpp)

set(SFML_LIBRARIES "${PROJECT_SOURCE_DIR}/lib/libsfml-graphics.so"
                   "${PROJECT_SOURCE_DIR}/lib/libsfml-window.so"
                   "${PROJECT_SOURCE_DIR}/lib/libsfml-system.so"
                   "${PROJECT_SOURCE_DIR}/lib/libsfml-audio.so"
                   "${PROJECT_SOURCE_DIR}/lib/libsfml-network.so" )
set(BOX2D_LIBRARIES "${PROJECT_SOURCE_DIR}/lib/libBox2D.a")

target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES} ${BOX2D_LIBRARIES})



