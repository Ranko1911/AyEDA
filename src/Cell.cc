
#include "../include/Cell.h"

// int getstate() const
// Método para obtener el estado de la celda
int Cell::getState() const {
  return value;
}

// void setState(int val)
// Método para establecer el estado de la celda
void Cell::setState(int val) {
  value = val;
}

// void setPosition(const PositionType& pos)
// Método para establecer la posición de la celda
void Cell::setPosition(const Position& pos) {
  position = pos;
}

// PositionType getPosition() const
// Método para obtener la posición de la celda
Position& Cell::getPosition() const {
  return position;
}

// void updateState()
// Método para actualizar el estado de la celda
void Cell::updateState() {
  value = nextValue;
}

// friend std::ostream& operator<<(std::ostream& os, const Cell<PositionType>&
// cell) Sobrecarga del operador de inserción como función 
// realmente solo llama a la funcion display
std::ostream& operator<<(std::ostream& os,
                         const Cell& cell) {
  if (cell.getState() == 0) {
    os << " ";
  } else if (cell.getState() == 1) {
    os << "X";
  }
  return os;
}

//metodo display, que realmente es una llamada a la sobrecarga del operador <<
std::ostream& Cell::display(std::ostream& os, const Cell& cell) const {
  if (cell.getState() == 0) {
    os << " ";
  } else if (cell.getState() == 1) {
    os << "X";
  }
  return os;
}

