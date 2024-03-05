#pragma once

#include <vector>

#include "Cell.h"
#include "FactoryCell.h"
#include "Position.h"

class Lattice {
 protected:
  int b;
  int v = 0;
  const FactoryCell& factory;
  std::string file_name = "";
  const Position& size;

 public:
  // cosntructores y destructor
  Lattice(const int& b, const int& v, const std::string& file_name,
          const FactoryCell& factory)
      : b(b), v(v), file_name(file_name), factory(factory), size(PositionDim<2>(0, 0)) {}
  Lattice(const int& b, const int& v, const FactoryCell& factory,
          const Position& size)
      : b(b), v(v), factory(factory), size(size) {}
  virtual ~Lattice() {}

  //meodos de clase
  virtual const Cell& getCell(const Position&) const = 0;
  virtual void nextGeneration() = 0;
  virtual int Population() = 0;
  virtual void saveToFile(const std::string& file_name) = 0;

  // metodos de acceso
  virtual Cell& Lattice::operator[](const Position&) const = 0;

  // metodos de modificacion
  virtual std::ostream& Lattice::display(std::ostream&) = 0;
  friend std::ostream& operator<<(std::ostream&, const Lattice&);
};