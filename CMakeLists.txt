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

# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND "${CMAKE_COMMAND}" -G "${CMAKE_GENERATOR}" .
  WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/googletest-download" )
execute_process(COMMAND "${CMAKE_COMMAND}" --build .
  WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/googletest-download" )

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This adds
# the following targets: gtest, gtest_main, gmock
add_subdirectory("${CMAKE_BINARY_DIR}/googletest-src"
                 "${CMAKE_BINARY_DIR}/googletest-build"
                 EXCLUDE_FROM_ALL)

# The gtest/gmock targets carry header search path
# dependencies automatically when using CMake 3.12+. Otherwise,
# you just need to add
# target_include_directories(your_test_target PRIVATE ${gtest_SOURCE_DIR}/include ${gmock_SOURCE_DIR}/include)

# Add tests
enable_testing()
add_executable(tests tests/HeroTest.cpp)
target_link_libraries(tests gtest_main)
add_test(AllTests tests)
