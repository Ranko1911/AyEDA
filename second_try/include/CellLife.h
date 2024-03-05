#pragma once

#include <iostream>

#include "Cell.h"

class CellLife : public Cell {
 public:
  CellLife(const Position& p, const int& v) : Cell(p, v){};

  virtual void nextState(const Lattice&);
};

class CellLife23_3 : public CellLife {
 public:
  CellLife23_3(const Position& p, const int& v) : CellLife(p, v){};

  void nextState(const Lattice&);
};

class CellLife51_364 : public CellLife {
 public:
  CellLife51_364(const Position& p, const int& v) : CellLife(p, v){};

  void nextState(const Lattice&);
};