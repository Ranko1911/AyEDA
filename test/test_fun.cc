#include <iostream>
#include "../include/sorting.h"
#include "../include/sequence.h"

void arreglooriginal(int sec[], int n) {
  std::cout << "Arreglo original: \n";
  for (int i = 0; i < n; i++) std::cout << sec[i] << " ";
  std::cout << std::endl;
}

int main() {
  int sec[] = {64, 25, 12, 22, 11}; // No se usa ningún elemento ficticio
  int n = sizeof(sec) / sizeof(sec[0]);
  bool printFlag = false;

  std::cout << "tamano de la secuencia: " << n << "\n";

  // Prueba de HeapSort
  HeapSort<int> heap_sort;
  //arreglooriginal(sec, n);
  heap_sort.sort(sec, n, printFlag);
  std::cout << "Arreglo ordenado usando HeapSort: \n";
  for (int i = 0; i < n; i++) std::cout << sec[i] << " ";
  std::cout << std::endl;

  int sec2[] = {64, 25, 12, 22, 11}; // No se usa ningún elemento ficticio
  n = sizeof(sec2) / sizeof(sec2[0]);

  // Prueba de QuickSort
  QuickSort<int> quick_sort;
  //arreglooriginal(sec2, n);
  quick_sort.sort(sec2, n, printFlag);
  std::cout << "Arreglo ordenado usando QuickSort: \n";
  for (int i = 0; i < n; i++) std::cout << sec2[i] << " ";
  std::cout << std::endl;

  int sec3[] = {64, 25, 12, 22, 11}; // No se usa ningún elemento ficticio
  n = sizeof(sec3) / sizeof(sec3[0]);

  // Prueba de RadixSort
  RadixSort<int> radix_sort;
  //arreglooriginal(sec3, n);
  radix_sort.sort(sec3, n, printFlag);
  std::cout << "Arreglo ordenado usando RadixSort: \n";
  for (int i = 0; i < n; i++) std::cout << sec3[i] << " ";
  std::cout << std::endl;

  int sec4[] = {64, 25, 12, 22, 11}; // No se usa ningún elemento ficticio
  n = sizeof(sec4) / sizeof(sec4[0]);

  // Prueba de SelectionSort
  SelectionSort<int> selection_sort;
  //arreglooriginal(sec4, n);
  selection_sort.sort(sec4, n, printFlag);
  std::cout << "Arreglo ordenado usando SelectionSort: \n";
  for (int i = 0; i < n; i++) std::cout << sec4[i] << " ";
  std::cout << std::endl;

  int sec5[] = {64, 25, 12, 22, 11}; // No se usa ningún elemento ficticio
  n = sizeof(sec5) / sizeof(sec5[0]);

  // Prueba de ShellSort
  ShellSort<int> shell_sort;
  //arreglooriginal(sec5, n);
  shell_sort.sort(sec5, n, printFlag);
  std::cout << "Arreglo ordenado usando ShellSort: \n";
  for (int i = 0; i < n; i++) std::cout << sec5[i] << " ";
  std::cout << std::endl;

  return 0;
}