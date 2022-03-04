//
// Created by Ivan Rodriguez on 2/17/22.
//

#ifndef ECMAC_AST_H
#define ECMAC_AST_H

#include <iostream>
#include <list>

class program;

class node;



class stmt_n;
class expr_stmt_n;

class expr_n;
class bin_expr_n;
class lit_expr_n;
class num_lit_n;


//TODO: separate node into object node and array node?
class node {
public:
    const std::string type;

    //pair denoting the line,column of a node
    const std::pair<int, int> loc;

    virtual void print() = 0;

    node(std::string t, std::pair<int, int> l);
};

class program : public node {
public:
    std::list<stmt_n*> stmts;
    void print() {}

    //TODO: construct with or without stmts list? for now, will append to list for each call to walk()
    program(std::string t, std::pair<int, int> l);
};


class stmt_n : public node {
public:
    stmt_n(std::string t, std::pair<int, int> l);
};

class expr_stmt_n : public stmt_n {
private:
    expr_n* expr;
public:
    expr_stmt_n(std::string t, std::pair<int, int> l, expr_n* e);
    void print() {}

};

class expr_n : public node {
public:
    expr_n(std::string t, std::pair<int, int> l);
};

class bin_expr_n : public expr_n {
private:
    expr_n *left, *right;
    std::string op;

public:
    bin_expr_n(std::string t, std::pair<int, int> loc, expr_n* l, expr_n* r, std::string o);

    void print() {}



};

class lit_expr_n : public expr_n {
public:
    lit_expr_n(std::string t, std::pair<int, int> l);
};

class num_lit_n : public lit_expr_n {
    const double value;

public:
    num_lit_n(std::string t, std::pair<int, int> l, double v);

    void print() {}
};


#endif //ECMAC_AST_H
