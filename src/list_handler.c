#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list_handler.h"

static bool is_list_empty(const list *linked_list);
static bool is_value_valid(const uint8_t *value_p, int value_size);
static node *create_node(const uint8_t *value_p, int value_size);

/* ######################################################### */
/*                          PUBLIC                           */
/* ######################################################### */

struct node_st
{
    uint8_t *value;
    node    *next;
};

struct list_st
{
    int   size;
    node *begin;
    node *end;
};

list *LIST_createList(void)
{
    list *linked_list = (list*) calloc(1, sizeof(list));
    return linked_list;
}

bool LIST_addNodeOnHead(list *linked_list, const uint8_t *value_p, int value_size)
{
    if(!is_value_valid(value_p, value_size)) return false;

    node *node_p = create_node(value_p, value_size);

    if(is_list_empty(linked_list)) linked_list->end = node_p;

    node_p->next       = linked_list->begin;
    linked_list->begin = node_p;
    linked_list->size++;

    return true;
}

bool LIST_addNodeOnTail(list *linked_list, const uint8_t *value_p, int value_size)
{
    if(!is_value_valid(value_p, value_size)) return false;

    node *node_p = create_node(value_p, value_size);

    if(is_list_empty(linked_list)) linked_list->begin     = node_p;
    else                           linked_list->end->next = node_p;

    linked_list->end = node_p;
    linked_list->size++;

    return true;
}

/* ######################################################### */
/*                          PRIVATE                          */
/* ######################################################### */

static bool is_list_empty(const list *linked_list)
{
    return linked_list->begin == NULL && linked_list->end == NULL;
}

static bool is_value_valid(const uint8_t *value_p, int value_size)
{
    if(value_size == 0 || value_p == NULL)
    {
        printf("Wrong value.");
        return false;
    }

    return true;
}

static node *create_node(const uint8_t *value_p, int value_size)
{
    node *node_p  = (node*)    calloc(1, sizeof(node));
    node_p->value = (uint8_t*) calloc(1, value_size*sizeof(uint8_t));

    memcpy(node_p->value, value_p, value_size);

    return node_p;
}