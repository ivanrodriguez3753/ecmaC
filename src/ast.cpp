//
// Created by Ivan Rodriguez on 2/17/22.
//

#include "ast.h"
#include <iostream>


node::node(std::string t, std::pair<int, int> l)
: type{t}, loc{l}
{

}

stmt_n::stmt_n(std::string t, std::pair<int, int> l)
: node{t, l}
{

}

expr_stmt_n::expr_stmt_n(std::string t, std::pair<int, int> l, expr_n *e)
: stmt_n{t, l}, expr{e}
{

}

expr_n::expr_n(std::string t, std::pair<int, int> l)
: node{t, l}
{

}

bin_expr_n::bin_expr_n(std::string t, std::pair<int, int> loc, expr_n *l, expr_n *r, std::string o)
: expr_n{t, loc}, left{l}, right{r}, op{o}
{

}

lit_expr_n::lit_expr_n(std::string t, std::pair<int, int> l)
: expr_n{t, l}
{

}

num_lit_n::num_lit_n(std::string t, std::pair<int, int> l, double v)
: lit_expr_n{t, l}, value{v}
{

}

program::program(std::string t, std::pair<int, int> l)
: node{t, l}
{

}
