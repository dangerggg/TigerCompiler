#include "maxargs.h"
#include "node.h"
#include <stdio.h>

A_exp parseList(A_expList list, int *cnt) {
    ++(*cnt);
    if (list->kind == A_lastExpList) {
        return list->u.last;
    } else {
        return parseList(list->u.pair.tail, cnt);
    }
}

int maxArgs(A_stm stm) {
    switch (stm->kind) {
    case A_compoundStm:
        return max(maxArgs(stm->u.compound.stm1), maxArgs(stm->u.compound.stm2));
        break;
    case A_assignStm:
        if (stm->u.assign.exp->kind == A_eseqExp) {
            return maxArgs(stm->u.assign.exp->u.eseq.stm);
        } else {
            return 0;
        }
        break;
    case A_printStm:{
        int cnt = 0;
        A_exp last = parseList(stm->u.printList, &cnt);
        if (last->kind == A_eseqExp) {
            return max(cnt, maxArgs(stm->u.assign.exp->u.eseq.stm));
        } else {
            return cnt;
        }}
        break;
    default:
        assert(!"Unknown types!\n");
        break;
    }
}
