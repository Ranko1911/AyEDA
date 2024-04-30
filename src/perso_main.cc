#include <cstdlib>  // Para std::atoi
#include <iostream>
#include <string>

#include "../include/ab.h"
#include "../include/abb.h"
#include "../include/abe.h"
#include "../include/avl.h"
#include "../include/main.h"
#include "../include/personaje.h"
#include "../include/nodo.h"

int main(int argc, char* argv[]) {
  DATA data = inputData(argc, argv);

  // Ejecutar las funciones correspondientes
  trabajarConArbol(data.tipoArbol);
  introducirDatos(data.metodo, data.opcion, data.nombreFichero);

  // crear puntero a la clase AB
  AB<personaje>* arbol;

  if (data.tipoArbol == "abe") {
    arbol = new ABE<personaje>();
  } else if (data.tipoArbol == "abb") {
    arbol = new ABB<personaje>();
  } else if (data.tipoArbol == "avl") {
    arbol = new AVL<personaje>(true);
  } else {
    std::cout << data.tipoArbol << std::endl;
    std::cout << "Tipo de arbol no valido" << std::endl;
    return 0;
  }

  if(data.traza == "true" && data.tipoArbol == "avl") {
    arbol = new AVL<personaje>(true);
  } else if (data.traza == "false" && data.tipoArbol == "avl") {
    arbol = new AVL<personaje>(false);
  }

  if (data.metodo == "random") {
    // llamar a la funcion randomInsert
    int numElementos = std::atoi(data.opcion.c_str());
    personaje_random_insert(*arbol, numElementos);
  }

  if (data.metodo == "file") {
    // llamar a la funcion fileInsert
    fileInsert(*arbol, data.nombreFichero);
  }

  int valor;
  personaje clave;
  personaje claveBuscar;

  while (valor != 0) {
    std::cout << "[0] - Salir" << std::endl;
    std::cout << "[1] - Insertar Clave" << std::endl;
    std::cout << "[2] - Buscar Clave" << std::endl;
    std::cout << "[3] - Imprimir Arbol Inorden" << std::endl;
    std::cout << "[4] - Imprimir Arbol" << std::endl;
    std::cout << "Introduce una opción: ";
    std::cin >> valor;

    switch (valor) {
      case 0:
        break;

      case 1:
        int temp;
        std::cout << "Introduce la clave a insertar: ";
        std::cout << "Introduce la vida: ";
        std::cin >> temp;
        clave[0] = temp;
        std::cout << "Introduce la fuerza: ";
        std::cin >> temp;
        clave[1] = temp;
        std::cout << "Introduce la destreza: ";
        std::cin >> temp;
        clave[2] = temp;
        std::cout << "Introduce la inteligencia: ";
        std::cin >> temp;
        clave[3] = temp;
        std::cout << "Introduce la sabiduria: ";
        std::cin >> temp;
        clave[4] = temp;
        std::cout << "Introduce la carisma: ";
        std::cin >> temp;
        clave[5] = temp;
        std::cout << "Introduce la constitucion: ";
        std::cin >> temp;
        clave[6] = temp;
        std::cout << "Introduce la defensa: ";
        std::cin >> temp;
        clave[7] = temp;
        std::cout << "Introduce la velocidad: ";
        std::cin >> temp;
        clave[8] = temp;
        std::cout << "Introduce el nombre: ";
        std::cin >> clave[9];
        clave.calcular_media();
 
        arbol->insert(clave);
        std::cout << *arbol << std::endl;
        break;

      case 2:
        std::cout << "Introduce la vida: ";
        std::cin >> claveBuscar[0];
        std::cout << "Introduce la fuerza: ";
        std::cin >> claveBuscar[1];
        std::cout << "Introduce la destreza: ";
        std::cin >> claveBuscar[2];
        std::cout << "Introduce la inteligencia: ";
        std::cin >> claveBuscar[3];
        std::cout << "Introduce la sabiduria: ";
        std::cin >> claveBuscar[4];
        std::cout << "Introduce la carisma: ";
        std::cin >> claveBuscar[5];
        std::cout << "Introduce la constitucion: ";
        std::cin >> claveBuscar[6];
        std::cout << "Introduce la defensa: ";
        std::cin >> claveBuscar[7];
        std::cout << "Introduce la velocidad: ";
        std::cin >> claveBuscar[8];
        std::cout << "Introduce el nombre: ";
        std::cin >> claveBuscar[9];
        std::cin >> claveBuscar;
        if (arbol->search(claveBuscar)) {
          std::cout << claveBuscar << " está presente en el árbol."
                    << std::endl;
        } else {
          std::cout << claveBuscar << " no está presente en el árbol."
                    << std::endl;
        }
        break;

      case 3:
        std::cout << "Árbol en orden: ";
        arbol->inorden();
        std::cout << std::endl;
        break;

      case 4:
        std::cout << "Árbol:\n " << *arbol << std::endl;
        break;

      default:
        std::cout << "Opción no válida" << std::endl;
        break;
    }
  }

  return 0;
}
