#include "Cell.h"

#include "Lattice.h"

Cell::Cell(int position, const int value) {
  this->position = position;
  this->value = value;
  this->nextValue = 0;
}

Cell::~Cell() {}

int Cell::getState() const { return this->value; }

// void Cell::setState(int value) { this->value = value; }

int Cell::getPosition() const { return this->position; }

void Cell::setPosition(const int& position) { this->position = position; }

int Cell::nextState(const Lattice& Lattice) {
  int actual = getPosition();
  int LeftPosition = getPosition();
  int RightPosition = getPosition();

  Cell LeftNeighbour = Lattice.getCell(actual);
  Cell RightNeighbour = Lattice.getCell(actual);

  Cell LeftBorder = Lattice.getCell(actual);
  Cell RightBorder = Lattice.getCell(actual);

  //   int sum1 = actualState + RightState;
  //   int mult1 = actualState * RightState;
  //   int mult2 = LeftState * actualState * RightState;
  //   nextValue = sum1 + mult1 + mult2;
  //   nextValue = nextValue % 2;

  // int sum1 = getState() + Lattice.getCell(getPosition() + 1).getState();
  // int mult1 = getState() * Lattice.getCell(getPosition() + 1).getState();
  // int mult2 = Lattice.getCell(getPosition() - 1).getState() * getState() *
  //             Lattice.getCell(getPosition() + 1).getState();
  // nextValue = sum1 + mult1 + mult2;
  // nextValue = nextValue % 2;

  return 0;
}

void Cell::updateState() {
  this->value = this->nextValue;
  this->nextValue = 0;
}

std::ostream& operator<<(std::ostream& os, const Cell& cell) {
  if (cell.getState() == 0) {
    os << "0";
  } else if (cell.getState() == 1) {
    os << "X";
  }
  return os;
}