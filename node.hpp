#ifndef NODE_HPP
#define NODE_HPP

#include "macros.hpp"
#include <functional>

template <typename T> class Node2 {
public:
  Node2 *next;
  Node2 *prev;
  T value;
  Node2(T v) : next(nullptr), prev(nullptr), value(v) {}
  Node2() : next(nullptr), prev(nullptr) {}
  ~Node2() {
    delete next;
    delete prev;
  }
};

template <typename T> class Node {
public:
  Node *next;
  T value;
  Node(T v) : next(nullptr), value(v) {}
  Node() : next(nullptr) {}
  ~Node() {}
};

template <typename T>
inline void each_node(Node<T> *first, Node<T> *last,
                      std::function<void(Node<T> *)> fn) {
  for (Node<T> *aux = first; first->next != nullptr && first != last; first) {
    fn(aux);
  }
}

  #endif
