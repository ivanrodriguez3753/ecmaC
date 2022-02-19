#include <iostream>
#include "ast.h"

int main() {
    std::cout << "Hi from ecmaC_driver's main\n";

    //testing right now by setting working directory of the executable to the /ecmaC/src/
    system("node ./js/main.js");

    someClass myInst; //from ast.h
    std::cout << myInst.returnHi();
}