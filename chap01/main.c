#include "utils.h"
#include "node.h"
#include "prog.h"
#include "maxargs.h"
#include "interp.h"

#include <stdio.h>
#include <stdlib.h>

int main() {
    // printf("%d", maxArgs(prog()));
    InterpStm(prog(), NULL);
    return 0;
}
