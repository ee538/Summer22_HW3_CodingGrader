#include <iostream>
#include <string>

#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "q.h"
using ::testing::ElementsAre;
using ::testing::UnorderedElementsAre;

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

template <class T>
int GetLeftIndex(int i, T& data) {
  if ((2 * i) + 1 >= data.size()) {
    return INT_MAX;
  }
  return (2 * i) + 1;
}

template <class T>
int GetRightIndex(int i, T& data) {
  if ((2 * i) + 2 >= data.size()) {
    return INT_MAX;
  }
  return (2 * i) + 2;
}

bool IsHeap(std::vector<Student>& v) {
  for (int i = 0; i < v.size(); i++) {
    const auto& data = v;
    auto left_index = GetLeftIndex(i, data);
    auto right_index = GetRightIndex(i, data);

    if (left_index != INT_MAX) {
      if (data[i].grade < data[left_index].grade) {
        return false;
      }
    }

    if (right_index != INT_MAX) {
      if (data[i].grade < data[right_index].grade) {
        return false;
      }
    }
  }
  return true;
}
//-----------------------------------------------------------------------------
// Write some test cases for each function.
//-----------------------------------------------------------------------------
// These tests are for IsHeap which is already written by us.
TEST(IsHeapTest, Empty) {
  std::vector<Student> v;
  EXPECT_TRUE(IsHeap(v));
}

TEST(IsHeapTest, Test1) {
  std::vector<Student> v = {Student("Ari", 1), Student("Brad", 2),
                            Student("Chris", 3)};
  EXPECT_FALSE(IsHeap(v));
}

TEST(IsHeapTest, Test2) {
  std::vector<Student> v = {Student("Ari", 3), Student("Brad", 2),
                            Student("Chris", 1)};
  EXPECT_TRUE(IsHeap(v));
}

TEST(IsHeapTest, Test3) {
  std::vector<Student> v = {Student("Ari", 3), Student("Brad", 1),
                            Student("Chris", 2)};
  EXPECT_TRUE(IsHeap(v));
}

TEST(IsHeapTest, Test4) {
  std::vector<Student> v = {Student("Ted", 5), Student("Ari", 3),
                            Student("Brad", 1), Student("Chris", 2)};
  EXPECT_TRUE(IsHeap(v));
}

TEST(IsHeapTest, Test5) {
  std::vector<Student> v = {Student("Ted", 5), Student("Ari", 3),
                            Student("Brad", 1), Student("Chris", 8)};
  EXPECT_FALSE(IsHeap(v));
}
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

  EXPECT_THAT(actual,
              UnorderedElementsAre(Student("Chris", 3), Student("Brad", 2),
                                   Student("Ari", 1)));
  EXPECT_TRUE(IsHeap(actual));
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
  EXPECT_THAT(actual,
              UnorderedElementsAre(Student("Ted", 20), Student("David", 10),
                                   Student("Chris", 3), Student("Zane", 5),
                                   Student("Brad", 2), Student("Ari", 1)));
  EXPECT_TRUE(IsHeap(actual));
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