//
// Created by Ivan Rodriguez on 2/19/22.
//

#include "jsonParser.h"

#include <nlohmann/json.hpp>
#include <istream>
#include "ast.h"

jsonParser::jsonParser(std::istream& json_stream) {
    json_stream >> j;
}

void jsonParser::dumpJson() {
    std::cout << j.dump();
}

void jsonParser::buildAST() {
    auto loc = std::make_pair<>(j["loc"]["start"]["line"], j["loc"]["start"]["column"]);
    std::string type = j["type"];

    //TODO: this is the only thing that's not constructed bottom up, but it's children are.
    //      see note in program's ctor
    prgrm = new program{type, loc};

    nlohmann::json body = j["body"];
    for(auto elem : body) {
        prgrm->stmts.push_back((stmt_n*)walk(elem));
    }
}

node* jsonParser::walk(nlohmann::json &current) {
    std::string type = current["type"];
    std::cout << "Begin walk of JSON type " << type << std::endl;

    /*TODO: enumerate all the types that esprima can spit out
     *      essentially take the interface found at
     *      https://docs.esprima.org/en/4.0/syntax-tree-format.html
     *      and put it in an enum or an otherwise named, group of constants
     *      so we don't have magic string literals in this if...else if...,
     *      and the string argument to the map in the recursive call to walk()
     *      */
    if(type == "ExpressionStatement") {
        expr_n* expr = (expr_n*)walk(current["expression"]);
        auto loc = std::make_pair<>(current["loc"]["start"]["line"], current["loc"]["start"]["column"]);
        return new expr_stmt_n{type, loc, expr};
    }
    /*TODO: optional but another thing somewhat related to the todo above. if we group
     *      these constants appropriately, we can clean up the code by moving
     *      mutually exclusive groups into their own functions. Like, expressions
     *      only happen in the context of ExpressionStatements, so it's kind of silly
     *      to have them at equal footing */
    else if(type == "BinaryExpression") {
        expr_n* left = (expr_n*)walk(current["left"]);
        expr_n* right = (expr_n*)walk(current["right"]);
        std::string op = current["operator"];
        auto loc = std::make_pair<>(current["loc"]["start"]["line"], current["loc"]["start"]["column"]);

        //TODO: stle ?: stack temps for building the return value's ctor args like I did below, or inline
        //      everything like I did for (type == "Literal") branch below?
        return new bin_expr_n{type, loc, left, right, op};

    }
    else if(type == "Literal") {
        if(current["value"].is_number()) {
            //TODO: style ?: see above. use stack temps or inline ctor arguments?
            return new num_lit_n{type,
                                 std::make_pair<>(current["loc"]["start"]["line"], current["loc"]["start"]["column"]),
                                 current["value"]};
        }
    }

    std::cout << "End walk of JSON type " << type << std::endl;
}

