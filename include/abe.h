#ifndef ABE_H
#define ABE_H

#include <queue>

#include "ab.h"

template <class T>
class ABE : public AB<T> {
 public:
  void insert(T data) override {
    this->root = insertRecursive(this->root, data);
  }

  NodeB<T>* insertRecursive(NodeB<T>* root, T data) {
    if (root == nullptr) {
      return new NodeB<T>(data);
    }

    // Calcula la altura de los subárboles izquierdo y derecho
    int leftHeight = getHeight(root->getLeft());
    int rightHeight = getHeight(root->getRight());

    // Si la altura del subárbol izquierdo es menor que la del derecho,
    // intenta insertar en el subárbol izquierdo; de lo contrario, intenta en el
    // derecho.

    if (leftHeight <= rightHeight) {
      root->setLeft(insertRecursive(root->getLeft(), data));
    } else {
      root->setRight(insertRecursive(root->getRight(), data));
    }

    // Recalcula la altura después de la inserción y ajusta si es necesario
    int newLeftHeight = getHeight(root->getLeft());
    int newRightHeight = getHeight(root->getRight());

    // std::cout << "root: " << root->getData() << std::endl;
    // std::cout << "data: " << data << std::endl;
    // std::cout << "newLeftHeight: " << newLeftHeight << std::endl;
    // std::cout << "newRightHeight: " << newRightHeight << std::endl;
    // std::cout << "++++++++++++++++++++++++++++++++++\n";

    // Si la diferencia de alturas es mayor que 1, reorganiza el árbol para
    // equilibrarlo
    if (std::abs(newLeftHeight - newRightHeight) > 1) {
      if (newLeftHeight > newRightHeight) {
        // Reorganiza el árbol rotando hacia la derecha
        root = rotateRight(root);
      } else {
        // Reorganiza el árbol rotando hacia la izquierda
        root = rotateLeft(root);
      }
    }

    return root;
  }

  int getHeight(NodeB<T>* node) {
    if (node == nullptr) {
      return 0;
    }
    return 1 +
           std::max(getHeight(node->getLeft()), getHeight(node->getRight()));
  }

  bool search(T data) override {
    std::queue<NodeB<T>*> q;
    q.push(this->root);

    while (!q.empty()) {
      NodeB<T>* current = q.front();
      q.pop();

      if (current != nullptr) {
        if (current->getData() == data) return true;
        q.push(current->getLeft());
        q.push(current->getRight());
      }
    }
    return false;
  }

  NodeB<T>* rotateRight(NodeB<T>* root) {
    NodeB<T>* newRoot = root->getLeft();
    root->setLeft(newRoot->getRight());
    newRoot->setRight(root);
    return newRoot;
  }

  NodeB<T>* rotateLeft(NodeB<T>* root) {
    NodeB<T>* newRoot = root->getRight();
    root->setRight(newRoot->getLeft());
    newRoot->setLeft(root);
    return newRoot;
  }

  // void remove(T data) override {
  //   if (this->root == nullptr) return;

  //   if (this->root->getData() == data) {
  //     delete this->root;
  //     this->root = nullptr;
  //     return;
  //   }

  //   std::queue<NodeB<T>*> q;
  //   q.push(this->root);

  //   NodeB<T>* keyNode = nullptr;
  //   NodeB<T>* current = nullptr;

  //   while (!q.empty()) {
  //     current = q.front();
  //     q.pop();

  //     if (current->getData() == data) keyNode = current;

  //     if (current->getLeft() != nullptr) q.push(current->getLeft());

  //     if (current->getRight() != nullptr) q.push(current->getRight());
  //   }

  //   if (keyNode != nullptr) {
  //     T temp = current->getData();
  //     this->removeDeepestNode(current);
  //     keyNode->setData(temp);
  //   }
  // }

 private:
  // void removeDeepestNode(NodeB<T>* delNode) {
  //   std::queue<NodeB<T>*> q;
  //   q.push(this->root);

  //   NodeB<T>* temp = nullptr;

  //   while (!q.empty()) {
  //     temp = q.front();
  //     q.pop();

  //     if (temp == delNode) {
  //       temp = nullptr;
  //       delete delNode;
  //       return;
  //     }

  //     if (temp->getRight()) {
  //       if (temp->getRight() == delNode) {
  //         temp->setRight(nullptr);
  //         delete delNode;
  //         return;
  //       } else {
  //         q.push(temp->getRight());
  //       }
  //     }

  //     if (temp->getLeft()) {
  //       if (temp->getLeft() == delNode) {
  //         temp->setLeft(nullptr);
  //         delete delNode;
  //         return;
  //       } else {
  //         q.push(temp->getLeft());
  //       }
  //     }
  //   }
  // }
};

#endif  // ABE_H
