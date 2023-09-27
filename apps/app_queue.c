#include <stdio.h>
#include "queue.h"

int main(int argc, char *argv[])
{
    queue *queue_p = QUEUE_createQueue();

    for(uint8_t i = 0; i < 30; i++)
    {
        QUEUE_enqueue(queue_p, &i, sizeof(uint8_t));
    }
    
    QUEUE_printQueue(queue_p);

    for(uint8_t i = 0; i < 10; i++)
    {
        QUEUE_dequeue(queue_p);
    }
    
    QUEUE_printQueue(queue_p);

    uint8_t *value = QUEUE_peekElement(queue_p);

    printf("Value: %d\n", *value);

    QUEUE_destroyQueue(queue_p);

    printf("\n");
    return 0;
}