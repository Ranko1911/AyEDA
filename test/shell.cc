#include <iostream>
#include "../include/sequence.h"

template<typename T>
void deltasort(int delta, staticSequence<T>& sec, int n) {
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

template<typename T>
void shellsort(staticSequence<T>& sec, int n) {
    int delta = n;
    while (delta > 1) {
        delta = delta / 2;
        deltasort(delta, sec, n);
    }
}

int main() {
    staticSequence<int> sec(5); // Creamos una staticSequence con capacidad para 5 elementos
    sec.Insert(64);
    sec.Insert(25);
    sec.Insert(12);
    sec.Insert(22);
    sec.Insert(11);

    int n = 5;
    std::cout << "Arreglo original:\n";
    for (int i = 0; i < n; i++)
        std::cout << sec[i] << " ";
    std::cout << std::endl;
    

    shellsort(sec, n);

    std::cout << "Arreglo ordenado usando Shellsort: \n";
    for (int i = 0; i < n; i++)
        std::cout << sec[i] << " ";
    std::cout << std::endl;

    return 0;
}
