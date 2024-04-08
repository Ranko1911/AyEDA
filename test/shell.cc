#include <iostream>

template<typename T>
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

template<typename T>
void shellsort(T sec[], int n) {
    int delta = n;
    while (delta > 1) {
        delta = delta / 2;
        deltasort(delta, sec, n);
    }
}

int main() {
    int sec[] = {64, 25, 12, 22, 11};
    int n = sizeof(sec) / sizeof(sec[0]);
    shellsort(sec, n);
    std::cout << "Arreglo ordenado usando Shellsort: \n";
    for (int i = 0; i < n; i++)
        std::cout << sec[i] << " ";
    std::cout << std::endl;
    return 0;
}
