
#include <iostream>
#include <string>

#include "../cell/Cell.h"

class FactoryCell {
 public:
  virtual Cell* createCell() = 0;
  virtual ~FactoryCell() = default;
};

class FactoryCellACE110 : public FactoryCell {
 public:
  Cell* createCell() override { return new CellACE110(Position{0, 0}, 0); }
};

class FactoryCellACE30 : public FactoryCell {
 public:
  Cell* createCell() override { return new CellACE30(Position{0, 0}, 0); }
};

class FactoryCellLife23_3 : public FactoryCell {
 public:
  Cell* createCell() override { return new CellLife23_3(Position{0, 0}, 0); }
};

class FactoryCellLife51_346 : public FactoryCell {
 public:
  Cell* createCell() override { return new CellLife51_346(Position{0, 0}, 0); }
};
