#pragma once

#include <iostream>
#include <string>

#include "Cell.h"
#include "CellACE.h"
#include "CellLife.h"
#include "Position.h"

// Clase abstracta FactoryCell
class FactoryCell {
 public:
  virtual Cell* createCell(Position&, int) = 0;
  virtual ~FactoryCell() = default;
};

class FactoryCellACE110 : public FactoryCell {
 public:
  Cell* createCell(Position& temp, int value) override { return new CellACE110(temp, value); } 
};

class FactoryCellACE30 : public FactoryCell {
 public:
  Cell* createCell(Position& temp, int value) override { return new CellACE30(temp, value); }
};

class FactoryCellLife23_3 : public FactoryCell {
 public:
  Cell* createCell(Position& temp, int value) override { return new CellLife23_3(temp, value); }
};

class FactoryCellLife51_346 : public FactoryCell {
 public:
  Cell* createCell(Position& temp, int value) override { return new CellLife51_346(temp, value); }
};
