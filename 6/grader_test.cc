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

std::ostream& operator<<(std::ostream& os, const Direction& d) {
  return os << ((d == Direction::kLeft) ? "kLeft" : "kRight");
}
//-----------------------------------------------------------------------------
// Write some test cases for each function.
//-----------------------------------------------------------------------------
TEST(BinaryTree, GetPathToIthElementWorksCorrectly0) {
  BinaryTree test_binary_tree;

  int in = 0;
  std::cout << "in: " << in << std::endl;

  auto actual_path = test_binary_tree.GetPathToIthElement(in);
  std::vector<Direction> expected_path = {};
  EXPECT_EQ(actual_path, expected_path);
}

TEST(BinaryTree, GetPathToIthElementWorksCorrectly1) {
  BinaryTree test_binary_tree;

  int in = 1;
  std::cout << "in: " << in << std::endl;

  auto actual_path = test_binary_tree.GetPathToIthElement(in);
  std::vector<Direction> expected_path = {Direction::kLeft};
  EXPECT_EQ(actual_path, expected_path);
}

TEST(BinaryTree, GetPathToIthElementWorksCorrectly10) {
  BinaryTree test_binary_tree;

  int in = 10;
  std::cout << "in: " << in << std::endl;

  auto actual_path = test_binary_tree.GetPathToIthElement(in);
  std::vector<Direction> expected_path = {Direction::kLeft, Direction::kRight,
                                          Direction::kRight};
  EXPECT_EQ(actual_path, expected_path);
}

TEST(BinaryTree, GetPathToIthElementWorksCorrectly14) {
  BinaryTree test_binary_tree;

  int in = 14;
  std::cout << "in: " << in << std::endl;

  auto actual_path = test_binary_tree.GetPathToIthElement(in);
  std::vector<Direction> expected_path = {Direction::kRight, Direction::kRight,
                                          Direction::kRight};
  EXPECT_EQ(actual_path, expected_path);
}

//-----------------------------------------------------------------------------
TEST(BinaryTree, PreOrderWorksCorrectly1) {
  std::vector<int> v = {0, 1, 2, 3};

  std::cout << "Input: ";
  PrintVector(v);

  BinaryTree bt(v);
  std::vector<int> actual = bt.PreOrder();

  std::vector<int> expected = {0, 1, 3, 2};

  EXPECT_EQ(actual, expected);
}
TEST(BinaryTree, PreOrderWorksCorrectly2) {
  std::vector<int> v = {0, 1, -2, 3};

  std::cout << "Input: ";
  PrintVector(v);

  BinaryTree bt(v);
  std::vector<int> actual = bt.PreOrder();
  std::vector<int> expected = {0, 1, 3};
  EXPECT_EQ(actual, expected);
}
TEST(BinaryTree, PreOrderWorksCorrectly3) {
  std::vector<int> v = {0, 1, 2, 3, 4, -5, 6};

  std::cout << "Input: ";
  PrintVector(v);

  BinaryTree bt(v);
  std::vector<int> actual = bt.PreOrder();
  std::vector<int> expected = {0, 1, 3, 4, 2, 6};
  EXPECT_EQ(actual, expected);
}
TEST(BinaryTree, PreOrderWorksCorrectly4) {
  std::vector<int> v = {0, -1, 2, -3, -4, -5, 6};

  std::cout << "Input: ";
  PrintVector(v);

  BinaryTree bt(v);
  std::vector<int> actual = bt.PreOrder();
  std::vector<int> expected = {0, 2, 6};
  EXPECT_EQ(actual, expected);
}

//-----------------------------------------------------------------------------
TEST(BinaryTree, sizeWorksCorrectlyEmpty) {
  std::vector<int> v;

  std::cout << "Input: ";
  PrintVector(v);

  BinaryTree bt(v);
  auto actual = bt.size();
  auto expected = 0;
  EXPECT_EQ(actual, expected);
}
TEST(BinaryTree, sizeWorksCorrectly1) {
  std::vector<int> v = {0, 1, 2, 3};

  std::cout << "Input: ";
  PrintVector(v);

  BinaryTree bt(v);
  auto actual = bt.size();
  auto expected = 4;
  EXPECT_EQ(actual, expected);
}
TEST(BinaryTree, sizeWorksCorrectly2) {
  std::vector<int> v = {0, 1, 2, 3, 4, -5, 6};

  std::cout << "Input: ";
  PrintVector(v);

  BinaryTree bt(v);
  auto actual = bt.size();
  auto expected = 6;
  EXPECT_EQ(actual, expected);
}

//-----------------------------------------------------------------------------
TEST(BinaryTree, GetHeightWorksCorrectlyEmpty) {
  std::vector<int> v;

  std::cout << "Input: ";
  PrintVector(v);

  BinaryTree bt(v);
  auto actual = bt.GetHeight();
  auto expected = 0;
  EXPECT_EQ(actual, expected);
}

TEST(BinaryTree, GetHeightWorksCorrectly1) {
  std::vector<int> v = {0};

  std::cout << "Input: ";
  PrintVector(v);

  BinaryTree bt(v);
  auto actual = bt.GetHeight();
  auto expected = 1;
  EXPECT_EQ(actual, expected);
}
TEST(BinaryTree, GetHeightWorksCorrectly2) {
  std::vector<int> v = {0, 1, 2, 3};

  std::cout << "Input: ";
  PrintVector(v);

  BinaryTree bt(v);
  auto actual = bt.GetHeight();
  auto expected = 3;
  EXPECT_EQ(actual, expected);
}
TEST(BinaryTree, GetHeightWorksCorrectly3) {
  std::vector<int> v = {0, 1, 2, 3, -4, -5, -6, 7};

  std::cout << "Input: ";
  PrintVector(v);

  BinaryTree bt(v);
  auto actual = bt.GetHeight();
  auto expected = 4;
  EXPECT_EQ(actual, expected);
}
TEST(BinaryTree, GetHeightWorksCorrectly4) {
  std::vector<int> v = {0, 1, 2, 3, 4, -5, 6};

  std::cout << "Input: ";
  PrintVector(v);

  BinaryTree bt(v);
  auto actual = bt.GetHeight();
  auto expected = 3;
  EXPECT_EQ(actual, expected);
}

//-----------------------------------------------------------------------------
TEST(BinaryTree, IsBstWorksCorrectlyEmpty) {
  std::vector<int> v;
  std::cout << "Input: ";
  PrintVector(v);

  BinaryTree bt(v);
  EXPECT_EQ(IsBST(bt.root_), true);
}

TEST(BinaryTree, IsBstWorksCorrectly1) {
  std::vector<int> v = {1, 2, 3};
  std::cout << "Input: ";
  PrintVector(v);

  BinaryTree bt(v);
  EXPECT_EQ(IsBST(bt.root_), false);
}

TEST(BinaryTree, IsBstWorksCorrectly2) {
  std::vector<int> v = {2, 1, 3};

  std::cout << "Input: ";
  PrintVector(v);

  BinaryTree bt(v);
  EXPECT_EQ(IsBST(bt.root_), true);
}
