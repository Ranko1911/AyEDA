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

  // calcular mi siguiente estado (el de la cell actual)
  getState().nextValue = getState().value + RightNeighbour.getState().value + getState().value * RightNeighbour.getState().value + LeftNeighbour.getState().value * getState().value * RightNeighbour.getState().value;
  getState().nextValue = getState().nextValue % 2;
  return getState().nextValue; 
}

void Cell::updateState() {
  State newState = {getState().nextValue, 0};
  setState(newState);
}

