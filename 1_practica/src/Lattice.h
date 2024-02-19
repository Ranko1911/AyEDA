#pragma once

#include <iostream>
#include <vector>
#include <fstream>

class Cell;
struct Position;
struct State;

class Lattice {
  private:
    int size;
    int b;
    int v = 0;
    std::string file_name = "standard.txt";
    std::vector<Cell*> cells;
  public:
    // Lattice(const int& size, const int& b, const int& v = 0, const std::string& file_name = "standard.txt");
    Lattice(){}
    Lattice(const int& b, const int& v, const std::string& file_name = "standard.txt");
    Lattice(const int& b, const int& v, const int& size);
    ~Lattice();	
    const Cell& getCell(const int&) const;
    // void setCell(const int&, const int&);
    int getSize() const;
    int getB() const;
    int getV() const;
    void nextGeneration(); // update function
    friend std::ostream& operator<<(std::ostream&, const Lattice&);
    void checkBorder();
};