#include <array>
#include <cstdlib>
#include <iostream>
#include <list>
#include <string>
#include <vector>

#include "../include/dispersion.h"
#include "../include/exploration.h"
#include "../include/hashtable.h"
#include "../include/sequence.h"

void test() {
  std::cout << "Ejemplo de uso de la clase DispersionFunction: \n";

  ModuloDispersion<unsigned> modulo(10);
  std::cout << "Modulo: " << modulo(23) << std::endl;

  SumaDispersion<std::vector<int>> suma(10);
  std::vector<int> key = {1, 2, 3};
  std::cout << "Suma: " << suma(key) << std::endl;

  PseudoaleatoriaDispersion<int> pseudo(10);
  std::cout << "Pseudoaleatoria: " << pseudo(42) << std::endl;

  std::cout << "Ejemplo de uso de la clase Exploracion: \n";

  ExploracionLineal lineal;
  std::cout << "Lineal: " << lineal(23, 2) << std::endl;

  ExploracionCuadratica cuadratica;
  std::cout << "Cuadratica: " << cuadratica(23, 2) << std::endl;

  ModuloDispersion<unsigned> modulo2(10);
  DobleDispersion doble_(&modulo2);
  std::cout << "Doble: " << doble_(23, 2) << std::endl;

  ModuloDispersion<unsigned> modulo3(10);
  Redispersion redis(&modulo3);
  std::cout << "Redispersion: " << redis(23, 2) << std::endl;

  std::cout << "Ejemplo de uso de la clase Sequence: \n";

  ArraySequence<int> array(3);
  std::cout << "Insetar 1 y 2 en el array: \n";
  array.insert(1);
  array.insert(2);

  std::cout << "Array: ";
  array.print(std::cout);

  std::cout << "Buscar 1 en el array: " << array.search(1) << std::endl;
  std::cout << "------------------\n";

  ListSequence<int> list;
  std::cout << "Insetar 1 y 2 en la lista: \n";
  list.insert(1);
  list.insert(2);

  std::cout << "List: ";
  list.print(std::cout);

  std::cout << "Buscar 1 en la lista: " << list.search(1) << std::endl;
}

int main() {
  //    test();

    std::cout << "Ejemplo de uso de la clase HashTable: \n";

  DispersionFunction<unsigned>* dispersion = new ModuloDispersion<unsigned>(10);
  Exploracion* exploration = new ExploracionLineal();
  Sequence<unsigned>* table = new ArraySequence<unsigned>(3);
    int tableSize = 10;
    int blockSize = 5;

  HashTable<unsigned, ArraySequence<unsigned>> hash(tableSize, dispersion, exploration, blockSize);

  return 0;
}