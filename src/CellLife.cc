#include "../include/Cell.h"
#include "../include/CellLife.h"


// constructor de CellLife23_3
// Constructor de la celda CellLife23_3
CellLife23_3::CellLife23_3(Position& pos, const int val) : CellLife(pos, val) {
  nextValue = 0;
}

// nextState CellLife23_3
// Método para obtener el siguiente estado de la celda CellLife23_3
int CellLife23_3::nextState(const Lattice& lattice) {
  // nuevos vecinos
  CellLife23_3 Neightbour1 = lattice[getPosition()[0] - 1][getPosition()[1] - 1];
  CellLife23_3 Neightbour2 = lattice[getPosition()[0] - 1][getPosition()[1]];
  CellLife23_3 Neightbour3 = lattice[getPosition()[0] - 1][getPosition()[1] + 1];
  CellLife23_3 Neightbour4 = lattice[getPosition()[0]][getPosition()[1] - 1];
  CellLife23_3 Neightbour5 = lattice[getPosition()[0]][getPosition()[1] + 1];
  CellLife23_3 Neightbour6 = lattice[getPosition()[0] + 1][getPosition()[1] - 1];
  CellLife23_3 Neightbour7 = lattice[getPosition()[0] + 1][getPosition()[1]];
  CellLife23_3 Neightbour8 = lattice[getPosition()[0] + 1][getPosition()[1] + 1];



  // colocar el calculo de la siguiente generacion
  int alive = Neightbour1.getState() + Neightbour2.getState() +
              Neightbour3.getState() + Neightbour4.getState() +
              Neightbour5.getState() + Neightbour6.getState() +
              Neightbour7.getState() + Neightbour8.getState();

  // si la celda esta viva y hay 2 o 3 vecinas vivas, sigue viva , si no pasa a
  // estado muerto
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

  return 0;
}

// constructor de CellLife51_346
// Constructor de la celda CellLife51_346
CellLife51_346::CellLife51_346(Position& pos, const int val) : CellLife(pos, val) {
  nextValue = 0;
}

// nextState CellLife51_346
// Método para obtener el siguiente estado de la celda CellLife51_346
int CellLife51_346::nextState(const Lattice& lattice) {
  //nuevos vecinos
  CellLife51_346 Neightbour1 = lattice[getPosition()[0] - 1][getPosition()[1] - 1];
  CellLife51_346 Neightbour2 = lattice[getPosition()[0] - 1][getPosition()[1]];
  CellLife51_346 Neightbour3 = lattice[getPosition()[0] - 1][getPosition()[1] + 1];
  CellLife51_346 Neightbour4 = lattice[getPosition()[0]][getPosition()[1] - 1];
  CellLife51_346 Neightbour5 = lattice[getPosition()[0]][getPosition()[1] + 1];
  CellLife51_346 Neightbour6 = lattice[getPosition()[0] + 1][getPosition()[1] - 1];
  CellLife51_346 Neightbour7 = lattice[getPosition()[0] + 1][getPosition()[1]];
  CellLife51_346 Neightbour8 = lattice[getPosition()[0] + 1][getPosition()[1] + 1];


  // colocar el calculo de la siguiente generacion
  int alive = Neightbour1.getState() + Neightbour2.getState() +
              Neightbour3.getState() + Neightbour4.getState() +
              Neightbour5.getState() + Neightbour6.getState() +
              Neightbour7.getState() + Neightbour8.getState();

  // si la celda esta viva y hay 5 o 6 vecinas vivas, sigue viva , si no pasa a
  // estado muerto
  if (getState() == 1) {
    if (alive == 5 || alive == 6) {
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
  return 0;
}
