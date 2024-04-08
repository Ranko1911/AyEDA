#include <iostream>
#include "../include/sequence.h"

template<typename T>
void swap(Sequence<T> &sec, int idx1, int idx2) {
  T temp = sec[idx1];
  sec[idx1] = sec[idx2];
  sec[idx2] = temp;
}

template<typename T>
void Qsort(Sequence<T> &sec, int ini, int fin) {
  int i = ini, f = fin;
  T p = sec[(i + f) / 2];
  while (i <= f) {
    while (sec[i] < p) i++;
    while (sec[f] > p) f--;
    if (i <= f) {
      swap(sec, i, f); // Pasamos los índices de los elementos
      i++;
      f--;
    }
  }
  if (ini < f) Qsort(sec, ini, f);
  if (i < fin) Qsort(sec, i, fin);
}

int main() {
  staticSequence<int> sec(5); // Creamos un objeto staticSequence
  sec.Insert(64);
  sec.Insert(25);
  sec.Insert(12);
  sec.Insert(22);
  sec.Insert(11);

  int n = 5;
  for (int i = 0; i < n; i++) std::cout << sec[i] << " ";
  std::cout << std::endl;

  Qsort(sec, 0, n - 1);

  std::cout << "Arreglo ordenado usando Quicksort: \n";
  for (int i = 0; i < n; i++) std::cout << sec[i] << " ";
  std::cout << std::endl;

  return 0;
}