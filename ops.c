#include "ops.h"
#include <math.h>

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
    case op_sin:
        success = stack_pop(stack, &left);
        if (success) {
            stack_push(stack, sin(left));
        }
        break;
    case op_cos:
        success = stack_pop(stack, &left);
        if (success) {
            stack_push(stack, cos(left));
        }
        break;
    case op_tan:
        success = stack_pop(stack, &left);
        if (success) {
            stack_push(stack, tan(left));
        }
        break;
    case op_arcsin:
        success = stack_pop(stack, &left);
        if (success) {
            stack_push(stack, asin(left));
        }
        break;
    case op_arccos:
        success = stack_pop(stack, &left);
        if (success) {
            stack_push(stack, acos(left));
        }
        break;
    case op_arctan:
        success = stack_pop(stack, &left);
        if (success) {
            stack_push(stack, atan(left));
        }
        break;
    case op_pow:
        success = stack_pop(stack, &right) && stack_pop(stack, &left);
        if (success) {
            stack_push(stack, pow(left, right));
        }
        break;
    case op_exp:
        success = stack_pop(stack, &left);
        if (success) {
            stack_push(stack, exp(left));
        }
        break;
    case op_log:
        success = stack_pop(stack, &right) && stack_pop(stack, &left);
        if (success) {
            stack_push(stack, log(right) / log(left));
        }
        break;
    case op_ln:
        success = stack_pop(stack, &left);
        if (success) {
            stack_push(stack, log(left));
        }
        break;
    }

    return success;
}
