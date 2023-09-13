#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list_handler.h"

struct node_st
{
    uint8_t *value;
    node    *next;
};

struct list_st
{
    node *begin;
    node *end;
};

linked_list *LIST_createList(void)
{
    linked_list *list = (linked_list*) calloc(1, sizeof(linked_list));
    return list;
}
