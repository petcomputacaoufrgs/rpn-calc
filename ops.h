#ifndef OPS_H
#define OPS_H

#include "stack.h"

#define OP_ADD_SYM "+"
#define OP_SUB_SYM "-"
#define OP_MUL_SYM "*"
#define OP_DIV_SYM "/"
#define OP_SIN_SYM "sin"
#define OP_COS_SYM "cos"
#define OP_TAN_SYM "tan"
#define OP_ARCSIN_SYM "arcsin"
#define OP_ARCCOS_SYM "arccos"
#define OP_ARCTAN_SYM "arctan"

enum operation {
    op_add,
    op_sub,
    op_mul,
    op_div,
    op_sin,
    op_cos,
    op_tan,
    op_arcsin,
    op_arccos,
    op_arctan
};

int op_exec(enum operation op, struct stack **stack);

#endif
