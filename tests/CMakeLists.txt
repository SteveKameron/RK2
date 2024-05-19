include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/release-1.11.0.zip
)

FetchContent_MakeAvailable(googletest)

set(TEST_SOURCES
    tests.cpp
)

add_executable(runTests ${TEST_SOURCES})
target_link_libraries(runTests gtest gtest_main)
target_include_directories(runTests PRIVATE ${gtest_SOURCE_DIR}/include)

add_test(NAME runTests COMMAND runTests)
