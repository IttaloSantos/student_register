#include <stdio.h>
#include "stack.h"

int main(int argc, char *argv[])
{
    stack *stack_p = STACK_createStack();

    for(uint8_t i = 0; i < 30; i++)
    {
        STACK_pushElement(stack_p, &i, sizeof(uint8_t));
    }

    STACK_printStack(stack_p);

    for(uint8_t i = 0; i < 10; i++)
    {
        STACK_popElement(stack_p);
    }

    STACK_printStack(stack_p);

    uint8_t *value_p = STACK_peekElement(stack_p);

    printf("Last value: %d\n", *value_p);

    STACK_destroyStack(stack_p);

    printf("\n");

    return 0;
}