cmake_minimum_required(VERSION 3.8)
project(MyLeetCode)

set(CMAKE_CXX_STANDARD 14)


###############################################################################
# Libraries
###############################################################################
find_package(GTest REQUIRED)            # gtest
list(APPEND PRIVATE_DEPEND_INCLUDES
     ${GTEST_INCLUDE_DIRS}
     )
list(APPEND PRIVATE_DEPEND_LIBS
     ${GTEST_LIBRARIES}
     )

###############################################################################
# Project Setting
###############################################################################
# export compile commands
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# projects build setting
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)


###############################################################################
# Project
###############################################################################
# modules
add_subdirectory(01_TwoSum)