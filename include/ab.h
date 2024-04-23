#ifndef AB_H
#define AB_H

#include <iostream>
#include <queue>

#include "nodo.h"
template <class T>
class AB {
 public:
  virtual void insert(T data) = 0;
  //   virtual void remove(T data) = 0;
  virtual bool search(T data) = 0;
  // virtual void print() = 0;

  friend std::ostream& operator<<(std::ostream& os, const AB<T>& ab) {
    ab.printLevelOrder(os);
    return os;
  }

  void inorden() { inordenRecursive(AB<T>::root); }

  void inordenRecursive(NodeB<T>* current) {
    if (current != nullptr) {
      inordenRecursive(current->getLeft());
      std::cout << current->getData() << " ";
      inordenRecursive(current->getRight());
    }
  }

  void postorden() { postordenRecursive(AB<T>::root); }

  void postordenRecursive(NodeB<T>* current) {
    if (current != nullptr) {
      postordenRecursive(current->getLeft());
      postordenRecursive(current->getRight());
      std::cout << current->getData() << " ";
    }
  }

 protected:
  NodeB<T>* root = nullptr;

  void printLevelOrder(std::ostream& os) const {
    if (this->root == nullptr) {
      os << "[.]";
      return;
    }

    std::queue<NodeB<T>*> q;
    q.push(this->root);

    while (!q.empty()) {
      int levelSize = q.size();
      bool allNull = true;  // Variable para controlar si todos los nodos en el
                            // nivel son nulos
      for (int i = 0; i < levelSize; ++i) {
        NodeB<T>* current = q.front();
        q.pop();

        if (current != nullptr) {
          os << "[" << current->data << "]";
          if (current->left != nullptr)
            q.push(current->left);
          else
            q.push(
                nullptr);  // Agregar un nodo nulo si el hijo izquierdo es nulo
          if (current->right != nullptr)
            q.push(current->right);
          else
            q.push(nullptr);  // Agregar un nodo nulo si el hijo derecho es nulo
          allNull = false;    // Si hay al menos un nodo no nulo en el nivel,
                              // cambia a false
        } else {
          os << "[.]";
          q.push(nullptr);  // Agregar dos nodos nulos para mantener la
                            // estructura del árbol
          q.push(nullptr);
        }
      }
      os << std::endl;
      // Si todos los nodos en el nivel son nulos, no hay necesidad de seguir
      // imprimiendo niveles
      if (allNull) break;
    }

    // añadir "\n -------------------------------------------- \n a os"
    // os << "\n--------------------------------------------" << std::endl;
  }
};

#endif  // AB_H