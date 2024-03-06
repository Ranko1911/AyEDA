#include "../include/Lattice1D.h"

// -------------Lattice1D---------------- //

//destructor
Lattice1D::~Lattice1D() {
  for (auto cell : cells) {
    delete cell;
  }
  delete size;
}

//operator []
Cell& Lattice1D::operator[](const Position& p) const {
  return *cells[p[0]];
}

//Population
int Lattice1D::Population() {
  int vivas = 0;
  for (auto cell : cells) {
    vivas += cell->getState();
  }
  return vivas;
}

// display
std::ostream& Lattice1D::display(std::ostream& os) {
  for (auto cell : cells) {
    os << *cell;
  }
  return os;
}

// operator <<
std::ostream& operator<<(std::ostream& os, Lattice1D& l) {
  return l.display(os);
}  

// saveToFile
void Lattice1D::saveToFile(const std::string& file_name) {
  std::ofstream file(file_name);
  for (auto cell : cells) {
    file << *cell;
  }
  file.close();
}

// nextGeneration
void Lattice1D::nextGeneration() {
  for (auto cell : cells) {
    cell->nextState(*this);
  }
  for (auto cell : cells) {
    cell->updateState();
  }
  return;
}

// -------------Lattice1D_open---------------- //

//destructor
Lattice1D_open::~Lattice1D_open() {
  Lattice::~Lattice();
}

//operator []
