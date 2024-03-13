
#include "../include/Cell.h"
#include "../include/Lattice1D.h"
#include "../include/Position.h"
#include <fstream>
#include <iostream>

// constructor de la clase template Lattice1D con entrada por fichero
Lattice1D::Lattice1D(const int& b, const int& v, const std::string& file_name,
                     FactoryCell& factory)
    : Lattice(b, v, file_name, factory), size(PositionDim<2>(0,0)), factory(factory){
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
  std::cout << "Contenido del archivo: " << std::endl;
  for (int i = 0; i < lineas.size(); i++) {
    for (int j = 0; j < lineas[i].size(); j++) {
      std::cout << lineas[i][j];
    }
  }
  std::cout << std::endl;
  // this->size[0] = 1;
  // this->size[1] = lineas[0].size();

  PositionDim<2> pos1(1, lineas[0].size());
  this->size = pos1;
  // std::cout << "lineas[0].size(): " << lineas[0].size() << std::endl;
  std::cout << "size[0]: " << this->size[0] << std::endl;
  // this->size = pos;

  for (int pos = 0; pos < size[0]; pos++) {
    // std::cout << "pos: " << pos << std::endl;
    if (lineas[0][pos] == ' ') {
      PositionDim<2> pos1(pos);
      Cell* c = factory.createCell(pos1, 0);
      cells.push_back(c);
      // cells[pos] = c;
      // std::cout << "cero" << std::endl;
    } else if (lineas[0][pos] == 'X') {
      PositionDim<2> pos1(2, pos);
      Cell* c = factory.createCell(pos1, 1);
      cells.push_back(c);
      // cells[pos] = c;
      // std::cout << "uno" << std::endl;
    }
  }

  // // imprimir cells, funciona
  // std::cout << "Contenido de cells: " << cells.size() << std::endl;
  // for (int i = 0; i < cells.size(); i++) {
  //   std::cout << *cells[i];
  // }
  // std::cout << std::endl;

  //imprimir cells con display
  std::cout << "Contenido de cells: " << std::endl;
  display(std::cout, *this);
}

// constructor de la clase template Lattice1D con entrada por tamaño
// se que no es necesario la parte de usar el constructor de la clase base
// pero lo pongo por si a caso
Lattice1D::Lattice1D(const int& b, const int& v, const Position& size,
                     FactoryCell& factory)
    : Lattice1D(b, v, size, factory){
  this->b = b;
  this->v = v;
  this->size = size[1];

  int pos = 0;
  for (pos = 0; pos < (size[1] / 2); pos++) {
    PositionDim<2> pos1(pos, 0);
    Cell* c = factory.createCell(pos1, 0);
    // cells.push_back(*c);
    cells[pos] = c;
  }

  PositionDim<2> pos1(pos, 0);
  Cell* d = factory.createCell(pos1, 1);
  // Cell* d = factory.create(pos, 1);
  cells.push_back(d);
  // cells[pos] = d;
  // pos++;

  for (pos = pos + 1; pos < size[1]; pos++) {
    // Cell* c = factory.create(pos, 0);
    // cells.push_back(*c);
    PositionDim<2> pos1(pos, 0);
    Cell* c = factory.createCell(pos1, 0);
    // cells[pos] = c;
    cells.push_back(c);
  }
}

// nextGeneration de la clase template Lattice1D
void Lattice1D::nextGeneration() {
  this->vivas = Population();

  // bucle para nextStates
  std::cout << "Antes de nextStates" << std::endl;
  std::cout << "size[1]: " << size[0] << std::endl;
  for (int i = 0; i < size[1]; i++) {
    cells[i]->nextState(*this);
    std::cout << "cell: " << *cells[i] << std::endl;
  }
  std::cout << "Despues de nextStates" << std::endl;

  std::cout << "Antes de updateStates" << std::endl;
  // bucle para updateStates
  for (int i = 0; i < size[1]; i++) {
    cells[i]->updateState();
  }
  std::cout << "Despues de updateStates" << std::endl;
}

// saveToFile de la clase template Lattice1D
void Lattice1D::saveToFile(const std::string& file_name) {
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
int Lattice1D::Population() {
  int population = 0;
  for (int i = 0; i < cells.size(); i++) {
    population += cells[i]->getState();
  }
  return population;
}

// destructor de la clase template Lattice1D
Lattice1D::~Lattice1D() {
  for (Cell* cell : cells) {
    delete cell;
  }
  cells.clear();
}

// getsize de la clase template Lattice1D
Position& Lattice1D::getSize() const {
  PositionDim<2> pos_var = size;
  return pos_var;
}

// operador << de la clase template Lattice1D
std::ostream& operator<<(std::ostream& os, Lattice1D& lattice) {
  // lamada a display de la clase template Lattice1D
  // lattice.display(os, lattice);
  std::cout << "entrando en operator<< de Lattice1D" << std::endl;
  std::vector<Cell*> cells_ = lattice.getCells();
  std::cout << "cells_.size(): " << cells_.size() << std::endl;
  for (int i = 0; i < lattice.getSize()[1]; i++) {
    os << *cells_[i];
  }
  return os;
}

// metodo display de la clase template Lattice1D
// realmente solo es una llama a operator<<
std::ostream& Lattice1D::display(std::ostream& os, const Lattice1D& lattice) {
  std::cout << "entrando en display de Lattice1D" << std::endl;
  Position& pos_var = lattice.getSize();
  for (int i = 0; i < lattice.size[0]; i++) {
    // std::cout << "i: " << i << std::endl;
    os << *lattice.cells[i];
  }
  os << std::endl;
  return os;
}

// operator[] de la clase template Lattice1D_open
Cell& Lattice1D_open::operator[](const Position& pos) const {
  int x = pos[0];
  return *const_cast<Cell*>(&getCell(pos));
}

// operator[] de la clase template Lattice1D_open
Cell& Lattice1D_periodic::operator[](const Position& pos) const {
  return *const_cast<Cell*>(&getCell(pos));
}

// getCell de la clase template Lattice1D_periodic
Cell& Lattice1D_open::getCell(const Position& pos) const {
  PositionDim<2> pos1(2, 0);
  Cell* VIVA = factory.createCell(pos1, 1);
  Cell* MUERTA = factory.createCell(pos1, 0);

  if (pos[1] < 0) {
    return *cells[size[1] - 1];
  } else if (pos[1] > size[1] - 1) {
    return *cells[0];
  } else {
    return *cells[pos[1]];
  }

  return *cells[pos[1]];
}

// operator[] de la clase template Lattice1D_periodic

Cell& Lattice1D_periodic::getCell(const Position& pos) const {
  PositionDim<2> pos1(2, 0);
  Cell* VIVA = factory.createCell(pos1, 1);
  Cell* MUERTA = factory.createCell(pos1, 0);
  int x = pos[0];
  int v = this->v;
  if (v == 0) {
    // std::cout << "periodic cold" << std::endl;
    if (x < 0) {
      return *cells[size[1] + x];
    } else if (x > size[1] - 1) {
      return *cells[x - size[1]];
    } else {
      return *cells[x];
    }
  } else if (v == 1) {
    // std::cout << "periodic hot" << std::endl;
    if (x < 0) {
      return *cells[size[1] + x];
    } else if (x > size[1] - 1) {
      return *cells[x - size[1]];
    } else {
      return *cells[x];
    }
  }
  return *cells[x];
}