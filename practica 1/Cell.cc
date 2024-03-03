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

  if (Lattice.getB() == 1) {  // Periodic
    // vecino izq
    LeftPosition = actual - 1;
    if (LeftPosition < 0) {
      LeftPosition = Lattice.getSize() - 1;
    }
    LeftNeighbour = Lattice.getCell(LeftPosition);
    // vecino der
    // actual = getPosition();
    RightPosition = actual + 1;
    if (RightPosition > Lattice.getSize() - 1) {
      RightPosition = 0;
    }
    RightNeighbour = Lattice.getCell(RightPosition);
    // calcular mi siguiente estado
    int RightState = RightNeighbour.getState();
    int LeftState = LeftNeighbour.getState();
    int actualState = getState();
    int sum1 = actualState + RightState;
    int mult1 = actualState * RightState;
    int mult2 = LeftState * actualState * RightState;
    nextValue = sum1 + mult1 + mult2;
    nextValue = nextValue % 2;
    // devolver mi siguiente estado
    return nextValue;
  } else if (Lattice.getB() == 0) {  // Open

    // std::cout << "open" << std::endl;  // place holder
    if (Lattice.getV() == 0) {
      RightBorder.value = 0;
      LeftBorder.value = 0;
    } else {
      RightBorder.value = 1;
      LeftBorder.value = 1;
    }

    // vecino open izq
    LeftPosition = actual - 1;
    if (LeftPosition < 0) {
      LeftPosition = Lattice.getSize() - 1;
      LeftNeighbour = LeftBorder;
    } else {
      LeftNeighbour = Lattice.getCell(LeftPosition);
    }

    // vecino open der
    RightPosition = actual + 1;
    if (RightPosition > Lattice.getSize() - 1) {
      RightPosition = 0;
      RightNeighbour = RightBorder;

    } else {
      RightNeighbour = Lattice.getCell(RightPosition);
    }

    // calcular mi siguiente estado
    int RightState = RightNeighbour.getState();
    int LeftState = LeftNeighbour.getState();
    int actualState = getState();
    int sum1 = actualState + RightState;
    int mult1 = actualState * RightState;
    int mult2 = LeftState * actualState * RightState;
    nextValue = sum1 + mult1 + mult2;
    nextValue = nextValue % 2;
    // devolver mi siguiente estado
    return nextValue;
  }

  return 0;
}

void Cell::updateState() {
  this->value = this->nextValue;
  this->nextValue = 0;

}

std::ostream& operator<<(std::ostream& os, const Cell& cell) {
  if (cell.getState() == 0) {
    os << "0";
  } else if(cell.getState() == 1){
    os << "X";
  }
  return os;
}