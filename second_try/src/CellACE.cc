#include "CellACE.h"

#include <iostream>

#include "Cell.h"

// Path: src/CellACE.cc

// nextState d CellACE110
void CellACE110::nextState(const Lattice& l) {
  // estos errors se debe areglar cuando se defina el operador [] n lattice
  int sum1 = getState() + l[getPosition()[0] + 1].getState();
  int mult1 = getState() * l[getPosition()[0] + 1].getState();
  int mult2 = l[getPosition()[0] - 1].getState() * getState() *
              l[getPosition()[0] + 1].getState();

  nextValue = sum1 + mult1 + mult2;
  nextValue = nextValue % 2;
}

// nextState d CellACE30
void CellACE30::nextState(const Lattice& l) {

  int sum1 = getState() + l[getPosition()[0] - 1].getState() +
             l[getPosition()[0] + 1].getState();
  int mult1 = getState() * l[getPosition()[0] + 1].getState();

  nextValue = mult1 + sum1;
  nextValue = nextValue % 2;
}