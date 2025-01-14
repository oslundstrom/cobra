#include "queue.h"
#include "stdio.h"

int queue_enqueue(Queue *queue, const void *data) {
	/* Add to tail */
	int result = list_ins_next(queue, queue->tail, data);
	return result;
}

int queue_dequeue(Queue *queue, void **data) {
	/* Remove from head */
	int result = list_rem_next(queue, NULL, data);
	return result;
}

