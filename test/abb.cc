#include <iostream>
#include "../include/ab.h"
#include "../include/nodo.h"
#include "../include/abb.h"

void randomInsert(ABB<int> &abb, int n) {
    for (int i = 0; i < n; ++i) {
        int data = rand() % 10;
        abb.insert(data); // Corregido para usar data en lugar de i
    }
}


int main() {

    std::cout << "Árbol binario de búsqueda funciona correctamente\n";
    ABB<int> abb;

    // abb.insert(10);
    // abb.insert(5);
    // abb.insert(15);
    abb.insert(7);
    // abb.insert(12);
    // abb.insert(26);
    // abb.insert(3);
    // abb.insert(8);
    // abb.insert(24);

    // randomInsert(abb, 10);

    int n;
    std::cout << "Número de elementos a insertar: ";
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        std::cout << "Insertar elemento " << i << ": ";
        int x;
        std::cin >> x;
        abb.insert(x);
        std::cout << abb << std::endl;
    }

    // for(int i = 0; i < 10; i++) {
    //     abb.insert(i);
    // }

    std::cout << "Árbol binario de búsqueda:\n " << abb << std::endl;

    std::cout << "¿El elemento 7 está en el árbol? " << (abb.search(7) ? "Sí" : "No") << std::endl;
    std::cout << "¿El elemento 20 está en el árbol? " << (abb.search(20) ? "Sí" : "No") << std::endl;

    // abb.remove(7);
    // std::cout << "Árbol después de eliminar el elemento 7: \n" << abb << std::endl;

    std::cout << "Impresión de Árbol inorden:\n";
    abb.inorden();
    std::cout << std::endl;

    return 0;
}

