#include "Lattice.h"

#include "Cell.h"

Lattice::Lattice(const int& size, const int& b, const int& v) {
  // this->size = size;
  // std::vector<Cell> row;
  // for (int i = 0; i < size; i++) {
  //   Position position = {i};
  //   State state = {false};
  //   Cell cell = Cell(position, state);
  //   row.push_back(cell);
  // }
  // this->cells = row;
}

Lattice::~Lattice() {}

const Cell& Lattice::getCell(const Position& position) const {
  return this->cells[position.x];
}

void Lattice::nextGeneration() { // no muy seguro de que esta miedra funciona, pero es una primera prueba
  //recorrer todas las celdas y calcular su proximo estado
  for(int i = 0; i < size; i++){
    Position actual = {i};
    Cell actualCell = getCell(actual);
    actualCell.nextState(*this);
  }

  //actualizar todas las celdas  
  for(int i = 0; i < size; i++){
    Position actual = {i};
    Cell actualCell = getCell(actual);
    actualCell.updateState();
  }

  
  return;
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