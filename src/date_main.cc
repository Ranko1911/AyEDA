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

  int valor = -1;
  int dia = 0;
  int mes = 0;
  int year = 0;
  std::string claveStr = "";
  std::string claveBuscarStr = "";

  while (valor != 0) {
    std::cout << "[0] - Salir" << std::endl;
    std::cout << "[1] - Insertar Clave"
              << std::endl;
    std::cout << "[2] - Buscar Clave"
              << std::endl;
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
        // int clave;
        // std::string clave2;
        std::cout << "Introduce la clave a insertar: ";
        std::cin >> claveStr;

        //pasar de clave de int a string
        // claveStr = std::to_string(clave);

        temp = date(claveStr);
        std::cout << "Insertando " << temp << std::endl;
        std::cout << "Dia: " << temp.day() << std::endl;
        std::cout << "Mes: " << temp.month() << std::endl;
        std::cout << "Año: " << temp.year() << std::endl;

        arbol->insert(temp);
        std::cout << *arbol << std::endl;
        break;

      case 2:
        // int claveBuscar;
        std::cout << "Introduce la clave a buscar: ";
        // std::cin >> claveBuscar;
        //  claveBuscarStr = std::to_string(claveBuscar);
        std::cin >> claveBuscarStr;

        temp = date(claveBuscarStr);
        if (arbol->search(temp)) {
          std::cout << claveBuscarStr << " está presente en el árbol."
                    << std::endl;
        } else {
          std::cout << claveBuscarStr << " no está presente en el árbol."
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
