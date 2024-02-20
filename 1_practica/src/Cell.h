#pragma once

#include <iostream>
#include "Lattice.h"

class Cell {
 private:
  int position;
  int value;
  int nextValue;
 public:
  Cell(const int, const int);
  ~Cell();
  int getPosition() const;
  void setPosition(const int&);
  int getState() const;
  // void setState(int );
  int nextState(const Lattice&);
  void updateState();
  friend std::ostream& operator<<(std::ostream& os, const Cell& cell);
};

