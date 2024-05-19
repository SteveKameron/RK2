cmake_minimum_required(VERSION 3.14)
project(BuilderDesignPattern)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(${PROJECT_SOURCE_DIR})

add_executable(SOURCES
               main.cpp
               Hero.cpp
               HeroBuilder.cpp)

add_executable(SOURCES ${SOURCES})

enable_testing()

add_subdirectory(tests)

