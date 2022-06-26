#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write some test cases for each function.
//-----------------------------------------------------------------------------
TEST(Queue, EmptyQueue) {
  Queue q;
  EXPECT_TRUE(q.IsEmpty());
  EXPECT_FALSE(q.Dequeue());
  EXPECT_EQ(q.Front(), -1);
}

TEST(Queue, SimpleOperations) {
  Queue q;

  std::cout << "Enqueue 1, 2, 3" << std::endl;
  q.Enqueue(1);
  q.Enqueue(2);
  q.Enqueue(3);

  std::cout << "Calling Dequeue()" << std::endl;
  q.Dequeue();

  EXPECT_EQ(q.Front(), 2);
}

TEST(Queue, CopyConstructor) {
  Queue q1;

  std::cout << "Enqueue 1, 2, 3" << std::endl;
  q1.Enqueue(1);
  q1.Enqueue(2);
  q1.Enqueue(3);

  std::cout << "Calling Dequeue()" << std::endl;
  q1.Dequeue();

  std::cout << "Performing Queue q2 = q1" << std::endl;

  Queue q2 = q1;
  EXPECT_EQ(q2.Front(), 2);

  std::cout << "Calling q1.Dequeue()" << std::endl;

  q1.Dequeue();
  EXPECT_EQ(q1.Front(), 3);
  EXPECT_EQ(q2.Front(), 2);
}