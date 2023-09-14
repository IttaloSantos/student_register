#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list_handler.h"

static bool is_list_empty(const linked_list *list);
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
    node *begin;
    node *end;
};

linked_list *LIST_createList(void)
{
    linked_list *list = (linked_list*) calloc(1, sizeof(linked_list));
    return list;
}

bool LIST_addNodeOnHead(linked_list *list, const uint8_t *value_p, int value_size)
{
    if(!is_value_valid(value_p, value_size)) return false;

    node *node_p = create_node(value_p, value_size);

    if(is_list_empty(list)) list->end = node_p;

    node_p->next = list->begin;
    list->begin  = node_p;

    return true;
}

bool LIST_addNodeOnTail(linked_list *list, const uint8_t *value_p, int value_size)
{
    if(!is_value_valid(value_p, value_size)) return false;

    node *node_p = create_node(value_p, value_size);

    if(is_list_empty(list)) list->begin     = node_p;
    else                    list->end->next = node_p;

    list->end = node_p;

    return true;
}

/* ######################################################### */
/*                          PRIVATE                          */
/* ######################################################### */

static bool is_list_empty(const linked_list *list)
{
    return list->begin == NULL && list->end == NULL;
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