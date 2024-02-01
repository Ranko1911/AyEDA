#include <iostream>
#include <string>

#include "Cell.h"
#include "Lattice.h"

int main(int argc, char** argv) {
  // Lattice lattice = Lattice(10);
  // std::cout << lattice << std::endl;
  // std::cout << "argc:    " << argc << std::endl;

  // No argumetos, no programa
  if (argc == 1) {
    std::cout << "No arguments" << std::endl;
    return 1;
  }

  // Imprimir los argumentos con sus indices
  // for (int i = 0; i < argc; i++) {
  //   std::cout << "argv[" << i << "]: " << argv[i] << std::endl;
  // }

  std::string file_name;
  int size;
  std::string b;
  int v;

  // Recorrer los argumentos y hacer algo con ellos
  for (int i = 1; i < argc; i++) {
    std::string arg = argv[i];
    if (arg == "-h" || arg == "--help") {
      std::cout << "Usage: " << argv[0] << "-size 'int' -b < b [v] > [options]"
                << "b -> open || periodic"
                << "v -> 1 || 0" << std::endl;
      std::cout << "Options:" << std::endl;
      std::cout << "  -h, --help\t\tShow this help message and exit"
                << std::endl;
      std::cout << "  -f, --file\t\tFile of start state" << std::endl;
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
        }
        b = b_arg;
        i++;
        std::cout << "B: " << b << std::endl;
      } else {
        std::cout << "Error: Not Valid option for b first argument: " << b_arg
                  << std::endl;
        return 1;
      }
      // std::cout << " i: " << i << " argc: " << argc << std::endl;
      // std::cout << " argv[i + 1]: " << argv[i + 1] << std::endl;
      if (argc > i) {
        v = std::stoi(argv[i + 1]);
        i++;
        std::cout << "V: " << v << std::endl;
      }
    } else {
      std::cout << "Unknown argument: " << argc << std::endl;
      return 1;
    }
  }

  Lattice lattice = Lattice(size);
  std::cout << lattice << std::endl;

  lattice.nextGeneration();

  std::cout << lattice << std::endl;

  return 0;
}