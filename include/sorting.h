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
  virtual void sort(T arr[], int size, bool printflag) = 0;
};

template <typename T>
class HeapSort : public SortingAlgorithm<T> {
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

  void sort(T sec[], int n, bool printFlag) {
    sec--;
    for (int i = n / 2; i >= 1; i--) {
      baja(i, sec, n);
      if (printFlag) {
        std::cout << "Array after iteration " << n / 2 - i + 1 << ": ";
        printArray(sec + 1, n);
      }
    }
    for (int i = n; i > 1; i--) {
      swap(sec[1], sec[i]);
      baja(1, sec, i - 1);
      if (printFlag) {
        std::cout << "Array after iteration " << n + n - i + 1 << ": ";
        printArray(sec + 1, n);
      }
    }
  }

 private:
  void printArray(T arr[], int size) {
    for (int i = 0; i < size; ++i) {
      std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
  }
};

template <typename T>
class QuickSort : public SortingAlgorithm<T> {
 public:
  void swap(Sequence<T> &sec, int idx1, int idx2) {
    T temp = sec[idx1];
    sec[idx1] = sec[idx2];
    sec[idx2] = temp;
  }

  void Qsort(Sequence<T> &sec, int ini, int fin, bool printFlag) {
    int i = ini, f = fin;
    T p = sec[(i + f) / 2];
    while (i <= f) {
      while (sec[i] < p) i++;
      while (sec[f] > p) f--;
      if (i <= f) {
        swap(sec, i, f);  // Pasamos los índices de los elementos
        i++;
        f--;
      }
    }
    // imprimir segun la flag
    if (printFlag) {
      std::cout << "Array after iteration " << n + n - i + 1 << ": ";
      printArray(sec + 1, n);
    }
    if (ini < f) Qsort(sec, ini, f);
    if (i < fin) Qsort(sec, i, fin);
  }

  void sort(T sec[], int n, bool printFlag) { Qsort(sec, 0, n - 1, printFlag); }

 private:
  void printArray(T arr[], int size) {
    for (int i = 0; i < size; ++i) {
      std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
  }
};

template <typename T>
class RadixSort : public SortingAlgorithm<T> {
 public:
  void sort(staticSequence<T> &sec, int size, bool printFlag) {
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

      for (int i = 0; i < size; i++) conteo[(sec[i] / exp) % 10]++;

      for (int i = 1; i < 10; i++) conteo[i] += conteo[i - 1];

      for (int i = size - 1; i >= 0; i--) {
        resultado[conteo[(sec[i] / exp) % 10] - 1] = sec[i];
        conteo[(sec[i] / exp) % 10]--;
      }

      if (printFlag) {
        std::cout << "Array after iteration " << n + n - i + 1 << ": ";
        printArray(sec + 1, n);
      }

      for (int i = 0; i < size; i++) sec[i] = resultado[i];
    }
  }

  int obtenerDigito(T numero, int posicion) {
    while (posicion--) numero /= 10;
    return numero % 10;
  }

 private:
  void printArray(T arr[], int size) {
    for (int i = 0; i < size; ++i) {
      std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
  }
};

template <typename T>
class SelectionSort : public SortingAlgorithm<T> {
 public:
  void sort(staticSequence<T> &sec, int n, bool printFlag) {
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
      if(printFlag){
        std::cout << "Array after iteration " << n + n - i + 1 << ": ";
        printArray(sec + 1, n);
      }
    }
  }

 private:
  void printArray(T arr[], int size) {
    for (int i = 0; i < size; ++i) {
      std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
  }
};

template <typename T>
class ShellSort : public SortingAlgorithm<T> {
 public:
  void deltasort(int delta, staticSequence<T> &sec, int n, bool printFlag) {
    for (int i = delta; i < n; i++) {
      T x = sec[i];
      int j = i;
      while (j >= delta && x < sec[j - delta]) {
        sec[j] = sec[j - delta];
        j = j - delta;
      }
      sec[j] = x;
      if(printFlag){
        std::cout << "Array after iteration " << n + n - i + 1 << ": ";
        printArray(sec + 1, n);
      }
    }
  }

  void sort(staticSequence<T> &sec, int n) {
    int delta = n;
    while (delta > 1) {
      delta = delta / 2;
      deltasort(delta, sec, n);
    }
  }

 private:
  void printArray(T arr[], int size) {
    for (int i = 0; i < size; ++i) {
      std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
  }
};