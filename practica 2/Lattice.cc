#include "Lattice.h"

#include "Cell.h"

Lattice::Lattice(const int& b, const int& v, const std::string& file_name) {
  this->b = b;
  this->v = v;
  this->file_name = file_name;

  std::vector<std::string> lineas;

  std::ifstream archivo(file_name);

  if (!archivo.is_open()) {
    std::cerr << "Error al abrir el archivo." << std::endl;
    return;
  }

  std::string linea;
  while (std::getline(archivo, linea)) {
    lineas.push_back(linea);
  }

  archivo.close();

  // imprimr el contenido del archivo
  // std::cout << "Contenido del archivo: " << std::endl;
  // for (int i = 0; i < lineas.size(); i++) {
  //   for (int j = 0; j < lineas[i].size(); j++) {
  //     std::cout << lineas[i][j];
  //   }
  //   std::cout << std::endl;
  // }
  // std::cout << std::endl;

  // // resize de cells para que tenga el mismo tamaño que el archivo
  // cells.resize(lineas.size());
  // for (int i = 0; i < lineas.size(); i++) {
  //   cells[i].resize(lineas[i].size());
  // }

  // primera linea es las dimensiones
  std::string dimensiones = lineas[0];
  // std::cout << "dimensiones: " << dimensiones << std::endl;

  // separar el string lineas[1] en dos strings
  // std::cout << "Lineas[1]:"<< lineas[1] << std::endl;
  std::string size_N_str = lineas[1].substr(0, lineas[1].find(" "));
  // std::cout << "size_N_str: " << size_N_str << std::endl;
  this->size_N = std::stoi(size_N_str);
  std::string size_M_str = lineas[1].substr(lineas[1].find(" ") + 1);
  // std::cout << "size_M_str: " << size_M_str << std::endl;
  this->size_M = std::stoi(size_M_str);

  // this->size_N = lineas.size();
  // this->size_M = 0;

  // // buscar el mayor tamaño de las lineas y asignarlo a size_N
  // for (int i = 0; i < lineas.size(); i++) {
  //   if (lineas[i].size() > this->size_M) {
  //     this->size_M = lineas[i].size();
  //     // std::cout << "Mayor tamaño: " << this->size_M << std::endl;
  //   }
  // }

  // std::cout << "size_N: " << this->size_N << " size_M: " << this->size_M
  //           << std::endl;

  // rellenar las lineas que no están completas con celdas vacias
  for (int i = 2; i < lineas.size(); i++) {
    // std::cout << "lineas[" << i << "].size(): " << lineas[i].size() <<
    // std::endl;
    for (int j = lineas[i].size(); j < this->size_M; j++) {
      // std::cout << "Rellenar con 0" << std::endl;
      lineas[i].push_back(' ');
    }
  }

  // imprimir lineas
  std::cout << "Contenido de lineas: " << std::endl;
  for (int i = 0; i < lineas.size(); i++) {
    for (int j = 0; j < lineas[i].size(); j++) {
      std::cout << lineas[i][j];
    }
    std::cout << std::endl;
  }

  // resize de cells para que tenga el mismo tamaño que el archivo
  cells.resize(this->size_N);
  // std::cout << "cells.size(): " << cells.size() << std::endl;
  for (int i = 0; i < this->size_N; i++) {
    cells[i].resize(this->size_M);
    // std::cout << "cells[" << i << "].size(): " << cells[i].size() <<
    // std::endl;
  }

  // asignar el estado de las celdas
  for (int i = 2; i < lineas.size(); i++) {
    for (int j = 0; j < this->size_M; j++) {
      Position pos = {i - 2, j};
      // std::cout << "lineas[" << i << "][" << j << "]: " << lineas[i][j] << "
      // --- " << "cells[" << i - 2 << "][" << j << "]: " << cells[i - 2][j] <<
      // " --- " << "Pos: " << pos.x << "," << pos.y << std::endl; std::cout <<
      // i - 2 << "," << j << " ";
      if (lineas[i][j] == ' ') {
        cells[i - 2][j] = new Cell(pos, 0);
        // std::cout << "cells[" << i - 2 << "][" << j << "]: " << *cells[i -
        // 2][j] << std::endl;
      } else if (lineas[i][j] == 'X') {
        cells[i - 2][j] = new Cell(pos, 1);
        // std::cout << "cells[" << i - 2 << "][" << j << "]: " << *cells[i -
        // 2][j] << std::endl;
      }
    }
    // std::cout << std::endl;
  }

  // imprimir cells
  // std::cout << "Contenido de cells: " << std::endl;
  // for (int i = 0; i < this->size_N; i++) {
  //   for (int j = 0; j < this->size_M; j++) {
  //     std::cout << *cells[i][j];
  //   }
  //   std::cout << std::endl;
  // }

  // imprimir this
  // std::cout << "Contenido de cells: " << std::endl;
  // std::cout << *this << std::endl;
}

