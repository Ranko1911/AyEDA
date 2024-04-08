#include <iostream>
#include "../include/sequence.h"

template<typename T>
void selectionSort(staticSequence<T>& sec, int n) {
  int min;
  T x;
  for (int i = 0; i < n - 1; i++) {
    min = i;
    for (int j = i + 1; j < n; j++) {
      if (sec[j] < sec[min]) min = j;
    }
    // Intercambio de elementos
    x = sec[min];
    sec[min] = sec[i];
    sec[i] = x;
  }
}

int main() {
  staticSequence<int> sec(5); // Creamos una staticSequence con capacidad para 5 elementos
  sec.Insert(64);
  sec.Insert(25);
  sec.Insert(12);
  sec.Insert(22);
  sec.Insert(11);

  int n = 5;
  std::cout << "Arreglo original:\n";
  for (int i = 0; i < n; i++) std::cout << sec[i] << " ";
  std::cout << std::endl;

  selectionSort(sec, n);

  std::cout << "Arreglo ordenado usando Selection Sort: \n";
  for (int i = 0; i < n; i++) std::cout << sec[i] << " ";
  std::cout << std::endl;

  return 0;
}