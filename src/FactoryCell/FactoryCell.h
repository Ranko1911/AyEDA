
#include <iostream>
#include <string>

#include "../cell/Cell.h"
#include "../Position/Position.h"

// Clase abstracta FactoryCell
template <typename PositionType>
class FactoryCell {
 public:
  virtual Cell* createCell(PositionType, int) = 0;
  virtual ~FactoryCell() = default;
};

template <typename PositionType>
class FactoryCellACE110 : public FactoryCell {
 public:
  Cell* createCell(PositionType temp, int value) override { return new CellACE110(temp, value); } // DUDA: el override ayuda o es un estorbo?
};

template <typename PositionType>
class FactoryCellACE30 : public FactoryCell {
 public:
  Cell* createCell(PositionType temp, int value) override { return new CellACE30(temp, value); }
};

template <typename PositionType>
class FactoryCellLife23_3 : public FactoryCell {
 public:
  Cell* createCell(PositionType temp, int value) override { return new CellLife23_3(temp, value); }
};

template <typename PositionType>
class FactoryCellLife51_346 : public FactoryCell {
 public:
  Cell* createCell(PositionType temp, int value) override { return new CellLife51_346(temp, value); }
};
