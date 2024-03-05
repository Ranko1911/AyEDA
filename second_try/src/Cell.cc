#include "../include/Cell.h"

// Path: src/Cell.cc

//constructor y destructor
Cell::~Cell() {
  delete &position;
}

//metodos de acceso
Position& Cell::getPosition() const {
  return position;
}

int Cell::getState() const {
  return value;
}

//metodos de modificación
void Cell::setPosition(const Position& p) {
  position = p;
}

void Cell::setValue(int& v) {
  value = v;
}

//método de evolución
void Cell::updateState() {
  value = nextValue;
}

//sobrecarga de operadores
std::ostream& operator<<(std::ostream& os, const Cell& c) {
  c.display(os);
  return os;
}

std::ostream& Cell::display(std::ostream& os) const {
    if (getState() == 0) {
    os << "-";
  } else if (getState() == 1) {
    os << "X";
  }
  return os;
}
