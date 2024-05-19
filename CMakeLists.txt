cmake_minimum_required(VERSION 3.16)
project(RK2)


set(PROJECT_SOURCES
    Hero.cpp
    HeroBuilder.cpp
)


set(PROJECT_HEADERS
    Hero.h
    HeroBuilder.h
)

target_link_libraries(${PROJECT_TEST_NAME}
    tests.cpp
    gtest
    gtest_main
)
add_library(project_lib STATIC ${PROJECT_SOURCES} ${PROJECT_HEADERS})


target_include_directories(project_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})


add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} project_lib)


enable_testing()
add_subdirectory(tests)
add_subdirectory(${CMAKE_BINARY_DIR}/googletest)
