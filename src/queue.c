#include <stdio.h>
#include "queue.h"
#include "list.h"

struct queue_st
{
    list *data;
};

queue *QUEUE_createQueue(void)
{
    queue *queue_p = (queue*) calloc(1, sizeof(queue));
    queue_p->data  = LIST_createList();

    return queue_p;
}

void QUEUE_destroyQueue(queue *queue_p)
{
    LIST_destroyList(queue_p->data);
    free(queue_p);

    queue_p = NULL;
}

bool QUEUE_enqueue(queue *queue_p, const uint8_t *value, int value_size)
{
    return LIST_addNodeOnTail(queue_p->data, value, value_size);
}

void QUEUE_dequeue(queue *queue_p)
{
    LIST_removeFirstNode(queue_p->data);
}

uint8_t *QUEUE_peekElement(queue *queue_p)
{
    return LIST_getNodeValue(queue_p->data, 0);
}

size_t QUEUE_getQueueSize(queue *queue_p)
{
    return LIST_getListSize(queue_p->data);
}

void QUEUE_printQueue(queue *queue_p)
{
    LIST_printListValues(queue_p->data);
}