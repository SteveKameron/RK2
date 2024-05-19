set(GTEST_ROOT "/home/runner/work/RK2/RK2/build/googletest-release-1.11.0")

set(TEST_SOURCES
    tests.cpp
)

add_executable(runTests ${TEST_SOURCES})
target_link_libraries(runTests gtest gtest_main ${PROJECT_NAME})
target_include_directories(runTests PRIVATE ${GTEST_ROOT}/include)

add_test(NAME runTests COMMAND runTests)
