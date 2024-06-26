#include <cstdlib>  // Para std::atoi
#include <iostream>
#include <string>

// struct DATA que contiene
struct DATA {
  std::string tipoArbol;
  std::string metodo;
  std::string opcion;
  std::string nombreFichero;
};

// Declaración de funciones
void trabajarConArbol(const std::string& tipoArbol);
void introducirDatos(const std::string& metodo, const std::string& opcion = "",
                     const std::string& nombreFichero = "");
void mostrarAyuda(const std::string& nombrePrograma);

DATA inputData(int argc, char* argv[]);

int main(int argc, char* argv[]) {

  DATA data = inputData(argc, argv);

  // Ejecutar las funciones correspondientes
  trabajarConArbol(data.tipoArbol);
  introducirDatos(data.metodo, data.opcion, data.nombreFichero);

  return 0;
}

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
