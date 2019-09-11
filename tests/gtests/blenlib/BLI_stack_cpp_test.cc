#include "testing/testing.h"
#include "BLI_stack.hpp"

using IntStack = BLI::Stack<int>;

TEST(stack, DefaultConstructor)
{
  IntStack stack;
  EXPECT_EQ(stack.size(), 0);
  EXPECT_TRUE(stack.empty());
}

TEST(stack, ArrayRefConstructor)
{
  std::array<int, 3> array = {4, 7, 2};
  IntStack stack(array);
  EXPECT_EQ(stack.size(), 3);
  EXPECT_EQ(stack.pop(), 2);
  EXPECT_EQ(stack.pop(), 7);
  EXPECT_EQ(stack.pop(), 4);
  EXPECT_TRUE(stack.empty());
}

TEST(stack, Push)
{
  IntStack stack;
  EXPECT_EQ(stack.size(), 0);
  stack.push(3);
  EXPECT_EQ(stack.size(), 1);
  stack.push(5);
  EXPECT_EQ(stack.size(), 2);
}

TEST(stack, Pop)
{
  IntStack stack;
  stack.push(4);
  stack.push(6);
  EXPECT_EQ(stack.pop(), 6);
  EXPECT_EQ(stack.pop(), 4);
}

TEST(stack, Peek)
{
  IntStack stack;
  stack.push(3);
  stack.push(4);
  EXPECT_EQ(stack.peek(), 4);
  EXPECT_EQ(stack.peek(), 4);
  stack.pop();
  EXPECT_EQ(stack.peek(), 3);
}