#include "Lattice.h"

#include "Cell.h"

Lattice::Lattice(const int& size) {
  this->size = size;
  std::vector<Cell> row;
  for (int i = 0; i < size; i++) {
    Position position = {i};
    State state = {false};
    Cell cell = Cell(position, state);
    row.push_back(cell);
  }
  this->cells = row;
}

Lattice::~Lattice() {}

const Cell& Lattice::getCell(const Position& position) const {
  return this->cells[position.x];
}

void Lattice::nextGeneration() {
  return; //place holder
}

std::ostream& operator<<(std::ostream& os, const Lattice& lattice) {
  for (int i = 0; i < lattice.size; i++) {
    if (lattice.cells[i].getState().value)
      os << "X";
    else
      os << "O";
  }
  return os;
}