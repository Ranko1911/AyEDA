#include <iostream>
#include "../include/sorting.h"
#include "../include/sequence.h"

int main() {
  
  // prueba de HeapSort 
  staticSequence<int> sec(5); // Creamos una staticSequence con capacidad para 5 elementos
  sec.Insert(64);
  sec.Insert(25);
  sec.Insert(12);
  sec.Insert(22);
  sec.Insert(11);

  int n = 5;
  std::cout << "Arreglo original:\n";
  for (int i = 0; i < n; i++) std::cout << sec[i] << " ";
  std::cout << std::endl;

  HeapSort<int> heapSort;
  std::cout << "Arreglando usando HeapSort: \n";
  heapSort.sort(sec, n, true);

  std::cout << "Arreglo ordenado usando HeapSort: \n";
  for (int i = 0; i < n; i++) std::cout << sec[i] << " ";
  std::cout << std::endl;

  // ---------------------------------------------------------- //

  // prueba de QuickSort
  staticSequence<int> sec2(5); // Creamos una staticSequence con capacidad para 5 elementos
  sec2.Insert(64);
  sec2.Insert(25);
  sec2.Insert(12);
  sec2.Insert(22);
  sec2.Insert(11);

  int n2 = 5;
  std::cout << "Arreglo original:\n";
  for (int i = 0; i < n2; i++) std::cout << sec2[i] << " ";
  std::cout << std::endl;

  QuickSort<int> quickSort;
  std::cout << "Arreglando usando QuickSort: \n";
  quickSort.sort(sec2, n2, true);

  std::cout << "Arreglo ordenado usando QuickSort: \n";
  for (int i = 0; i < n2; i++) std::cout << sec2[i] << " ";
  std::cout << std::endl;

  // ---------------------------------------------------------- //

  // prueba de RadixSort
  staticSequence<int> sec3(5); // Creamos una staticSequence con capacidad para 5 elementos
  sec3.Insert(64);
  sec3.Insert(25);
  sec3.Insert(12);
  sec3.Insert(22);
  sec3.Insert(11);

  int n3 = 5;
  std::cout << "Arreglo original:\n";
  for (int i = 0; i < n3; i++) std::cout << sec3[i] << " ";
  std::cout << std::endl;

  RadixSort<int> radixSort;
  std::cout << "Arreglando usando RadixSort: \n";
  radixSort.sort(sec3, n3, true);

  std::cout << "Arreglo ordenado usando RadixSort: \n";
  for (int i = 0; i < n3; i++) std::cout << sec3[i] << " ";
  std::cout << std::endl;

  // ---------------------------------------------------------- //

  // prueba de SelectionSort
  staticSequence<int> sec4(5); // Creamos una staticSequence con capacidad para 5 elementos
  
  sec4.Insert(64);
  sec4.Insert(25);
  sec4.Insert(12);
  sec4.Insert(22);
  sec4.Insert(11);

  int n4 = 5;
  std::cout << "Arreglo original:\n";
  for (int i = 0; i < n4; i++) std::cout << sec4[i] << " ";
  std::cout << std::endl;

  SelectionSort<int> selectionSort;
  std::cout << "Arreglando usando SelectionSort: \n";
  selectionSort.sort(sec4, n4, true);

  std::cout << "Arreglo ordenado usando SelectionSort: \n";
  for (int i = 0; i < n4; i++) std::cout << sec4[i] << " ";
  std::cout << std::endl;

  // ---------------------------------------------------------- //

  // prueba de ShellSort
  staticSequence<int> sec5(5); // Creamos una staticSequence con capacidad para 5 elementos
  sec5.Insert(64);
  sec5.Insert(25);
  sec5.Insert(12);
  sec5.Insert(22);
  sec5.Insert(11);

  int n5 = 5;
  std::cout << "Arreglo original:\n";
  for (int i = 0; i < n5; i++) std::cout << sec5[i] << " ";
  std::cout << std::endl;

  ShellSort<int> shellSort;
  std::cout << "Arreglando usando ShellSort: \n";
  shellSort.sort(sec5, n5, true);

  std::cout << "Arreglo ordenado usando ShellSort: \n";
  for (int i = 0; i < n5; i++) std::cout << sec5[i] << " ";
  std::cout << std::endl;

  return 0;
  
}