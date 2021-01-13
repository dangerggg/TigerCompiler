#ifndef INTERP_H
#define INTERP_H

#include "node.h"

typedef struct I_table_ *I_table;
struct I_table_ {
    string id;
    int value;
    I_table tail;
};
/* This function can also be used as update */
I_table I_Table(string, int, I_table);
int Lookup(string, I_table);

I_table InterpStm(A_stm, I_table);
I_table InterpExp(A_exp, I_table, int *);

#endif
