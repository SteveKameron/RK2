include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/release-1.11.0.zip
)

FetchContent_MakeAvailable(googletest)

set(GTEST_ROOT "/home/runner/work/RK2/RK2/build/googletest-release-1.11.0")

set(TEST_SOURCES
    tests.cpp
)

add_executable(runTests ${TEST_SOURCES})
target_link_libraries(runTests gtest gtest_main)
target_include_directories(runTests PRIVATE ${GTEST_ROOT}/include)

add_test(NAME runTests COMMAND runTests)


