#include "algorithm/sort/assess.h"
#include "algorithm/sort/heap.h"

template <typename T>
void BinaryHeap(std::vector<T>& given) {
  std::vector<T> data;
  std::swap(data, given);
  auto before = &data[0];
  data = algorithm::sort::BinaryHeap(std::move(data));
  auto after = &data[0];
  ASSERT_EQ(before, after);
  std::swap(data, given);
}

TEST(SortTest, BinaryHeap) {
  algorithm::sort::Assess<int>(BinaryHeap);
}
