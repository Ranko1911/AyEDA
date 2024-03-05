#pragma once

#include <iostream>

#include "Cell.h"

class CellACE : public Cell {
 public:
  CellACE(const Position& p, const int& v) : Cell(p, v){};

  virtual void nextState(const Lattice&);
};

class CellACE110 : public CellACE {
 public:
  CellACE110(const Position& p, const int& v) : CellACE(p, v){};

  void nextState(const Lattice&);
};

class CellACE30 : public CellACE {
 public:
  CellACE30(const Position& p, const int& v) : CellACE(p, v){};

  void nextState(const Lattice&);
};