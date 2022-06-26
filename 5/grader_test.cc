#include <iostream>
#include <string>

#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "q.h"
using ::testing::ElementsAre;

template <class T>
void PrintVector(std::vector<T> input) {
  std::cout << "{ ";
  unsigned int count = 0;
  for (auto n : input) {
    count++;
    std::cout << n;
    if (count < input.size()) std::cout << ", ";
  }
  std::cout << " }" << std::endl;
}

//-----------------------------------------------------------------------------
// Write some test cases for each function.
//-----------------------------------------------------------------------------

TEST(StudentMaxHeapTest, Empty) {
  StudentMaxHeap h;
  EXPECT_TRUE(h.empty());
  EXPECT_FALSE(h.pop());
  EXPECT_EQ(h.size(), 0);
  EXPECT_EQ(h.top(), Student("NO_NAME", INT_MIN));
}

TEST(StudentMaxHeapTest, T1) {
  StudentMaxHeap h;

  std::cout << "Pushing (Ari, 1), (Brad, 2), (Chris, 3)" << std::endl;
  h.push(Student("Ari", 1));
  h.push(Student("Brad", 2));
  h.push(Student("Chris", 3));

  EXPECT_EQ(h.top(), Student("Chris", 3));
  EXPECT_TRUE(h.pop());

  EXPECT_EQ(h.top(), Student("Brad", 2));
  EXPECT_TRUE(h.pop());

  EXPECT_EQ(h.top(), Student("Ari", 1));
  EXPECT_TRUE(h.pop());

  EXPECT_EQ(h.top(), Student("NO_NAME", INT_MIN));
  EXPECT_FALSE(h.pop());
}

TEST(StudentMaxHeapTest, ConvertToHeap) {
  StudentMaxHeap h;

  std::cout << "Pushing (Ari, 1), (Brad, 2), (Chris, 3)" << std::endl;

  std::vector<Student> v = {Student("Ari", 1), Student("Brad", 2),
                            Student("Chris", 3)};

  std::cout << "Input: ";
  PrintVector(v);

  h.ConvertToHeap(v);
  auto actual = h.GetData();

  EXPECT_THAT(actual, ElementsAre(Student("Chris", 3), Student("Brad", 2),
                                  Student("Ari", 1)));
}

TEST(StudentMaxHeapTest, ConvertToHeapRandomOrder) {
  StudentMaxHeap h;
  std::vector<Student> v = {Student("Ari", 1),  Student("David", 10),
                            Student("Ted", 20), Student("Zane", 5),
                            Student("Brad", 2), Student("Chris", 3)};

  std::cout << "Input: ";
  PrintVector(v);

  h.ConvertToHeap(v);
  auto actual = h.GetData();
  EXPECT_THAT(actual, ElementsAre(Student("Ted", 20), Student("David", 10),
                                  Student("Chris", 3), Student("Zane", 5),
                                  Student("Brad", 2), Student("Ari", 1)));
}

TEST(StudentMaxHeapTest, HeapSort) {
  StudentMaxHeap h;
  std::vector<Student> v = {Student("Ari", 1),  Student("David", 10),
                            Student("Ted", 20), Student("Zane", 5),
                            Student("Brad", 2), Student("Chris", 3)};

  std::cout << "Input: ";
  PrintVector(v);

  HeapSort(v);

  EXPECT_THAT(v, ElementsAre(Student("Ari", 1), Student("Brad", 2),
                             Student("Chris", 3), Student("Zane", 5),
                             Student("David", 10), Student("Ted", 20)));
}
