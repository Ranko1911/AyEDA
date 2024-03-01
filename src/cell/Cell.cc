
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

// friend std::ostream& operator<<(std::ostream& os, const Cell<PositionType>& cell)
// Sobrecarga del operador de inserción como función amiga
template <typename PositionType>
std::ostream& operator<<(std::ostream& os, const Cell<PositionType>& cell) {
  if (cell.getState() == 0) {
    os << "-";
  } else if (cell.getState() == 1) {
    os << "X";
  }
  return os;
}

// nextState ACE110
// Método para obtener el siguiente estado de la celda ACE110
template <typename PositionType>
int Cell<PositionType>::nextState(const Lattice& lattice) {
    // Implementa la lógica para obtener el siguiente estado de la celda
    // Usualmente, esto involucra asignar nextValue a 0 o 1 dependiendo de las reglas del juego
    // Devuelve 0 si la celda no cambia de estado, 1 si cambia
    return 0;
}


// nextState ACE30
// Método para obtener el siguiente estado de la celda ACE30
template <typename PositionType>
int Cell<PositionType>::nextState(const Lattice& lattice) {
    // Implementa la lógica para obtener el siguiente estado de la celda
    // Usualmente, esto involucra asignar nextValue a 0 o 1 dependiendo de las reglas del juego
    // Devuelve 0 si la celda no cambia de estado, 1 si cambia
    return 0;
}


// nextState CellLife23_3
// Método para obtener el siguiente estado de la celda CellLife23_3
template <typename PositionType>
int Cell<PositionType>::nextState(const Lattice& lattice) {
    // Implementa la lógica para obtener el siguiente estado de la celda
    // Usualmente, esto involucra asignar nextValue a 0 o 1 dependiendo de las reglas del juego
    // Devuelve 0 si la celda no cambia de estado, 1 si cambia
    return 0;
}

// nextState CellLife51_346
// Método para obtener el siguiente estado de la celda CellLife51_346
template <typename PositionType>
int Cell<PositionType>::nextState(const Lattice& lattice) {
    // Implementa la lógica para obtener el siguiente estado de la celda
    // Usualmente, esto involucra asignar nextValue a 0 o 1 dependiendo de las reglas del juego
    // Devuelve 0 si la celda no cambia de estado, 1 si cambia
    return 0;
}
