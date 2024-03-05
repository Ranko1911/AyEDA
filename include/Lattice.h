
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
 public:
 Lattice() = default;
  Lattice(const int& b, const int& v, const std::string& file_name, const FactoryCell& factory);
  Lattice(const int& b, const int& v, const int& size_N, const int& size_M, const FactoryCell& factory);
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
