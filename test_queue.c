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

void test_enqueue_should_increase_size(void) {
    int value = 42;
    void *data = &value;
    queue_init(&queue, NULL);

    TEST_ASSERT_EQUAL_INT(0, queue_enqueue(&queue, data));
    TEST_ASSERT_EQUAL_INT(1, queue_size(&queue));

    queue_destroy(&queue);
}

void test_peek_should_return_first_value_enqueued(void) {
    Queue queue;
    queue_init(&queue, NULL);

    int value = 42;
    void *data = &value;
    queue_enqueue(&queue, data);

    void *peeked = queue_peek(&queue);
    TEST_ASSERT_EQUAL_PTR(&value, peeked);
    TEST_ASSERT_EQUAL_INT(value, *(int*)peeked);

    queue_destroy(&queue);
}

void test_enqueue_should_store_correct_pointer_level(void) {
    Queue queue;
    queue_init(&queue, NULL);

    int value = 42;
    void *data = &value;      // data points to value

    queue_enqueue(&queue, data);  // Should store data (0x100), not data_ptr (0x200)

    void *peeked = queue_peek(&queue);
	printf("value returned by peek: %p\n", peeked);
    TEST_ASSERT_EQUAL_PTR(&value, peeked);  // Should point directly to value
    TEST_ASSERT_EQUAL_INT(42, *(int*)peeked);

    queue_destroy(&queue);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_new_queue_should_be_empty);
    RUN_TEST(test_enqueue_should_increase_size);
    RUN_TEST(test_enqueue_should_store_correct_pointer_level);
    RUN_TEST(test_peek_should_return_first_value_enqueued);
    return UNITY_END();
}
