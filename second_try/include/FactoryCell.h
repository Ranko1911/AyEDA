#pragma once

#include <iostream>
#include <vector>

#include "Cell.h"
#include "CellACE.h"
#include "CellLife.h"
#include "Position.h"

class FactoryCell {
 public:
  // Método creador de células
  virtual Cell* createCell(const Position&, const int&) const = 0;
};

// Replicar para cada tipo de célula
class FactoryCellACE110 : public FactoryCell {
 public:
  Cell* createCell(const Position& p, const int& s) const {
    return new CellACE110(p, s);
  }
};