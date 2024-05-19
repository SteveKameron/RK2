cmake_minimum_required(VERSION 3.10)
project(BuilderDesignPattern)

set(CMAKE_CXX_STANDARD 14)


set(SOURCE_FILES
    main.cpp
    Hero.cpp
    HeroBuilder.cpp
)

add_executable(BuilderDesignPattern ${SOURCE_FILES})

target_include_directories(BuilderDesignPattern PUBLIC ${PROJECT_SOURCE_DIR})
