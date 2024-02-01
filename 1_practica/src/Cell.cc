#include "Cell.h"
#include "Lattice.h"

Cell::Cell(const Position& position, const State& state) {
  this->position = position;
  this->state = state;
}

Cell::~Cell() {}

State Cell::getState() const {
  return this->state;
}


void Cell::setState(const State& state) {
  this->state = state;
}

Position Cell::getPosition() const {
  return this->position;
}

int Cell::nextState(const Lattice& Lattice) {
  //obtner las vecinas
  Position actual = getPosition();
  actual.x = actual.x - 1;
  Cell LeftNeighbour= Lattice.getCell(actual);
  actual = getPosition();
  actual.x = actual.x + 1;
  Cell RightNeighbour= Lattice.getCell(actual);
  State Right = RightNeighbour.getState();
  State Left = LeftNeighbour.getState();
  State actualState = getState();

  // calcular mi siguiente estado (el de la cell actual)
  actualState.nextValue = actualState.value + Right.value + actualState.value * Right.value + Left.value * actualState.value * Right.value;
  actualState.nextValue = actualState.nextValue % 2;
  return actualState.nextValue; 
}

void Cell::updateState() {
  State newState = {getState().nextValue, 0};
  setState(newState);
}

