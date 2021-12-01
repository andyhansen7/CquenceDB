cmake_minimum_required (VERSION 3.10)
project (CquenceDB)

set( CMAKE_CXX_STANDARD 17 )
set( CMAKE_CXX_STANDARD_REQUIRED ON )
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall")

include(CTest)
include(GoogleTest)

include_directories(src)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

add_subdirectory( "${CMAKE_CURRENT_SOURCE_DIR}/src" )
#add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/services")