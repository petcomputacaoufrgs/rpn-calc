#ifndef STACK_H
#define STACK_H

typedef double stack_data;

struct stack {
    stack_data data;
    struct stack *next;
};

void stack_push(struct stack **stack, stack_data data);

int stack_pop(struct stack **stack, stack_data *data);

void stack_free(struct stack **stack);

#endif
