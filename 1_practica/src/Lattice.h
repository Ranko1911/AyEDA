#pragma once

#include <iostream>
#include <array>

class Cell;

class Lattice {
  private:
    int size;
    // array de tamaño size de celdas
    std::array<Cell, 1> cells;
  public:
    Lattice(const int&);
    ~Lattice();	
    const Cell& getCell(const Position&) const;
    void nextGeneration(); // update function
    friend std::ostream& operator<<(std::ostream&, const Lattice&);
};