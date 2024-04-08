#include <iostream>
#include "../include/sorting.h"
#include "../include/sequence.h"

int main() {
  int sec[] = {64, 25, 12, 22, 11}; // No se usa ningún elemento ficticio
  int n = sizeof(sec) / sizeof(sec[0]);

  std::cout << "tamano de la secuencia: " << n << "\n";

  // Prueba de HeapSort
  HeapSort<int> heap_sort;
  heap_sort.sort(sec, n);
  std::cout << "Arreglo ordenado usando HeapSort: \n";
  for (int i = 0; i < n; i++) std::cout << sec[i] << " ";
  std::cout << std::endl;

  int sec2[] = {64, 25, 12, 22, 11}; // No se usa ningún elemento ficticio
  n = sizeof(sec2) / sizeof(sec2[0]);

  // Prueba de QuickSort
  QuickSort<int> quick_sort;
  quick_sort.sort(sec2, n);
  std::cout << "Arreglo ordenado usando QuickSort: \n";
  for (int i = 0; i < n; i++) std::cout << sec2[i] << " ";
  std::cout << std::endl;

  int sec3[] = {64, 25, 12, 22, 11}; // No se usa ningún elemento ficticio
  n = sizeof(sec3) / sizeof(sec3[0]);

  // Prueba de RadixSort
  RadixSort<int> radix_sort;
  radix_sort.sort(sec3, n);
  std::cout << "Arreglo ordenado usando RadixSort: \n";
  for (int i = 0; i < n; i++) std::cout << sec3[i] << " ";
  std::cout << std::endl;

  int sec4[] = {64, 25, 12, 22, 11}; // No se usa ningún elemento ficticio
  n = sizeof(sec4) / sizeof(sec4[0]);

  // Prueba de SelectionSort
  SelectionSort<int> selection_sort;
  selection_sort.sort(sec4, n);
  std::cout << "Arreglo ordenado usando SelectionSort: \n";
  for (int i = 0; i < n; i++) std::cout << sec4[i] << " ";
  std::cout << std::endl;

  int sec5[] = {64, 25, 12, 22, 11}; // No se usa ningún elemento ficticio
  n = sizeof(sec5) / sizeof(sec5[0]);

  // Prueba de ShellSort
  ShellSort<int> shell_sort;
  shell_sort.sort(sec5, n);
  std::cout << "Arreglo ordenado usando ShellSort: \n";
  for (int i = 0; i < n; i++) std::cout << sec5[i] << " ";
  std::cout << std::endl;

  return 0;
}