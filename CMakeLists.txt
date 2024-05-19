cmake_minimum_required(VERSION 3.16)
project(BuilderDesignPattern)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Загрузка и компиляция GoogleTest
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
set(gtest_disable_pthreads ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Добавление Google Test
enable_testing()

# Добавление исполняемого файла
add_executable(BuilderDesignPattern
    main.cpp
    Hero.cpp
    Hero.h
    Item.h
    HeroBuilder.cpp
    HeroBuilder.h
)

# Добавление тестов
add_executable(tests
    tests.cpp
    Hero.cpp
    Hero.h
    Item.h
    HeroBuilder.cpp
    HeroBuilder.h
)
target_link_libraries(tests gtest gtest_main)
target_include_directories(tests PUBLIC ${gtest_SOURCE_DIR}/include)
add_test(NAME tests COMMAND tests)

