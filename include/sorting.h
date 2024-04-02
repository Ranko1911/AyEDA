#include <iostream>
#include <vector>
#include <algorithm>


template <typename T>
class SortingAlgorithm {
 public:
  void swap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
  }

  void baja(int i, T sec[], int n) {
    while (2 * i <= n) {
      int h1 = 2 * i;
      int h2 = h1 + 1;
      int h;
      if (h1 == n || sec[h1] > sec[h2])
        h = h1;
      else
        h = h2;
      if (sec[h] <= sec[i])
        break;
      else {
        swap(sec[i], sec[h]);
        i = h;
      }
    }
  }

  void heapsort(T sec[], int n) {
    for (int i = n / 2; i > 0; i--) baja(i, sec, n);
    for (int i = n; i > 1; i--) {
      swap(sec[1], sec[i]);
      baja(1, sec, i - 1);
    }
  }



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

  // Función auxiliar para obtener el dígito en una posición específica
  int obtenerDigito(T numero, int posicion) {
    while (posicion--) numero /= 10;
    return numero % 10;
  }

  // Función para ordenar el vector usando RadixSort
  void radixSort(std::vector<T> &sec) {
    // Encontrar el dígito máximo en el vector
    T max = *std::max_element(sec.begin(), sec.end());

    // Realizar el conteo de frecuencia para cada dígito
    for (T exp = 1; max / exp > 0; exp *= 10) {
      std::vector<int> conteo(10, 0);
      std::vector<T> resultado(sec.size());

      for (int i = 0; i < sec.size(); i++) conteo[(sec[i] / exp) % 10]++;

      for (int i = 1; i < 10; i++) conteo[i] += conteo[i - 1];

      for (int i = sec.size() - 1; i >= 0; i--) {
        resultado[conteo[(sec[i] / exp) % 10] - 1] = sec[i];
        conteo[(sec[i] / exp) % 10]--;
      }

      for (int i = 0; i < sec.size(); i++) sec[i] = resultado[i];
    }
  }

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

  void deltasort(int delta, T sec[], int n) {
    for (int i = delta; i < n; i++) {
      T x = sec[i];
      int j = i;
      while (j >= delta && x < sec[j - delta]) {
        sec[j] = sec[j - delta];
        j = j - delta;
      }
      sec[j] = x;
    }
  }

  void shellsort(T sec[], int n) {
    int delta = n;
    while (delta > 1) {
      delta = delta / 2;
      deltasort(delta, sec, n);
    }
  }
};
