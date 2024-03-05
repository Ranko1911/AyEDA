#include <atomic>
#include <chrono>  // sleep_for
#include <iostream>
#include <memory>
#include <string>
#include <thread>  // sleep_for
#include <vector>

#include "../include/Cell.h"
#include "../include/CellACE.h"
#include "../include/CellLife.h"
#include "../include/FactoryCell.h"
#include "../include/Lattice.h"
#include "../include/Lattice1D.h"
#include "../include/Lattice2D.h"
#include "../include/Position.h"

// estructura de codificacion de Martin Fowler -> apache maven

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

int TooMuchArguments(std::string file_name, std::vector<int> size) {
  if (file_name != "" && size.size() != 0) {
    std::cout << "Error: Both file and size are defined" << std::endl;
    return 1;

  } else if (file_name == "" && size.size() == 0) {
    std::cout << "Error: No file or size defined" << std::endl;
    return 1;
  }
  return 0;
}

void ArgumentsFunction(int argc, char** argv, std::string& file_name,
                       std::vector<int>& size, int& b, int& v, int& c,
                       int& dim) {
  for (int i = 1; i < argc; i++) {
    std::string arg = argv[i];
    if (arg == "-h" || arg == "--help") {
      std::cout << "Usage: " << argv[0] << " [options]" << std::endl;
      std::cout << "Options:" << std::endl;
      std::cout << "  -h, --help\t\t\tShow this help message and exit"
                << std::endl;
      std::cout << "  -init FILE\t\t\tFile to initialize the lattice"
                << std::endl;
      std::cout << "  -size N M\t\t\tSize of the lattice" << std::endl;
      std::cout << "  -b, --border\t\t\tBorder type: periodic, open, noborder, "
                   "reflective [v -> 0 || 1]"
                << std::endl;
      std::cout << "  -c\t\t\t\tCell type: ACE110, ACE30, Life23_3, Life51_346"
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
      // size_N = std::stoi(argv[i + 1]);
      // i++;
      // size_M = std::stoi(argv[i + 1]);
      // i++;

      // mientras el siguiente argumento no es una de las opciones , introducir
      // en el vector
      while (i < argc && argv[i + 1] != "-b" && argv[i + 1] != "--border" &&
             argv[i + 1] != "-c" && argv[i + 1] != "-init" &&
             argv[i + 1] != "-size" && argv[i + 1] != "-h" &&
             argv[i + 1] != "--help" && argv[i + 1] != "-v" &&
             argv[i + 1] != "-dim") {
        size.push_back(std::stoi(argv[i + 1]));
        i++;
      }

      // std::cout << "Size: " << size_M << "x" << size_N << std::endl;
    } else if (arg == "-b" || arg == "--border") {
      std::string b_arg = argv[i + 1];
      if (b_arg == "periodic" || b_arg == "open" || b_arg == "noborder" ||
          b_arg == "reflective") {
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
        } else if (b_arg == "reflective") {
          b_arg = "3";
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
    } else if (arg == "-cell") {
      std::string c_arg = argv[i + 1];
      if (c_arg == "ACE110" || c_arg == "ACE30" || c_arg == "Life23_3" ||
          c_arg == "Life51_346") {
        if (c_arg == "ACE110") {
          c = 1;
          i++;
        } else if (c_arg == "ACE30") {
          c = 2;
          i++;
        } else if (c_arg == "Life23_3") {
          c = 3;
          i++;
        } else if (c_arg == "Life51_346") {
          c = 4;
          i++;
        }
        i++;
        std::cout << "C: " << c_arg << std::endl;
      } else {
        std::cout << "Error: Not Valid option for c first argument: " << c_arg
                  << std::endl;
        exit(1);
      }

    } else if (arg == "-dim") {
      std::cout << "Dim: " << argv[i + 1] << std::endl;
      std::string dim_arg = argv[i + 1];

      // si no es un numero, error
      if (std::stoi(dim_arg) <= 0) {
        std::cout << "Error: Dim must be greater than 0" << std::endl;
        exit(1);
      }

      dim = std::stoi(dim_arg);
      i++;
      // std::cout << "Dim: " << dim << std::endl;

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
  // int size_N = 0;  // numero de columnas
  // int size_M = 0;  // numero de filas
  // vector de int
  std::vector<int> size;
  int b;
  int v = -1;
  int celula = 0;
  int dim = 1;
  FactoryCell* factory = nullptr;
  Lattice* lattice_ptr = nullptr;
  Position* pos = nullptr;

  // crear un PositionDim en base del valor de dim
  // si dim es menor de 2 o mayor de 3, dar error
  // si dim es 2, crear un PositionDim<2>
  // si dim es 3, crear un PositionDim<3>

  // std::cout << "Antes de funcion argumentos" << std::endl;

  ArgumentsFunction(argc, argv, file_name, size, b, v, celula, dim);

  std::cout << "Despues de funcion argumentos" << std::endl;

  // Lattice* lattice_ptr = nullptr;

  // si celula es 1, crear un FactoryCellACE110
  // si celula es 2, crear un FactoryCellACE30
  // si celula es 3, crear un FactoryCellLife23_3
  // si celula es 4, crear un FactoryCellLife51_346
  if (celula == 1) {
    std::cout << "Creating FactoryCellACE110" << std::endl;
    factory = new FactoryCellACE110();
  } else if (celula == 2) {
    std::cout << "Creating FactoryCellACE30" << std::endl;
    factory = new FactoryCellACE30();
  } else if (celula == 3) {
    std::cout << "Creating FactoryCellLife23_3" << std::endl;
    factory = new FactoryCellLife23_3();
  } else if (celula == 4) {
    std::cout << "Creating FactoryCellLife51_346" << std::endl;
    factory = new FactoryCellLife51_346();
  } else {
    std::cout << "Error: Not valid option for c" << std::endl;
    return 1;
  }

  std::cout << "file_name:" << file_name << std::endl;

  // comprobar que size y file_name no estén definidos a la vez
  if (TooMuchArguments(file_name, size) == 1) {
    return 1;
  }

  //si el vector size esta vacio, relleanr con 0 hasta 3
  while (size.size() < 3) {
    size.push_back(0);
  }

  if (dim < 2 || dim > 3) {
    std::cout << "Error: Dim must be 2 or 3" << std::endl;
    return 1;
  } else if (dim == 2) {
    std::cout << "Creating PositionDim<2>" << std::endl;
    pos = new PositionDim<2>(2, size[0], size[1]);
    std::cout << "Creating lattice with size: " << size[0] << "x" << size[1]
              << std::endl;
  } else if (dim == 3) {
    std::cout << "Creating PositionDim<3>" << std::endl;
    pos = new PositionDim<3>(3, size[0], size[1], size[2]);
    std::cout << "Creating lattice with size: " << size[0] << "x" << size[1]
              << "x" << size[2] << std::endl;
  }
  std::cout << "Creating lattice with size: ";

  if (file_name != "") {
    std::cout << "Creating lattice with file: " << file_name << std::endl;
    if (b == 0) {
      lattice_ptr = new Lattice1D_open(b, v, file_name, *factory);
      std::cout << "Creating lattice1D_open" << std::endl;
    } else if (b == 1) {
      lattice_ptr = new Lattice1D_periodic(b, v, file_name, *factory);
      std::cout << "Creating lattice1D_periodic" << std::endl;
    } else if (b == 2) {
      lattice_ptr = new Lattice2D_NoBorder(b, v, file_name, *factory);
      std::cout << "Creating lattice2D_NoBorder" << std::endl;
    } else if (b == 3) {
      lattice_ptr = new Lattice2D_reflective(b, v, file_name, *factory);
      std::cout << "Creating lattice2D_reflective" << std::endl;
    }

  } else {
    std::cout << "Creating lattice with size: ";

    if (b == 1) {
      lattice_ptr = new Lattice1D_open(b, v, *pos, *factory);
    } else if (b == 0) {
      lattice_ptr = new Lattice1D_periodic(b, v, *pos, *factory);
    } else if (b == 2) {
      lattice_ptr = new Lattice2D_NoBorder(b, v, *pos, *factory);
    } else if (b == 3) {
      lattice_ptr = new Lattice2D_reflective(b, v, *pos, *factory);
    }
  }
  std::cout << "Contenido del lattice:\n" << std::endl;
  lattice_ptr->display(std::cout, *lattice_ptr);
  std::cout << std::endl;

  char option = ' ';
  bool c = false;

  // PositionDim<2> p(1, 2);
  // std::cout << "p[0]: " << p[0] << std::endl;
  // std::cout << "p[1]: " << p[1] << std::endl;

  int gen = 1;
  while (true) {
    // std::cout << "\033[2J\033[1;1H";  // limpia la pantalla
    // if (gen = 1) {
    //   if (file_name != "") {
    //     std::cout << "Creating lattice with file: " << file_name <<
    //     std::endl;
    //     // lattice_ptr = new Lattice(b, v, file_name);
    //     // std::cout << "Contenido del lattice:\n" << *lattice_ptr <<
    //     std::endl;
    //   } else {
    //     std::cout << "Creating lattice with size: ";
    //     for (int i = 0; i < size.size(); i++) {
    //       std::cout << size[i] << " ";
    //     }
    //     std::cout << std::endl;
    //     // lattice_ptr = new Lattice(b, v, size_N, size_M);
    //     // std::cout << "Contenido del lattice:\n" << *lattice_ptr <<
    //     std::endl;
    //   }
    // }
    // std::cout << "\033[2J\033[1;1H";  // limpia la pantalla

    // std::cout << "Dimensiones: " << lattice_ptr->getSize()[1] << "x"
    // << lattice_ptr->getSize()[0] << std::endl;  // filas x columnas
    if (c == false) {
      std::cout << "Mode: Print Lattice" << std::endl;
    } else {
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
        std::cout << "Calcular y mostrar la siguiente generacion" << std::endl;
        lattice_ptr->nextGeneration();
        // std::cout << "Acierto despues de nextGeneration" << std::endl;
        if (c == false) {
          std::cout << "Generation: " << gen << std::endl;
          lattice_ptr->display(std::cout, *lattice_ptr);
          // std::cout << "despues de nextGeneration" << std::endl;
        } else {
          std::cout << "Poblacion: " << lattice_ptr->Population() << std::endl;
        }

        break;
      case 'L':
        // std::cout << "\033[2J\033[1;1H";  // limpia la pantalla

        // calcular las siguientes 5 generaciones y mostrarlas
        for (int i = 0; i < 5; i++) {
          std::cout << "Generation: " << i << std::endl;
          // std::cout << *lattice_ptr << std::endl;
          lattice_ptr->display(std::cout, *lattice_ptr);
          lattice_ptr->nextGeneration();
        }
        if (c == false) {
          std::cout << "Generation: " << std::endl;
          // std::cout << *lattice_ptr << std::endl;
          lattice_ptr->display(std::cout, *lattice_ptr);
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