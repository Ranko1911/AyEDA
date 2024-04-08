#include <iostream>

template<typename T>
void swap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

template<typename T>
void baja(int i, T sec[], int n) {
    while (2 * i <= n) {
        int h1 = 2 * i;
        int h2 = h1 + 1;
        int h;
        if (h1 == n || sec[h1] > sec[h2])
            h = h1;
        else
            h = h2;
        if (sec[h] <= sec[i])
            break;
        else {
            swap(sec[i], sec[h]);
            i = h;
        }
    }
}

template<typename T>
void heapsort(T sec[], int n) {
    for (int i = n / 2; i > 0; i--)
        baja(i, sec, n);
    for (int i = n; i > 1; i--) {
        swap(sec[1], sec[i]);
        baja(1, sec, i - 1);
    }
}

int main() {
    int sec[] = {-1, 64, 25, 12, 22, 11}; // Se usa -1 como un elemento ficticio en la posición 0
    int n = sizeof(sec) / sizeof(sec[0]) - 1; // Ignoramos el elemento ficticio
    heapsort(sec, n);
    std::cout << "Arreglo ordenado usando Heapsort: \n";
    for (int i = 1; i <= n; i++)
        std::cout << sec[i] << " ";
    std::cout << std::endl;
    return 0;
}
