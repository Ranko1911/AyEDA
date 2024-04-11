#ifndef ABB_H
#define ABB_H

#include <iostream>

#include "../include/ab.h"

template <class T>
class ABB : public AB<T> {
 public:
  void insert(T data) {
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

  // void remove(T data) { AB<T>::root = removeRecursive(AB<T>::root, data); }

  // NodeB<T>* removeRecursive(NodeB<T>* node, T data) {
  //   if (node == nullptr) {
  //     return nullptr;
  //   }

  //   if (data < node->getData()) {
  //     node->setLeft(removeRecursive(node->getLeft(), data));
  //   } else if (data > node->getData()) {
  //     node->setRight(removeRecursive(node->getRight(), data));
  //   } else {
  //     // Caso 1: nodo a eliminar tiene 0 o 1 hijo
  //     if (node->getLeft() == nullptr) {
  //       NodeB<T>* temp = node->getRight();
  //       delete node;
  //       return temp;
  //     } else if (node->getRight() == nullptr) {
  //       NodeB<T>* temp = node->getLeft();
  //       delete node;
  //       return temp;
  //     }

  //     // Caso 2: nodo a eliminar tiene 2 hijos
  //     NodeB<T>* temp = minValueNode(node->getRight());
  //     node->setData(temp->getData());
  //     node->setRight(removeRecursive(node->getRight(), temp->getData()));
  //   }
  //   return node;
  // }

  // NodeB<T>* minValueNode(NodeB<T>* node) {
  //   NodeB<T>* current = node;
  //   while (current && current->getLeft() != nullptr) {
  //     current = current->getLeft();
  //   }
  //   return current;
  // }

  // void inorden() { inordenRecursive(AB<T>::root); }

  // void inordenRecursive(NodeB<T>* current) {
  //   if (current != nullptr) {
  //     inordenRecursive(current->getLeft());
  //     std::cout << current->getData() << " ";
  //     inordenRecursive(current->getRight());
  //   }
  // }
};

#endif