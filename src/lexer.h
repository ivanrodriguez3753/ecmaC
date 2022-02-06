#ifndef ECMAC_LEXER_H
#define ECMAC_LEXER_H

#include <iostream>

enum TOKS {
    //identifiers
    ID,
    //literals
    NUM_LITERAL,
    STR_LITERAL,
    //keywords
    AWAIT_KW,
    BREAK_KW,
    CASE_KW,
    CATCH_KW,
    CLASS_KW,
    CONST_KW,
    CONTINUE_KW,
    DEBUGGER_KW,
    DEFAULT_KW,
    DELETE_KW,
    DO_KW,
    ELSE_KW,
    EXPORT_KW,
    EXTENDS_KW,
    FINALLY_KW,
    FOR_KW,
    FUNCTION_KW,
    IF_KW,
    IMPORT_KW,
    IN_KW,
    INSTACEOF_KW,
    NEW_KW,
    RETURN_KW,
    SUPER_KW,
    SWITCH_KW,
    THIS_KW,
    THROW_KW,
    TRY_KW,
    TYPEOF_KW,
    VAR_KW,
    VOID_KW,
    WHILE_KW,
    WITH_KW,
    YIELD_KW
};

class someClass {
public:
    someClass() {
        std::cout << "called someClass ctr" << std::endl;
    }

    int return1();
};


#endif