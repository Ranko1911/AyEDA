#pragma once

#include "Lattice.h"

// -------------------- BASE  --------------------------- //


// getB de la clase template Lattice
template <typename PositionType, typename Cell, typename FactoryCell>
int Lattice<PositionType, Cell, FactoryCell>::getB() const {
  return b;
}

// getV de la clase template Lattice
template <typename PositionType, typename Cell, typename FactoryCell>
int Lattice<PositionType, Cell, FactoryCell>::getV() const {
  return v;
}

// -------------------- 1D --------------------------- //

// constructor de la clase template Lattice1D con entrada por fichero
template <typename PositionType, typename Cell, typename FactoryCell>
Lattice1D<PositionType, Cell, FactoryCell>::Lattice1D(const int& b, const int& v,
                                                      const std::string& file_name, const FactoryCell& factory)
    : Lattice<PositionType>(b, v, file_name) {
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

  //imprimr el contenido del archivo
  // std::cout << "Contenido del archivo: " << std::endl;
  // for (int i = 0; i < lineas.size(); i++) {
  //   for (int j = 0; j < lineas[i].size(); j++) {
  //     std::cout << lineas[i][j];
  //   }
  // }
  // std::cout << std::endl;

  this->size = lineas[0].size();

  for (int pos = 0; pos < lineas[0].size(); pos++) {
    if (lineas[0][pos] == '0') {
      Cell *c = factory.create(pos, 0);
      cells.push_back(*c);
      // std::cout << "cero" << std::endl;
    } else if (lineas[0][pos] == '1') {
      Cell *c = factory.create(pos, 1);
      cells.push_back(*c);
      // std::cout << "uno" << std::endl;
    }
  }

  //imprimir cells, funciona
  // std::cout << "Contenido de cells: " << std::endl;
  // for (int i = 0; i < cells.size(); i++) {
  //   std::cout << *cells[i];
  // }
  // std::cout << std::endl;
}

// constructor de la clase template Lattice1D con entrada por tamaño
// se que no es necesario la parte de usar el constructor de la clase base
// pero lo pongo por si a caso
template <typename PositionType, typename Cell, typename FactoryCell>
Lattice1D<PositionType, Cell, FactoryCell>::Lattice1D(const int& b, const int& v,
                                                      const int& size_N, const int& size_M, const FactoryCell& factory)
    : Lattice<PositionType>(b, v, size_N, size_M) {
this->b = b;
  this->v = v;
  this->size = size;

  int pos = 0;
  for (pos = 0; pos < (size / 2); pos++) {
    Cell *c = factory.create(pos, 0);
    cells.push_back(*c);
  }

  Cell *d = factory.create(pos, 1);
  cells.push_back(*d);
  // pos++;

  for (pos = pos + 1; pos < size; pos++) {
    Cell *c = factory.create(pos, 0);
    cells.push_back(*c);
  }
}

// nextGeneration de la clase template Lattice1D
template <typename PositionType, typename Cell, typename FactoryCell>
void Lattice1D<PositionType, Cell, FactoryCell>::nextGeneration() {
  PositionType size = this->getSize();

  this->vivas = Population();

  //bucle para nextStates
  for (int i = 0; i < size; i++) {
    cells[i].nextState(*this);
  }

  //bucle para updateStates
  for (int i = 0; i < size; i++) {
    cells[i].updateState();
  }

}

// saveToFile de la clase template Lattice1D
template <typename PositionType, typename Cell, typename FactoryCell>
void Lattice1D<PositionType, Cell, FactoryCell>::saveToFile(const std::string& file_name) {
  std::ofstream archivo(file_name);
  if (!archivo.is_open()) {
    std::cerr << "Error al abrir el archivo." << std::endl;
    return;
  }
  for (int i = 0; i < cells.size(); i++) {
    archivo << cells[i]->getState();
  }
  archivo.close();
}

// population de la clase template Lattice1D
template <typename PositionType, typename Cell, typename FactoryCell>
int Lattice1D<PositionType, Cell, FactoryCell>::Population() {
  int population = 0;
  for (int i = 0; i < cells.size(); i++) {
    population += cells[i]->getState();
  }
  return population;
}

//destructor de la clase template Lattice1D
template <typename PositionType, typename Cell, typename FactoryCell>
Lattice1D<PositionType, Cell, FactoryCell>::~Lattice1D() {
  for (Cell* cell : cells) {
    delete cell;
  }
  cells.clear();
}

//getsize de la clase template Lattice1D
template <typename PositionType, typename Cell, typename FactoryCell>
PositionType Lattice1D<PositionType, Cell, FactoryCell>::getSize() const {
  return this-> size;
}

// operator<< de la clase template Lattice1D
template <typename PositionType, typename Cell, typename FactoryCell>
std::ostream& operator<<(std::ostream& os, const Lattice1D<PositionType, Cell, FactoryCell>& lattice) {
  for (int i = 0; i < lattice.size; i++) {
    os << *lattice.cells[i];
  }
  return os;
}

//nextGeneration de la clase template Lattice1D_open usando el de la clase Lattice1D 
template <typename PositionType, typename Cell, typename FactoryCell>
void Lattice1D_open<PositionType, Cell, FactoryCell>::nextGeneration() {
  Lattice1D<PositionType, Cell, FactoryCell>::nextGeneration();
}

