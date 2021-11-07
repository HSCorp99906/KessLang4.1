#ifndef KESS_TOKEN_H_
#define KESS_TOKEN_H_

#include <stdlib.h>


enum TokenType {
    T_IDENTIFIER,
    T_OPENPAREN,
    T_CLOSEDPAREN,
    T_END_STATEMENT,
};

enum TokenIdentifiers {
    T_OUT,
};


struct _Token {
    int data;
    int type;
    int line;
    char* string;
};

typedef struct _Token Token;


Token* token_create(int type, int data, int line);
void token_destroy(Token* tok);


struct _TokenList {
    Token** data;
    int ptr;
    size_t size;

};

typedef struct _TokenList TokenList;

TokenList* create_token_list(size_t size);
void token_list_add(TokenList* list, Token* tok);
Token* token_list_get(TokenList* list, unsigned int index);
void token_list_create(TokenList* list, int size);
void token_list_destory(TokenList* list);

typedef struct _TokenList TokenList;



#endif  // KESS_TOKEN_H_
