cmake_minimum_required(VERSION 3.17)
project(ecmaC)

#src stuff
add_library(ecmaC_lib SHARED
    src/lexer.cpp src/lexer.h
)

add_executable(
    ecmaC_driver
    src/driver.cpp
)

target_link_libraries(
    ecmaC_driver
        ecmaC_lib
)

#test stuff
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/e2239ee6043f73722e7aa812a459f54a28552929.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
    ecmaC_test
        test/hello_test.cpp
)
target_link_libraries(
    ecmaC_test
        ecmaC_lib
        gtest_main
)
include(GoogleTest)
gtest_discover_tests(ecmaC_test)