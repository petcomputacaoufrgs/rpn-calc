#ifndef OPS_H
#define OPS_H

#include "stack.h"

#define OP_ADD_SYM "+"
#define OP_SUB_SYM "-"
#define OP_MUL_SYM "*"
#define OP_DIV_SYM "/"

enum operation {
    op_add,
    op_sub,
    op_mul,
    op_div
};

int op_exec(enum operation op, struct stack **stack);

#endif
