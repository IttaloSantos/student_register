#include <stdio.h>
#include "stack.h"
#include "list.h"

struct stack_st
{
    list *data;
};

stack *STACK_createStack(void)
{
    stack *stack_p = (stack*) calloc(1, sizeof(stack));
    stack_p->data = LIST_createList();

    return stack_p;
}

void STACK_destroyStack(stack *stack_p)
{
    LIST_destroyList(stack_p->data);
    free(stack_p);

    stack_p = NULL;
}

bool STACK_pushElement(stack *stack_p, const uint8_t *value, int value_size)
{
    return LIST_addNodeOnTail(stack_p->data, value, value_size);
}

uint8_t *STACK_peekElement(stack *stack_p)
{
    size_t element_idx = LIST_getListSize(stack_p->data) - 1;
    return LIST_getNodeValue(stack_p->data, (int)element_idx);
}