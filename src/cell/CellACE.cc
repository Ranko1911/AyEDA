#include "Cell.h"
#include "CellACE.h"


// nextState de CellLifeACE110
// Método para obtener el siguiente estado de la celda ACE110
template <typename PositionType, typename Lattice>
int CellACE110<PositionType, Lattice>::nextState(const Lattice& lattice) {
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
template <typename PositionType, typename Lattice>
int CellACE30<PositionType, Lattice>::nextState(const Lattice& lattice) {
  int sum1 = getState() + Lattice.getCell(getPosition() - 1).getState() +
             Lattice.getCell(getPosition() + 1).getState();
  int mult1 = getState() * Lattice.getCell(getPosition() + 1).getState();
  nextValue = mult1 + sum1;
  nextValue = nextValue % 2;
  return 0
}