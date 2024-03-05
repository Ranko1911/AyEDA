#include "../include/Cell.h"
#include "../include/CellLife.h"
#include "../include/Lattice.h"
#include "../include/Position.h"
#include "../include/CellACE.h"

// constructor de CellLife23_3
// Constructor de la celda CellLife23_3
// CellLife23_3::CellLife23_3(Position& pos, const int val) : CellLife(pos, val) {
//   nextValue = 0;
// }

// nextState CellLife23_3
// Método para obtener el siguiente estado de la celda CellLife23_3
int CellLife23_3::nextState(const Lattice& lattice) {
  // nuevos vecinos

  int size_N = lattice.getSize()[0];

  // CellLife23_3 Neightbour1 = lattice[0];
  PositionDim<3> pos1(3, lattice.getSize()[01] - 1, lattice.getSize()[2] - 1);
  int Neightbour1 = lattice[pos1].getState();
  // CellLife23_3 Neightbour1 = lattice[lattice.getSize()[0] - 1][lattice.getSize()[1] - 1];

  PositionDim<3> pos2(3, lattice.getSize()[1] - 1, lattice.getSize()[2]);
  int Neightbour2 = lattice[pos2].getState();
  // CellLife23_3 Neightbour2 = lattice[lattice.getSize()[0] - 1][lattice.getSize()[1] + 0];

  PositionDim<3> pos3(3, lattice.getSize()[1] - 1, lattice.getSize()[2] + 1);
  int Neightbour3 = lattice[pos3].getState();
  // CellLife23_3 Neightbour3 = lattice[lattice.getSize()[0] - 1][lattice.getSize()[1] + 1];

  PositionDim<3> pos4(3, lattice.getSize()[1], lattice.getSize()[2] - 1);
  int Neightbour4 = lattice[pos4].getState();
  // CellLife23_3 Neightbour4 = lattice[lattice.getSize()[0] - 0][lattice.getSize()[1] - 1];

  PositionDim<3> pos5(3, lattice.getSize()[1], lattice.getSize()[2] + 1);
  int Neightbour5 = lattice[pos5].getState();
  // CellLife23_3 Neightbour5 = lattice[lattice.getSize()[0] + 0][lattice.getSize()[1] + 1];

  PositionDim<3> pos6(3, lattice.getSize()[1] + 1, lattice.getSize()[2] - 1);
  int Neightbour6 = lattice[pos6].getState();
  // CellLife23_3 Neightbour6 = lattice[lattice.getSize()[0] + 1][lattice.getSize()[1] - 1];

  PositionDim<3> pos7(3, lattice.getSize()[1] + 1, lattice.getSize()[2]);
  int Neightbour7 = lattice[pos7].getState();
  // CellLife23_3 Neightbour7 = lattice[lattice.getSize()[0] + 1][lattice.getSize()[1] - 0];

  PositionDim<3> pos8(3, lattice.getSize()[1] + 1, lattice.getSize()[2] + 1);
  int Neightbour8 = lattice[pos8].getState();
  // CellLife23_3 Neightbour8 = lattice[lattice.getSize()[0] + 1][lattice.getSize()[1] + 1];



  // colocar el calculo de la siguiente generacion
  int alive = Neightbour1 + Neightbour2 +
              Neightbour3 + Neightbour4 +
              Neightbour5 + Neightbour6 +
              Neightbour7 + Neightbour8;

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
// CellLife51_346::CellLife51_346(Position& pos, const int val) : CellLife(pos, val) {
//   nextValue = 0;
// }

// nextState CellLife51_346
// Método para obtener el siguiente estado de la celda CellLife51_346
int CellLife51_346::nextState(const Lattice& lattice) {
  //nuevos vecinos
  // CellLife51_346 Neightbour1 = lattice[lattice.getSize()[0] - 1][lattice.getSize()[1] - 1];
  PositionDim<3> pos1(3, lattice.getSize()[1] - 1, lattice.getSize()[2] - 1);
  int Neightbour1 = lattice[pos1].getState();

  // CellLife51_346 Neightbour2 = lattice[lattice.getSize()[0] - 1][lattice.getSize()[1]];
  PositionDim<3> pos2(3, lattice.getSize()[1] - 1, lattice.getSize()[2]);
  int Neightbour2 = lattice[pos2].getState();

  // CellLife51_346 Neightbour3 = lattice[lattice.getSize()[0] - 1][lattice.getSize()[1] + 1];
  PositionDim<3> pos3(3, lattice.getSize()[1] - 1, lattice.getSize()[2] + 1);
  int Neightbour3 = lattice[pos3].getState();
  // CellLife51_346 Neightbour4 = lattice[lattice.getSize()[0]][lattice.getSize()[1] - 1];
  PositionDim<3> pos4(3, lattice.getSize()[1], lattice.getSize()[2] - 1);
  int Neightbour4 = lattice[pos4].getState();
  // CellLife51_346 Neightbour5 = lattice[lattice.getSize()[0]][lattice.getSize()[1] + 1];
  PositionDim<3> pos5(3, lattice.getSize()[1], lattice.getSize()[2] + 1);
  int Neightbour5 = lattice[pos5].getState();
  // CellLife51_346 Neightbour6 = lattice[lattice.getSize()[0] + 1][lattice.getSize()[1] - 1];
  PositionDim<3> pos6(3, lattice.getSize()[1] + 1, lattice.getSize()[2] - 1);
  int Neightbour6 = lattice[pos6].getState();
  // CellLife51_346 Neightbour7 = lattice[lattice.getSize()[0] + 1][lattice.getSize()[1]];
  PositionDim<3> pos7(3, lattice.getSize()[1] + 1, lattice.getSize()[2]);
  int Neightbour7 = lattice[pos7].getState();
  // CellLife51_346 Neightbour8 = lattice[lattice.getSize()[0] + 1][lattice.getSize()[1] + 1];
  PositionDim<3> pos8(3, lattice.getSize()[1] + 1, lattice.getSize()[2] + 1);
  int Neightbour8 = lattice[pos8].getState();


  // colocar el calculo de la siguiente generacion
  int alive = Neightbour1 + Neightbour2 +
              Neightbour3 + Neightbour4 +
              Neightbour5 + Neightbour6 +
              Neightbour7 + Neightbour8;

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
