#include "stack.h"
#include <stdlib.h>

void stack_push(struct stack **stack, stack_data data)
{
    struct stack *new_node = malloc(sizeof(struct stack));

    if (new_node == NULL) {
        abort();
    }

    new_node->data = data;
    new_node->next = *stack;
    *stack = new_node;
}

int stack_pop(struct stack **stack, stack_data *data)
{
    int success = 0;
    struct stack *node_ptr = *stack;

    if (node_ptr != NULL) {
        success = 1;
        *stack = node_ptr->next;
 
        if (data != NULL) {
            *data = node_ptr->data;
        }

        free(node_ptr);
    }

    return success;
}

void stack_free(struct stack **stack)
{
    while (stack_pop(stack, NULL)) {}
}
