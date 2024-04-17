#include "../include/main.h"

#include <cstdlib>  // Para std::atoi
#include <iostream>
#include <string>

#include "../include/ab.h"
#include "../include/abb.h"
#include "../include/abe.h"
#include "../include/nif.h"
#include "../include/nodo.h"

int main(int argc, char* argv[]) {
  DATA data = inputData(argc, argv);

  // Ejecutar las funciones correspondientes
  trabajarConArbol(data.tipoArbol);
  introducirDatos(data.metodo, data.opcion, data.nombreFichero);

  // crear puntero a la clase AB
  AB<nif>* arbol;

  if (data.tipoArbol == "abe") {
    arbol = new ABE<nif>();
  } else if (data.tipoArbol == "abb") {
    arbol = new ABB<nif>();
  } else {
    std::cout << "Tipo de arbol no valido" << std::endl;
    return 0;
  }

  if(data.metodo == "random") {
    //llamar a la funcion nifiInsert
    int numElementos = std::atoi(data.opcion.c_str());
    nif_insert(*arbol, numElementos);
  }

  int valor;

  while (valor != 0) {
    std::cout << "[0] - Salir" << std::endl;
    std::cout << "[1] - Insertar Clave" << std::endl;
    std::cout << "[2] - Buscar Clave" << std::endl;
    std::cout << "[3] - Imprimir Arbol Inorden" << std::endl;
    std::cout << "[4] - Imprimir Arbol" << std::endl;
    std::cout << "Introduce una opción: ";
    std::cin >> valor;

    nif temp;

    switch (valor) {
      case 0:
        break;

      case 1:
        int clave;
        std::cout << "Introduce la clave a insertar: ";
        std::cin >> clave;
        if(clave < 10000000 || clave > 99999999) {
          std::cout << "Clave no válida" << std::endl;
          break;
        }
        temp = nif(clave);
        std::cout << "Insertando " << temp << std::endl;

        arbol->insert(temp);
        std::cout << *arbol << std::endl;
        break;

      case 2:
        int claveBuscar;
        std::cout << "Introduce la clave a buscar: ";
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