Lattice::Lattice(const int& b, const int& v, const int& size_N,
                 const int& size_M) {
  this->b = b;
  this->v = v;
  this->size_M = size_M;
  this->size_N = size_N;

  cells.resize(size_M);
  // dos bucles que ponen todas las Cell en valor 0
  for (int i = 0; i < size_M; i++) {
    for (int j = 0; j < size_N; j++) {
      Position pos = {i, j};
      // std::cout << "pos: " << pos.x << "," << pos.y << std::endl;
      cells[i].push_back(new Cell(pos, 0));
      // std::cout << "celda: " << cells[i][j] << std::endl;
    }
  }
  std::cout << "Intrduzca cuantas celdas desea poner en estado 1: ";
  int n;
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    int x, y;
    std::cout << "Introduzca la coordenada x: ";
    std::cin >> x;
    std::cout << "Introduzca la coordenada y: ";
    std::cin >> y;
    Position pos = {x, y};
    this->setCell(pos, 1);
  }
}

Lattice::~Lattice() {
  for (int i = 0; i < size_M; i++) {
    for (int j = 0; j < size_N; j++) {
      delete cells[i][j];
    }
  }
  cells.clear();
}

const Cell& Lattice::getCell(const Position& x) const {
  //  return *cells[x];
  Position temporal = {x.x, x.y};  // x, y
  Cell* VIVA = new Cell(temporal, 1);
  Cell* MUERTA = new Cell(temporal, 0);

  // codigo de las diferentes fronteras
  if (b == 1) {  // frontera peridica b = 1
    if (temporal.x < 0) {
      temporal.x = size_N - 1;
    } else if (temporal.x >= size_N) {
      temporal.x = 0;
    }
    if (temporal.y < 0) {
      temporal.y = size_M - 1;
    } else if (temporal.y >= size_M) {
      temporal.y = 0;
    }
  } else if (b == 0 && v == 0) {  // frontera abierta fria b = 0 v = 0
    if (temporal.x < 0 || temporal.x >= size_N || temporal.y < 0 ||
        temporal.y >= size_M) {
      return *MUERTA;
    }
  } else if (b == 0 && v == 1) {  // frontera abierta caliente b = 0 v = 1
    if (temporal.x < 0 || temporal.x >= size_N || temporal.y < 0 ||
        temporal.y >= size_M) {
      return *VIVA;
    }
  } else if (b == 2) {  // no frontera b = 2
    if (temporal.x < 0) {
      return *MUERTA;
    } else if (temporal.x >= size_N) {
      return *MUERTA;
    }
    if (temporal.y < 0) {
      return *MUERTA;
    } else if (temporal.y >= size_M) {
      return *MUERTA;
    }
  }

  return *cells[temporal.x][temporal.y];
}

Position Lattice::getSize() const {
  Position size = {size_N, size_M};
  return size;
}

int Lattice::getB() const { return this->b; }

int Lattice::getV() const { return this->v; }

void Lattice::nextGeneration() {
  // std::cout << "nextGeneration" << std::endl;
  Position size = getSize();
  // std::cout << "Size: " << size.x << "x" << size.y << std::endl;
  vivas = Population();
  // std::cout << "Poblacion: " << vivas << std::endl;

  // calcular el siguiente estado de todas las celdas
  for (int i = 0; i < size.x; i++) {
    for (int j = 0; j < size.y; j++) {
      cells[i][j]->nextState(*this);
    }
  }

  // std::cout << "nextState satisfactorio " << std::endl;

  // actualizar todas las celdas
  for (int i = 0; i < size.x; i++) {
    for (int j = 0; j < size.y; j++) {
      cells[i][j]->updateState();
    }
  }

  // std::cout << "updateState satisfactorio " << std::endl;

  // llamar la funcion que modifica el tamaño de la matriz si b vale 2
  if (b == 2) {
    // std::cout << "Aumentar tamaño" << std::endl;
    increaseSize();
  }

  return;
}

// std::ostream& operator<<(std::ostream& os, const Lattice& lattice) {
//   // // limpiar la pantalla aqui o en el main?
//   // Position size = lattice.getSize();
//   // for (int i = 0; i < size.x; i++) {
//   //   for (int j = 0; j < size.y; j++) {
//   //     os << *lattice.cells[i][j] ;  // << "(" << i << "," << j << ") "
//   //     // os << "[ " << i << "," << j << " ]";
//   //     // os << "[" << lattice.cells[i][j]->getPosition().x << "," << lattice.cells[i][j]->getPosition().y << "]";
//   //   }
//   //   os << std::endl;
//   // }
//   // return os;
  
//   // llamar al metodo display de cada celda
//   Position size = lattice.getSize();

// }

