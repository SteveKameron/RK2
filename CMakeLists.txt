cmake_minimum_required(VERSION 3.16)
project(BuilderDesignPattern)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(BuilderDesignPattern
    main.cpp
    Hero.cpp
    Hero.h
    Item.h
    HeroBuilder.cpp
    HeroBuilder.h
)
