#pragma once

#include <iostream>
#include <vector>

class Cell;
struct Position;

class Lattice {
  private:
    int size;
    std::vector<Cell> cells;
  public:
    Lattice(const int& size, const int& b, const int& v = 0);
    ~Lattice();	
    const Cell& getCell(const Position&) const;
    void nextGeneration(); // update function
    friend std::ostream& operator<<(std::ostream&, const Lattice&);
};