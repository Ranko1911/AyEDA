#ifndef NODE_H
#define NODE_H

#include <iostream>

template <class T>
class NodeB {
 protected:
  T data;
  NodeB<T>* left;
  NodeB<T>* right;
  int height;

 public:
  NodeB(T data) : data(data), left(nullptr), right(nullptr), height(1) {}

  T getData() const { return data; }

  // Método para comparar el dato almacenado con otro valor
  bool compareData(const T& otherData) const { return data < otherData; }

  NodeB<T>* getLeft() { return left; }

  NodeB<T>* getRight() { return right; }

  void setData(T data) { this->data = data; }

  void setLeft(NodeB<T>* left) { this->left = left; }

  void setRight(NodeB<T>* right) { this->right = right; }

  int getHeight() { return height; }

  void setHeight(int height) { this->height = height; }

  // Método para actualizar la altura del nodo
  void updateHeight() {
    int leftHeight = (left != nullptr) ? left->getHeight() : 0;
    int rightHeight = (right != nullptr) ? right->getHeight() : 0;
    height = 1 + std::max(leftHeight, rightHeight);
  }

  template <class U>
  friend class ABB;

  template <class U>
  friend class AB;
};

#endif  // NODE_H