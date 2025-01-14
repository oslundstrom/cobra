#include <string.h>

#include "unity.h"
#include "list.h"

List list;

// Optional: Mock destroy function to test with
static void test_destroy(void *data) {
    // Empty implementation for testing
}

// Helper function to destroy string data
void destroy_string(void *data) {
    free(data);
}

// Helper function to create a new string
char* create_string(const char* str) {
    char* new_str = (char*)malloc(strlen(str) + 1);
    strcpy(new_str, str);
    return new_str;
}

void setUp(void) {
    list_init(&list, destroy_string);
}

void tearDown(void) {
    list_destroy(&list);
}

void test_InsertIntoEmptyList(void) {
    // Arrange
    char* data = create_string("first");

    // Act
    int result = list_ins_next(&list, NULL, data);

    // Assert
    TEST_ASSERT_EQUAL_INT(0, result);
    TEST_ASSERT_EQUAL_INT(1, list_size(&list));
    TEST_ASSERT_NOT_NULL(list_head(&list));
    TEST_ASSERT_NOT_NULL(list_tail(&list));
    TEST_ASSERT_TRUE(list_head(&list) != list_tail(&list));
    TEST_ASSERT_EQUAL_STRING("first", (char*)list_data(list_head(&list)));
}

void test_InsertAfterElement(void) {
    // Arrange
    char* first = create_string("first");
    list_ins_next(&list, NULL, first);
    char* second = create_string("second");

    // Act
    int result = list_ins_next(&list, list_head(&list), second);

    // Assert
    TEST_ASSERT_EQUAL_INT(0, result);
    TEST_ASSERT_EQUAL_INT(2, list_size(&list));
    TEST_ASSERT_TRUE(list_head(&list) != list_tail(&list));
    TEST_ASSERT_EQUAL_STRING("second", (char*)list_data(list_next(list_head(&list))));
}

void test_InsertWithNullList(void) {
    // Arrange
    char* data = create_string("test");

    // Act
    int result = list_ins_next(NULL, NULL, data);

    // Assert
    TEST_ASSERT_EQUAL_INT(-1, result);
    free(data);  // Clean up since insertion failed
}

void test_InsertAfterTail(void) {
    // Arrange
    char* first = create_string("first");
    char* second = create_string("second");
    list_ins_next(&list, NULL, first);
    list_ins_next(&list, list_head(&list), second);
    char* third = create_string("third");

    // Act
    int result = list_ins_next(&list, list_tail(&list), third);

    // Assert
    TEST_ASSERT_EQUAL_INT(0, result);
    TEST_ASSERT_EQUAL_INT(3, list_size(&list));
    TEST_ASSERT_EQUAL_STRING("third", (char*)list_data(list_tail(&list)));
}

void test_InsertWithNullData(void) {
    // Act
    int result = list_ins_next(&list, NULL, NULL);

    // Assert
    TEST_ASSERT_EQUAL_INT(0, result);
    TEST_ASSERT_EQUAL_INT(1, list_size(&list));
}

void test_list_init_should_initialize_empty_list(void) {
    // When
    list_init(&list, test_destroy);

    // Then
    TEST_ASSERT_EQUAL_INT(0, list.size);
    TEST_ASSERT_NULL(list.head);
    TEST_ASSERT_NULL(list.tail);
    TEST_ASSERT_TRUE(test_destroy != list.destroy);
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

    RUN_TEST(test_InsertIntoEmptyList);
    RUN_TEST(test_InsertAfterElement);
    RUN_TEST(test_InsertWithNullList);
    RUN_TEST(test_InsertAfterTail);
    RUN_TEST(test_InsertWithNullData);

    return UNITY_END();
}
