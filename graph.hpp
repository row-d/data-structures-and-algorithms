#ifndef GRAPH_HPP
#define GRAPH_HPP
#include "dynamicarray.hpp"
#include "macros.hpp"

template <typename T> class GraphElement {
private:
  static size_t current_id;

public:
  size_t id;
  T value;
  GraphElement(T v) : value(v), id(current_id++) {}
};
template <typename T> size_t GraphElement<T>::current_id = 0;

template <typename T, typename W = bool> class GraphMatrixBased {
private:
  size_t __length;
  DynamicArray<DynamicArray<W>> adjacencyMatrix;
  T *Nodes;

public:
  GraphMatrixBased(const size_t);
  ~GraphMatrixBased();
  void addVertex(size_t from, size_t to);
  void addVertex(size_t from, size_t to, W weight);
};

template <typename T, typename W>
inline GraphMatrixBased<T, W>::GraphMatrixBased(const size_t len) {
  __length = len;
  Nodes = new T[len];
  adjacencyMatrix.reserve(len);
  size_t i;
  FROM0TO(i, len) { adjacencyMatrix[i].reserve(len);   }
}

template <typename T, typename W>
inline GraphMatrixBased<T, W>::~GraphMatrixBased() {
  size_t i;
  FROM0TO(i, __length) { delete[] adjacencyMatrix[i]; }
  delete[] adjacencyMatrix;
  delete[] Nodes;
}

#endif // GRAPH_HPP