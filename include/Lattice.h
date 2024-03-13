
#pragma once

#include <fstream>
#include <iostream>
#include <vector>

#include "Position.h"
#include "Cell.h"
#include "FactoryCell.h"
// class Position

// Clase plantilla Lattice
class Lattice {
  protected:
    int b;
    int v = 0;
    std::string file_name = "";
    const FactoryCell& factory;
    const Position& size;  // columnas
  
    // std::vector<Cell*>
 public:
  Lattice() = default;
  Lattice(const int& b, const int& v, const std::string& file_name, const FactoryCell& factory) : b(b), v(v), file_name(file_name), factory(factory), size(PositionDim<2>(0,0)) {}
  Lattice(const int& b, const int& v, const Position& size, const FactoryCell& factory): b(b), v(v), size(size), factory(factory) {}
  ~Lattice() {}  // Destructor virtual para permitir la herencia

  // Métodos virtuales puros
  virtual Position& getSize() const = 0;
  // int getB() const; // Hecho, no comprobado
  // int getV() const; // Hecho, no comprobado
  virtual void nextGeneration() = 0;
  virtual int Population() = 0;
  virtual Cell& operator[](const Position&) const = 0;
  virtual void saveToFile(const std::string& file_name) = 0;
  virtual std::ostream& display(std::ostream&, const Lattice&) = 0;
  // friend std::ostream& operator<<(std::ostream&, const Lattice&){};
  // friend std::ostream& operator<<(std::ostream&, const Lattice&); // Hecho, no comprobado};
};
