#ifndef MAIN_H
#define MAIN_H

#include <algorithm>  // Para shuffle
#include <cstdlib>    // Para rand()
#include <ctime>      // Para time()
#include <fstream>    // Para ifstream
#include <iostream>
#include <string>
#include <vector>  // Para vector

#include "../include/ab.h"
#include "../include/abb.h"
#include "../include/abe.h"
#include "../include/nif.h"
#include "../include/nodo.h"

// struct DATA que contiene
struct DATA {
  std::string tipoArbol;
  std::string metodo;
  std::string opcion;
  std::string nombreFichero;
};

void trabajarConArbol(const std::string& tipoArbol) {
  // Lógica para trabajar con el tipo de árbol especificado
  std::cout << "Trabajando con árbol de tipo: " << tipoArbol << std::endl;
}

void introducirDatos(const std::string& metodo, const std::string& opcion,
                     const std::string& nombreFichero) {
  // Lógica para introducir los datos de la secuencia según el método
  // especificado
  std::cout << "Método de introducción de datos: " << metodo << std::endl;
  if (metodo == "file") {
    std::cout << "Número de elementos: " << opcion << std::endl;
    std::cout << "Nombre del archivo: " << nombreFichero << std::endl;
  } else if (metodo == "random") {
    int numElementos = std::atoi(opcion.c_str());
    std::cout << "Número de elementos aleatorios: " << numElementos
              << std::endl;
    // Lógica para generar datos aleatorios con el número de elementos
    // especificado
  }
  // Implementa la lógica para los otros métodos si es necesario
}

void mostrarAyuda(const std::string& nombrePrograma) {
  std::cout
      << "Uso: " << nombrePrograma << " -ab <abe|abb> -init <i> [s][f]\n\n"
      << "Opciones:\n"
      << "  -ab <abe|abb>          Especifica el tipo de árbol a utilizar\n"
      << "  -init <i> [s][f]       Especifica el método de inicialización de "
         "datos\n"
      << "                         i=manual, i=random [s], i=file [s][f]\n"
      << "  -h, -help              Muestra este mensaje de ayuda\n";
}

DATA inputData(int argc, char* argv[]) {
  DATA data;

  // Si no se proporcionan argumentos, mostrar la ayuda
  if (argc == 1) {
    mostrarAyuda(argv[0]);
    exit(0);
  }

  // Procesar los argumentos de línea de comandos
  for (int i = 1; i < argc; ++i) {
    std::string arg = argv[i];
    if (arg == "-h" || arg == "-help") {
      mostrarAyuda(argv[0]);
      exit(0);
    } else if (arg == "-ab") {
      if (i + 1 < argc) {
        data.tipoArbol = argv[++i];
      } else {
        std::cerr << "-ab requiere un argumento\n";
        exit(1);
      }
    } else if (arg == "-init") {
      if (i + 1 < argc) {
        data.metodo = argv[++i];
        if (data.metodo == "file") {
          if (i + 1 < argc) {
            data.opcion = argv[++i];  // Número de elementos (opcional)
            if (i + 1 < argc && argv[i + 1][0] != '-') {
              data.nombreFichero = argv[++i];  // Nombre del fichero
              // si el nombre del fichero no tiene la extensión .txt, se la
              // añadimos
              if (data.nombreFichero.find(".txt") == std::string::npos) {
                data.nombreFichero += ".txt";
              }
            }

            // si no se proporciona el nombre del fichero, mostrar un mensaje de
            // error
            if (data.nombreFichero.empty()) {
              std::cerr << "La opción file requiere el nombre del archivo\n";
              exit(1);
            }
          } else {
            std::cerr
                << "La opción file requiere al menos el nombre del archivo\n";
            exit(1);
          }
        } else if (data.metodo == "random") {
          if (i + 1 < argc && std::isdigit(argv[i + 1][0])) {
            data.opcion = argv[++i];
          } else {
            std::cerr << "La opción random requiere un número de elementos\n";
            exit(1);
          }
        }
      } else {
        std::cerr << "-init requiere un argumento\n";
        exit(1);
      }
    }
  }

  // Verificar que se hayan proporcionado todas las opciones necesarias
  if (data.tipoArbol.empty() || data.metodo.empty()) {
    std::cerr << "Faltan argumentos obligatorios\n";
    exit(1);
  }

  return data;
}

void randomInsert(AB<int>& abb, int n) {
  for (int i = 0; i < n; ++i) {
    int data = rand() % 100000;
    abb.insert(data);  // Corregido para usar data en lugar de i
  }
}

// Función para insertar elementos únicos en un vector de NIFs
void insertUniqueNifs(std::vector<nif>& nifs, int n) {
  for (int i = 0; i < n; ++i) {
    long data =
        10000000 +
        rand() % 90000000;  // Generar números aleatorios válidos para un NIF
    nifs.push_back(nif(data));
  }
  // Eliminar duplicados
  std::sort(nifs.begin(), nifs.end());
  nifs.erase(std::unique(nifs.begin(), nifs.end()), nifs.end());

  std::random_shuffle(nifs.begin(), nifs.end());
}

void nif_insert(AB<nif>& abb, int n) {
  std::vector<nif> nifs;
  insertUniqueNifs(nifs, n);
  for (const auto& nif : nifs) {
    abb.insert(nif);
  }
}

template <typename T>
void fileInsert(AB<T>& abb, const std::string& nombreFichero) {
  // añadir la extensión .txt si no se proporciona
  if (nombreFichero.find(".txt") == std::string::npos) {
    std::cerr << "El archivo debe tener la extensión .txt" << std::endl;
    return;
  }

  // buscar el archivo en el directorio ../files
  std::ifstream file("files/" + nombreFichero);

  if (!file.is_open()) {
    std::cerr << "No se pudo abrir el archivo " << nombreFichero << std::endl;
    return;
  }

  T data;
  while (file >> data) {
    abb.insert(data);
  }
}

#endif  // MAIN_H