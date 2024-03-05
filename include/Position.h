#pragma once

#include <stdarg.h>

#include <iostream>
#include <string>


typedef int Coor_t;

class Position {
 public:
  // int x;
  // int y;
  virtual Coor_t operator[](unsigned int) const = 0;
};

// de aqui para abajo, no entiendo mucho nada

template <int Dim = 2, class Coordinate_t = int>
class PositionDim : public Position {
 private:
  Coor_t Coordinates[Dim];

 public:
  // Constructor por defecto
    // // Constructor por defecto
  PositionDim(){
    for (int d = 0; d < Dim; d++) {
      Coordinates[d] = 0;
    }
  }
  // PositionDim() {  }
  // Constructor con lista variable de parámetros
  PositionDim(int sz, ...){
    va_list vl;
    va_start(vl, sz);
    for (int d = 0; d < Dim; d++) {
      Coordinates[d] = va_arg(vl, Coor_t);
    }
    va_end(vl);
  }

  Coor_t operator[](unsigned int i) const { return Coordinates[i]; }
  // Coor_t& operator[](unsigned int i) { return Coordinates[i]; }

};



//ejemplo de uso
// PositionDim<2> p(1, 2);
// PositionDim<3> p(1, 2, 3);
