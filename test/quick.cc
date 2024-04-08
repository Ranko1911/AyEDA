#include <iostream>

template<typename T>
void swap(T &a, T &b) {
  T temp = a;
  a = b;
  b = temp;
}

template<typename T>
void Qsort(T sec[], int ini, int fin) {
  int i = ini, f = fin;
  T p = sec[(i + f) / 2];
  while (i <= f) {
    while (sec[i] < p) i++;
    while (sec[f] > p) f--;
    if (i <= f) {
      swap(sec[i], sec[f]);
      i++;
      f--;
    }
  }
  if (ini < f) Qsort(sec, ini, f);
  if (i < fin) Qsort(sec, i, fin);
}

int main() {
  int sec[] = {64, 25, 12, 22, 11};
  int n = sizeof(sec) / sizeof(sec[0]);
  for (int i = 0; i < n; i++) std::cout << sec[i] << " ";
  std::cout << std::endl;
  Qsort(sec, 0, n - 1);
  std::cout << "Arreglo ordenado usando Quicksort: \n";
  for (int i = 0; i < n; i++) std::cout << sec[i] << " ";
  std::cout << std::endl;
  return 0;
}
