#include <iostream>
#include "../include/ab.h"
#include "../include/nodo.h"

int main() {
    ABB<int> abb;
    abb.insert(10);
    abb.insert(5);
    abb.insert(15);
    abb.insert(7);
    abb.insert(12);

    std::cout << "Árbol binario de búsqueda: " << abb << std::endl;

    // std::cout << "¿El elemento 7 está en el árbol? " << (abb.search(7) ? "Sí" : "No") << std::endl;
    // std::cout << "¿El elemento 20 está en el árbol? " << (abb.search(20) ? "Sí" : "No") << std::endl;

    // abb.remove(7);
    // std::cout << "Árbol después de eliminar el elemento 7: " << abb << std::endl;

    return 0;
}

