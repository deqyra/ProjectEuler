cmake_minimum_required(VERSION 3.11)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

project("Project Euler")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_BUILD_TYPE "release")

add_custom_target("copy_latest")
add_custom_command(
    TARGET "copy_latest"
    COMMAND ${CMAKE_COMMAND} -E copy "$<TARGET_FILE:ProjectEuler0010>" "${CMAKE_BINARY_DIR}/latest.exe"
)

# Problem n°1
add_subdirectory(${CMAKE_SOURCE_DIR}/solutions/0001 ${CMAKE_BINARY_DIR}/0001)

# Problem n°2
add_subdirectory(${CMAKE_SOURCE_DIR}/solutions/0002 ${CMAKE_BINARY_DIR}/0002)

# Problem n°3
add_subdirectory(${CMAKE_SOURCE_DIR}/solutions/0003 ${CMAKE_BINARY_DIR}/0003)

# Problem n°4
add_subdirectory(${CMAKE_SOURCE_DIR}/solutions/0004 ${CMAKE_BINARY_DIR}/0004)

# Problem n°5
add_subdirectory(${CMAKE_SOURCE_DIR}/solutions/0005 ${CMAKE_BINARY_DIR}/0005)

# Problem n°6
add_subdirectory(${CMAKE_SOURCE_DIR}/solutions/0006 ${CMAKE_BINARY_DIR}/0006)

# Problem n°7
add_subdirectory(${CMAKE_SOURCE_DIR}/solutions/0007 ${CMAKE_BINARY_DIR}/0007)

# Problem n°8
add_subdirectory(${CMAKE_SOURCE_DIR}/solutions/0008 ${CMAKE_BINARY_DIR}/0008)

# Problem n°0009
add_subdirectory(${CMAKE_SOURCE_DIR}/solutions/0009 ${CMAKE_BINARY_DIR}/0009)

# Problem n°0010
add_subdirectory(${CMAKE_SOURCE_DIR}/solutions/0010 ${CMAKE_BINARY_DIR}/0010)

