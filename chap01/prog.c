#include "node.h"
#include "prog.h"

A_stm prog() {
    return 
    A_CompoundStm(A_AssignStm("a",
                    A_OpExp(A_NumExp(5), A_NumExp(3), A_plus)),
    A_CompoundStm(A_AssignStm("b",
        A_EseqExp(A_PrintStm(A_PairExpList(A_IdExp("a"),
                    A_LastExpList(A_OpExp(A_IdExp("a"), 
                                        A_NumExp(1), A_minus)))),
                A_OpExp(A_NumExp(10), A_IdExp("a"), A_times))),
    A_PrintStm(A_LastExpList(A_IdExp("b")))));
}
