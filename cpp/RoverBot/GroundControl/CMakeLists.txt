# Copyleft

cmake_minimum_required(VERSION 3.12.4 FATAL_ERROR)
set (CMAKE_CXX_STANDARD 17)
SET(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

project(GroundControl)

find_package(fastcdr REQUIRED)
find_package(fastrtps REQUIRED)

add_library(${PROJECT_NAME} STATIC
  src/GroundControl.cpp
  ../ddsNode/src/OpMode_Sub.cpp
  ../IDL/OpMode_.cxx
  ../IDL/OpMode_PubSubTypes.cxx
  ../ddsNode/src/Power_Sub.cpp
  ../IDL/Power_.cxx
  ../IDL/Power_PubSubTypes.cxx
  ../ddsNode/src/Attitude_Sub.cpp
  ../IDL/Attitude_.cxx
  ../IDL/Attitude_PubSubTypes.cxx
  ../ddsNode/src/Position3d_Sub.cpp
  ../IDL/Position3d_.cxx
  ../IDL/Position3d_PubSubTypes.cxx
  ../ddsNode/src/Velocity3d_Sub.cpp
  ../IDL/Velocity3d_.cxx
  ../IDL/Velocity3d_PubSubTypes.cxx
)

target_include_directories(${PROJECT_NAME} PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/../IDL"
    "${CMAKE_CURRENT_SOURCE_DIR}/../ddsNode/include"
    "${CMAKE_CURRENT_SOURCE_DIR}/../Utils"
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
    "${CMAKE_CURRENT_SOURCE_DIR}/mavlink/v2.0"
)

target_link_libraries(${PROJECT_NAME} PRIVATE fastcdr fastrtps)
add_executable(roverbot-${PROJECT_NAME} main.cpp)
target_link_libraries(roverbot-${PROJECT_NAME} PRIVATE ${PROJECT_NAME})
install(TARGETS roverbot-${PROJECT_NAME} DESTINATION ${CMAKE_SOURCE_DIR}/build/install)