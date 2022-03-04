//
// Created by Ivan Rodriguez on 2/19/22.
//

#ifndef ECMAC_JSONPARSER_H
#define ECMAC_JSONPARSER_H

#include <iostream>
#include <nlohmann/json.hpp>
#include "ast.h"




class jsonParser {
    nlohmann::json j;

    program* prgrm;
public:
    jsonParser(std::istream& json_stream);
    void dumpJson();

    //driver for recursively walking JSON and building the AST, where `this->prgrm` is the root
    void buildAST();

    //recursive helper to have arbitrarily nested for loops (through recursive function calls)
    node* walk(nlohmann::json& current);
};

#endif //ECMAC_JSONPARSER_H
