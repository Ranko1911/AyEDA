#include <algorithm>
#include <iostream>
#include <vector>

#include "sequence.h"

template <typename T>
class SortingAlgorithm {
 private:
  void swap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
  }

  staticSequence<T> *sequence_;

 public:
  virtual void sort(staticSequence<T> &arr, int size, bool printflag) = 0;
};

template <typename T>
class HeapSort : public SortingAlgorithm<T> {
 private:
  int comparisons;  // Contador de comparaciones
  int iterations;   // Contador de iteraciones

 public:
  HeapSort() : comparisons(0), iterations(0) {}

  void baja(int i, staticSequence<T> &seq, int n) {
    while (2 * i <= n) {
      iterations++;  // Aumenta el contador de iteraciones
      int h1 = 2 * i;
      int h2 = h1 + 1;
      int h;
      if (h2 <= n && seq[h2 - 1] > seq[h1 - 1]) {
        comparisons++;  // Aumenta el contador de comparaciones
        h = h2;
      } else {
        h = h1;
      }
      if (seq[h - 1] <= seq[i - 1]) {
        comparisons++;  // Aumenta el contador de comparaciones
        break;
      } else {
        std::swap(seq[i - 1], seq[h - 1]);
        i = h;
      }
    }
  }

  void sort(staticSequence<T> &seq, int n, bool printflag) {
    comparisons = 0;  // Reinicia el contador de comparaciones
    iterations = 0;   // Reinicia el contador de iteraciones

    for (int i = n / 2; i >= 1; i--) {
      baja(i, seq, n);
      if (printflag) {
        for (int j = 0; j < n; j++) {
          std::cout << seq[j] << " ";
        }
        std::cout << std::endl;
      }
    }
    for (int i = n; i > 1; i--) {
      std::swap(seq[0], seq[i - 1]);
      baja(1, seq, i - 1);
      if (printflag) {
        for (int j = 0; j < n; j++) {
          std::cout << seq[j] << " ";
        }
        std::cout << std::endl;
      }
    }

    std::cout << "Comparaciones: " << comparisons << std::endl;
    std::cout << "Iteraciones: " << iterations << std::endl;
  }
};

template <typename T>
class QuickSort : public SortingAlgorithm<T> {
 private:
  int comparisons;  // Contador de comparaciones
  int iterations;   // Contador de iteraciones

 public:
  QuickSort() : comparisons(0), iterations(0) {}

  void swap(staticSequence<T> &sec, int idx1, int idx2) {
    T temp = sec[idx1];
    sec[idx1] = sec[idx2];
    sec[idx2] = temp;
  }

  void Qsort(staticSequence<T> &sec, int ini, int fin, bool printFlag) {
    int i = ini, f = fin;
    int n = fin - ini + 1;
    T p = sec[(i + f) / 2];
    while (i <= f) {
      iterations++;  // Aumenta el contador de iteraciones
      while (sec[i] < p) {
        comparisons++;  // Aumenta el contador de comparaciones
        i++;
      }
      while (sec[f] > p) {
        comparisons++;  // Aumenta el contador de comparaciones
        f--;
      }
      if (i <= f) {
        swap(sec, i, f);
        i++;
        f--;
      }
      if (printFlag) {
        for (int i = 0; i < n; i++) {
          std::cout << sec[i] << " ";
        }
        std::cout << std::endl;
      }
    }
    if (ini < f) Qsort(sec, ini, f, printFlag);
    if (i < fin) Qsort(sec, i, fin, printFlag);
  }

  void sort(staticSequence<T> &sec, int n, bool printflag) override {
    comparisons = 0;  // Reinicia el contador de comparaciones
    iterations = 0;   // Reinicia el contador de iteraciones

    Qsort(sec, 0, n - 1, printflag);

    std::cout << "Comparaciones: " << comparisons << std::endl;
    std::cout << "Iteraciones: " << iterations << std::endl;
  }
};

template <typename T>
class RadixSort : public SortingAlgorithm<T> {
 private:
  int comparisons;  // Contador de comparaciones
  int iterations;   // Contador de iteraciones

 public:
  RadixSort() : comparisons(0), iterations(0) {}

  int obtenerDigito(T numero, int posicion) {
    while (posicion--) numero /= 10;
    return numero % 10;
  }

