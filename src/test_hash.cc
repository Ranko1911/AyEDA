#include "../include/hashtable.h"

int main() {

  DispersionFunction<int> *fd = new DispersionFunctionModule<int>(10);
  ExplorationFunction<int> *fe = new ExplorationFunctionLineal<int>;
  
  //crear hash table
  std::cout << "Crear hash table" << std::endl;
  HashTable<int> h1(12, fd, fe, 6);

  //crear hash table vacia

  //insertar elementos
  std::cout << "Insertar elementos" << std::endl;
  h1.Insert(5);
  std::cout << "Insertar 5" << std::endl;
  h1.Insert(15);
  std::cout << "Insertar 15" << std::endl;

  //insertar elementos que ya estan
  std::cout << "Insertar elementos que ya estan" << std::endl;
  h1.Insert(5);
  h1.Insert(15);

  //buscar elementos
  std::cout << "Buscar elementos" << std::endl;
  std::cout << "Busqueda de 5: " << h1.Search(5) << std::endl;
  std::cout << "Busqueda de 15: " << h1.Search(15) << std::endl;


  //buscar elementos que no estan
  std::cout << "Buscar elementos que no estan" << std::endl;
  std::cout << "Busqueda de 10: " << h1.Search(10) << std::endl;
  std::cout << "Busqueda de 20: " << h1.Search(20) << std::endl;



  return 0;

}