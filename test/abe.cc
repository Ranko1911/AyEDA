// #include <iostream>

// #include "../include/ab.h"

// int main() {
//     // Crear un árbol binario equilibrado (ABE) de enteros
//     ABE<int> avlTree;

//     // Insertar algunos valores
//     avlTree.insert(10);
//     avlTree.insert(5);
//     avlTree.insert(15);
//     avlTree.insert(3);
//     avlTree.insert(7);
//     avlTree.insert(12);
//     avlTree.insert(17);

//     // Imprimir el árbol en orden
//     std::cout << "Árbol en orden: ";
//     avlTree.inorden();
//     std::cout << std::endl;

//     // Buscar algunos valores
//     std::cout << "Buscar 7: " << (avlTree.search(7) ? "Encontrado" : "No encontrado") << std::endl;
//     std::cout << "Buscar 20: " << (avlTree.search(20) ? "Encontrado" : "No encontrado") << std::endl;

//     // Eliminar algunos valores
//     avlTree.remove(7);
//     avlTree.remove(15);

//     // Imprimir el árbol actualizado en orden
//     std::cout << "Árbol actualizado en orden después de eliminar 7 y 15: ";
//     avlTree.inorden();
//     std::cout << std::endl;

//     return 0;
// }