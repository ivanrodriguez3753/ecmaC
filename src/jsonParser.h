//
// Created by Ivan Rodriguez on 2/19/22.
//

#ifndef ECMAC_JSONPARSER_H
#define ECMAC_JSONPARSER_H

#include <iostream>
#include <nlohmann/json.hpp>




class jsonParser {
    nlohmann::json j;
public:
    jsonParser(std::istream& json_stream);
    void dumpJson();
};

#endif //ECMAC_JSONPARSER_H
