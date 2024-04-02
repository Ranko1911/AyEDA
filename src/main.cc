#include <iostream>
#include "../include/sorting.h"

int main() {
    int sec[] = {-1, 64, 25, 12, 22, 11}; // Se usa -1 como un elemento ficticio en la posición 0
    int n = sizeof(sec) / sizeof(sec[0]) - 1; // Ignoramos el elemento ficticio

    SortingAlgorithm<int> sorting_algorithm;
    sorting_algorithm.heapsort(sec, n);

    std::cout << "Arreglo ordenado usando Heapsort: \n";
    for (int i = 1; i <= n; i++)
        std::cout << sec[i] << " ";
    std::cout << std::endl;

    return 0;
}
