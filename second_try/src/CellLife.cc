
#include <iostream>

#include "Cell.h"
#include "CellLife.h"

// Path: src/CellLife.cc

// nextState d CellLife110
void CellLife23_3::nextState(const Lattice& l) {

    // vecinos de la modificacion
  CellLife23_3 Neightbour1 = l[getPosition()[0] - 1][ getPosition()[1] - 1]; //done
  CellLife23_3 Neightbour2 = l[getPosition()[0] - 1][ getPosition()[1]];  //done 
  CellLife23_3 Neightbour3 = l[getPosition()[0] - 1][ getPosition()[1] + 1]; //done
  CellLife23_3 Neightbour4 = l[getPosition()[0]][ getPosition()[1] + 1]; //done 
  CellLife23_3 Neightbour5 = l[getPosition()[0] + 1][ getPosition()[1] + 1]; //done 
  CellLife23_3 Neightbour6 = l[getPosition()[0] + 1][ getPosition()[1]]; //done
  CellLife23_3 Neightbour7 = l[getPosition()[0] + 1][ getPosition()[1] - 1];  //done
  CellLife23_3 Neightbour8 = l[getPosition()[0]][ getPosition()[1] - 1]; //done

  int alive = Neightbour1.getState() + Neightbour2.getState() + Neightbour3.getState() + Neightbour4.getState() + Neightbour5.getState() + Neightbour6.getState() + Neightbour7.getState() + Neightbour8.getState();

  if (getState() == 1) {
    if (alive == 2 || alive == 3) {
      this->nextValue = 1;
    } else {
      this->nextValue = 0;
    }
  } else if (getState() == 0) {
    // si la celda esta muerta y hay 3 vecinas vivas, pasa a estado viva
    if (alive == 3) {
      this->nextValue = 1;
    } else {
      this->nextValue = 0;
    }
  }
}

// nextState d CellLife30
void CellLife51_364::nextState(const Lattice& l) {
  // vecinos de la modificacion
  CellLife51_364 Neightbour1 = l[getPosition()[0] - 1][ getPosition()[1] - 1]; //done
  CellLife51_364 Neightbour2 = l[getPosition()[0] - 1][ getPosition()[1]];  //done 
  CellLife51_364 Neightbour3 = l[getPosition()[0] - 1][ getPosition()[1] + 1]; //done
  CellLife51_364 Neightbour4 = l[getPosition()[0]][ getPosition()[1] + 1]; //done 
  CellLife51_364 Neightbour5 = l[getPosition()[0] + 1][ getPosition()[1] + 1]; //done 
  CellLife51_364 Neightbour6 = l[getPosition()[0] + 1][ getPosition()[1]]; //done
  CellLife51_364 Neightbour7 = l[getPosition()[0] + 1][ getPosition()[1] - 1];  //done
  CellLife51_364 Neightbour8 = l[getPosition()[0]][ getPosition()[1] - 1]; //done

  int alive = Neightbour1.getState() + Neightbour2.getState() + Neightbour3.getState() + Neightbour4.getState() + Neightbour5.getState() + Neightbour6.getState() + Neightbour7.getState() + Neightbour8.getState();

  if (getState() == 1) {
    if (alive == 5 || alive == 1) {
      this->nextValue = 1;
    } else {
      this->nextValue = 0;
    }
  } else if (this->getState() == 0) {
    // si la celda esta muerta y hay 3, 4 o 6 vecinas vivas, pasa a estado viva
    if (alive == 3 || alive == 4 || alive == 6) {
      this->nextValue = 1;
    } else {
      this->nextValue = 0;
    }
  }
}