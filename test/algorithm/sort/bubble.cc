#include <algorithm>

#include "fixture.h"
#include "gtest/gtest.h"
#include "algorithm/sort/bubble.h"

using namespace algorithm::sort;

const int kCount = 100;

TEST(SortTest, Bubble) {
  const std::vector<int> data = fixture::Generate<int>(kCount);
  std::vector<int> expected(data);
  std::sort(expected.begin(), expected.end());

  std::vector<int> actual(data);
  Bubble<int>(actual);
  ASSERT_EQ(actual, expected);
}
