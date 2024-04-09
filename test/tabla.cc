#include "../include/sequence.h"
#include "../include/sorting.h"

int main() {

  int heap_iteraciones = 0;
  int quick_iteraciones = 0;
  int radix_iteraciones = 0;
  int seleccion_iteraciones = 0;
  int shell_iteraciones = 0;

  int heap_comparaciones = 0;
  int quick_comparaciones = 0;
  int radix_comparaciones = 0;
  int seleccion_comparaciones = 0;
  int shell_comparaciones = 0;


  std::cout << "Tabla Comparativa de Metodos de Ordenamcion\n";
  std::cout << "Metodo          || Comparaciones || Iteraciones\n";
  std::cout << "HeapSort        || " << heap_comparaciones << "             || " << heap_iteraciones << "\n";
  std::cout << "QuickSort       || " << quick_comparaciones << "             || " << quick_iteraciones << "\n";
  std::cout << "RadixSort       || " << radix_comparaciones << "             || " << radix_iteraciones << "\n";
  std::cout << "SelectionSort   || " << seleccion_comparaciones << "             || " << seleccion_iteraciones << "\n";
  std::cout << "ShellSort       || " << shell_comparaciones << "             || " << shell_iteraciones << "\n";

}