#ifndef QUEUE_H
#define QUEUE_H

#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct queue_st queue;

queue   *QUEUE_createQueue(void);
void     QUEUE_destroyQueue(queue *queue_p);
bool     QUEUE_enqueue(queue *queue_p, const uint8_t *value, int value_size);
void     QUEUE_dequeue(queue *queue_p);
uint8_t *QUEUE_peekElement(queue *queue_p);
size_t   QUEUE_getQueueSize(queue *queue_p);
void     QUEUE_printQueue(queue *queue_p);

#endif