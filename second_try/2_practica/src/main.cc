#include <atomic>
#include <chrono>  // sleep_for
#include <iostream>
#include <string>
#include <thread>  // sleep_for

#include "Cell.h"
#include "Lattice.h"

//estructura de codificacion de Martin Fowler -> apache maven

// Opcion periodica: ./programa -size 10 10 -b periodic
// Opcion open frontera caliente: ./programa -size 5 5 -b open 1
// Opcion open frontera fria: ./programa -size 5 5 -b open 0
// Opcion con fichero:./programa -b periodic -init variante.txt
// Opcion sin bordes: ./programa -init variante.txt -b noborder

void checkKeyPress(std::atomic<bool>& stop) {
  char key;
  std::cin >> key;
  stop.store(true);
}

void PrintOptions() {
  std::cout << "Opciones: " << std::endl;
  std::cout << "x. Finalizar la ejecución del programa." << std::endl;
  std::cout << "n: Calcula y muestra la siguiente generación." << std::endl;
  std::cout << "L: Calcula las siguientes 5 generaciones y las muestra."
            << std::endl;
  std::cout << "c: Los comandos n y L dejas de mostrar el estado del tablero y "
               "solo muestran la población de la generación. Toogle on/off."
            << std::endl;
  std::cout << "s: guarda la generacion en un archivo." << std::endl;
}

void ArgumentsFunction(int argc, char** argv, std::string& file_name,
                       int& size_N, int& size_M, int& b, int& v) {
  for (int i = 1; i < argc; i++) {
    std::string arg = argv[i];
    if (arg == "-h" || arg == "--help") {
      std::cout << "Usage: " << argv[0]
                << " [-init file | -size M N] [-b periodic | open [V]]"
                << std::endl;
      exit(0);
    } else if (arg == "-init") {
      std::cout << "Init: " << argv[i + 1] << std::endl;
      file_name = argv[i + 1];
      i++;
    } else if (arg == "-size") {
      // si size es 0 o menor, error
      if (std::stoi(argv[i + 1]) <= 0) {
        std::cout << "Error: Size must be greater than 0" << std::endl;
        exit(1);
      }
      size_N = std::stoi(argv[i + 1]);
      i++;
      size_M = std::stoi(argv[i + 1]);
      i++;
      std::cout << "Size: " << size_M << "x" << size_N << std::endl;
    } else if (arg == "-b") {
      std::string b_arg = argv[i + 1];
      if (b_arg == "periodic" || b_arg == "open" || b_arg == "noborder") {
        if (b_arg == "periodic") {
          b_arg = "1";
          i++;
          v = 0;
        } else if (b_arg == "open") {
          b_arg = "0";
          i++;
          if (argc > i) {
            std::cout << "V: " << argv[i + 1] << std::endl;
            v = std::stoi(argv[i + 1]);
            i++;
          }
        } else if (b_arg == "noborder") {
          b_arg = "2";
          i++;
          v = 0;
        }
        b = std::stoi(b_arg);
        // i++;
        std::cout << "B: " << b << std::endl;
      } else {
        std::cout << "Error: Not Valid option for b first argument: " << b_arg
                  << std::endl;
        exit(1);
      }
    } else {
      std::cout << "Unknown argument: " << argc << std::endl;
      exit(1);
    }
  }
}

int main(int argc, char** argv) {
  std::atomic<bool> stop(false);

  // No argumetos, no programa
  if (argc == 1) {
    std::cout << "No arguments" << std::endl;
    return 1;
  }
  std::string file_name = "";
  int size_N = 0;  // numero de columnas
  int size_M = 0;  // numero de filas
  int b;
  int v = -1;

  ArgumentsFunction(argc, argv, file_name, size_N, size_M, b, v);

  Lattice* lattice_ptr = nullptr;

  // comprobar que size y file_name no estén definidos a la vez
  if (file_name != "" && (size_N != 0 || size_M != 0)) {
    std::cout << "Error: Both file and size are defined" << std::endl;
    return 1;

  } else if (size_N != 0 || size_M != 0) {  // si size está definido, crear un lattice con el tamaño dado
    // std::cout << "Creating lattice with size: " << size_M << "x" << size_N << std::endl;
    lattice_ptr = new Lattice(b, v, size_N, size_M);
    // std::cout << "Contenido del lattice:\n" << *lattice_ptr << std::endl;

  } else if (file_name != "") {
    // std::cout << "Creating lattice with file: " << file_name << std::endl;
    lattice_ptr = new Lattice(b, v, file_name);
    // std::cout << "Contenido del lattice:\n" << *lattice_ptr << std::endl;
  } else {
    std::cout << "Error: No size or file defined" << std::endl;
    return 1;
  }

  char option = ' ';
  bool c = false;

  int gen = 1;
  while (true) {    
    // std::cout << "\033[2J\033[1;1H";  // limpia la pantalla
    if(gen = 1){
      if (size_N != 0 || size_M != 0){
        std::cout << "Creating lattice with size: " << size_M << "x" << size_N << std::endl;
        std::cout << "Contenido del lattice:\n" <<*lattice_ptr << std::endl;
      }else if (file_name != "") {
        std::cout << "Creating lattice with file: " << file_name << std::endl;
        std::cout << "Contenido del lattice:\n" << *lattice_ptr << std::endl;
      }

    }
    // std::cout << "\033[2J\033[1;1H";  // limpia la pantalla

    std::cout << "Dimensiones: " << lattice_ptr->getSize().x << "x" << lattice_ptr->getSize().y << std::endl;
    if(c == false){
      std::cout << "Mode: Print Lattice" << std::endl;
    }else {
      std::cout << "Mode: Print Population" << std::endl;
    }
    PrintOptions();
    std::cin >> option;
    switch (option) {
      case 'x':
        // dejar de ejcutar el programa
        return 0;
        break;
      case 'n':
          // std::cout << "\033[2J\033[1;1H";  // limpia la pantalla

        // calcular y mostrar la siguiente generacion
        // std::cout << "Calcular y mostrar la siguiente generacion" << std::endl;
        lattice_ptr->nextGeneration();
        // std::cout << "Acierto despues de nextGeneration" << std::endl;
        if (c == false) {
          std::cout << "Generation: " << gen << std::endl;
          std::cout << *lattice_ptr << std::endl;
          // std::cout << "despues de nextGeneration" << std::endl;
        } else {
          std::cout << "Poblacion: " << lattice_ptr->Population() << std::endl;
        }

        break;
      case 'L':
          // std::cout << "\033[2J\033[1;1H";  // limpia la pantalla

        // calcular las siguientes 5 generaciones y mostrarlas
        for (int i = 0; i < 5; i++) {
          // std::cout << "Generation: " << i << std::endl;
          // std::cout << *lattice_ptr << std::endl;
          lattice_ptr->nextGeneration();
        }
        if (c == false) {
          // std::cout << "Generation: " << std::endl;
          std::cout << *lattice_ptr << std::endl;
        } else {
          std::cout << "Poblacion: " << lattice_ptr->Population() << std::endl;
        }
        break;

      case 'c':
        // los comandos n y L dejas de mostrar el estado del tablero y solo
        // muestran la población de la generación
        if (c == false) {
          c = true;
        } else {
          c = false;
        }
        break;

      case 's':
        // guardar la generacion en un archivo
        std::cout << "Guardando generacion en un archivo" << std::endl;
        lattice_ptr->saveToFile("generacion.txt");
        break;

      default:
        std::cout << "Opcion no valida" << std::endl;
        break;
    }
    gen++;
  }

  lattice_ptr = nullptr;
  delete lattice_ptr;
  return 0;
}