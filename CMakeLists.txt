cmake_minimum_required(VERSION 3.11)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

project("Project Euler")

set(CMAKE_CXX_STANDARD 20)

add_custom_target("copy_latest")
add_custom_command(
    TARGET "copy_latest"
    COMMAND ${CMAKE_COMMAND} -E copy "$<TARGET_FILE:ProjectEuler0001>" "${CMAKE_BINARY_DIR}/latest.exe"
)

# Problem n°0001
add_subdirectory(${CMAKE_SOURCE_DIR}/solutions/0001 ${CMAKE_BINARY_DIR}/0001)

