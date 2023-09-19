#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list_handler.h"

static bool is_list_empty(const list *linked_list);
static bool is_value_valid(const uint8_t *value_p, int value_size);
static node *create_node(const uint8_t *value_p, int value_size);
static bool find_value_in_node(const uint8_t *n_value, const uint8_t *value, 
                                int value_size, uint8_t offset);

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

int LIST_getListSize(list *linked_list)
{
    return linked_list->size;
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

uint8_t *LIST_getNodeValue(list *linked_list, const int node_idx)
{
    if(linked_list == NULL || 
        node_idx > LIST_getListSize(linked_list)) return NULL;

    node *node_p = linked_list->begin;
    int   i = 0;

    while(node_p->next != NULL)
    {
        if(i++ == node_idx) break;
        node_p = node_p->next;
    }

    return node_p->value;
}

void LIST_removeNode(list *linked_list, const uint8_t *value, int value_size, uint8_t offset)
{
    node *node_p   = linked_list->begin;
    node *node_aux = linked_list->begin;

    for(int i = 0; i < linked_list->size; i++)
    {
        if(!find_value_in_node(node_p->value, value, value_size, offset))
        {
            node_aux = node_p;
            node_p   = node_p->next;
            continue;
        }

        if(i == 0)                          linked_list->begin = node_p->next;
        else if(i == linked_list->size - 1) linked_list->end   = node_aux;
        else                                node_aux->next     = node_p->next;
        
        free(node_p);
        node_p = NULL;
        break;
    }
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

static bool find_value_in_node(const uint8_t *n_value, const uint8_t *value,
                                int value_size, uint8_t offset)
{
    return memcmp(n_value+offset, value, value_size) == 0;
}