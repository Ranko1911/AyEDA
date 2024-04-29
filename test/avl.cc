#include "../include/avl.h"

#include <iostream>

int main() {
  AVL<int> avlTree(true);

  //impirimir por niveles
  std::cout << "Árbol vacío:\n" << avlTree << std::endl;

  // Insertar elementos
  std::cout << "Insertar 30" << std::endl;
  avlTree.insert(30);
  std::cout << "Insertar 25" << std::endl;
  avlTree.insert(25);
  std::cout << "Insertar 15" << std::endl;
  avlTree.insert(15);
  std::cout << "Insertar 40" << std::endl;
  avlTree.insert(40);

  // Imprimir por niveles
  std::cout << "Niveles:\n" << avlTree << std::endl;



  return 0;
}
