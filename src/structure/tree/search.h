#ifndef STRUCTURE_TREE_SEARCH_H_
#define STRUCTURE_TREE_SEARCH_H_

#include <memory>
#include <utility>

namespace structure { namespace tree {

template <typename K, typename V>
class BinarySearch {
 public:
  struct Node {
   public:
    Node(K key, V value) : key(key), value(std::move(value)) {}

    K key;
    V value;
    std::unique_ptr<Node> left;
    std::unique_ptr<Node> right;
  };

  void Insert(std::unique_ptr<Node> node);

  void Insert(K key, V value) {
    Insert(std::unique_ptr<Node>(new Node(key, std::move(value))));
  }

  template <typename T>
  void Accept(T& visitor) {
    if (root_) Accept(visitor, root_.get());
  }

  Node* Search(K key) const;

  Node* root() const {
    return root_.get();
  }

 protected:
  std::unique_ptr<Node> root_;

 private:
  template <typename T>
  void Accept(T& visitor, Node* node);
};

template <typename K, typename V>
void BinarySearch<K, V>::Insert(std::unique_ptr<Node> node) {
  if (!root_) {
    std::swap(root_, node);
    return;
  }
  auto current = root_.get();
  while (true) {
    if (node->key <= current->key) {
      if (current->left) {
        current = current->left.get();
      } else {
        std::swap(current->left, node);
        return;
      }
    } else {
      if (current->right) {
        current = current->right.get();
      } else {
        std::swap(current->right, node);
        return;
      }
    }
  }
}

template <typename K, typename V>
typename BinarySearch<K, V>::Node* BinarySearch<K, V>::Search(K key) const {
  auto current = this->root_.get();
  while (current) {
    if (key < current->key) current = current->left.get();
    else if (key > current->key) current = current->right.get();
    else return current;
  }
  return nullptr;
}

template <typename K, typename V>
template <typename T>
void BinarySearch<K, V>::Accept(T& visitor, Node* node) {
  if (node->left) Accept(visitor, node->left.get());
  visitor.Visit(node);
  if (node->right) Accept(visitor, node->right.get());
}

} } // namespace structure::tree

#endif // STRUCTURE_TREE_SEARCH_H_
