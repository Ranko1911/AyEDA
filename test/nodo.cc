// fichero para comprobar el funcionamiento de nodo
#include <iostream>
#include "../include/nodo.h"

int main() {
    NodeB<int> node1(5);
    NodeB<int> node2(10);
    NodeB<int> node3(15);

    // Linking nodes
    node1.setLeft(&node2);
    node1.setRight(&node3);

    std::cout << "Node 1 data: " << node1.getData() << std::endl;
    std::cout << "Node 1 left child data: " << node1.getLeft()->getData() << std::endl;
    std::cout << "Node 1 right child data: " << node1.getRight()->getData() << std::endl;

    return 0;
}