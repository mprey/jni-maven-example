cmake_minimum_required(VERSION 3.5)

if(NOT DEFINED NATIVE_LIBRARY_NAME)
    message(SEND_ERROR "Must pass NATIVE_LIBRARY_NAME to project" )
endif()
message(STATUS "Using library name: ${NATIVE_LIBRARY_NAME}" )
project(${NATIVE_LIBRARY_NAME})

find_package(JNI REQUIRED)
include_directories(${JNI_INCLUDE_DIRS})

file(GLOB SOURCE_FILES CONFIGURE_DEPENDS "*.h" "*.cpp")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/../../../target/classes)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
add_library(${NATIVE_LIBRARY_NAME} SHARED ${SOURCE_FILES})