#ifndef LIST_HANDLER_H
#define LIST_HANDLER_H

#include <stdint.h>
#include <stdbool.h>

typedef struct list_st list;
typedef struct node_st node;

list    *LIST_createList(void);
bool     LIST_addNodeOnHead(list *linked_list, const uint8_t *value_p, int value_size);
bool     LIST_addNodeOnTail(list *linked_list, const uint8_t *value_p, int value_size);
int      LIST_getListSize(list *linked_list);
uint8_t *LIST_getNodeValue(list *linked_list, const int node_idx);
void     LIST_removeNode(list *linked_list, const uint8_t *value, int value_size, uint8_t offset);

#endif