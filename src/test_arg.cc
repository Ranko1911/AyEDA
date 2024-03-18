#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype> // Para isdigit()

// Función para verificar si una cadena representa un número entero válido
bool isInteger(const std::string& str) {
    if (str.empty()) return false;
    for (char c : str) {
        if (!std::isdigit(c)) return false;
    }
    return true;
}

struct Options {
    int tableSize = -1;
    std::string hashFunction;
    std::string hashTechnique;
    int blockSize = -1;
    std::string explorationFunction;
};

void printUsage() {
    std::cout << "Usage: program_name -ts <table_size> -fd <hash_function> -hash <open|close> [-bs <block_size> -fe <exploration_function>]\n";
}

Options parseArgs(int argc, char* argv[]) {
    Options options;

    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg == "-ts" && i + 1 < argc) {
            if (isInteger(argv[i+1])) {
                options.tableSize = std::stoi(argv[++i]);
            } else {
                std::cerr << "Error: Invalid table size argument.\n";
                printUsage();
                exit(1);
            }
        } else if (arg == "-fd" && i + 1 < argc) {
            options.hashFunction = argv[++i];
        } else if (arg == "-hash" && i + 1 < argc) {
            options.hashTechnique = argv[++i];
        } else if (arg == "-bs" && i + 1 < argc) {
            if (isInteger(argv[i+1])) {
                options.blockSize = std::stoi(argv[++i]);
            } else {
                std::cerr << "Error: Invalid block size argument.\n";
                printUsage();
                exit(1);
            }
        } else if (arg == "-fe" && i + 1 < argc) {
            options.explorationFunction = argv[++i];
        } else {
            std::cerr << "Error: Unknown option or missing argument: " << arg << std::endl;
            printUsage();
            exit(1);
        }
    }

    if (options.tableSize == -1 || options.hashFunction.empty() || options.hashTechnique.empty()) {
        std::cerr << "Error: Missing required arguments.\n";
        printUsage();
        exit(1);
    }

    if (options.hashTechnique == "close" && (options.blockSize == -1 || options.explorationFunction.empty())) {
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
    if (options.hashTechnique == "close") {
        std::cout << "Block Size: " << options.blockSize << std::endl;
        std::cout << "Exploration Function: " << options.explorationFunction << std::endl;
    }

    return 0;
}