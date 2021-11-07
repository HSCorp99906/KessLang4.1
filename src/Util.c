#include "../include/Util.h"


char* read_ascii_file(const char* path) {
    FILE* file = fopen(path, "r");

    fseek(file, 0, SEEK_END);
    int size = ftell(file);
    fseek(file, 0, SEEK_SET);

    char* buf = (char*)malloc(sizeof(char) * size);
    fread(buf, 1, size, file);
    return buf;
}
