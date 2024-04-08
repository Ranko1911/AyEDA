#include <iostream>

template <typename T>
void swap(T &a, T &b) {
  T temp = a;
  a = b;
  b = temp;
}

template <typename T>
void baja(int i, T sec[], int n) {
  while (2 * i <= n) {
    int h1 = 2 * i;
    int h2 = h1 + 1;
    int h;
    if (h2 <= n && sec[h2] > sec[h1])
      h = h2;
    else
      h = h1;
    if (sec[h] <= sec[i])
      break;
    else {
      swap(sec[i], sec[h]);
      i = h;
    }
  }
}

template <typename T>
void heapsort(T sec[], int n) {
  for (int i = n / 2; i >= 1; i--) baja(i, sec, n);
  for (int i = n; i > 1; i--) {
    swap(sec[1], sec[i]);
    baja(1, sec, i - 1);
  }
}

int main() {
  int sec[] = {64, 25, 12, 22, 11};  // No hay elemento ficticio
  int n = sizeof(sec) / sizeof(sec[0]);
  heapsort(sec - 1, n);  // Aplicamos un offset de -1 al puntero del arreglo
  std::cout << "Arreglo ordenado usando Heapsort: \n";
  for (int i = 0; i < n; i++) std::cout << sec[i] << " ";
  std::cout << std::endl;
  return 0;
}
