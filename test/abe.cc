#include <iostream>
#include "../include/abe.h"

int main() {
    // Crear un árbol binario de búsqueda AVL de enteros
    ABE<int> avlTree;

    // Insertar algunos elementos en el árbol
    avlTree.insert(10);
    avlTree.insert(20);
    avlTree.insert(30);
    avlTree.insert(40);
    avlTree.insert(50);
    avlTree.insert(25);

    for (int i = 0; i < 10; i++) {
        avlTree.insert(i);
    }

    // Imprimir el árbol
    std::cout << "Árbol AVL en orden: \n";
    std::cout << avlTree << std::endl;

    // // Imprimir el árbol en orden
    // std::cout << "Árbol AVL en orden: ";
    // avlTree.inorden();
    // std::cout << std::endl;

    // Buscar un elemento en el árbol
    int searchKey = 39;
    if (avlTree.search(searchKey)) {
        std::cout << searchKey << " está presente en el árbol." << std::endl;
    } else {
        std::cout << searchKey << " no está presente en el árbol." << std::endl;
    }

    // Eliminar un elemento del árbol
    int removeKey = 20;
    avlTree.remove(removeKey);
    std::cout << "Eliminado " << removeKey << " del árbol." << std::endl;

    // Imprimir el árbol en orden
    std::cout << "Árbol AVL en orden: \n";
    std::cout << avlTree << std::endl;

    // // Imprimir el árbol nuevamente en orden después de la eliminación
    // std::cout << "Árbol AVL en orden después de eliminar " << removeKey << ": ";
    // avlTree.inorden();
    // std::cout << std::endl;

    return 0;
}
