#include <iostream>
#include <vector>
#include <algorithm>

// Función auxiliar para obtener el dígito en una posición específica
template<typename T>
int obtenerDigito(T numero, int posicion) {
    while (posicion--)
        numero /= 10;
    return numero % 10;
}

// Función para ordenar el vector usando RadixSort
template<typename T>
void radixSort(std::vector<T>& sec) {
    // Encontrar el dígito máximo en el vector
    T max = *std::max_element(sec.begin(), sec.end());

    // Realizar el conteo de frecuencia para cada dígito
    for (T exp = 1; max / exp > 0; exp *= 10) {
        std::vector<int> conteo(10, 0);
        std::vector<T> resultado(sec.size());
        
        for (int i = 0; i < sec.size(); i++)
            conteo[(sec[i] / exp) % 10]++;

        for (int i = 1; i < 10; i++)
            conteo[i] += conteo[i - 1];

        for (int i = sec.size() - 1; i >= 0; i--) {
            resultado[conteo[(sec[i] / exp) % 10] - 1] = sec[i];
            conteo[(sec[i] / exp) % 10]--;
        }

        for (int i = 0; i < sec.size(); i++)
            sec[i] = resultado[i];
    }
}

int main() {
    std::vector<int> sec = {170, 45, 75, 90, 802, 24, 2, 66};
    
    std::cout << "Arreglo original:\n";
    for (int i = 0; i < sec.size(); i++)
        std::cout << sec[i] << " ";
    std::cout << std::endl;
    
    radixSort(sec);
    
    std::cout << "Arreglo ordenado usando RadixSort:\n";
    for (int i = 0; i < sec.size(); i++)
        std::cout << sec[i] << " ";
    std::cout << std::endl;

    return 0;
}
