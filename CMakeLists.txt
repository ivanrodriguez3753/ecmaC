cmake_minimum_required(VERSION 3.17)
project(ecmaC)

set(NODEJS "node")
#the parser is written in JS, so require node as a package
find_program(NODE_RESULT ${NODEJS} REQUIRED)
#from the documentation on find_program,
#If nothing is found, the result will be <VAR>-NOTFOUND
if("${NODE_RESULT}" STREQUAL "NODE_RESULT-NOTFOUND")
    message(FATAL_ERROR "negative path. didn't find ${NODEJS}")
else()
    message("positive path. found ${NODEJS} at ${NODE_RESULT}")
    #TODO: insert a check for npm, but brew had node and npm installed together so this might be redundant. Hence leaving as a todo
    execute_process(COMMAND npm ls
                    COMMAND grep esprima RESULT_VARIABLE grep_res) #0 if grep found something
    if(grep_res) #if grep didn't find esprima
        message("Installing esprima")
        execute_process(COMMAND npm install esprima)
    else()
        message("found esprima")
    endif()


endif()



#src stuff
add_library(ecmaC_lib SHARED
    src/ast.cpp src/ast.h src/jsonParser.cpp src/jsonParser.h)

#JSON library
include(FetchContent)
FetchContent_Declare(json
        URL https://github.com/nlohmann/json/releases/download/v3.10.5/json.tar.xz
        )

FetchContent_GetProperties(json)
if(NOT json_POPULATED)
    FetchContent_Populate(json)
    add_subdirectory(${json_SOURCE_DIR} ${json_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()
target_link_libraries(ecmaC_lib PUBLIC nlohmann_json::nlohmann_json)

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