#ifndef STACK_H
#define STACK_H

#include <stdint.h>
#include <stdlib.h>

typedef struct stack_st stack;

stack   *STACK_createStack(void);
void     STACK_destroyStack(stack *stack_p);
void     STACK_pushElement(stack *stack_p, const uint8_t *value);
uint8_t *STACK_popElement(stack *stack_p);
uint8_t *STACK_peekElement(stack *stack_p);
size_t   STACK_getStackSize(stack *stack_p);
void     STACK_printStack(stack *stack_p);

#endif