# Copyleft

cmake_minimum_required(VERSION 3.12.4 FATAL_ERROR)
set (CMAKE_CXX_STANDARD 17)

project(ddsNode)

find_package(fastcdr REQUIRED)
find_package(fastrtps REQUIRED)

add_library(${PROJECT_NAME} STATIC
  src/*.cpp
  ../IDL/*.cxx
)

target_include_directories(${PROJECT_NAME} PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/../IDL"
    "${CMAKE_CURRENT_SOURCE_DIR}/../Utils"
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
)

target_link_libraries(${PROJECT_NAME} fastcdr fastrtps)
install(TARGETS ${PROJECT_NAME} DESTINATION ${CMAKE_SOURCE_DIR}/build/install/bin)