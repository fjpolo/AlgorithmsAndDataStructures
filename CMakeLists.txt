cmake_minimum_required(VERSION 3.16)
project(UdemyModernCPP)

#including CPM.cmake, a package manager:
#https://github.com/TheLartians/CPM.cmake
include(CMake/CPM.cmake)

#Compile commands, useful for some IDEs like VS-Code
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

#static linking in Windows
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

#adding project folders:
add_subdirectory(Algorithms)
add_subdirectory(BitManipulation)
# add_subdirectory(Concepts)
add_subdirectory(DataStructures)


