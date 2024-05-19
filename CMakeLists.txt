cmake_minimum_required(VERSION 3.14)
project(BuilderDesignPattern)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(BuilderDesignPattern
               main.cpp
               Hero.cpp
               HeroBuilder.cpp)

add_executable(builder_tests tests.cpp)
add_library(builder_lib Hero.cpp HeroBuilder.cpp)
target_link_libraries(builder_tests PRIVATE gtest_main builder_lib)

