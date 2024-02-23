#include "Cell.h"

#include "Lattice.h"

Cell::Cell(Position position, const int value) {
  this->position = position;
  this->value = value;
  this->nextValue = 0;
}

Cell::~Cell() {}

int Cell::getState() const { return this->value; }

void Cell::setState(int value) { this->value = value; }

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

  //colocar el calculo de la siguiente generacion

  // contar vecinos vivos y muertos al rededor de la celda
  int alive = 0;
  int dead = 0;

  for (int i = -1; i <= 1; i++) {
    for (int j = -1; j <= 1; j++) {
      if (i != 0 && j != 0) {
        Position new_position = {actual.x + i, actual.y + j};
        // std::cout << "depurar" << std::endl;
        Cell neighbour = Lattice.getCell(new_position);
        // std::cout << "depurar 2" << std::endl;
        if (neighbour.getState() == 1) {
          alive++;
        } else {
          dead++;
        }
      }
    }
  } 

  //si la celda esta viva y hay 2 o 3 vecinas vivas, sigue viva , si no pasa a estado muerto
  if (getState() == 1) {
    if (alive == 2 || alive == 3) {
      this->nextValue = 1;
    } else {
      this->nextValue = 0;
    }
  } else {
    //si la celda esta muerta y hay 3 vecinas vivas, pasa a estado viva
    if (alive == 3) {
      this->nextValue = 1;
    } else {
      this->nextValue = 0;
    }
  }


  return 0;
}

void Cell::updateState() {
  this->value = this->nextValue;
  this->nextValue = 0;
}

std::ostream& operator<<(std::ostream& os, const Cell& cell) {
  if (cell.getState() == 0) {
    os << " ";
  } else if (cell.getState() == 1) {
    os << "X";
  }
  return os;
}