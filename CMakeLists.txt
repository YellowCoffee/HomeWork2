cmake_minimum_required(VERSION 3.5)

project(ip_filter LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set( COMPILE_OPTIONS "-Wpedantic;-Wall;-Wextra" )

include_directories(${Boost_INCLUDE_DIRS})
find_package( Boost COMPONENTS unit_test_framework REQUIRED )

#add_executable( tests functions.cpp functions_test.cpp)
#target_link_libraries( tests ${Boost_LIBRARIES} )

add_executable(ip_filter main.cpp functions.cpp)

