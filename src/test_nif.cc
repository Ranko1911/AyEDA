#include "../include/nif.h"

int main() {
    nif n1; // Constructor por defecto, inicializa un nif con valor predeterminado
    std::cout << "n1: " << static_cast<long>(n1) << std::endl; // Mostrar el valor de n1 como long

    //crear nif con un cin
    // nif n3;
    // std::cin >> n3;
    // std::cout << "n3: " << static_cast<long>(n3) << std::endl; // Mostrar el valor de n3 como long

    nif n2(12345678); // Constructor de cambio de tipo a partir de un dato entero long
    std::cout << "n2: " << static_cast<long>(n2) << std::endl; // Mostrar el valor de n2 como long

    std::cout << "Comparación: " << (n1 == n2) << std::endl; // Ejemplo de operador de comparación

    std::cin >> n1; // Ejemplo de operador de inserción

    std::cout << "n1: " << static_cast<long>(n1) << std::endl; // Mostrar el valor de n1 como long

    return 0;
}