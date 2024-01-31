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

int nextState(const Lattice&) {
  return 0; //place holder
}

void updateState() {
  return; //place holder
}

