#include "node.h"

A_stm A_CompoundStm(A_stm stm1, A_stm stm2) {
    A_stm stm = checked_malloc(sizeof(*stm));
    stm->kind = A_compoundStm;
    stm->u.compound.stm1 = stm1; stm->u.compound.stm2 = stm2;
    return stm;
}

A_stm A_AssignStm(string id, A_exp exp) {
    A_stm stm = checked_malloc(sizeof(*stm));
    stm->kind = A_assignStm;
    stm->u.assign.id = id; stm->u.assign.exp = exp;
    return stm;
}

A_stm A_PrintStm(A_expList list) {
    A_stm stm = checked_malloc(sizeof(*stm));
    stm->kind = A_printStm;
    stm->u.printList = list;
    return stm;
}

A_exp A_IdExp(string id) {
    A_exp exp = checked_malloc(sizeof(*exp));
    exp->kind = A_idExp;
    exp->u.id = id;
    return exp;
}

A_exp A_NumExp(int num) {
    A_exp exp = checked_malloc(sizeof(*exp));
    exp->kind = A_numExp;
    exp->u.num = num;
    return exp;
}

A_exp A_OpExp(A_exp lExp, A_exp rExp, A_binop oper) {
    A_exp exp = checked_malloc(sizeof(*exp));
    exp->kind = A_opExp;
    exp->u.op.lExp = lExp; exp->u.op.rExp = rExp; exp->u.op.oper = oper;
    return exp;
}

A_exp A_EseqExp(A_stm stm, A_exp exp) {
    A_exp exp = checked_malloc(sizeof(*exp));
    exp->kind = A_eseqExp;
    exp->u.eseq.stm = stm; exp->u.eseq.exp = exp;
    return exp;
}

A_expList A_PairExpList(A_exp head, A_expList tail) {
    A_expList expList = checked_malloc(sizeof(*expList));
    expList->kind = A_pairExpList;
    expList->u.pair.head = head; expList->u.pair.tail = tail;
    return expList;
}

A_expList A_LastExpList(A_exp last) {
    A_expList expList = checked_malloc(sizeof(*expList));
    expList->kind = A_lastExpList;
    expList->u.last = last;
    return expList;
}