#include <gtest/gtest.h>
#include <iostream>
//TODO include using angled brackets because we're building a library but including it from ../src
#include "../src/ast.h"

TEST(suite1, test1) {
    std::cout << "about to call into library through an object defined in ast.h\n";
    someClass myInst;
    std::cout << myInst.returnHi();

    //testing right now by setting working directory of the executable to the /ecmaC/src/
    system("node ./js/main.js");

    EXPECT_EQ(true, true);
}