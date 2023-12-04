#include "stack.h"
#include <gtest.h>

TEST(TStack, can_create_stack_with_positive_length) {
	ASSERT_NO_THROW(TStack<int> stack(5));
}

TEST(TStack, cant_create_stack_with_negative_length) {
	ASSERT_ANY_THROW(TStack<int> stack(-5));
}

TEST(TStack, cant_pop_empty_stack) {
	TStack<int> stack;
	ASSERT_ANY_THROW(stack.pop());
}

TEST(TStack, cant_top_empty_stack) {
	TStack<int> stack;
	ASSERT_ANY_THROW(stack.top());
}

TEST(TStack, can_push_element) {
	TStack<int> stack;
	ASSERT_NO_THROW(stack.push(-1));
}

TEST(TStack, can_push_many_elements) {
	TStack<int> stack;
	ASSERT_NO_THROW(stack.push(1));
	ASSERT_NO_THROW(stack.push(2));
	ASSERT_NO_THROW(stack.push(3));
	ASSERT_NO_THROW(stack.push(4));
	ASSERT_NO_THROW(stack.push(5));
	ASSERT_NO_THROW(stack.push(6));
	ASSERT_NO_THROW(stack.push(7));
	ASSERT_NO_THROW(stack.push(8));
}

TEST(TStack, is_pushed_elements_correct) {
	TStack<int> stack;
	stack.push(10);
	EXPECT_EQ(10, stack.top());

	stack.push(100);
	EXPECT_EQ(100, stack.top());

	stack.push(1000);
	EXPECT_EQ(1000, stack.top());
}

TEST(TStack, can_stack_copy) {
	TStack<int> stack;
	stack.push(10);
	stack.push(100);
	stack.push(1000);
	ASSERT_NO_THROW(TStack<int> st2(stack));
}

TEST(TStack, is_stack_copy_correct) {
	TStack<int> stack;
	stack.push(10);
	stack.push(100);
	stack.push(1000);
	TStack<int> st2(stack);
	EXPECT_TRUE(stack == st2);
}