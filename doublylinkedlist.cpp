#ifndef DOUBLY_LINKED_LIST_HPP
#define DOUBLY_LINKED_LIST_HPP
#include "macros.hpp"
#include "node.hpp"
#include <functional>

template <class T> class DoublyLinkedList {
private:
  Node2<T> *head;
  Node2<T> *tail;

public:
  size_t length = 0;
  DoublyLinkedList();
  ~DoublyLinkedList();
  void forEach(std::function<void(T)>);
  void remove(size_t);
  void insert(T, size_t);
  T get(size_t);
  bool isEmpty();
};

template <typename T>
inline DoublyLinkedList<T>::DoublyLinkedList() : head(nullptr), tail(nullptr) {}

template <typename T> inline DoublyLinkedList<T>::~DoublyLinkedList() {
  Node2<T> *n;
  EACH_NODE(n, head->next) { delete n->prev; }
  delete tail;
}

template <typename T> inline bool DoublyLinkedList<T>::isEmpty() {
  return length == 0 || (head == nullptr && tail == nullptr);
}

template <typename T>
inline void DoublyLinkedList<T>::forEach(std::function<void(T)> callback) {
  if (!isEmpty()) {
    Node2<T> *n;
    EACH_NODE(n, head) { callback(n->value); }
  }
}

template <typename T> inline void DoublyLinkedList<T>::insert(T v, size_t i) {

  Node2<T> *node = new Node2<T>(v);
  if (isEmpty()) {
    head = node;
    tail = node;
    length++;
    return;
  }

  if (i == 0) {
    head->prev = node;
    node->next = head;
    head = node;
  }
  if (i == length - 1) {
    tail->next = node;
    node->prev = tail;
    tail = node;
  }
  if (i > 0 || i < length - 1) {
    Node2<T> *aux;
    size_t j = 0;
    EACH_NODE(aux, head) {
      if (j == i) {
        node->next = aux;
        node->prev = aux->prev;
        aux->prev = node;
        aux->prev->next = node;
        break;
      }
      j++;
    }
  }

  length++;
}
template <typename T> inline void DoublyLinkedList<T>::remove(size_t i) {
  if (isEmpty())
    return;
  if (i == 0) {
    head = head->next;
    delete head->prev;
    head->prev = nullptr;
  }

  if (i > 0 || i < length - 1) {
    Node2<T> *aux;
    size_t j = 0;
    EACH_NODE(aux, head) {
      if (j == i) {
        aux->prev->next = aux->next;
        aux->next->prev = aux->prev;
        delete aux;
        break;
      }
    }
  }

  if (i == length - 1) {
    tail = tail->prev;
    delete tail->next;
    tail->next = nullptr;
  }
  length--;
}
template <typename T> inline T DoublyLinkedList<T>::get(size_t i) {
  if (i == 0)
    return head->value;
  if (i == length - 1)
    return tail->value;
  if (i > 0 || i < length < 1) {
    Node2<T> *n;
    size_t j = 0;
    EACH_NODE(n, head->next) {
      if (j == i) {
        return n->value;
      }
      j++;
    }
  }

  return head->value || tail->value;
}

#endif
