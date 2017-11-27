#ifndef INTERVIEW_STRUCTURE_TREE_SEARCH_BINARY_H_
#define INTERVIEW_STRUCTURE_TREE_SEARCH_BINARY_H_

#include <memory>

namespace interview { namespace structure { namespace tree { namespace search {

struct Node;

class Binary {
 public:
  void Insert(int value);
  std::shared_ptr<Node> root() const;

 private:
  std::shared_ptr<Node> root_;
};

struct Node {
  Node(int value) : value(value) {}

  int value;
  std::shared_ptr<Node> left;
  std::shared_ptr<Node> right;
};

} } } } // namespace interview::structure::tree::search

#endif // INTERVIEW_STRUCTURE_TREE_SEARCH_BINARY_H_
