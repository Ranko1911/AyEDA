#include <iostream>
#include "../include/sorting.h"

int main() {
  int sec[] = {-1, 64, 25, 12, 22, 11}; // Se usa -1 como un elemento ficticio en la posición 0
  int n = sizeof(sec) / sizeof(sec[0]) - 1; // Ignoramos el elemento ficticio

  // Prueba de HeapSort
  HeapSort<int> heap_sort;
  heap_sort.sort(sec, n);
  std::cout << "Arreglo ordenado usando HeapSort: \n";
  for (int i = 1; i <= n; i++) std::cout << sec[i] << " ";
  std::cout << std::endl;

  // Prueba de QuickSort
  QuickSort<int> quick_sort;
  quick_sort.sort(sec, n);
  std::cout << "Arreglo ordenado usando QuickSort: \n";
  for (int i = 0; i < n; i++) std::cout << sec[i] << " ";
  std::cout << std::endl;

  // Prueba de RadixSort
  RadixSort<int> radix_sort;
  radix_sort.sort(sec, n);
  std::cout << "Arreglo ordenado usando RadixSort: \n";
  for (int i = 0; i < n; i++) std::cout << sec[i] << " ";
  std::cout << std::endl;

  // Prueba de SelectionSort
  SelectionSort<int> selection_sort;
  selection_sort.sort(sec, n);
  std::cout << "Arreglo ordenado usando SelectionSort: \n";
  for (int i = 0; i < n; i++) std::cout << sec[i] << " ";
  std::cout << std::endl;

  // Prueba de ShellSort
  ShellSort<int> shell_sort;
  shell_sort.sort(sec, n);
  std::cout << "Arreglo ordenado usando ShellSort: \n";
  for (int i = 0; i < n; i++) std::cout << sec[i] << " ";
  std::cout << std::endl;

  return 0;
}