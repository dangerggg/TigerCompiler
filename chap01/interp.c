#include "interp.h"
#include <stdio.h>
#include <string.h>

I_table I_Table(string id, int value, I_table tail) {
    I_table newTable = checked_malloc(sizeof(newTable));
    newTable->id = id; newTable->value = value; newTable->tail = tail;
    return newTable;
}

int Lookup(string id, I_table curTab) {
    I_table probeTab = curTab;
    while (probeTab) {
        if (strcmp(id, probeTab->id) == 0) {
            return probeTab->value;
        }
    }
    printf("Undefined variable %s", id);
    return 0;
}

I_table InterpStm(A_stm stm, I_table table) {
    assert(stm != NULL);
    int ret = 0;
    if (stm->kind == A_compoundStm) {
        table = InterpStm(stm->u.compound.stm1, table);
        table = InterpStm(stm->u.compound.stm2, table);
        return table;
    } else if (stm->kind == A_assignStm) {
        table = InterpExp(stm->u.assign.exp, table, &ret);
        return I_Table(stm->u.assign.id, ret, table);
    } else if (stm->kind == A_printStm) {
        A_expList list = stm->u.printList;
        while (list->kind != A_lastExpList) {
            table = InterpExp(list->u.pair.head, table, &ret);
            printf("%d\n", ret);
            list = list->u.pair.tail;
        }
        table = InterpExp(list->u.last, table, &ret);
        printf("%d\n", ret);
        return table;
    } else {
        assert(!"Unknown types\n");
    }
}

I_table InterpExp(A_exp exp, I_table table, int *ret) {
    if (exp->kind == A_idExp) {
        *ret = Lookup(exp->u.id, table);
        return table;
    } else if (exp->kind == A_numExp) {
        *ret = exp->u.num;
        return table;
    } else if (exp->kind == A_opExp) {
        int a = 0, b = 0;
        table = InterpExp(exp->u.op.lExp, table, &a);
        table = InterpExp(exp->u.op.rExp, table, &b);
        switch (exp->u.op.oper) {
        case A_plus: *ret = a + b; break;
        case A_minus: *ret = a - b; break;
        case A_times: *ret = a * b; break;
        case A_dev: *ret = a / b; break;
        default: assert(!"Unknown ops\n"); break;
        }
        return table;
    } else if (exp->kind == A_eseqExp) {
        table = InterpStm(exp->u.eseq.stm, table);
        return InterpExp(exp->u.eseq.exp, table, ret);
    } else {
        assert(!"Unknown expression\n");
    }
}