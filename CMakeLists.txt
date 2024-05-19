cmake_minimum_required(VERSION 3.16)
project(RK2)


set(PROJECT_SOURCES
    Hero.cpp
    HeroBuilder.cpp
    main.cpp
)


set(PROJECT_HEADERS
    Hero.h
    HeroBuilder.h
)


add_executable(${PROJECT_NAME} ${PROJECT_SOURCES} ${PROJECT_HEADERS})


target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})


enable_testing()
add_subdirectory(tests)

