#include "../include/Position.h"


template <int Dim, class Coordinate_t>
Coor_t PositionDim<Dim, Coordinate_t>::operator[](unsigned int i) const {
  return Coordinates[i];
}
