#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>

#include "list.h"

typedef List Queue; // TODO: A more safe approach that hides this detail

/* Public interface */

#define queue_init list_init

#define queue_destroy list_destroy

int queue_enque(Queue *queue, void **data);

int queue_dequeue(Queue *queue, void **data);

#define queue_peek(queue) ((queue)->head == NULL ? NULL : (queue)->head->data)

#define queue_size list_size

#endif // QUEUE_H
