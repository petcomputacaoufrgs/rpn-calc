#ifndef OPS_H
#define OPS_H

#include "stack.h"

#define OP_ADD_SYM "+"
#define OP_SUB_SYM "-"
#define OP_MUL_SYM "*"
#define OP_DIV_SYM "/"
#define OP_POW_SYM "^"
#define OP_EXP_SYM "exp"
#define OP_LOG_SYM "log"
#define OP_LN_SYM "ln"

enum operation {
    op_add,
    op_sub,
    op_mul,
    op_div,
    op_pow,
    op_exp,
    op_log,
    op_ln
};

int op_exec(enum operation op, struct stack **stack);

#endif
