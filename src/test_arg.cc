#include <cctype>  // Para isdigit()
#include <iostream>
#include <vector>

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

Options parseArgs(int argc, char* argv[]) {
  Options options;

  for (int i = 1; i < argc; ++i) {
    char* arg = argv[i];
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

  return 0;
}
