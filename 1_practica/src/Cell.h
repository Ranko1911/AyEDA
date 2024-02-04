#pragma once

#include <iostream>
#include "Lattice.h"

struct Position {
  int x = 0;
};

struct State {
  int value = 0;
  int nextValue = 0;
};

class Cell {
 private:
  Position position;
  State state;

 public:
  Cell(const Position&, const State&);
  ~Cell();
  Position getPosition() const;
  void setPosition(const Position&);
  State getState() const;
  void setState(const State&);
  int nextState(const Lattice&);
  void updateState();
};

