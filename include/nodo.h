#ifndef NODE_H
#define NODE_H

#include <iostream>

template <class T>
class NodeB {
 protected:
  T data;
  NodeB<T>* left;
  NodeB<T>* right;

 public:
  NodeB(T data) : data(data), left(nullptr), right(nullptr) {}

  T getData() const { return data; }

  // Método para comparar el dato almacenado con otro valor
  bool compareData(const T& otherData) const { return data < otherData; }

  NodeB<T>* getLeft() { return left; }

  NodeB<T>* getRight() { return right; }

  void setData(T data) { this->data = data; }

  void setLeft(NodeB<T>* left) { this->left = left; }

  void setRight(NodeB<T>* right) { this->right = right; }

  template <class U>
  friend class ABB;

  template <class U>
  friend class AB;
};

#endif  // NODE_H