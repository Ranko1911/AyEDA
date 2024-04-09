#ifndef AB_H
#define AB_H

#include <iostream>
#include <queue>
#include "nodo.h"
template <class T>
class AB {
public:
    virtual void insert(T data) = 0;
    virtual void remove(T data) = 0;
    virtual bool search(T data) = 0;
    // virtual void print() = 0;
    virtual void inorden() = 0;

    friend std::ostream &operator<<(std::ostream &os, const AB<T> &ab) {
        ab.printLevelOrder(os);
        return os;
    }

protected:
    NodeB<T> *root = nullptr;

        void printLevelOrder(std::ostream &os) const {
    if (this->root == nullptr) {
        os << "[.]";
        return;
    }

    std::queue<NodeB<T> *> q;
    q.push(this->root);

    while (!q.empty()) {
        int levelSize = q.size();
        bool allNull = true; // Variable para controlar si todos los nodos en el nivel son nulos
        for (int i = 0; i < levelSize; ++i) {
            NodeB<T> *current = q.front();
            q.pop();

            if (current != nullptr) {
                os << "[" << current->data << "]";
                if (current->left != nullptr)
                    q.push(current->left);
                else
                    q.push(nullptr); // Agregar un nodo nulo si el hijo izquierdo es nulo
                if (current->right != nullptr)
                    q.push(current->right);
                else
                    q.push(nullptr); // Agregar un nodo nulo si el hijo derecho es nulo
                allNull = false; // Si hay al menos un nodo no nulo en el nivel, cambia a false
            } else {
                os << "[.]";
                q.push(nullptr); // Agregar dos nodos nulos para mantener la estructura del árbol
                q.push(nullptr);
            }
        }
        os << std::endl;
        // Si todos los nodos en el nivel son nulos, no hay necesidad de seguir imprimiendo niveles
        if (allNull)
            break;
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

    bool search(T data){
        NodeB<T> *current = AB<T>::root;
        while (current != nullptr) {
            if (current->getData() == data) {
                return true;
            }
            if (current->compareData(data)) {
                current = current->left;
            } else {
                current = current->right;
            }
        }
        return false;
    } 

    void remove(T data){
        NodeB<T> *current = AB<T>::root;
        NodeB<T> *parent = nullptr;
        while (current != nullptr && current->getData() != data) {
            parent = current;
            if (current->compareData(data)) {
                current = current->left;
            } else {
                current = current->right;
            }
        }
        if (current == nullptr) {
            return;
        }
        if (current->left == nullptr || current->right == nullptr) {
            NodeB<T> *newCurrent = current->left == nullptr ? current->right : current->left;
            if (parent == nullptr) {
                AB<T>::root = newCurrent;
            } else if (parent->left == current) {
                parent->left = newCurrent;
            } else {
                parent->right = newCurrent;
            }
            delete current;
        } else {
            NodeB<T> *successor = current->right;
            parent = nullptr;
            while (successor->left != nullptr) {
                parent = successor;
                successor = successor->left;
            }
            current->setData(successor->getData());
            if (parent != nullptr) {
                parent->left = successor->right;
            } else {
                current->right = successor->right;
            }
            delete successor;
        }
    }

    //metodo de impresion de inorden
    void inorden(){
        inorden(AB<T>::root);
    }
    void inorden(NodeB<T> *current){
        if (current != nullptr){
            inorden(current->getLeft());
            std::cout << current->getData() << " ";
            inorden(current->getRight());
        }
    }

};

#endif  // AB_H