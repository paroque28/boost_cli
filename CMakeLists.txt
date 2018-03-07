cmake_minimum_required(VERSION 3.5)
project(boost_cli)

set(CMAKE_CXX_STANDARD 98)

set(SOURCE_FILES main.cpp)
add_executable(boost_cli ${SOURCE_FILES})

#Include Boost
find_package( Boost REQUIRED COMPONENTS program_options)

include_directories(${Boost_INCLUDE_DIRS})
target_link_libraries(boost_cli ${Boost_LIBRARIES})