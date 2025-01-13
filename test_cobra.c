#include "unity.h"
#include "list.h"

// Declare test state variables
List list;

// Optional: Mock destroy function to test with
static void test_destroy(void *data) {
    // Empty implementation for testing
}

void setUp(void) {
    // Setup runs before each test
}

void tearDown(void) {
    // Cleanup runs after each test
}

void test_list_init_should_initialize_empty_list(void) {
    // When
    list_init(&list, test_destroy);

    // Then
    TEST_ASSERT_EQUAL_INT(0, list.size);
    TEST_ASSERT_NULL(list.head);
    TEST_ASSERT_NULL(list.tail);
    TEST_ASSERT_EQUAL_PTR(test_destroy, list.destroy);
    TEST_ASSERT_NULL(list.match);
}

void test_list_init_should_accept_null_destroy_function(void) {
    // When
    list_init(&list, NULL);

    // Then
    TEST_ASSERT_EQUAL_INT(0, list.size);
    TEST_ASSERT_NULL(list.head);
    TEST_ASSERT_NULL(list.tail);
    TEST_ASSERT_NULL(list.destroy);
    TEST_ASSERT_NULL(list.match);
}

// Test runner
int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_list_init_should_initialize_empty_list);
    RUN_TEST(test_list_init_should_accept_null_destroy_function);

    return UNITY_END();
}
