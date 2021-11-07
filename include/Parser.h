#ifndef KESS_PARSER_H_
#define KESS_PARSER_H_

#include "Token.h"
#include <string.h>
#include <stdio.h>


enum _ParserStatus {
    PARSER_SUCCESS,
    PARSER_SYNTAX_ERROR
};


int parser_start(TokenList* list, const char* source);

#endif  // KESS_PARSER_H_
