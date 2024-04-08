#include <iostream>

template<typename T>
void selectionSort(T sec[], int n) {
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
  int sec[] = {64, 25, 12, 22, 11};
  int n = sizeof(sec) / sizeof(sec[0]);
  for (int i = 0; i < n; i++) std::cout << sec[i] << " ";
  selectionSort(sec, n);
  std::cout << "Arreglo ordenado usando Selection Sort: \n";
  for (int i = 0; i < n; i++) std::cout << sec[i] << " ";
  std::cout << std::endl;
  return 0;
}
