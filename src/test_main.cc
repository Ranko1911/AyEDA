#include <iostream>
#include <vector>
#include <cstdlib>
#include <list>
#include <array>

#include "../include/dispersion.h"
#include "../include/exploration.h"
#include "../include/sequence.h"

#include <string>


int main() {

    std::cout << "Ejemplo de uso de la clase DispersionFunction: \n";

    ModuloDispersion<unsigned> modulo(10);
    std::cout << "Modulo: " << modulo(23) << std::endl;

    SumaDispersion<std::vector<int>> suma(10);
    std::vector<int> key = {1, 2, 3};
    std::cout << "Suma: " << suma(key) << std::endl;

    PseudoaleatoriaDispersion<int> pseudo(10);
    std::cout << "Pseudoaleatoria: " << pseudo(42) << std::endl;

    std::cout << "Ejemplo de uso de la clase Exploracion: \n";

    ExploracionLineal lineal;
    std::cout << "Lineal: " << lineal(23, 2) << std::endl;

    ExploracionCuadratica cuadratica;
    std::cout << "Cuadratica: " << cuadratica(23, 2) << std::endl;

    ModuloDispersion<unsigned> modulo2(10);
    DobleDispersión doble(&modulo2);
    std::cout << "Doble: " << doble(23, 2) << std::endl;

    ModuloDispersion<unsigned> modulo3(10);
    Redispersión redis(&modulo3);
    std::cout << "Redispersion: " << redis(23, 2) << std::endl;

    std::cout << "Ejemplo de uso de la clase Sequence: \n";

    ArraySequence<int> array;
    std::cout << "Insetar 1 y 2 en el array: \n";
    array.insert(1);
    array.insert(2);

    std::cout << "Array: ";
    array.print(std::cout);

    std::cout << "Buscar 1 en el array: " << array.search(1) << std::endl;
    std::cout << "------------------\n";

    
    ListSequence<int> list;
    std::cout << "Insetar 1 y 2 en la lista: \n";
    list.insert(1);
    list.insert(2);

    std::cout << "List: ";
    list.print(std::cout);

    std::cout << "Buscar 1 en la lista: " << list.search(1) << std::endl;

    return 0;
}
