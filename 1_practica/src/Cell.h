#pragma once

#include <iostream>
#include "Lattice.h"

struct Position {
  int x;
};

struct State {
  int value;
};

class Cell {
 private:
  Position position;
  State state;

 public:
  Cell(const Position&, const State&);
  ~Cell();
  Position getPosition() const;
  State getState() const;
  void setState(const State&);
  int nextState(const Lattice&);
  void updateState();
};

