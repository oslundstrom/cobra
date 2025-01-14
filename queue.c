#include "queue.h"
#include "stdio.h"

int queue_enqueue(Queue *queue, const void *data) {
	printf("The pointer is %p\n", data);
	printf("The data is %i\n", *(int *)data); // First cast void pointer to int pointer, then deref
	int result = list_ins_next(queue, NULL, data);
	return result;
}

int queue_dequeue(Queue *queue, void **data) {
	int result = list_rem_next(queue, NULL, data);
	return result;
}

