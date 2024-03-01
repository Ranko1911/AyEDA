
#include "Cell.h"

#include "../Lattice/Lattice.h"

// int getstate() const
// Método para obtener el estado de la celda
template <typename PositionType>
int Cell<PositionType>::getState() const {
  return value;
}

// void setState(int val)
// Método para establecer el estado de la celda
template <typename PositionType>
void Cell<PositionType>::setState(int val) {
  value = val;
}

// void setPosition(const PositionType& pos)
// Método para establecer la posición de la celda
template <typename PositionType>
void Cell<PositionType>::setPosition(const PositionType& pos) {
  position = pos;
}

// PositionType getPosition() const
// Método para obtener la posición de la celda
template <typename PositionType>
PositionType Cell<PositionType>::getPosition() const {
  return position;
}

// void updateState()
// Método para actualizar el estado de la celda
template <typename PositionType>
void Cell<PositionType>::updateState() {
  value = nextValue;
}

// friend std::ostream& operator<<(std::ostream& os, const Cell<PositionType>&
// cell) Sobrecarga del operador de inserción como función amiga
template <typename PositionType>
std::ostream& operator<<(std::ostream& os, const Cell<PositionType>& cell) {
  if (cell.getState() == 0) {
    os << "-";
  } else if (cell.getState() == 1) {
    os << "X";
  }
  return os;
}

// nextState de CellLifeACE110
// Método para obtener el siguiente estado de la celda ACE110
template <typename PositionType>
int CellACE110<PositionType>::nextState(const Lattice& lattice) {
  int sum1 = getState() + Lattice.getCell(getPosition() + 1).getState();
  int mult1 = getState() * Lattice.getCell(getPosition() + 1).getState();
  int mult2 = Lattice.getCell(getPosition() - 1).getState() * getState() *
              Lattice.getCell(getPosition() + 1).getState();
  nextValue = sum1 + mult1 + mult2;
  nextValue = nextValue % 2;
  return 0;
}

// nextState ACE30
// Método para obtener el siguiente estado de la celda ACE30
template <typename PositionType>
int CellACE30<PositionType>::nextState(const Lattice& lattice) {
  int sum1 = getState() + Lattice.getCell(getPosition() - 1).getState() +
             Lattice.getCell(getPosition() + 1).getState();
  int mult1 = getState() * Lattice.getCell(getPosition() + 1).getState();
  nextValue = mult1 + sum1;
  nextValue = nextValue % 2;
  return 0;
}

// nextState CellLife23_3
// Método para obtener el siguiente estado de la celda CellLife23_3
template <typename PositionType>
int CellLife23_3<PositionType>::nextState(const Lattice& lattice) {
  // crar a los 8 vecinos
  Cell Neightbour1 =
      Lattice[Position{getPosition().x - 1, getPosition().y - 1}];
  Cell Neightbour2 = Lattice[Position{getPosition().x - 1, getPosition().y}];
  Cell Neightbour3 =
      Lattice[Position{getPosition().x - 1, getPosition().y + 1}];
  Cell Neightbour4 = Lattice[Position{getPosition().x, getPosition().y - 1}];
  Cell Neightbour5 = Lattice[Position{getPosition().x, getPosition().y + 1}];
  Cell Neightbour6 =
      Lattice[Position{getPosition().x + 1, getPosition().y - 1}];
  Cell Neightbour7 = Lattice[Position{getPosition().x + 1, getPosition().y}];
  Cell Neightbour8 =
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
template <typename PositionType>
int CellLife51_346<PositionType>::nextState(const Lattice& lattice) {
  // crar a los 8 vecinos
  Cell Neightbour1 =
      Lattice[Position{getPosition().x - 1, getPosition().y - 1}];
  Cell Neightbour2 = Lattice[Position{getPosition().x - 1, getPosition().y}];
  Cell Neightbour3 =
      Lattice[Position{getPosition().x - 1, getPosition().y + 1}];
  Cell Neightbour4 = Lattice[Position{getPosition().x, getPosition().y - 1}];
  Cell Neightbour5 = Lattice[Position{getPosition().x, getPosition().y + 1}];
  Cell Neightbour6 =
      Lattice[Position{getPosition().x + 1, getPosition().y - 1}];
  Cell Neightbour7 = Lattice[Position{getPosition().x + 1, getPosition().y}];
  Cell Neightbour8 =
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
    } else if (getState() == 0) {
      // si la celda esta muerta y hay 3, 4 o 6 vecinas vivas, pasa a estado viva
      if (alive == 3 || alive == 4 || alive == 6) {
        this->nextValue = 1;
      } else {
        this->nextValue = 0;
      }
    }
}
