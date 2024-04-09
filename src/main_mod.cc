#include <iostream>
#include "../include/sorting.h"
#include "../include/sequence.h"

void randomInit(staticSequence<int>& sequence, int size) {
  srand(time(nullptr));  // Initialize random seed
  for (int i = 0; i < size; i++) {
    sequence.Insert(rand() % 100);
  }
}

int main() {
  
  int size = 1000;
  int compar = 0;
  int interar = 0;
  // prueba de HeapSort 
  staticSequence<int> sec(size); // Creamos una staticSequence con capacidad para 10 elementos
  
  randomInit(sec, size);

  int n = size;
  // std::cout << "Arreglo original:\n";
  // for (int i = 0; i < n; i++) std::cout << sec[i] << " ";
  // std::cout << std::endl;

  HeapSort<int> heapSort;
  std::cout << "Arreglando usando HeapSort: \n";
  heapSort.sort(sec, n, false);

  // std::cout << "Arreglo ordenado usando HeapSort: \n";
  // for (int i = 0; i < n; i++) std::cout << sec[i] << " ";
  // std::cout << std::endl;

  // ---------------------------------------------------------- //

  // prueba de QuickSort
  staticSequence<int> sec2(size); // Creamos una staticSequence con capacidad para 5 elementos
  randomInit(sec2, size);

  int n2 = size;
  // std::cout << "Arreglo original:\n";
  // for (int i = 0; i < n2; i++) std::cout << sec2[i] << " ";
  // std::cout << std::endl;

  QuickSort<int> quickSort;
  std::cout << "Arreglando usando QuickSort: \n";
  quickSort.sort(sec2, n2, false);

  // std::cout << "Arreglo ordenado usando QuickSort: \n";
  // for (int i = 0; i < n2; i++) std::cout << sec2[i] << " ";
  // std::cout << std::endl;

  // ---------------------------------------------------------- //

  // prueba de RadixSort
  staticSequence<int> sec3(size); // Creamos una staticSequence con capacidad para 5 elementos
  randomInit(sec3, size);

  int n3 = size;
  // std::cout << "Arreglo original:\n";
  // for (int i = 0; i < n3; i++) std::cout << sec3[i] << " ";
  // std::cout << std::endl;

  RadixSort<int> radixSort;
  std::cout << "Arreglando usando RadixSort: \n";
  radixSort.sort(sec3, n3, false);

  // std::cout << "Arreglo ordenado usando RadixSort: \n";
  // for (int i = 0; i < n3; i++) std::cout << sec3[i] << " ";
  // std::cout << std::endl;

  // ---------------------------------------------------------- //

  // prueba de SelectionSort
  staticSequence<int> sec4(size); // Creamos una staticSequence con capacidad para 5 elementos
  randomInit(sec4, size);

  int n4 = size;
  // std::cout << "Arreglo original:\n";
  // for (int i = 0; i < n4; i++) std::cout << sec4[i] << " ";
  // std::cout << std::endl;

  SelectionSort<int> selectionSort;
  std::cout << "Arreglando usando SelectionSort: \n";
  selectionSort.sort(sec4, n4, false);

  // std::cout << "Arreglo ordenado usando SelectionSort: \n";
  // for (int i = 0; i < n4; i++) std::cout << sec4[i] << " ";
  // std::cout << std::endl;

  // ---------------------------------------------------------- //

  // prueba de ShellSort
  staticSequence<int> sec5(size); // Creamos una staticSequence con capacidad para 5 elementos
  randomInit(sec5, size);

  int n5 = size;
  // std::cout << "Arreglo original:\n";
  // for (int i = 0; i < n5; i++) std::cout << sec5[i] << " ";
  // std::cout << std::endl;

  ShellSort<int> shellSort;
  std::cout << "Arreglando usando ShellSort: \n";
  shellSort.sort(sec5, n5, false);

  // std::cout << "Arreglo ordenado usando ShellSort: \n";
  // for (int i = 0; i < n5; i++) std::cout << sec5[i] << " ";
  // std::cout << std::endl;

  return 0;
  
}