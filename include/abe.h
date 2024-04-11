#ifndef ABE_H
#define ABE_H

#include <queue>

#include "ab.h"

template <class T>
class ABE : public AB<T> {
 public:
  void insert(T data) override {
    if (this->root == nullptr) {
      this->root = new NodeB<T>(data);
      return;
    }

    std::queue<NodeB<T>*> q;
    q.push(this->root);

    while (!q.empty()) {
      NodeB<T>* current = q.front();
      q.pop();

      if (current->getLeft() == nullptr) {
        current->setLeft(new NodeB<T>(data));
        return;
      } else {
        q.push(current->getLeft());
      }

      if (current->getRight() == nullptr) {
        current->setRight(new NodeB<T>(data));
        return;
      } else {
        q.push(current->getRight());
      }
    }
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
