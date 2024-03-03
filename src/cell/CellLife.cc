#include "Cell.h"
#include "CellLife.h"


// nextState CellLife23_3
// Método para obtener el siguiente estado de la celda CellLife23_3
template <typename PositionType, typename Lattice>
int CellLife23_3<PositionType, Lattice>::nextState(const Lattice& lattice) {
  // crar a los 8 vecinos
  CellLife23_3 Neightbour1 =
      Lattice[Position{getPosition().x - 1, getPosition().y - 1}];
  CellLife23_3 Neightbour2 =
      Lattice[Position{getPosition().x - 1, getPosition().y}];
  CellLife23_3 Neightbour3 =
      Lattice[Position{getPosition().x - 1, getPosition().y + 1}];
  CellLife23_3 Neightbour4 =
      Lattice[Position{getPosition().x, getPosition().y - 1}];
  CellLife23_3 Neightbour5 =
      Lattice[Position{getPosition().x, getPosition().y + 1}];
  CellLife23_3 Neightbour6 =
      Lattice[Position{getPosition().x + 1, getPosition().y - 1}];
  CellLife23_3 Neightbour7 =
      Lattice[Position{getPosition().x + 1, getPosition().y}];
  CellLife23_3 Neightbour8 =
      Lattice[Position{getPosition().x + 1, getPosition().y + 1}];

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

// nextState CellLife51_346
// Método para obtener el siguiente estado de la celda CellLife51_346
template <typename PositionType, typename Lattice>
int CellLife51_346<PositionType, Lattice>::nextState(const Lattice& lattice) {
  // crar a los 8 vecinos
  CellLife51_346 Neightbour1 =
      Lattice[Position{getPosition().x - 1, getPosition().y - 1}];
  CellLife51_346 Neightbour2 =
      Lattice[Position{getPosition().x - 1, getPosition().y}];
  CellLife51_346 Neightbour3 =
      Lattice[Position{getPosition().x - 1, getPosition().y + 1}];
  CellLife51_346 Neightbour4 =
      Lattice[Position{getPosition().x, getPosition().y - 1}];
  CellLife51_346 Neightbour5 =
      Lattice[Position{getPosition().x, getPosition().y + 1}];
  CellLife51_346 Neightbour6 =
      Lattice[Position{getPosition().x + 1, getPosition().y - 1}];
  CellLife51_346 Neightbour7 =
      Lattice[Position{getPosition().x + 1, getPosition().y}];
  CellLife51_346 Neightbour8 =
      Lattice[Position{getPosition().x + 1, getPosition().y + 1}];

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
