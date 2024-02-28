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
  Position position;
  int value;
  int nextValue;
 public:
  Cell(Position , const int);
  ~Cell();
  Position getPosition() const;
  void setPosition(const Position& );
  int getState() const;
  void setState(int );
  int nextState(const Lattice&);
  void updateState();
  friend std::ostream& operator<<(std::ostream& os, const Cell& cell);
};

class CellACE : public Cell {
 public:
  CellACE(Position , const int);
  ~CellACE();
};

class CellACE110 : public CellACE {
 public:
  CellACE110(Position , const int);
  ~CellACE110();
};

class CellACE30 : public CellACE {
 public:
  CellACE30(Position , const int);
  ~CellACE30();
};

class CellLife : public Cell {
 public:
  CellLife(Position , const int);
  ~CellLife();
};

class CellLife23_3 : public CellLife {
 public:
  CellLife23_3(Position , const int);
  ~CellLife23_3();
};

class CellLife51_346 : public CellLife {
 public:
  CellLife51_346(Position , const int);
  ~CellLife51_346();
};