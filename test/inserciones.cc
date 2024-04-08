#include <cstdlib>   // for rand()
#include <ctime>     // for srand()
#include <fstream>
#include <iostream>
#include "../include/sequence.h"  // Incluir el encabezado de la clase staticSequence

void manualInit(staticSequence<int>& sequence, int size) {
  std::cout << "Introduce los elementos de la secuencia:\n";
  int element;
  for (int i = 0; i < size; i++) {
    std::cin >> element;
    sequence.Insert(element);
    std::cout << "Elemento insertado: " << element << std::endl;
  }
}

void randomInit(staticSequence<int>& sequence, int size) {
  srand(time(nullptr));  // Initialize random seed
  for (int i = 0; i < size; i++) {
    sequence.Insert(rand() % 100);
  }
}

void fileInit(staticSequence<int>& sequence, std::string fileName) {
  std::ifstream file("files/" + fileName);  // Adjusting the file path
  if (!file.is_open()) {
    std::cerr << "No se pudo abrir el archivo " << fileName << std::endl;
    exit(1);
  }

  int n;
  while (file >> n) {
    sequence.Insert(n);
  }
}

void printSequence(const staticSequence<int>& sequence, int size) {
  std::cout << "Secuencia:\n";
  for (int i = 0; i < size; i++) {
    std::cout << sequence[i] << " ";
  }
  std::cout << std::endl;
}

int main() {
  const int size = 5;
  staticSequence<int> sequence(size);
  staticSequence<int> sequence2(size);
  staticSequence<int> sequence3(size);

  // Inicialización manual
  manualInit(sequence, size);
  printSequence(sequence, size);

  // Inicialización aleatoria
  randomInit(sequence2, size);
  printSequence(sequence2, size);

  // Inicialización desde archivo
  fileInit(sequence3, "datos.txt");
  printSequence(sequence3, size);

  return 0;
}
