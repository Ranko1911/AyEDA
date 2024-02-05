#include "Cell.h"

#include "Lattice.h"

Cell::Cell(const Position& position, const State& state) {
  this->position = position;
  this->state = state;
}

Cell::~Cell() {}

State Cell::getState() const { return this->state; }

void Cell::setState(const State& state) { this->state = state; }

Position Cell::getPosition() const { return this->position; }

void Cell::setPosition(const Position& position) { this->position = position; }

int Cell::nextState(const Lattice& Lattice) {
  Position actual = getPosition();
  Position LeftPosition = getPosition();
  Position RightPosition = getPosition();

  Cell LeftNeighbour = Lattice.getCell(actual);
  Cell RightNeighbour = Lattice.getCell(actual);

  Cell LeftBorder = Lattice.getCell(actual);
  Cell RightBorder = Lattice.getCell(actual);

  if (Lattice.getB() == 1) {  // Periodic
    // vecino izq
    LeftPosition.x = actual.x - 1;
    if (LeftPosition.x < 0) {
      LeftPosition.x = Lattice.getSize() - 1;
    }
    LeftNeighbour = Lattice.getCell(LeftPosition);
    // vecino der
    // actual = getPosition();
    RightPosition.x = actual.x + 1;
    if (RightPosition.x > Lattice.getSize() - 1) {
      RightPosition.x = 0;
    }
    RightNeighbour = Lattice.getCell(RightPosition);
    // calcular mi siguiente estado
    State RightState = RightNeighbour.getState();
    State LeftState = LeftNeighbour.getState();
    State actualState = getState();
    int sum1 = actualState.value + RightState.value;
    int mult1 = actualState.value * RightState.value;
    int mult2 = LeftState.value * actualState.value * RightState.value;
    actualState.nextValue = sum1 + mult1 + mult2;
    actualState.nextValue = actualState.nextValue % 2;
    // devolver mi siguiente estado
    return actualState.nextValue;
  } else if (Lattice.getB() == 0) {  // Open

    // std::cout << "open" << std::endl;  // place holder
    if (Lattice.getV() == 0) {
      RightBorder.state.value = 0;
      LeftBorder.state.value = 0;
    } else {
      RightBorder.state.value = 1;
      LeftBorder.state.value = 1;
    }

    // vecino open izq
    LeftPosition.x = actual.x - 1;
    if (LeftPosition.x < 0) {
      LeftPosition.x = Lattice.getSize() - 1;
      LeftNeighbour = LeftBorder;
    } else {
      LeftNeighbour = Lattice.getCell(LeftPosition);
    }

    // vecino open der
    RightPosition.x = actual.x + 1;
    if (RightPosition.x > Lattice.getSize() - 1) {
      RightPosition.x = 0;
      RightNeighbour = RightBorder;

    } else {
      RightNeighbour = Lattice.getCell(RightPosition);
    }

    // calcular mi siguiente estado
    State RightState = RightNeighbour.getState();
    State LeftState = LeftNeighbour.getState();
    State actualState = getState();
    int sum1 = actualState.value + RightState.value;
    int mult1 = actualState.value * RightState.value;
    int mult2 = LeftState.value * actualState.value * RightState.value;
    actualState.nextValue = sum1 + mult1 + mult2;
    actualState.nextValue = actualState.nextValue % 2;
    // devolver mi siguiente estado
    return actualState.nextValue;
  }

  return 0;
}

void Cell::updateState() {
  this->state.value = this->state.nextValue;
  this->state.nextValue = 0;
  // State newState = {getState().value, getState().nextValue};
  // std::cout << "newState: " << newState.value << " " << newState.nextValue <<
  // std::endl; this->setState(newState);
}