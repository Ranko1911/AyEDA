#include <cstdlib>  // for rand()
#include <ctime>    // for srand()
#include <fstream>
#include <iostream>

void manualInit(int x[], int size) {
  std::cout << "Introduce los elementos de la secuencia:\n";
  for (int i = 0; i < size; i++) {
    std::cin >> x[i];
  }
}

void randomInit(int x[], int size) {
  srand(time(nullptr));  // Initialize random seed
  for (int i = 0; i < size; i++) {
    x[i] = rand() % 100;
  }
}

void fileInit(int x[], int size, std::string fileName) {
  std::ifstream file("files/" + fileName);  // Adjusting the file path
  if (!file.is_open()) {
    std::cerr << "No se pudo abrir el archivo " << fileName << std::endl;
    exit(1);
  }

  int n;
  int i = 0;
  while (file >> n && i < size) {
    x[i++] = n;
  }
}

void printSequence(int x[], int size) {
  std::cout << "Secuencia:\n";
  for (int i = 0; i < size; i++) {
    std::cout << x[i] << " ";
  }
  std::cout << std::endl;
}

int main() {
  const int size = 5;
  int sequence[size];

  // Inicialización manual
  manualInit(sequence, size);
  printSequence(sequence, size);

  // Inicialización aleatoria
  randomInit(sequence, size);
  printSequence(sequence, size);

  // Inicialización desde archivo
  fileInit(sequence, size, "datos.txt");
  printSequence(sequence, size);

  return 0;
}
