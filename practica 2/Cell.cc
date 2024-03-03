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

  // crar a los 8 vecinos
  Cell Neightbour1 = Lattice[Position{getPosition().x - 1, getPosition().y - 1}];
  Cell Neightbour2 = Lattice[Position{getPosition().x - 1, getPosition().y}];
  Cell Neightbour3 = Lattice[Position{getPosition().x - 1, getPosition().y + 1}];
  Cell Neightbour4 = Lattice[Position{getPosition().x, getPosition().y - 1}];
  Cell Neightbour5 = Lattice[Position{getPosition().x, getPosition().y + 1}];
  Cell Neightbour6 = Lattice[Position{getPosition().x + 1, getPosition().y - 1}];
  Cell Neightbour7 = Lattice[Position{getPosition().x + 1, getPosition().y}];
  Cell Neightbour8 = Lattice[Position{getPosition().x + 1, getPosition().y + 1}];

  //colocar el calculo de la siguiente generacion
  int alive = Neightbour1.getState() + Neightbour2.getState() + Neightbour3.getState() + Neightbour4.getState() + Neightbour5.getState() + Neightbour6.getState() + Neightbour7.getState() + Neightbour8.getState();


  //si la celda esta viva y hay 2 o 3 vecinas vivas, sigue viva , si no pasa a estado muerto
  if (getState() == 1) {
    if (alive == 2 || alive == 3) {
      this->nextValue = 1;
    } else {
      this->nextValue = 0;
    }
  } else if(getState() == 0){
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
    os << "-";
  } else if (cell.getState() == 1) {
    os << "X";
  }
  return os;
}