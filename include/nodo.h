#include <iostream>

template <class T>
class NodeB {
 protected:
  T data;
  NodeB<T>* left;
  NodeB<T>* right;

 public:
  NodeB(T data) : data(data), left(nullptr), right(nullptr) {}

  T getData() { return data; }

  NodeB<T>* getLeft() { return left; }

  NodeB<T>* getRight() { return right; }

  void setData(T data) { this->data = data; }

  void setLeft(NodeB<T>* left) { this->left = left; }

  void setRight(NodeB<T>* right) { this->right = right; }
};