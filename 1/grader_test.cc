#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write some test cases for each function.
//-----------------------------------------------------------------------------

TEST(WordHistogram, Empty) {
  std::string in;
  auto actual = WordHistogram(in);
  EXPECT_EQ(actual, (std::map<std::string, int>{}));
}

TEST(WordHistogram, SingleWord) {
  std::string in = "this";
  auto actual = WordHistogram(in);
  EXPECT_EQ(actual, (std::map<std::string, int>{//
                                                {{"this", 1}}}));
}

TEST(WordHistogram, SingleWordWithSpaceAtEnd) {
  std::string in = "this ";
  auto actual = WordHistogram(in);
  EXPECT_EQ(actual, (std::map<std::string, int>{//
                                                {{"this", 1}}}));
}

TEST(WordHistogram, SingleWordWithSpaceAtBegin) {
  std::string in = " this";
  auto actual = WordHistogram(in);
  EXPECT_EQ(actual, (std::map<std::string, int>{//
                                                {{"this", 1}}}));
}

TEST(WordHistogram, SingleWordWithSpaceAtBeginAndEnd) {
  std::string in = " this ";
  auto actual = WordHistogram(in);
  EXPECT_EQ(actual, (std::map<std::string, int>{//
                                                {{"this", 1}}}));
}

TEST(WordHistogram, SingleWordWithComma1) {
  std::string in = " this, ";
  auto actual = WordHistogram(in);
  EXPECT_EQ(actual, (std::map<std::string, int>{//
                                                {{"this", 1}}}));
}
TEST(WordHistogram, SingleWordWithDotAndComma1) {
  std::string in = " this ,.";
  auto actual = WordHistogram(in);
  EXPECT_EQ(actual, (std::map<std::string, int>{//
                                                {{"this", 1}}}));
}

TEST(WordHistogram, Duplicates1) {
  std::string in = "this this. this, this,this.this. ";
  auto actual = WordHistogram(in);
  EXPECT_EQ(actual, (std::map<std::string, int>{//
                                                {{"this", 6}}}));
}

TEST(WordHistogram, MultipleWords1) {
  std::string in = "this is a test, and this is another one.";
  auto actual = WordHistogram(in);
  EXPECT_EQ(actual, (std::map<std::string, int>{//
                                                {{"a", 1},
                                                 {"and", 1},
                                                 {"another", 1},
                                                 {"is", 2},
                                                 {"one", 1},
                                                 {"test", 1},
                                                 {"this", 2}}}));
}

TEST(WordHistogram, MultipleWords2) {
  std::string in =
      "this is a test, and this is another one. here is one more and more and "
      "more. ";
  auto actual = WordHistogram(in);
  EXPECT_EQ(actual, (std::map<std::string, int>{//
                                                {{"a", 1},
                                                 {"and", 3},
                                                 {"another", 1},
                                                 {"here", 1},
                                                 {"is", 3},
                                                 {"more", 3},
                                                 {"one", 2},
                                                 {"test", 1},
                                                 {"this", 2}}}));
}