  void sort(staticSequence<T> &sec, int size, bool printFlag) override {
    comparisons = 0;  // Reinicia el contador de comparaciones
    iterations = 0;   // Reinicia el contador de iteraciones

    // Encontrar el dígito máximo en la secuencia
    T max = sec[0];
    for (int i = 1; i < size; i++) {
      if (sec[i] > max) {
        max = sec[i];
      }
    }

    // Crear un arreglo para el conteo de frecuencia
    staticSequence<int> conteo(10);  // Los dígitos van de 0 a 9

    // Crear un arreglo para el resultado ordenado
    staticSequence<T> resultado(size);

    // Realizar el conteo de frecuencia para cada dígito
    for (T exp = 1; max / exp > 0; exp *= 10) {
      conteo = staticSequence<int>(
          10);  // Reiniciamos el arreglo de conteo en cada iteración

      for (int i = 0; i < size; i++) {
        iterations++;  // Aumenta el contador de iteraciones
        conteo[(sec[i] / exp) % 10]++;
      }

      for (int i = 1; i < 10; i++) {
        conteo[i] += conteo[i - 1];
      }

      for (int i = size - 1; i >= 0; i--) {
        resultado[conteo[(sec[i] / exp) % 10] - 1] = sec[i];
        conteo[(sec[i] / exp) % 10]--;
      }

      if (printFlag) {
        std::cout << "Estado del arreglo en la iteración " << exp
                  << " del RadixSort:\n";
        for (int i = 0; i < size; i++) std::cout << resultado[i] << " ";
        std::cout << std::endl;
      }

      for (int i = 0; i < size; i++) {
        comparisons++;  // Aumenta el contador de comparaciones
        sec[i] = resultado[i];
      }
    }

    std::cout << "Comparaciones: " << comparisons << std::endl;
    std::cout << "Iteraciones: " << iterations << std::endl;
  }
};

template <typename T>
class SelectionSort : public SortingAlgorithm<T> {
 private:
  int comparisons;  // Contador de comparaciones
  int iterations;   // Contador de iteraciones

 public:
  SelectionSort() : comparisons(0), iterations(0) {}

  void sort(staticSequence<T> &sec, int n, bool printFlag) override {
    comparisons = 0;  // Reinicia el contador de comparaciones
    iterations = 0;   // Reinicia el contador de iteraciones

    int min;
    T x;
    for (int i = 0; i < n - 1; i++) {
      min = i;
      for (int j = i + 1; j < n; j++) {
        iterations++;  // Aumenta el contador de iteraciones
        if (sec[j] < sec[min]) {
          comparisons++;  // Aumenta el contador de comparaciones
          min = j;
        }
      }
      // Intercambio de elementos
      x = sec[min];
      sec[min] = sec[i];
      sec[i] = x;
      if (printFlag) {
        for (int i = 0; i < n; i++) std::cout << sec[i] << " ";
        std::cout << std::endl;
      }
    }

    std::cout << "Comparaciones: " << comparisons << std::endl;
    std::cout << "Iteraciones: " << iterations << std::endl;
  }
};

template <typename T>
class ShellSort : public SortingAlgorithm<T> {
 private:
  int comparisons;  // Contador de comparaciones
  int iterations;   // Contador de iteraciones

 public:
  ShellSort() : comparisons(0), iterations(0) {}

  void deltasort(int delta, staticSequence<T> &sec, int n, bool printFlag) {
    for (int i = delta; i < n; i++) {
      T x = sec[i];
      int j = i;
      while (j >= delta && x < sec[j - delta]) {
        comparisons++;  // Aumenta el contador de comparaciones
        sec[j] = sec[j - delta];
        j = j - delta;
        iterations++;  // Aumenta el contador de iteraciones
      }
      sec[j] = x;
      if (printFlag) {
        for (int i = 0; i < n; i++) std::cout << sec[i] << " ";
        std::cout << std::endl;
      }
    }
  }

  void sort(staticSequence<T> &sec, int n, bool printFlag) {
    comparisons = 0;  // Reinicia el contador de comparaciones
    iterations = 0;   // Reinicia el contador de iteraciones

    int delta = n;
    while (delta > 1) {
      delta = delta / 2;
      deltasort(delta, sec, n, printFlag);
    }

    std::cout << "Comparaciones: " << comparisons << std::endl;
    std::cout << "Iteraciones: " << iterations << std::endl;
  }
};