// getCell de la clase template Lattice1D_open
template <typename PositionType, typename Cell, typename FactoryCell>
Cell& Lattice1D_open<PositionType, Cell, FactoryCell>::operator[](const PositionType& pos) const {
Cell* VIVA = factory.create(pos, 1);
  Cell* MUERTA = factory.create(pos, 0);
  int x = pos[0];
  int v = this->v;
  if (v == 0) {
    // std::cout << "open cold" << std::endl;
    if (x < 0) {
      return *MUERTA;
    } else if (x > size - 1) {
      return *MUERTA;
    } else {
      return *cells[x];
    }
  } else if (v == 1) {
    // std::cout << "open hot" << std::endl;
    if (x < 0) {
      return *VIVA;
    } else if (x > size - 1) {
      return *VIVA;
    } else {
      return *cells[x];
    }
  }
  return *cells[x];
}

// getCell de la clase template Lattice1D_periodic
template <typename PositionType, typename Cell, typename FactoryCell>
Cell& Lattice1D_periodic<PositionType, Cell, FactoryCell>::operator[](const PositionType& pos) const {
Cell* VIVA = factory.create(pos, 1);
  Cell* MUERTA = factory.create(pos, 0);
  int x = pos[0];
  int v = this->v;
  if (v == 0) {
    // std::cout << "periodic cold" << std::endl;
    if (x < 0) {
      return *cells[size + x];
    } else if (x > size - 1) {
      return *cells[x - size];
    } else {
      return *cells[x];
    }
  } else if (v == 1) {
    // std::cout << "periodic hot" << std::endl;
    if (x < 0) {
      return *cells[size + x];
    } else if (x > size - 1) {
      return *cells[x - size];
    } else {
      return *cells[x];
    }
  }
  return *cells[x];
}



// -------------------- 2D --------------------------- //


// constructor de la clase template Lattice2D por fichero
template <typename PositionType, typename Cell, typename FactoryCell>
Lattice2D<PositionType, Cell, FactoryCell>::Lattice2D(const int& b, const int& v,
                                                      const std::string& file_name, const FactoryCell& factory)
    : Lattice<PositionType>(b, v, file_name) {
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
        Cell *c = factory.create(pos, 0);
        cells[i - 2][j] = *c;
        // std::cout << "cells[" << i - 2 << "][" << j << "]: " << *cells[i -
        // 2][j] << std::endl;
      } else if (lineas[i][j] == 'X') {
        Cell *c = factory.create(pos, 1);
        cells[i - 2][j] = *c;
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

// constructor de la clase template Lattice2d por tamaño
template <typename PositionType, typename Cell, typename FactoryCell>
Lattice2D<PositionType, Cell, FactoryCell>::Lattice2D(const int& b, const int& v,
                                                      const int& size_N, const int& size_M, const FactoryCell& factory)
    : Lattice<PositionType>(b, v, size_N, size_M) {
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
      Cell *c = factory.create(pos, 0);
      cells[i].push_back(*c);
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

// destructor de la clase template Lattice2D
template <typename PositionType, typename Cell, typename FactoryCell>
Lattice2D<PositionType, Cell, FactoryCell>::~Lattice2D() {
  for (int i = 0; i < size_M; i++) {
    for (int j = 0; j < size_N; j++) {
      delete cells[i][j];
    }
  }
  cells.clear();
}

// getsize de la clase template Lattice2D
template <typename PositionType, typename Cell, typename FactoryCell>
PositionType Lattice2D<PositionType, Cell, FactoryCell>::getSize() const {
  Position pos = {size_N, size_M};
  return pos;
}

// population de la clase template Lattice2D
template <typename PositionType, typename Cell, typename FactoryCell>
int Lattice2D<PositionType, Cell, FactoryCell>::Population() {
  int population = 0;
  for (int i = 0; i < size_M; i++) {
    for (int j = 0; j < size_N; j++) {
      population += cells[i][j]->getState();
    }
  }
  return population;
}

// saveToFile de la clase template Lattice2D
template <typename PositionType, typename Cell, typename FactoryCell>
void Lattice2D<PositionType, Cell, FactoryCell>::saveToFile(const std::string& file_name) {
  std::ofstream archivo(file_name);
  if (!archivo.is_open()) {
    std::cerr << "Error al abrir el archivo." << std::endl;
    return;
  }
  archivo << size_N << " " << size_M << std::endl;
  for (int i = 0; i < size_M; i++) {
    for (int j = 0; j < size_N; j++) {
      archivo << cells[i][j]->getState();
    }
    archivo << std::endl;
  }
  archivo.close();
}

// operador<< de la clase template Lattice2D
template <typename PositionType, typename Cell, typename FactoryCell>
std::ostream& operator<<(std::ostream& os, const Lattice2D<PositionType, Cell, FactoryCell>& lattice) {
  for (int i = 0; i < lattice.size_M; i++) {
    for (int j = 0; j < lattice.size_N; j++) {
      os << *lattice.cells[i][j];
    }
    os << std::endl;
  }
  return os;
}

// nextGeneration de la clase template Lattice2D_reflective
template <typename PositionType, typename Cell, typename FactoryCell>
void Lattice2D_reflective<PositionType, Cell, FactoryCell>::nextGeneration() {
  std::vector<std::vector<Cell*>> new_cells;
  for (int i = 0; i < size_M; i++) {
    std::vector<Cell*> row;
    for (int j = 0; j < size_N; j++) {
      row.push_back(cells[i][j]->nextGeneration(cells, i, j));
    }
    new_cells.push_back(row);
  }
  cells = new_cells;
}














