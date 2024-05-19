include (FetchContent)

Fetchcontent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/release-1.11.0.zip
)

set(TEST_SOURCES
    tests.cpp
)

add_executable(runTests ${TEST_SOURCES})
target_link_libraries(runTests gtest gtest_main)

add_test(NAME runTests COMMAND runTests)
