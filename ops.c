#include "ops.h"

int op_exec(enum operation op, struct stack **stack)
{
    double left, right;
    int success = 0;

    switch (op) {
    case op_add:
        success = stack_pop(stack, &right) && stack_pop(stack, &left);
        if (success) {
            stack_push(stack, left + right);
        }
        break;
    case op_sub:
        success = stack_pop(stack, &right) && stack_pop(stack, &left);
        if (success) {
            stack_push(stack, left - right);
        }
        break;
    case op_mul:
        success = stack_pop(stack, &right) && stack_pop(stack, &left);
        if (success) {
            stack_push(stack, left * right);
        }
        break;
    case op_div:
        success = stack_pop(stack, &right) && stack_pop(stack, &left);
        if (success) {
            stack_push(stack, left / right);
        }
        break;
    }

    return success;
}
