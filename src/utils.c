#include "utils.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void *checked_malloc(int len) {
    void *ptr = malloc(len);
    if (!ptr) {
        fprintf(stderr, "\nRan out of memory!\n");
        exit(1);
    }
    return ptr;
}

string String(char *str) {
    string ptr = checked_malloc(strlen(str)+1);
    strcpy(ptr, str);
    return ptr;
}

U_boolList U_BoolList(bool head, U_boolList tail) {
    U_boolList list = checked_malloc(sizeof(*list));
    list->head = head;
    list->tail = tail;
    return list;
}