#include <gtest/gtest.h>
#include <iostream>
#include <fstream>
//TODO include using angled brackets because we're building a library but including it from ../src
#include "../src/ast.h"
#include "../src/jsonParser.h"

TEST(suite1, test1) {
    //testing right now by setting working directory of the executable to the /ecmaC/src/
    std::string tmpFileName = "jstree1.json";
    std::string command = "node ./js/main.js >> " + tmpFileName;
    system(command.c_str());

    //read into memory
    std::ifstream file_stream(tmpFileName);
    if(!file_stream.is_open()) {
        std::cout << "Couldn't open temp file\n";
        exit(1);
    }


    jsonParser j_parser(file_stream);
    j_parser.dumpJson();




    command = "rm -rf " + tmpFileName;
    system(command.c_str());

    EXPECT_EQ(true, true);
}