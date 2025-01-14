#include "unity.h"
#include "queue.h"

Queue queue;
void *data;

void setUp(void) {
}

void tearDown(void) {
}

void test_new_queue_should_be_empty(void) {
    queue_init(&queue, NULL);
    TEST_ASSERT_EQUAL_INT(0, queue_size(&queue));
    queue_destroy(&queue);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_new_queue_should_be_empty);
    return UNITY_END();
}
