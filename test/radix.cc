#include <iostream>
#include "../include/sequence.h" // Asumiendo que la implementación de staticSequence está en "staticSequence.h"

// Función para obtener el dígito en una posición específica
template<typename T>
int obtenerDigito(T numero, int posicion) {
    while (posicion--)
        numero /= 10;
    return numero % 10;
}

// Función para ordenar la secuencia usando RadixSort
template<typename T>
void radixSort(staticSequence<T>& sec, int size) {
    // Encontrar el dígito máximo en la secuencia
    T max = sec[0];
    for (int i = 1; i < size; i++) {
        if (sec[i] > max) {
            max = sec[i];
        }
    }

    // Crear un arreglo para el conteo de frecuencia
    staticSequence<int> conteo(10); // Los dígitos van de 0 a 9

    // Crear un arreglo para el resultado ordenado
    staticSequence<T> resultado(size);

    // Realizar el conteo de frecuencia para cada dígito
    for (T exp = 1; max / exp > 0; exp *= 10) {
        conteo = staticSequence<int>(10); // Reiniciamos el arreglo de conteo en cada iteración

        for (int i = 0; i < size; i++)
            conteo[(sec[i] / exp) % 10]++;

        for (int i = 1; i < 10; i++)
            conteo[i] += conteo[i - 1];

        for (int i = size - 1; i >= 0; i--) {
            resultado[conteo[(sec[i] / exp) % 10] - 1] = sec[i];
            conteo[(sec[i] / exp) % 10]--;
        }

        for (int i = 0; i < size; i++)
            sec[i] = resultado[i];
    }
}

int main() {
    staticSequence<int> sec(8); // Creamos una staticSequence con capacidad para 8 elementos
    
    sec.Insert(170);
    sec.Insert(45);
    sec.Insert(75);
    sec.Insert(90);
    sec.Insert(802);
    sec.Insert(24);
    sec.Insert(2);
    sec.Insert(66);
    
    std::cout << "Arreglo original:\n";
    for (int i = 0; i < 8; i++)
        std::cout << sec[i] << " ";
    std::cout << std::endl;
    
    radixSort(sec, 8);
    
    std::cout << "Arreglo ordenado usando RadixSort:\n";
    for (int i = 0; i < 8; i++)
        std::cout << sec[i] << " ";
    std::cout << std::endl;

    return 0;
}
