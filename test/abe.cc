#include <iostream>
#include "../include/abe.h"

int main() {

    // std::cout << "La inserción la hace mal, no se puede hacer de manera recursiva\n";
    // Crear un árbol binario de búsqueda ABE de enteros
    ABE<int> abeTree;

    // Insertar algunos elementos en el árbol
    // abeTree.insert(10);
    abeTree.insert(20);
    // abeTree.insert(30);
    // abeTree.insert(40);
    // abeTree.insert(50);
    // abeTree.insert(25);

    int n;
    std::cout << "Numero de elementos a insetar: \n";
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        // std::cout << "Insertar elemento " << i << " : \n";
        // int x;
        // std::cin >> x;
        abeTree.insert(i+1);
        std::cout << abeTree << std::endl;
    }


    // for (int i = 0; i < 10; i++) {
    //     abeTree.insert(rand() % 10);
    // }

    // Imprimir el árbol
    // std::cout << "Árbol ABE: \n";
    // std::cout << abeTree << std::endl;

    // Imprimir el árbol en orden
    std::cout << "Árbol ABE en orden: ";
    abeTree.inorden();
    std::cout << std::endl;

    // Buscar un elemento en el árbol
    int searchKey = 39;
    if (abeTree.search(searchKey)) {
        std::cout << searchKey << " está presente en el árbol." << std::endl;
    } else {
        std::cout << searchKey << " no está presente en el árbol." << std::endl;
    }

    // Eliminar un elemento del árbol
    // int removeKey = 20;
    // abeTree.remove(removeKey);
    // std::cout << "Eliminado " << removeKey << " del árbol." << std::endl;

    // Imprimir el árbol en orden
    // std::cout << "Árbol ABE despues de eliminar: \n";
    // std::cout << abeTree << std::endl;

    // Imprimir el árbol nuevamente en orden después de la eliminación
    // std::cout << "Árbol ABE en orden después de eliminar " << removeKey << ": ";
    // abeTree.inorden();
    // std::cout << std::endl;

    return 0;
}
