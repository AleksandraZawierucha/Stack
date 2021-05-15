#include "gtest/gtest.h"
#include "myQueue.hpp"


class MyQueueTest: public ::testing::Test
{
protected:
    MyQueue<int> queue;
};

TEST_F(MyQueueTest, QueueIsEmptyFirst)
{
    EXPECT_TRUE(queue.isEmpty());
}
TEST_F(MyQueueTest, PushBackEleementQueueIsNotEmpty)
{
    queue.push_back(1);
    EXPECT_FALSE(queue.isEmpty());
}
TEST_F(MyQueueTest, PushBack2EleementQueueCountIs2)
{
    queue.push_back(1);
    queue.push_back(1);
    EXPECT_EQ(queue.count(), 2);
}
TEST_F(MyQueueTest, Push1PopReturn1AndQueueIsEmpty)
{
    queue.push_back(1); 
    EXPECT_EQ(queue.pop_front(), 1);
    EXPECT_TRUE(queue.isEmpty());
}
TEST_F(MyQueueTest, PopEmptyQueueThrowExeption)
{
    ASSERT_THROW(queue.pop_front(), std::out_of_range);
}
TEST_F(MyQueueTest, PushBack2EleementsPopInFIFOorder)
{
    queue.push_back(1);
    queue.push_back(2);
    EXPECT_FALSE(queue.isEmpty());
    EXPECT_EQ(queue.pop_front(), 1);
    EXPECT_FALSE(queue.isEmpty());
    EXPECT_EQ(queue.pop_front(), 2);
    EXPECT_TRUE(queue.isEmpty());
}