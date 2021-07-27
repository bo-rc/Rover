# Copyleft

cmake_minimum_required(VERSION 3.12.4 FATAL_ERROR)
set (CMAKE_CXX_STANDARD 17)
SET(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

project(Navigator)

find_package(Eigen3 REQUIRED)
find_package(fastcdr REQUIRED)
find_package(fastrtps REQUIRED)

add_library(${PROJECT_NAME} STATIC
  src/Navigator.cpp
  src/PIDCtrl.cpp
  ../ddsNode/src/NavPose2d_Sub.cpp
  ../IDL/NavPose2d_.cxx
  ../IDL/NavPose2d_PubSubTypes.cxx
  ../ddsNode/src/OpCmd_Sub.cpp
  ../IDL/OpCmd_.cxx
  ../IDL/OpCmd_PubSubTypes.cxx
  ../ddsNode/src/OpMode_Sub.cpp
  ../IDL/OpMode_.cxx
  ../IDL/OpMode_PubSubTypes.cxx
  ../ddsNode/src/ManCmd_Sub.cpp
  ../IDL/ManCmd_.cxx
  ../IDL/ManCmd_PubSubTypes.cxx
  ../ddsNode/src/ActCmd_Pub.cpp
  ../IDL/ActCmd_.cxx
  ../IDL/ActCmd_PubSubTypes.cxx
)

target_include_directories(${PROJECT_NAME} PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/../IDL"
    "${CMAKE_CURRENT_SOURCE_DIR}/../ddsNode/include"
    "${CMAKE_CURRENT_SOURCE_DIR}/../Utils"
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
    "${EIGEN3_INCLUDE_DIR}"
)

target_link_libraries(${PROJECT_NAME} fastcdr fastrtps)

add_executable(roverbot-${PROJECT_NAME} main.cpp)
target_link_libraries(roverbot-${PROJECT_NAME} PRIVATE ${PROJECT_NAME})
install(TARGETS roverbot-${PROJECT_NAME} DESTINATION ${CMAKE_SOURCE_DIR}/build/install)