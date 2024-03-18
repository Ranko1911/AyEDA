#include <cctype>  // Para isdigit()
#include <iostream>

#include "../include/hashtable.h"
#include "../include/nif.h"

// Función para verificar si un carácter es un dígito
bool isDigit(char c) { return std::isdigit(static_cast<unsigned char>(c)); }

struct Options {
  int tableSize = -1;
  char hashFunction;
  char hashTechnique;
  int blockSize = -1;
  char explorationFunction;
};

void printUsage() {
  std::cout
      << "Usage: program_name -ts <table_size> -fd <hash_function> -hash "
         "<1|2> [-bs <block_size> -fe <exploration_function>]\n"
         "Options:\n"
         "-ts <table_size>: Size of the hash table.\n"
         "-fd <hash_function>: Hash function to use. 1 for Modulo, 2 for "
         "Pseudoaleatoria, 3 for Suma.\n"
         "-hash <1|2>: Hash technique to use. 1 for open, 2 "
         "for close.\n"
         "-bs <block_size>: Block size to use for close hashing.\n"
         "-fe <exploration_function>: Exploration function to use for "
         "close hashing. 1 for Lineal, 2 for Doble, 3 for Cuadratica, 4 "
         "for Redispersion.\n";
}

Options parseArgs(int argc, char *argv[]) {
  Options options;

  for (int i = 1; i < argc; ++i) {
    char *arg = argv[i];
    if (arg[0] == '-' && arg[1] != '\0' && i + 1 < argc) {
      if (arg[1] == 't' && arg[2] == 's') {
        if (isDigit(argv[i + 1][0])) {
          options.tableSize = std::stoi(argv[++i]);
        } else {
          std::cerr << "Error: Invalid table size argument.\n";
          printUsage();
          exit(1);
        }
      } else if (arg[1] == 'f' && arg[2] == 'd') {
        options.hashFunction = argv[++i][0];
      } else if (arg[1] == 'h') {
        options.hashTechnique = argv[++i][0];
      } else if (arg[1] == 'b' && arg[2] == 's') {
        if (isDigit(argv[i + 1][0])) {
          options.blockSize = std::stoi(argv[++i]);
        } else {
          std::cerr << "Error: Invalid block size argument.\n";
          printUsage();
          exit(1);
        }
      } else if (arg[1] == 'f' && arg[2] == 'e') {
        options.explorationFunction = argv[++i][0];
      } else {
        std::cerr << "Error: Unknown option or missing argument: " << arg
                  << std::endl;
        printUsage();
        exit(1);
      }
    }
  }

  if (options.tableSize == -1 || options.hashFunction == '\0' ||
      options.hashTechnique == '\0') {
    std::cerr << "Error: Missing required arguments.\n";
    printUsage();
    exit(1);
  }

  if (options.hashTechnique == 'c' &&
      (options.blockSize == -1 || options.explorationFunction == '\0')) {
    std::cerr << "Error: Missing required arguments for closed hashing.\n";
    printUsage();
    exit(1);
  }

  return options;
}

DispersionFunction<nif> *dispersion_menu(unsigned table_size, Options options) {
  char option;
  option = options.hashFunction;
  while (true) {
    // std::cout << " Seleccione el tipo de dispersion que se quiera utilizar"
    //           << std::endl
    //           << "1. Modulo" << std::endl
    //           << "2. Pseudoaleatoria" << std::endl
    //           << "3. Suma" << std::endl;
    // std::cin >> option;
    switch (option) {
      case '1': {
        DispersionFunction<nif> *fd =
            new DispersionFunctionModule<nif>(table_size);
        return fd;
        break;
      }

      case '2': {
        DispersionFunction<nif> *fd =
            new DispersionFunctionPseudorandom<nif>(table_size);
        return fd;
        break;
      }

      case '3': {
        DispersionFunction<nif> *fd =
            new DispersionFunctionSum<nif>(table_size);
        return fd;
        break;
      }

      default:
        std::cout << "funcion Distribucion: Opcion Incorrecta."
                  << std::endl;
                  exit(1);
        break;
    }
  }
}

