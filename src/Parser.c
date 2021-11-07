#include "../include/Parser.h"


void string_set_get(Token* token, unsigned int pos, char* src) {
    unsigned short int quote_enc = 0;
    char to_concat[5000];
    unsigned short int canRun = 1;

    for (int i = pos; i < strlen(src) && canRun; ++i) {
        switch (src[i]) {
            case 'a':
            case 'b':
            case 'c':
            case 'd':
            case 'e':
            case 'f':
            case 'g':
            case 'h':
            case 'i':
            case 'j':
            case 'k':
            case 'l':
            case 'm':
            case 'n':
            case 'o':
            case 'p':
            case 'q':
            case 'r':
            case 's':
            case 't':
            case 'u':
            case 'v':
            case 'w':
            case 'x':
            case 'y':
            case 'z':
            case 'A':
            case 'B':
            case 'C':
            case 'D':
            case 'E':
            case 'F':
            case 'G':
            case 'H':
            case 'I':
            case 'J':
            case 'K':
            case 'L':
            case 'M':
            case 'N':
            case 'O':
            case 'P':
            case 'Q':
            case 'R':
            case 'S':
            case 'T':
            case 'U':
            case 'V':
            case 'W':
            case 'X':
            case 'Y':
            case 'Z':
            case '.':
            case ',':
            case '>':
            case '<':
            case '\'':
            case '+':
            case '=':
            case '-':
            case '_':
            case ' ':
            case '*':
            case '&':
            case '^':
            case '%':
            case '$':
            case '#':
            case '@':
            case '!':
            case '~':
            case '`':
            case ']':
            case '[':
            case '?':
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                strncat(to_concat, &src[i], 1);
                break;
            case '"':
                if (quote_enc == 1) {
                    canRun = 0;
                    break;
                } else {
                    quote_enc = 1;
                    strncat(to_concat, &src[i], 1);
                    break;
                }
        }
    }

    token -> string = to_concat;
}


int parser_start(TokenList* list, const char* source) {
    typedef unsigned short int bool_t;
    char lex[256];  /* Lexical Buffer. */
    int lexi = 0;
    int i = 0;
    unsigned int line = 1;
    bool_t instruction_found = 0;
    unsigned int status = PARSER_SUCCESS;

    while (1) {
        memset(lex, 0, 256);

        while (source[i] != ' ' && source[i] != '\n' && source[i] && source[i] != '\0') {
            lex[lexi] = source[i];
            ++lexi;
            ++i;

            if (strcmp(lex, "out") == 0) {
                instruction_found = 1;
                token_list_add(list, token_create(T_IDENTIFIER, T_OUT, line));
            }

        }

        lex[lexi] = '\0';

        if (source[i] == '\n') {
            ++line;
        } else if (source[i] == '\0') {
            break;
        }

        printf("%c\n", source[i]);

        if (!(instruction_found)) {
            status = PARSER_SYNTAX_ERROR;
            printf("ERROR: No identifier named \"%s\".", lex);
            break;
        }

        lexi = 0;
        ++i;
        instruction_found = 0;
    }

    return status;
}
