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
  virtual void sort(T arr[], int size) = 0;
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

  void sort(T sec[], int n) {
    sec--;
    for (int i = n / 2; i >= 1; i--) baja(i, sec, n);
    for (int i = n; i > 1; i--) {
      swap(sec[1], sec[i]);
      baja(1, sec, i - 1);
    }
  }
};

template <typename T>
class QuickSort : public SortingAlgorithm<T> {
 public:
  void swap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
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

  void sort(T sec[], int n) override { Qsort(sec, 0, n - 1); }
};
template <typename T>
class RadixSort : public SortingAlgorithm<T> {
 public:
  void sort(T sec[], int n) override {
    T max = getMax(sec, n);
    for (T exp = 1; max != 0; exp *= 10) {
      countSort(sec, n, exp);
      max /= 10;
    }
  }

 private:
  T getMax(T arr[], int n) {
    T mx = abs(arr[0]);
    for (int i = 1; i < n; i++) {
      if (abs(arr[i]) > mx) {
        mx = abs(arr[i]);
      }
    }
    return mx;
  }

  void countSort(T arr[], int n, int exp) {
    T output[n];
    int i, count[19] = {0};  // 19 para manejar valores negativos también

    for (i = 0; i < n; i++) {
      count[(arr[i] / exp) % 10 + 9]++;  // Ajuste para valores negativos
    }

    for (i = 1; i < 19; i++) {  // 19 para manejar valores negativos también
      count[i] += count[i - 1];
    }

    for (i = n - 1; i >= 0; i--) {
      output[count[(arr[i] / exp) % 10 + 9] - 1] =
          arr[i];  // Ajuste para valores negativos
      count[(arr[i] / exp) % 10 + 9]--;
    }

    for (i = 0; i < n; i++) {
      arr[i] = output[i];
    }
  }
};

template <typename T>
class SelectionSort : public SortingAlgorithm<T> {
 public:
  void sort(T arr[], int n) override {
    for (int i = 0; i < n - 1; i++) {
      int min = i;
      for (int j = i + 1; j < n; j++) {
        if (arr[j] < arr[min]) min = j;
      }
      if (min != i) {
        T temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
      }
    }
  }
};

template <typename T>
class ShellSort : public SortingAlgorithm<T> {
 public:
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

  void sort(T sec[], int n) {
    int delta = n;
    while (delta > 1) {
      delta = delta / 2;
      deltasort(delta, sec, n);
    }
  }
};