ExplorationFunction<nif> *exploration_menu(DispersionFunction<nif> *fd, Options options) {
  char option;
  option = options.explorationFunction;
  while (true) {
    // std::cout << " Seleccione el tipo de exploracion que se quiera utilizar"
    //           << std::endl
    //           << "1. Lineal" << std::endl
    //           << "2. Doble" << std::endl
    //           << "3. Cuadratica" << std::endl
    //           << "4. Redispersion" << std::endl;
    // std::cin >> option;
    switch (option) {
      case '1': {
        ExplorationFunction<nif> *fe = new ExplorationFunctionLineal<nif>;
        return fe;
        break;
      }

      case '2': {
        ExplorationFunction<nif> *fe = new ExplorationFunctionDouble<nif>(fd);
        return fe;
        break;
      }

      case '3': {
        ExplorationFunction<nif> *fe = new ExplorationFunctionQuadratic<nif>;
        return fe;
        break;
      }

      case '4': {
        ExplorationFunction<nif> *fe =
            new ExplorationFunctionRedispersion<nif>(fd);
        return fe;
        break;
      }

      default:
        std::cout << "Funcion Exploracion: Opcion Incorrecta."
                  << std::endl;
                  exit(1);
        break;
    }
  }
}

int main(int argc, char* argv[]) {
  Options options = parseArgs(argc, argv);

  std::cout << "Table Size: " << options.tableSize << std::endl;
  std::cout << "Hash Function: " << options.hashFunction << std::endl;
  std::cout << "Hash Technique: " << options.hashTechnique << std::endl;
  if (options.hashTechnique == '2') {
    std::cout << "Block Size: " << options.blockSize << std::endl;
    std::cout << "Exploration Function: " << options.explorationFunction
              << std::endl;
  }

  HashTable<nif> ht;
  bool is_table_created = false;
  char option, dispersion_type;
  unsigned table_size, block_size;
  nif key;

  table_size = options.tableSize;
  block_size = options.blockSize;
  dispersion_type = options.hashTechnique;

  while (true) {
    std::cout << "1.Crear Tabla" << std::endl;
    std::cout << "2.Buscar en la tabla" << std::endl
              << "3.Insertar en la tabla" << std::endl
              << "Q.Salir" << std::endl;
    std::cin >> option;
    switch (option) {
      case '1':
        while (true) {
          if (is_table_created) {
            break;
          }

          switch (dispersion_type) {
            case '1': {
              DispersionFunction<nif> *dispersion_function =
                  dispersion_menu(table_size, options);
              HashTable<nif> hash_table(table_size, dispersion_function);
              ht = hash_table;
              is_table_created = true;
              break;
            }

            case '2': {
              DispersionFunction<nif> *dispersion_function =
                  dispersion_menu(table_size, options);
              ExplorationFunction<nif> *exploration_function =
                  exploration_menu(dispersion_function, options);
              // std::cout << "Introduzca el tamaño del bloque: " << std::endl;
              // std::cin >> block_size;
              HashTable<nif> hash_table(table_size, dispersion_function,
                                        exploration_function, block_size);
              ht = hash_table;
              is_table_created = true;
              break;
            }

            default:
              std::cout << "Tipo de Dispersion: Opcion Incorrecta."
                        << std::endl;
                        exit(1);
              break;
          }
        }
        std::cout << "Se ha creado la tabla" << std::endl;
        break;

      case '2':
        if (is_table_created) {
          std::cout << "Introduzca una clave: " << std::endl;
          std::cin >> key;
          if (ht.Search(key)) {
            std::cout << "Se ha encontrado la clave" << std::endl;
          } else {
            std::cout << "No se ha encontrado la clave" << std::endl;
          }
        }else {
          std::cout << "No se ha creado una tabla" << std::endl;
        }
        break;

      case '3':
        if (is_table_created) {
          std::cout << "Introduzca una clave: " << std::endl;
          std::cin >> key;
          // std::cout << "A" << std::endl;
          if (ht.Insert(key)) {
            // std::cout << "B" << std::endl;
            std::cout << "Se ha insertado la clave" << std::endl;
          } else {
            std::cout << "No se ha insertado la clave" << std::endl;
          }
        } else {
          std::cout << "No se ha creado una tabla" << std::endl;
        }
        break;

      case 'Q':
        return 0;
        break;

      case 'q':
        return 0;
        break;

      default:
        std::cout << "Opcion Incorrecta, vuelva a escoger otra opcion"
                  << std::endl;
        break;
    }
  }

  return 0;
}
