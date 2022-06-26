#include <iostream>
#include <string>

#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "q.h"
using ::testing::ElementsAreArray;
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

//-----------------------------------------------------------------------------
// Write some test cases for each function.
//-----------------------------------------------------------------------------
TEST(SinglyLinkedList, PushBackWorks) {
  SinglyLinkedList l;
  std::cout << "Push 2" << std::endl;
  l.push_back(2);

  EXPECT_EQ(l[0], 2);
  EXPECT_EQ(l[1], -1);
  EXPECT_EQ(l[200], -1);
}

TEST(SinglyLinkedList, PopBackWorks) {
  SinglyLinkedList l;
  std::cout << "Push 0, 1, 2" << std::endl;
  l.push_back(0);
  l.push_back(1);
  l.push_back(2);

  std::cout << "Pop" << std::endl;
  EXPECT_TRUE(l.pop_back());

  EXPECT_EQ(l[0], 0);
  EXPECT_EQ(l[1], 1);
  EXPECT_EQ(l.size(), 2);
}

TEST(SinglyLinkedList, PopBackWorksEmpty) {
  SinglyLinkedList l;
  std::cout << "Pop" << std::endl;

  EXPECT_FALSE(l.pop_back());
  EXPECT_TRUE(l.empty());
}

TEST(SinglyLinkedList, EraseWorks) {
  SinglyLinkedList l;
  std::cout << "Push 1, 2, 3" << std::endl;

  l.push_back(1);
  l.push_back(2);
  l.push_back(3);

  std::cout << "Call erase(0)" << std::endl;

  auto actual = l.erase(0);

  EXPECT_EQ(l[0], 2);
  EXPECT_EQ(l[1], 3);
  EXPECT_EQ(l.size(), 2);
  EXPECT_EQ(actual, nullptr);
}

TEST(SinglyLinkedList, EraseWorksMiddle) {
  SinglyLinkedList l;

  std::cout << "Push 1, 2, 3" << std::endl;

  l.push_back(1);
  l.push_back(2);
  l.push_back(3);

  std::cout << "Call erase(1)" << std::endl;

  auto actual = l.erase(1);

  EXPECT_EQ(l[0], 1);
  EXPECT_EQ(l[1], 3);
  EXPECT_EQ(l.size(), 2);
  EXPECT_EQ(actual->val, 1);
}

TEST(SinglyLinkedList, EraseWorksEnd) {
  SinglyLinkedList l;
  std::cout << "Push 1, 2, 3" << std::endl;

  l.push_back(1);
  l.push_back(2);
  l.push_back(3);

  std::cout << "Call erase(2)" << std::endl;

  auto actual = l.erase(2);

  EXPECT_EQ(l[0], 1);
  EXPECT_EQ(l[1], 2);
  EXPECT_EQ(l.size(), 2);
  EXPECT_EQ(actual->val, 2);
}

TEST(SinglyLinkedList, EraseWorksOutside) {
  SinglyLinkedList l;
  std::cout << "Push 1, 2, 3" << std::endl;

  l.push_back(1);
  l.push_back(2);
  l.push_back(3);

  auto actual = l.erase(3);

  EXPECT_EQ(l[0], 1);
  EXPECT_EQ(l[1], 2);
  EXPECT_EQ(l[2], 3);
  EXPECT_EQ(l.size(), 3);
  EXPECT_EQ(actual, nullptr);
}

TEST(SinglyLinkedList, ConvertToVectorWorks) {
  SinglyLinkedList l;
  std::cout << "Push 1, 2, 3" << std::endl;

  l.push_back(1);
  l.push_back(2);
  l.push_back(3);

  auto actual = l.convert_to_vector();
  EXPECT_THAT(actual, ElementsAreArray({1, 2, 3}));
}

TEST(SinglyLinkedList, ConvertToVectorEmpty) {
  SinglyLinkedList l;

  auto actual = l.convert_to_vector();
  EXPECT_TRUE(actual.empty());
}

TEST(SinglyLinkedList, ConstructorWorks) {
  std::vector<int> in = {0, 1, 2, 3};

  std::cout << "Input: ";
  PrintVector(in);

  SinglyLinkedList l(in);

  auto actual = l.convert_to_vector();
  EXPECT_THAT(actual, ElementsAreArray({0, 1, 2, 3}));
}

TEST(SinglyLinkedList, CopyConstructorWorks) {
  std::vector<int> in = {0, 1, 2, 3};

  std::cout << "Input: ";
  PrintVector(in);

  SinglyLinkedList l1(in);

  std::cout << "Performing SinglyLinkedList l2 = l1.";

  SinglyLinkedList l2 = l1;
  auto actual = l2.convert_to_vector();
  EXPECT_THAT(actual, ElementsAreArray({0, 1, 2, 3}));
}

TEST(SinglyLinkedList, CopyConstructorWorksEmpty) {
  SinglyLinkedList l1;

  std::cout << "Performing SinglyLinkedList l2 = l1 on an empty list.";

  SinglyLinkedList l2 = l1;
  auto actual = l2.convert_to_vector();
  EXPECT_TRUE(actual.empty());
}

TEST(SinglyLinkedList, RemoveDuplicatesWorks) {
  std::vector<int> in = {0, 1, 2, 3, 1};

  std::cout << "Input: ";
  PrintVector(in);

  SinglyLinkedList l(in);

  l.remove_duplicates();

  auto actual = l.convert_to_vector();
  EXPECT_THAT(actual, ElementsAreArray({0, 1, 2, 3}));
}

TEST(SinglyLinkedList, RemoveDuplicatesWorksMoreNumbers) {
  std::vector<int> in = {0, 1, 2, 3, 1, 2, 2, 3, 3, 1, 0, 0, 4};

  std::cout << "Input: ";
  PrintVector(in);

  SinglyLinkedList l(in);
  l.remove_duplicates();

  auto actual = l.convert_to_vector();
  EXPECT_THAT(actual, ElementsAreArray({0, 1, 2, 3, 4}));
}

TEST(SinglyLinkedList, RemoveDuplicatesWorksNoDuplicates) {
  std::vector<int> in = {0, 1, 2, 3, 4};

  std::cout << "Input: ";
  PrintVector(in);

  SinglyLinkedList l(in);

  l.remove_duplicates();

  auto actual = l.convert_to_vector();
  EXPECT_THAT(actual, ElementsAreArray({0, 1, 2, 3, 4}));
}

TEST(SinglyLinkedList, RemoveDuplicatesWorksEmpty) {
  SinglyLinkedList l;
  l.remove_duplicates();

  auto actual = l.convert_to_vector();
  EXPECT_TRUE(actual.empty());
}