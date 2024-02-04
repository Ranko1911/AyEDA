#pragma once

#include <iostream>
#include <vector>

class Cell;
struct Position;
struct State;

class Lattice {
  private:
    int size;
    int b;
    int v;
    std::string file_name;
    std::vector<Cell> cells;
  public:
    Lattice(const int& size, const int& b, const int& v = 0, const std::string& file_name = "standard.txt");
    ~Lattice();	
    const Cell& getCell(const Position&) const;
    void setCell(const Position&, const State&);
    int getSize() const;
    int getB() const;
    int getV() const;
    void nextGeneration(); // update function
    friend std::ostream& operator<<(std::ostream&, const Lattice&);
};