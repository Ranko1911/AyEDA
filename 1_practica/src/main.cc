#include <atomic>
#include <chrono>  // sleep_for
#include <iostream>
#include <string>
#include <thread>  // sleep_for

#include "Cell.h"
#include "Lattice.h"

// Opcion periodica: ./programa -size 10 -b periodic
// Opcion open frontera caliente: ./programa -size 5 -b open 1
// Opcion open frontera fria: ./programa -size 5 -b open 0

void checkKeyPress(std::atomic<bool>& stop) {
  char key;
  std::cin >> key;
  stop.store(true);
}


int main(int argc, char** argv) {
  std::atomic<bool> stop(false);

  // No argumetos, no programa
  if (argc == 1) {
    std::cout << "No arguments" << std::endl;
    return 1;
  }
  std::string file_name = "";
  int size;
  int b;
  int v = -1;
  // Recorrer los argumentos y hacer algo con ellos
  for (int i = 1; i < argc; i++) {
    std::string arg = argv[i];
    if (arg == "-h" || arg == "--help") {
      std::cout << "Usage: " << argv[0]
                << " -size 'int' -b < b [v] > [options] \n"
                << "b -> open (v -> 1 || 0 ) || periodic " << std::endl
                << "Options:" << std::endl
                << "  -h, --help\t\tShow this help message and exit"
                << std::endl
                << "  -f, --file\t\tFile of start state" << std::endl;
      return 0;
    } else if (arg == "-init") {
      file_name = argv[i + 1];
      i++;

    } else if (arg == "-size") {
      // si size es 0 o menor, error
      if (std::stoi(argv[i + 1]) <= 0) {
        std::cout << "Error: Size must be greater than 0" << std::endl;
        return 1;
      }
      size = std::stoi(argv[i + 1]);
      i++;
      std::cout << "Size: " << size << std::endl;
    } else if (arg == "-b") {
      std::string b_arg = argv[i + 1];
      if (b_arg == "periodic" || b_arg == "open") {
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
        }
        b = std::stoi(b_arg);
        i++;
        std::cout << "B: " << b << std::endl;
      } else {
        std::cout << "Error: Not Valid option for b first argument: " << b_arg
                  << std::endl;
        return 1;
      }
    } else {
      std::cout << "Unknown argument: " << argc << std::endl;
      return 1;
    }
  }

  // comprobar que size y file_name no estén definidos a la vez
  if (file_name != "" && size != 0) {
    std::cout << "Error: Both file and size are defined" << std::endl;
    return 1;
  }

  Lattice* lattice_ptr = nullptr;

  // si size está definido, crear un lattice con el tamaño dado
  if (size != 0) {
    std::cout << "Creating lattice with size: " << size << std::endl;
    // Lattice lattice_(b, v, size);
    lattice_ptr = new Lattice(b, v, size);
  } else if (file_name != "") {
    std::cout << "Creating lattice with file: " << file_name << std::endl;
    // Lattice lattice_(b, v, file_name);
    lattice_ptr = new Lattice(b, v, file_name);
  } else {
    std::cout << "Error: No size or file defined" << std::endl;
    return 1;
  }

  // for (int i = 0; i < 10; i++)
  // {
  //   std::cout << "Generation: " << i << std::endl;
  //   std::cout << *lattice_ptr << std::endl;
  //   // std::cout << *lattice_ptr << std::endl;
  //   lattice_ptr->nextGeneration();
  // }

  // Crear un hilo para verificar la entrada de teclado de manera asíncrona
  std::thread inputThread(checkKeyPress, std::ref(stop));

  while (!stop.load()) {
    std::cout << *lattice_ptr << std::endl;
    lattice_ptr->nextGeneration();
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
  }
  // Esperar a que el hilo de entrada termine
  inputThread.join();


  lattice_ptr = nullptr;
  delete lattice_ptr;
  return 0;
}