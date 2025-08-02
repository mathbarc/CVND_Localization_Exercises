cmake_minimum_required(VERSION 3.7)
project("2D Histogram Filter")

find_package(Eigen3 REQUIRED)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

file(GLOB SIMULATOR_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/sources/*.cpp)
file(GLOB SIMULATOR_INCLUDES ${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp)

add_library(sim STATIC ${SIMULATOR_SOURCES} ${SIMULATOR_INCLUDES})
target_link_libraries(sim Eigen3::Eigen)

add_executable(simulator ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)
target_link_libraries(simulator sim)