Cell& Lattice::operator[](const Position& pos) const {
  // return *cells[pos.x][pos.y];
  // return this->getCell(pos);

  // usar el metodo getCell para obtener la celda
  return *const_cast<Cell*>(&getCell(pos));
}

int Lattice::Population() {
  int population = 0;
  Position size = getSize();
  for (int i = 0; i < size.x; i++) {
    for (int j = 0; j < size.y; j++) {
      population += cells[i][j]->getState();
    }
  }
  return population;
}

void Lattice::saveToFile(const std::string& file_name) {
  //usar el operador << para imprimir el contenido de cells en un archivo
  std::ofstream archivo(file_name);
  archivo << *this;
  archivo.close();
}

void Lattice::setCell(const Position& pos, const int& state) {
  cells[pos.x][pos.y]->setState(state);
  return;
}

void Lattice::increaseSize() {
  // revisar si hay celulas vivas en el borde derecho
  // aumentarDerecha();
  for (int i = 0; i < size_M; i++) {
    if (cells[size_N - 1][i]->getState() == 1) {
      aumentarDerecha();
      break;
    }
  }

  // std::cout << "SALIDAAAAA" << std::endl;

  // revisar si hay celulas vivas en el borde izquierdo
  // aumentarIzquierda();
  for (int i = 0; i < size_N; i++) {
    if (cells[i][0]->getState() == 1) {
      aumentarIzquierda();
      break;
    }
  }

  // revisar si hay celulas vivas en el borde superior
  // aumentarArriba();
  for (int i = 0; i < size_M; i++) {
    if (cells[0][i]->getState() == 1) {
      aumentarArriba();
      break;
    }
  }

  // comprobar si hay celulas vivas en el borde inferior
  // aumentarAbajo();
  for (int i = 0; i < size_M; i++) {
    if (cells[size_N - 1][i]->getState() == 1) {
      aumentarAbajo();
      break;
    }
  }

  return;
}

void Lattice::aumentarDerecha() {
  // imprimr el contenido de cells
  // std::cout << "Contenido de cells antes de aumentar: " << std::endl;
  // std::cout << *this << std::endl;

  // aumentar el valor de size_M
  size_M++;

  for (int i = 0; i < size_N; i++) {
    Position pos = {0, size_M - 1};
    cells[i].push_back(new Cell(pos, 0));
  }

  // imprimr el contenido de cells
  // std::cout << "Contenido de cells despues de aumentar: " << std::endl;
  // std::cout << *this << std::endl;

  // std::cout << "SALSA DE MORA" << std::endl;

  return;
}

void Lattice::aumentarAbajo() {
  // imprimr el contenido de cells
  // std::cout << "Contenido de cells antes de aumentar: " << std::endl;
  // std::cout << *this << std::endl;

  // crear un vector de celdas
  std::vector<Cell*> fila;

  // llenar en vector de celulas muertas
  for (int i = 0; i < size_M; i++) {
    Position pos = {size_N, i};
    fila.push_back(new Cell(pos, 0));
  }

  // agregar el vector de celdas muertas a cells
  cells.push_back(fila);

  // aumentar el valor de size_N
  size_N++;

  // imprimr el contenido de cells
  // std::cout << "Contenido de cells despues de aumentar: " << std::endl;
  // std::cout << *this << std::endl;

  return;
}

void Lattice::aumentarIzquierda() {
  // insertar una celula muerta en la primera columna
  // std::cout << "Insertar celdas muertas en la primera columna" << std::endl;
  for (int i = 0; i < size_N; i++) {
    Cell temp = this->getCell(Position{0, 0});
    Position pos = {0, temp.getPosition().y - 1};
    cells[i].insert(cells[i].begin(), new Cell(pos, 0));
  }

  // aumentar el valor de size_M
  // std::cout << "Aumentar el valor de size_M" << std::endl;
  size_M++;

  // recorre todas las filas y aumenta la coordenada x de cada celda
  // std::cout << "Aumentar la coordenada x de cada celda" << std::endl;
  // for (int i = 0; i < size_N; i++) {
  //   for (int j = 0; j < size_M; j++) {
  //     Position temporal = {i, j};
  //     cells[i][j]->setPosition(temporal);
  //   }
  // }
}

void Lattice::aumentarArriba() {  // hacer lo que dijo el profe de indices
                                  // negativos

  // crear un vector de celdas muertas
  std::vector<Cell*> fila;

  // llenar el vector de celdas muertas
  for (int i = 0; i < size_M; i++) {
    Cell temp = this->getCell(Position{0, 0});
    Position pos = {temp.getPosition().x - 1, i};
    fila.push_back(new Cell(pos, 0));
  }

  // insertar en el principio de cells el vector de celdas muertas
  cells.insert(cells.begin(), fila);

  // aumentar el valor de size_N
  size_N++;
}
