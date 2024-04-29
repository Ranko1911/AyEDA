#ifndef ABB_H
#define ABB_H

#include <iostream>

#include "ab.h"

template <class T>
class ABB : public AB<T> {
 public:
  void insert(T data) {
    // si el elemento ya está en el árbol, no lo inserta
    if (search(data)) {
      std::cout << "El valor "<< data << " ya está en el árbol, no se puede insertar\n";
      return;
    }

    NodeB<T>* newNode = new NodeB<T>(data);
    if (AB<T>::root == nullptr) {
      AB<T>::root = newNode;
      return;
    }

    NodeB<T>* current = AB<T>::root;
    NodeB<T>* parent = nullptr;

    while (current != nullptr) {
      parent = current;
      if (data < current->getData()) {
        current = current->left;
      } else {
        current = current->right;
      }
    }

    if (data < parent->getData()) {
      parent->left = newNode;
    } else {
      parent->right = newNode;
    }
  }

  bool search(T data) { return searchRecursive(AB<T>::root, data); }

  bool searchRecursive(NodeB<T>* node, T data) {
    if (node == nullptr) {
      return false;
    }

    if (node->getData() == data) {
      return true;
    } else if (data < node->getData()) {
      return searchRecursive(node->left, data);
    } else {
      return searchRecursive(node->right, data);
    }
  }
  
};

#endif