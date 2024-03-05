
#include "../include/Position.h"

// // Constructor por defecto
// template <int Dim , class Coordinate_t >
// PositionDim<Dim, Coordinate_t>::PositionDim() {
//   for (int d = 0; d < Dim; d++) {
//     Coordinates[d] = 0;
//   }
// }

// // Constructor con lista variable de parámetros
// template <int Dim , class Coordinate_t >
// PositionDim<Dim, Coordinate_t>::PositionDim(int sz, ...) {
//   va_list vl;
//   va_start(vl, sz);
//   for (int d = 0; d < Dim; d++) {
//     Coordinates[d] = va_arg(vl, Coor_t);
//   }
//   va_end(vl);
// }

// // Operador de acceso
// template <int Dim , class Coordinate_t >
// Coor_t PositionDim<Dim, Coordinate_t>::operator[](unsigned int i) const {
//   return Coordinates[i];
// }