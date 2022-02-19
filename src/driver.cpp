#include <iostream>
#include <fstream>
#include "ast.h"
#include "jsonParser.h"

int main() {
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


}