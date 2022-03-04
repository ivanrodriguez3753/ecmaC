#include <iostream>
#include <ostream>
#include <fstream>
#include "ast.h"
#include "jsonParser.h"

const std::string ESPRIMA_DRIVER_TEMP_FILENAME = "esprima_driver_temp.js";
const std::string TREE_TEMP_FILENAME = "tree_temp.json";

void generate_esprima_driver(const std::string& user_file_name) {
    std::string source =
        "const fs = require(\"fs\");\n"
        "const esprima = require(\"esprima\");\n"
        "const contentBuffer = fs.readFileSync(\"" + user_file_name + "\");\n"
        "const content_asString = contentBuffer.toString();\n"
        "var tree = esprima.parseScript(content_asString, {loc: true});\n"
        "console.log(JSON.stringify(tree));\n"
        "\n"
        "";
    std::ofstream os(ESPRIMA_DRIVER_TEMP_FILENAME);
    os << source;
    os.close();
}

int main(int argc, char* argv[]) {
    std::string user_file_name;
    bool keep_temps = false;
    if(argc == 3) {
        std::string arg2 = argv[1];
        if(arg2 != "--keep-temps") {
            std::cerr << "Optional middle argument can only be --keep-temps\n";
            exit(1);
        }
        else {
            keep_temps = true;
        }
        user_file_name = argv[2];
    }
    else if(argc == 2) {
        user_file_name = argv[1];
    }
    else {
        std::cerr << "Must provide 1 or 2 arguments\n";
        exit(1);
    }

    generate_esprima_driver(user_file_name);

    std::string command = "node " + ESPRIMA_DRIVER_TEMP_FILENAME  + " >> " + TREE_TEMP_FILENAME;
    system(command.c_str());

    //read into memory
    std::ifstream file_stream(TREE_TEMP_FILENAME);
    if(!file_stream.is_open()) {
        std::cerr << "Couldn't open temp file\n";
        exit(1);
    }

    if(!keep_temps) {
        remove(ESPRIMA_DRIVER_TEMP_FILENAME.c_str());
        remove(TREE_TEMP_FILENAME.c_str());
    }


    jsonParser j_parser(file_stream);
    j_parser.buildAST();


    j_parser.dumpJson();


}