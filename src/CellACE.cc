#include "../include/Cell.h"
#include "../include/CellACE.h"
#include "../include/Lattice.h"
#include "../include/Position.h"

// constructor de CellACE110
// Constructor de la celda ACE110
// CellACE110::CellACE110(Position& pos, const int val) : CellACE(pos, val) {
//   nextValue = 0;
// }

// nextState de CellLifeACE110
// Método para obtener el siguiente estado de la celda ACE110
int CellACE110::nextState(const Lattice& lattice) {
  Position& pos = getPosition();
  int pos01 = pos[0] + 1;
  PositionDim<2> pos1(2, pos01, pos[1]);
  int sum1 = getState() + lattice[pos1].getState();

  int pos11 = pos[0] - 1;
  PositionDim<2> pos2(2, pos11, pos[1]);
  int mult1 = getState() * lattice[pos2].getState();

  int pos21 = pos[1] + 1;
  PositionDim<2> pos3(2, pos11, pos21);
  int mult2 = lattice[pos2].getState() * getState() * lattice[pos3].getState();

  // int sum1 = getState() + lattice[getPosition()[0] + 1].getState();
  // int mult1 = getState() * lattice[getPosition()[0] + 1].getState();
  // int mult2 = lattice[getPosition()[0] - 1].getState() * getState() *
  //             lattice[getPosition()[1] + 1].getState();
  nextValue = sum1 + mult1 + mult2;
  nextValue = nextValue % 2;
  return 0;
}

// constructor de CellACE30
// CellACE30::CellACE30(Position& pos, const int val) : CellACE(pos, val) {}

// nextState ACE30
// Método para obtener el siguiente estado de la celda ACE30
int CellACE30::nextState(const Lattice& lattice) {
  Position& pos = getPosition();
  int pos01 = pos[0] + 1;
  PositionDim<2> pos1(2, pos01, pos[1]);
  int sum1 = getState() + lattice[pos1].getState();

  int pos11 = pos[0] - 1;
  PositionDim<2> pos2(2, pos11, pos[1]);
  int mult1 = getState() * lattice[pos2].getState();
  
  // int sum1 = getState() + lattice[getPosition()[0] - 1].getState() +
  //            lattice[getPosition()[0] + 1].getState();
  // int mult1 = getState() * lattice[getPosition()[0] + 1].getState();
  nextValue = mult1 + sum1;
  nextValue = nextValue % 2;
  return 0;
}