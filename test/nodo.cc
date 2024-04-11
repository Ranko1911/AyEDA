#include <iostream>
#include "../include/nodo.h"

int main() {
    // Crear algunos nodos
    NodeB<int>* node1 = new NodeB<int>(10);
    NodeB<int>* node2 = new NodeB<int>(5);
    NodeB<int>* node3 = new NodeB<int>(15);

    // Establecer las relaciones entre los nodos
    node1->setLeft(node2);
    node1->setRight(node3);

    // Actualizar la altura de node1
    node1->updateHeight();

    // Mostrar la altura de node1
    std::cout << "Altura de node1: " << node1->getHeight() << std::endl;
    std::cout << "Altura de node2: " << node2->getHeight() << std::endl;
    std::cout << "Altura de node3: " << node3->getHeight() << std::endl;

    // Crear otro nodo y establecerlo como hijo derecho de node2
    NodeB<int>* node4 = new NodeB<int>(7);
    node2->setRight(node4);

    // Actualizar la altura de node1
    node1->updateHeight();

    // Mostrar la altura de node1 nuevamente
    std::cout << "Altura de node1 después de agregar node4: " << node1->getHeight() << std::endl;

    // Liberar la memoria asignada a los nodos
    delete node1;
    delete node2;
    delete node3;
    delete node4;

    return 0;
}
