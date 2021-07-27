#+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#
# File: CMakeLists.txt
#
# Brief: Cmake list file.
#
# Author: Bo Liu (bo.robotics@gmail.com)
#
# Copyleft
#
#+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
cmake_minimum_required(VERSION 3.5)
#-------------------------------------------------------------------------------
# cmake project
#-------------------------------------------------------------------------------
project(RoverBot)

#-------------------------------------------------------------------------------
# Sources
#-------------------------------------------------------------------------------
#
add_subdirectory(Navigator)
add_subdirectory(RCinput)
add_subdirectory(Localizer)
add_subdirectory(Actuator)
add_subdirectory(GroundControl)
add_subdirectory(BatteryMonitor)
add_subdirectory(AHRS)

install(TARGETS Navigator DESTINATION ${CMAKE_SOURCE_DIR}/build/install/)
install(TARGETS RCinput DESTINATION ${CMAKE_SOURCE_DIR}/build/install/)
install(TARGETS Localizer DESTINATION ${CMAKE_SOURCE_DIR}/build/install/)
install(TARGETS Actuator DESTINATION ${CMAKE_SOURCE_DIR}/build/install/)
install(TARGETS GroundControl DESTINATION ${CMAKE_SOURCE_DIR}/build/install/)
install(TARGETS BatteryMonitor DESTINATION ${CMAKE_SOURCE_DIR}/build/install/)
install(TARGETS AHRS DESTINATION ${CMAKE_SOURCE_DIR}/build/install/)

install(FILES runAll.sh killAll.sh PERMISSIONS OWNER_EXECUTE OWNER_WRITE OWNER_READ DESTINATION ${CMAKE_SOURCE_DIR}/build/install/)