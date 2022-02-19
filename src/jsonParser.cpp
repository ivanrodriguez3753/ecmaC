//
// Created by Ivan Rodriguez on 2/19/22.
//

#include "jsonParser.h"

#include <nlohmann/json.hpp>
#include <istream>

jsonParser::jsonParser(std::istream& json_stream) {
    json_stream >> j;
}

void jsonParser::dumpJson() {
    std::cout << j.dump();
}
