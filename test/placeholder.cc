#include <iostream>
#include "../include/sequence.h"

template <typename T>
class SortingAlgorithm {
public:
    virtual void sort(staticSequence<T> &arr, int size, bool printflag) = 0;
};

template <typename T>
class HeapSort : public SortingAlgorithm<T> {
public:
    void baja(int i, staticSequence<T> &seq, int n) {
        while (2 * i <= n) {
            int h1 = 2 * i;
            int h2 = h1 + 1;
            int h;
            if (h2 <= n && seq[h2 - 1] > seq[h1 - 1]) // Corregir los índices
                h = h2;
            else
                h = h1;
            if (seq[h - 1] <= seq[i - 1]) // Corregir los índices
                break;
            else {
                std::swap(seq[i - 1], seq[h - 1]); // Corregir los índices
                i = h;
            }
        }
    }

    void sort(staticSequence<T> &seq, int n, bool printflag) {
        for (int i = n / 2; i >= 1; i--) {
            baja(i, seq, n);
            if (printflag) {
                for (int j = 0; j < n; j++) { // Corregir los índices
                    std::cout << seq[j] << " "; // Corregir los índices
                }
                std::cout << std::endl;
            }
        }
        for (int i = n; i > 1; i--) {
            std::swap(seq[0], seq[i - 1]); // Corregir los índices
            baja(1, seq, i - 1);
            if (printflag) {
                for (int j = 0; j < n; j++) { // Corregir los índices
                    std::cout << seq[j] << " "; // Corregir los índices
                }
                std::cout << std::endl;
            }
        }
    }
};

int main() {
    staticSequence<int> arr(5);
    arr.Insert(64);
    arr.Insert(25);
    arr.Insert(12);
    arr.Insert(22);
    arr.Insert(11); 
    HeapSort<int> sorter;
    sorter.sort(arr, 5, true);
    return 0;
}
