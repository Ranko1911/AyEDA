#ifndef AVL_H
#define AVL_H

#include <iostream>
#include <queue>

#include "abb.h"  // Suponiendo que abb.h contiene la definición de la clase ABB

template <class T>
class AVL : public ABB<T> {
 private:
  int balance = 0;
  bool traza;

 public:
  AVL(bool traza = false) : traza(traza) {}

  bool getTraza() {
    return traza;
  }

  void setTraza(bool traza) {
    this->traza = traza;
  }

  void insert(T data) {
    // si el elemento ya está en el árbol, no lo inserta
    if (ABB<T>::search(data)) {
      std::cout << "El valor " << data
                << " ya está en el árbol, no se puede insertar\n";
      return;
    }

    ABB<T>::insert(data);
    balanceTree(this->root);
  }

  void rotateRight(NodeB<T>*& node) {
    NodeB<T>* temp = node->left;
    node->left = temp->right;
    temp->right = node;
    node = temp;
  }

  void rotateLeft(NodeB<T>*& node) {
    NodeB<T>* temp = node->right;
    node->right = temp->left;
    temp->left = node;
    node = temp;
  }

  int height(NodeB<T>* node) const {
    if (node == nullptr) return -1;
    return 1 + std::max(height(node->left), height(node->right));
  }

  int getBalance(NodeB<T>* node) const {
    if (node == nullptr) return 0;
    return height(node->left) - height(node->right);
  }

  void balanceTree(NodeB<T>*& node) {
    if (node == nullptr) return;

    balanceTree(node->left);
    balanceTree(node->right);

    int balance = getBalance(node);

    if (balance != 0 && traza) {
      std::cout << "Desbalanceo" << std::endl;
      std::cout << "Niveles ( " << balance << " ) :\n" << *this << std::endl;
      std::cout << "Desbalanceo en " << node->getData() << std::endl;
    }

    if (balance > 1) {
      if (getBalance(node->left) < 0) {
        // Rotación doble de tipo izquierda-derecha
        std::cout << "Rotación doble de tipo izquierda-derecha en "
                  << node->getData() << std::endl;
        rotateLeft(node->left);
      }
      // rotacion simple a la derecha
      std::cout << "Rotación simple a la derecha en " << node->getData()
                << std::endl;
      rotateRight(node);
    } else if (balance < -1) {
      if (getBalance(node->right) > 0) {
        // Rotación doble de tipo derecha-izquierda
        std::cout << "Rotación doble de tipo derecha-izquierda en "
                  << node->getData() << std::endl;
        rotateRight(node->right);
      }
      // rotacion simple a la izquierda
      std::cout << "Rotación simple a la izquierda en " << node->getData()
                << std::endl;
      rotateLeft(node);
    }
  }

  friend std::ostream& operator<<(std::ostream& os, const AVL<T>& ab) {
    ab.printLevelOrder(os);
    return os;
  }

  void printLevelOrder(std::ostream& os) const {
    if (this->root == nullptr) {
      os << "[.]";
      return;
    }

    std::queue<NodeB<T>*> q;
    q.push(this->root);

    while (!q.empty()) {
      int levelSize = q.size();
      bool allNull = true;  

      for (int i = 0; i < levelSize; ++i) {
        NodeB<T>* current = q.front();
        q.pop();

        if (current != nullptr) {
          os << "[" << current->data << "]" << "(" << getBalance(current) << ")"; // Aquí se calcula y muestra el balance correctamente
          if (current->left != nullptr)
            q.push(current->left);
          else
            q.push(nullptr);
          if (current->right != nullptr)
            q.push(current->right);
          else
            q.push(nullptr);
          allNull = false;
        } else {
          os << "[.]";
          q.push(nullptr);
          q.push(nullptr);
        }
      }
      os << std::endl;
      if (allNull) break;
    }
  }

};

#endif
