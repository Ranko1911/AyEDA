#pragma once

#include <iostream>

class Lattice;

struct Position {
  int x;
  int y;
};

struct State {
  bool value;
};

class Cell {
 private:
  Position position;
  State state;

 public:
  Cell(const Position&, const State&);
  ~Cell();
  State getState() const;
  void setState(const State&);
  int nextState(const Lattice&);
  void updateState();
};

