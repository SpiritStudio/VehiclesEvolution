cmake_minimum_required(VERSION 3.12)
project(VehiclesEvolution)

include_directories(.)

set(CMAKE_CXX_STANDARD 14)

# Define sources and executable
set(EXECUTABLE_NAME "VehiclesEvolution")
add_executable(${EXECUTABLE_NAME}
        main.cpp
        ${PROJECT_SOURCE_DIR}/include/Singleton.h)

set(SFML_LIBRARIES "${PROJECT_SOURCE_DIR}/lib/libsfml-graphics.so"
                   "${PROJECT_SOURCE_DIR}/lib/libsfml-window.so"
                   "${PROJECT_SOURCE_DIR}/lib/libsfml-system.so"
                   "${PROJECT_SOURCE_DIR}/lib/libsfml-audio.so"
                   "${PROJECT_SOURCE_DIR}/lib/libsfml-network.so" )
set(BOX2D_LIBRARIES "${PROJECT_SOURCE_DIR}/lib/libBox2D.a")

target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES} ${BOX2D_LIBRARIES})



