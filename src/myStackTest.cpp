#include "gtest/gtest.h"
#include "myStack.hpp"

class MyStackTest: public ::testing::Test
{
protected:
    MyStack<int> stack;
};

TEST_F(MyStackTest, StackIsEmptyFist)
{
    EXPECT_TRUE(stack.isEmpty());
}
TEST_F(MyStackTest, StackIsEmptySoCounterIsZero)
{
    EXPECT_EQ(stack.count(), 0);
}
TEST_F(MyStackTest, AfterPushElementStackIsNotEmpty)
{
    stack.push(1);
    EXPECT_FALSE(stack.isEmpty());
}
TEST_F(MyStackTest, AfterPushElementStackCounterIs1)
{
    stack.push(1);
    EXPECT_EQ(stack.count(), 1);
}
TEST_F(MyStackTest, AfterPushTwoElementStackCounterIs2)
{
    stack.push(1);
    stack.push(2);
    EXPECT_EQ(stack.count(), 2);
}
TEST_F(MyStackTest, AfterPushAndPopStackIsEmpty)
{
    stack.push(1);
    stack.pop();
    EXPECT_TRUE(stack.isEmpty());
}
TEST_F(MyStackTest, AfterPush1PopReturn1)
{
    stack.push(1);
    EXPECT_EQ(stack.pop(), 1);
}
TEST_F(MyStackTest, AfterDoublePushPopReturnLastElAndStackIsNotEmpty)
{
    stack.push(1);
    stack.push(2);
    EXPECT_EQ(stack.pop(), 2);
    EXPECT_FALSE(stack.isEmpty());
    EXPECT_EQ(stack.pop(), 1);
    EXPECT_TRUE(stack.isEmpty());
}
TEST_F(MyStackTest, AfterPush1TopReturn1AndStackIsNotEmpty)
{
    stack.push(1);
    EXPECT_EQ(stack.top(), 1);
    EXPECT_FALSE(stack.isEmpty());
}
TEST_F(MyStackTest, PopEmptyStackThrowException)
{
    ASSERT_THROW(stack.pop(), std::out_of_range);
}
TEST_F(MyStackTest, TopEmptyStackThrowException)
{
    ASSERT_THROW(stack.top(), std::out_of_range);
}