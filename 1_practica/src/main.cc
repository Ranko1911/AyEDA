#include <atomic>
#include <chrono>  // sleep_for
#include <iostream>
#include <string>
#include <thread>  // sleep_for

#include "Cell.h"
#include "Lattice.h"

// Función para verificar la entrada de teclado de manera asíncrona
void checkKeyPress(std::atomic<bool>& stop) {
  char key;
  std::cin >> key;
  stop.store(true);
}

// Opcion periodica: ./programa -size 5 -b periodic
// Opcion open frontera caliente: ./programa -size 5 -b open 1
// Opcion open frontera fria: ./programa -size 5 -b open 0

int main(int argc, char** argv) {
  std::atomic<bool> stop(false);

  // No argumetos, no programa
  if (argc == 1) {
    std::cout << "No arguments" << std::endl;
    return 1;
  }
  std::string file_name;
  int size;
  int b;
  int v;
  // Recorrer los argumentos y hacer algo con ellos
  for (int i = 1; i < argc; i++) {
    std::string arg = argv[i];
    if (arg == "-h" || arg == "--help") {
      std::cout << "Usage: " << argv[0]
                << " -size 'int' -b < b [v] > [options] \n"
                << "b -> open (v -> 1 || 0 ) || periodic " << std::endl;
      std::cout << "Options:" << std::endl;
      std::cout << "  -h, --help\t\tShow this help message and exit"
                << std::endl;
      std::cout << "  -f, --file\t\tFile of start state" << std::endl;
      return 0;
    } else if (arg == "-init") {
      file_name = argv[i + 1];
      i++;
      std::cout << "File Name: " << file_name << std::endl;
    } else if (arg == "-size") {
      size = std::stoi(argv[i + 1]);
      i++;
      std::cout << "Size: " << size << std::endl;
    } else if (arg == "-b") {
      std::string b_arg = argv[i + 1];
      if (b_arg == "periodic" || b_arg == "open") {
        if (b_arg == "periodic") {
          b_arg = "1";
        } else if (b_arg == "open") {
          b_arg = "0";
          if (argc > i) {
            v = std::stoi(argv[i + 1]);
            i++;
            std::cout << "V: " << v << std::endl;
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

  Lattice lattice = Lattice(size, b, v);
  int i = 0;

  // Crear un hilo para verificar la entrada de teclado de manera asíncrona
  std::thread inputThread(checkKeyPress, std::ref(stop));

  while (!stop.load()) {
    // std::cout << "Generation: " << i << std::endl;
    std::cout << lattice << std::endl;
    lattice.nextGeneration();
    std::this_thread::sleep_for(std::chrono::seconds(2));
    i++;
  }
  // Esperar a que el hilo de entrada termine
  inputThread.join();

  return 0;
}