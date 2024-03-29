#include "../include/Token.h"


Token* token_create(int data, int type, int line) {
    Token* tok = (Token*)malloc(sizeof(Token));
    tok -> type = type;
    tok -> data = data;
    tok -> line = line;
}


void token_destroy(Token* tok) {
    free(tok);
}


void token_list_create(TokenList* list, int size) {
    list -> data = (Token**)malloc(sizeof(Token*) * size);
    list -> ptr = 0;
    list -> size = size;
}


void token_list_add(TokenList* list, Token* tok) {
    if (list -> ptr >= list -> size) {
        list -> size *= 2;
        list -> data = (Token**)realloc(list -> data, sizeof(Token*) * list -> size);
    }

    list -> data[list -> ptr++] = tok;
}


Token* token_list_get(TokenList* list, unsigned int index) {
    return list -> data[index];
}


void token_list_destory(TokenList* list) {
    for (int i = 0; i < list -> ptr; ++i) {
        free(list -> data[i]);
    }

    free(list -> data);
}
