#include "../include/Token.h"
#include "../include/Util.h"
#include "../include/Parser.h"
#include <stdio.h>
#include <string.h>


int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Too little arguments.\n");
        return 1;
    }

    if (strcmp(argv[1], "compile") == 0) {
        char* source = read_ascii_file(argv[2]);

        TokenList tokens;
        token_list_create(&tokens, 1);

        parser_start(&tokens, source);

        token_list_destory(&tokens);
        free(source);
    }
}
