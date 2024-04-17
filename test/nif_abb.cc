#include <iostream>
#include <cstdlib> // Para rand()
#include <ctime>   // Para time()
#include <vector>  // Para vector
#include <algorithm> // Para shuffle
#include "../include/nif.h"  // Incluir el archivo de encabezado de la clase nif
#include "../include/ab.h"
#include "../include/nodo.h"
#include "../include/abb.h"

// Función para insertar elementos únicos en un vector de NIFs
void insertUniqueNifs(std::vector<nif> &nifs, int n) {
    for (int i = 0; i < n; ++i) {
        long data = 10000000 + rand() % 90000000; // Generar números aleatorios válidos para un NIF
        nifs.push_back(nif(data));
    }
    // Eliminar duplicados
    std::sort(nifs.begin(), nifs.end());
    nifs.erase(std::unique(nifs.begin(), nifs.end()), nifs.end());
}

int main() {
    srand(time(nullptr)); // Inicializar la semilla del generador de números aleatorios

    ABB<nif> abb; // Cambiar el tipo de dato del árbol a nif

    std::vector<nif> nifs;
    insertUniqueNifs(nifs, 10); // Insertar 10 NIFs únicos

    // Mezclar el vector para garantizar aleatoriedad
    std::random_shuffle(nifs.begin(), nifs.end());

    // Insertar los NIFs en el árbol
    for(const auto& nif : nifs) {
        abb.insert(nif);
    }

    std::cout << "Árbol binario de búsqueda:\n " << abb << std::endl;

    std::cout << "¿El elemento 10000007 está en el árbol? " << (abb.search(nif(10000007)) ? "Sí" : "No") << std::endl;
    std::cout << "¿El elemento 10000020 está en el árbol? " << (abb.search(nif(10000020)) ? "Sí" : "No") << std::endl;

    // abb.remove(nif(10000007));
    // std::cout << "Árbol después de eliminar el elemento 10000007: \n" << abb << std::endl;

    std::cout << "Impresión de Árbol inorden:\n";
    abb.inorden();
    std::cout << std::endl;

    return 0;
}
