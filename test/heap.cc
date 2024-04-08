#include <iostream>
#include "../include/sequence.h" // Incluimos la definición de staticSequence

template <typename T>
void swap(T &a, T &b) {
  T temp = a;
  a = b;
  b = temp;
}

template <typename T>
void baja(int i, Sequence<T>& seq, int n) {
  while (2 * i <= n) {
    int h1 = 2 * i;
    int h2 = h1 + 1;
    int h;
    if (h2 <= n && seq[h2] > seq[h1]) // Modificamos el acceso a los elementos
      h = h2;
    else
      h = h1;
    if (seq[h] <= seq[i]) // Modificamos el acceso a los elementos
      break;
    else {
      swap(seq[i], seq[h]); // Modificamos el acceso a los elementos
      i = h;
    }
  }
}

template <typename T>
void heapsort(Sequence<T>& seq, int n) {
  for (int i = n / 2; i >= 1; i--) baja(i, seq, n);
  for (int i = n; i > 1; i--) {
    swap(seq[1], seq[i]); // Modificamos el acceso a los elementos
    baja(1, seq, i - 1);
  }
}

int main() {
  staticSequence<int> seq(6); // Creamos una instancia de staticSequence
  seq.Insert(0); // Agregamos un elemento ficticio para evitar el acceso a sec[-1]
  seq.Insert(64);
  seq.Insert(25);
  seq.Insert(12);
  seq.Insert(22);
  seq.Insert(11);

  int n = 6; // Utilizamos un método para obtener el tamaño
  std::cout << "Arreglo original:\n";
  for (int i = 1; i < n; i++) std::cout << seq[i] << " "; // Empezamos desde 1
  std::cout << std::endl;
  heapsort(seq, n - 1); // Aplicamos un offset de -1 al tamaño
  std::cout << "Arreglo ordenado usando Heapsort: \n";
  for (int i = 1; i < n; i++) std::cout << seq[i] << " "; // Empezamos desde 1
  std::cout << std::endl;
  return 0;
}
