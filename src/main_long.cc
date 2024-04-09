#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "../include/sequence.h"
#include "../include/sorting.h"

struct Options {
  int size;                   // Tamaño de la secuencia
  std::string sortingMethod;  // Método de ordenación
  std::string initMethod;     // Método de inicialización
  std::string fileName;       // Nombre del archivo de entrada
  bool trace;                 // Mostrar traza o no
};

void printHelp() {
  std::cout << "Uso: programa_principal [-size <s>] [-ord <m>] [-init <i> [f]] "
               "[-trace <y|n>] [-h]\n";
  std::cout << "Opciones:\n";
  std::cout << "  -size <s>      Especifica el tamaño de la secuencia.\n";
  std::cout << "  -ord <m>       Especifica el método de ordenación.\n";
  std::cout << "                 m=heap | quick | radix | seleccion | shell\n";
  std::cout << "  -init <i> [f]  Especifica cómo se inicializan los datos de "
               "la secuencia.\n";
  std::cout << "                 i=manual | i=random | i=file f=nombre del "
               "fichero de entrada.txt\n";
  std::cout << "  -trace <y|n>   Indica si se muestra o no la traza durante la "
               "ejecución.\n";
  std::cout << "  -h             Muestra esta ayuda.\n";
}

Options parseCommandLine(int argc, char* argv[]) {
  Options options;
  options.trace = false;  // Valor predeterminado para trace

  if (argc == 1) {
    printHelp();
    exit(0);
  }

  for (int i = 1; i < argc; ++i) {
    std::string arg = argv[i];

    if (arg == "-h") {
      printHelp();
      exit(0);
    } else if (arg == "-size") {
      if (i + 1 < argc) {
        options.size = std::stoi(argv[i + 1]);
        std::cout << "Tamaño de la secuencia: " << options.size << std::endl;
        ++i;
      }
    } else if (arg == "-ord") {
      if (i + 1 < argc) {
        // si el metodo seleccionado es diefente de "heap", "quick", "radix",
        // "seleccion" o "shell" se muestra un mensaje de error
        if (std::string(argv[i + 1]) != "heap" &&
            std::string(argv[i + 1]) != "quick" &&
            std::string(argv[i + 1]) != "radix" &&
            std::string(argv[i + 1]) != "seleccion" &&
            std::string(argv[i + 1]) != "shell") {
          std::cerr << "Método de ordenación incorrecto: " << argv[i + 1]
                    << std::endl;
          exit(1);
        }
        options.sortingMethod = argv[i + 1];
        std::cout << "Método de ordenación: " << options.sortingMethod
                  << std::endl;
        ++i;
      }
    } else if (arg == "-init") {
      if (i + 1 < argc) {
        options.initMethod = argv[i + 1];
        // si options.initMethod es diferente de "manual", "random" o "file"
        // entonces se muestra un mensaje de error
        if (options.initMethod != "manual" && options.initMethod != "random" &&
            options.initMethod != "file") {
          std::cerr << "Método de inicialización incorrecto: "
                    << options.initMethod << std::endl;
          exit(1);
        }
        std::cout << "Método de inicialización: " << options.initMethod;
        if (options.initMethod == "file" && i + 2 < argc) {
          options.fileName = argv[i + 2];
          std::cout << " (" << options.fileName << ")";
          i += 2;
        }
        std::cout << std::endl;
        ++i;
      }
    } else if (arg == "-trace") {
      if (i + 1 < argc) {
        options.trace = (argv[i + 1][0] == 'y');
        std::cout << "Mostrar traza: " << (options.trace ? "Sí" : "No")
                  << std::endl;
        ++i;
      }
    }
  }

  return options;
}

void manualInit(staticSequence<long>& sequence, int size) {
  std::cout << "Introduce los elementos de la secuencia:\n";
  int element;
  for (int i = 0; i < size; i++) {
    std::cin >> element;
    sequence.Insert(element);
    std::cout << "Elemento insertado: " << element << std::endl;
  }
}

void randomInit(staticSequence<long>& sequence, int size) {
  srand(time(nullptr));  // Initialize random seed
  for (int i = 0; i < size; i++) {
    sequence.Insert(rand() % 100);
  }
}

void fileInit(staticSequence<long>& sequence, std::string fileName) {
  std::ifstream file("files/" + fileName);  // Adjusting the file path
  if (!file.is_open()) {
    std::cerr << "No se pudo abrir el archivo " << fileName << std::endl;
    exit(1);
  }

  int n;
  while (file >> n) {
    sequence.Insert(n);
  }
}

void printSequence(const staticSequence<long>& sequence, int size) {
  std::cout << "Secuencia:\n";
  for (int i = 0; i < size; i++) {
    std::cout << sequence[i] << " ";
  }
  std::cout << std::endl;
}

int main(int argc, char* argv[]) {
  Options options = parseCommandLine(argc, argv);

  staticSequence<long> sec(options.size);  // No se usa ningún elemento ficticio

  if (options.initMethod == "random") {
    randomInit(sec, options.size);
  } else if (options.initMethod == "manual") {
    manualInit(sec, options.size);
  } else if (options.initMethod == "file") {
    fileInit(sec, options.fileName);
  }

  printSequence(sec, options.size);

  // std::cout << "Tamaño de la secuencia: " << options.size << std::endl;

  if (options.sortingMethod == "heap") {
    HeapSort<long> heap_sort;
    heap_sort.sort(sec, options.size, options.trace);
  } else if (options.sortingMethod == "quick") {
    QuickSort<long> quick_sort;
    quick_sort.sort(sec, options.size, options.trace);
  } else if (options.sortingMethod == "radix") {
    RadixSort<long> radix_sort;
    radix_sort.sort(sec, options.size, options.trace);
  } else if (options.sortingMethod == "seleccion") {
    SelectionSort<long> selection_sort;
    selection_sort.sort(sec, options.size, options.trace);
  } else if (options.sortingMethod == "shell") {
    ShellSort<long> shell_sort;
    shell_sort.sort(sec, options.size, options.trace);
  }

  std::cout << "Arreglo ordenado usando " << options.sortingMethod << "\n";
  printSequence(sec, options.size);

  return 0;
}
