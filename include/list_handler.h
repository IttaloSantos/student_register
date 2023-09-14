#ifndef LIST_HANDLER_H
#define LIST_HANDLER_H

#include <stdint.h>
#include <stdbool.h>

typedef struct list_st linked_list;
typedef struct node_st node;

linked_list *LIST_createList(void);
bool LIST_addNodeOnHead(linked_list *list, uint8_t *value_p, int value_size);

#endif