#ifndef AB_H
#define AB_H

#include <iostream>
#include <queue>
#include "nodo.h"
template <class T>
class AB {
public:
    virtual void insert(T data) = 0;
    // virtual void remove(T data) = 0;
    // virtual bool search(T data) = 0;
    // virtual void print() = 0;
    // virtual void inorden() = 0;

    friend std::ostream &operator<<(std::ostream &os, const AB<T> &ab) {
        ab.printLevelOrder(os);
        return os;
    }

protected:
    NodeB<T> *root = nullptr;

    void printLevelOrder(std::ostream &os) const {
        if (root == nullptr) {
            os << "[.]";
            return;
        }

        std::queue<NodeB<T> *> q;
        q.push(root);

        while (!q.empty()) {
            NodeB<T> *current = q.front();
            q.pop();

            if (current != nullptr) {
                os << "[" << current->data << "]";
                q.push(current->left);
                q.push(current->right);
            } else {
                os << "[.]";
            }
        }
    }
};

template <class T>
class ABB : public AB<T> { 
    public:

    void insert(T data) {
    NodeB<T> *newNode = new NodeB<T>(data);
    if (AB<T>::root == nullptr) {
        AB<T>::root = newNode;
        return;
    }

    NodeB<T> *current = AB<T>::root;
    NodeB<T> *parent = nullptr;

    while (current != nullptr) {
        parent = current;
        if (current->compareData(data)) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    if (parent->compareData(data)) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }
}

};

#endif  // AB_H