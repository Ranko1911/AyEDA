#pragma once

#include <iostream>

#include "../Lattice/Lattice.h"
#include "../Position/Position.h"

// struct Position {
//   int x;
//   int y;
// };

class Cell {
 private:
  // Position position;
  PositionDim<2> position;
  int value;
  int nextValue;

 public:
  Cell(const PositionDim<2>&, const int);
  ~Cell();
  PositionDim<2> getPosition() const;
  void setPosition(const PositionDim<2>&);
  int getState() const;
  void setState(int);
  int nextState(const Lattice&);
  void updateState();
  friend std::ostream& operator<<(std::ostream& os, const Cell& cell);
};

class CellACE : public Cell {
 public:
  CellACE(PositionDim<2>, const int);
  ~CellACE();
};

class CellACE110 : public CellACE {
 public:
  CellACE110(PositionDim<2>, const int);
  ~CellACE110();
};

class CellACE30 : public CellACE {
 public:
  CellACE30(PositionDim<2>, const int);
  ~CellACE30();
};

class CellLife : public Cell {
 public:
  CellLife(PositionDim<2>, const int);
  ~CellLife();
};

class CellLife23_3 : public CellLife {
 public:
  CellLife23_3(PositionDim<2>, const int);
  ~CellLife23_3();
};

class CellLife51_346 : public CellLife {
 public:
  CellLife51_346(PositionDim<2>, const int);
  ~CellLife51_346();
};