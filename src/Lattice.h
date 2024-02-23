#pragma once

#include <fstream>
#include <iostream>
#include <vector>

class Cell;
struct Position;
struct State;

class Lattice {
 private:
  int size_N;
  int size_M;
  int b;
  int v = 0;
  std::string file_name = "";
  std::vector<std::vector<Cell*>> cells;
  int vivas;

 public:
  Lattice() {}
  Lattice(const int& b, const int& v, const std::string& file_name);
  Lattice(const int& b, const int& v, const int& size_N, const int& size_M);
  ~Lattice();
  const Cell& getCell(const Position&) const;
  Position getSize() const;
  int getB() const;
  int getV() const;
  void nextGeneration();
  int Population();  // no hecha
  friend std::ostream& operator<<(std::ostream&, const Lattice&);
  Cell& operator[](const Position&) const;
  void saveToFile(const std::string& file_name);
  void setCell(const Position&, const int&);
};