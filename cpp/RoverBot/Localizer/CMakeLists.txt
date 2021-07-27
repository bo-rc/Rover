# Copyleft

cmake_minimum_required(VERSION 3.12.4 FATAL_ERROR)
set (CMAKE_CXX_STANDARD 17)
SET(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

project(Localizer)

find_package(realsense2 REQUIRED)
find_package(Eigen3 REQUIRED)
find_package(fastcdr REQUIRED)
find_package(fastrtps REQUIRED)

add_library(${PROJECT_NAME} STATIC
  src/Localizer.cpp
  ../ddsNode/src/NavPose2d_Pub.cpp
  ../IDL/NavPose2d_.cxx
  ../IDL/NavPose2d_PubSubTypes.cxx
  ../ddsNode/src/Position3d_Pub.cpp
  ../IDL/Position3d_.cxx
  ../IDL/Position3d_PubSubTypes.cxx
  ../ddsNode/src/Velocity3d_Pub.cpp
  ../IDL/Velocity3d_.cxx
  ../IDL/Velocity3d_PubSubTypes.cxx
)

target_include_directories(${PROJECT_NAME} PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/../IDL"
    "${CMAKE_CURRENT_SOURCE_DIR}/../ddsNode/include"
    "${CMAKE_CURRENT_SOURCE_DIR}/../Utils"
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
    "${EIGEN3_INCLUDE_DIR}"
)

target_link_libraries(${PROJECT_NAME} realsense2::realsense2 fastcdr fastrtps)

add_executable(roverbot-${PROJECT_NAME} main.cpp)
target_link_libraries(roverbot-${PROJECT_NAME} PRIVATE ${PROJECT_NAME})
install(TARGETS roverbot-${PROJECT_NAME} DESTINATION ${CMAKE_SOURCE_DIR}/build/install)