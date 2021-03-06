#ifndef PROBLEM_MEDIAN_TRACKER_H_
#define PROBLEM_MEDIAN_TRACKER_H_

#include <cstddef>

#include "structure/tree/search.h"

namespace problem {

// Numbers are randomly generated and stored into an (expanding) array. How
// would you keep track of the median?
template <typename T>
class MedianTracker {
 public:
  MedianTracker() : count_(0) {}

  void Consume(T value) {
    ++count_;
    tree_.Insert(value);
  }

  double Compute() const {
    Visitor visitor(count_);
    tree_.Root()->Accept(visitor);
    return visitor.median;
  }

 private:
  using Tree = structure::tree::BinarySearch<T>;
  struct Visitor;

  std::size_t count_;
  Tree tree_;
};

template <typename T>
struct MedianTracker<T>::Visitor {
  Visitor(std::size_t count)
      : begin(((double)count - 0.5) / 2),
        take(count % 2 == 0 ? 2 : 1),
        index(0), median(0.0) {}

  bool Visit(const typename Tree::Node& node) {
    if (index >= begin) {
      median += node.Value();
      if (--take == 0) {
        median /= index - begin + 1;
        return false;
      }
    }
    ++index;
    return true;
  }

  std::size_t begin;
  std::size_t take;
  std::size_t index;
  double median;
};

} // namespace problem

#endif // PROBLEM_MEDIAN_TRACKER_H_
