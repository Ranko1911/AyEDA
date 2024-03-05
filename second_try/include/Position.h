#pragma once

#include <cstdarg>
#include <iostream>

typedef int Coor_t;
class Position {
 public:
  // Operador de acceso a la i-ésima coordenada
  virtual Coor_t operator[](unsigned int) const = 0;
};

template <int Dim = 2, class Coordinate_t = int>
class PositionDim : public Position {
 private:
  Coor_t Coordinates[Dim];

 public:
  // Constructor con lista variable de parámetros
  PositionDim(int sz, ...) {
    va_list vl;
    va_start(vl, sz);
    for (int d = 0; d < Dim; d++) {
      Coordinates[d] = va_arg(vl, Coor_t);
    }
    va_end(vl);
  }
  Coor_t operator[](unsigned int) const;
};

