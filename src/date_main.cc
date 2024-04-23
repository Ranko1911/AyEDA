#include <cstdlib>  // Para std::atoi
#include <iostream>
#include <string>

#include "../include/ab.h"
#include "../include/abb.h"
#include "../include/abe.h"
#include "../include/date.h"
#include "../include/main.h"
#include "../include/nodo.h"

int main(int argc, char* argv[]) {
  DATA data = inputData(argc, argv);

  // Ejecutar las funciones correspondientes
  trabajarConArbol(data.tipoArbol);
  introducirDatos(data.metodo, data.opcion, data.nombreFichero);

  // crear puntero a la clase AB
  AB<date>* arbol;

  if (data.tipoArbol == "abe") {
    arbol = new ABE<date>();
  } else if (data.tipoArbol == "abb") {
    arbol = new ABB<date>();
  } else {
    std::cout << "Tipo de arbol no valido" << std::endl;
    return 0;
  }

  if (data.metodo == "random") {
    // llamar a la funcion dateiInsert
    int numElementos = std::atoi(data.opcion.c_str());
    date_insert(*arbol, numElementos);
  }

  if (data.metodo == "file") {
    // llamar a la funcion fileInsert
    fileInsert(*arbol, data.nombreFichero);
  }

  int valor;
  int dia = 0;
  int mes = 0;
  int year = 0;

  while (valor != 0) {
    std::cout << "[0] - Salir" << std::endl;
    std::cout << "[1] - Insertar Clave - formato de la fecha yyyymmdd" << std::endl;
    std::cout << "[2] - Buscar Clave - formato de la fecha yyyymmdd" << std::endl;
    std::cout << "[3] - Imprimir Arbol Post" << std::endl;
    std::cout << "[4] - Imprimir Arbol" << std::endl;
    std::cout << "[5] - Imprimir Arbol Inorden" << std::endl;
    std::cout << "Introduce una opción: ";
    std::cin >> valor;

    date temp;

    switch (valor) {
      case 0:
        break;

      case 1:
        int clave;
        std::cout << "Introduce la clave a insertar: ";
        std::cin >> clave;
        if (clave < 10000000 || clave > 99999999) {
          std::cout << "Clave no válida" << std::endl;
          break;
        }
        // separar la clave en día, mes y año
        // sia son los 2 mas significativos
        dia = clave % 100;
        mes = (clave / 100) % 100;
        year = (clave / 10000) % 10000;
        std::cout << "Dia: " << dia << " Mes: " << mes << " Año: " << year
                  << std::endl;
        temp = date(dia, mes, year);
        std::cout << "Insertando " << temp << std::endl;

        arbol->insert(temp);
        std::cout << *arbol << std::endl;
        break;

      case 2:
        int claveBuscar;
        std::cout << "Introduce la clave a buscar: ";
        std::cin >> claveBuscar;
        dia = clave % 100;
        mes = (clave / 100) % 100;
        year = (clave / 10000) % 10000;
        std::cout << "Dia: " << dia << " Mes: " << mes << " Año: " << year
                  << std::endl;
        temp = date(dia, mes, year);
        if (arbol->search(temp)) {
          std::cout << claveBuscar << " está presente en el árbol."
                    << std::endl;
        } else {
          std::cout << claveBuscar << " no está presente en el árbol."
                    << std::endl;
        }
        break;

      case 3:
        std::cout << "Árbol en postorden: ";
        arbol->postorden();
        std::cout << std::endl;
        break;

      case 4:
        std::cout << "Árbol:\n " << *arbol << std::endl;
        break;

      case 5:
        std::cout << "Árbol en inorden: ";
        arbol->inorden();
        std::cout << std::endl;

      default:
        std::cout << "Opción no válida" << std::endl;
        break;
    }
  }

  return 0;
}
