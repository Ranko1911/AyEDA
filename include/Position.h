#pragma once

#include <stdarg.h>

#include <iostream>
#include <string>


typedef int Coor_t;
class Position
{
public:
  // Operator of access to the coordinates
  // virtual Coor_t operator[](unsigned int) const = 0; me da error
  virtual Coor_t operator[](unsigned int) const { return 0; }
};

// Derived class PositionDim
template <int Dim = 2, class Coordinate_t = int>
class PositionDim : public Position
{
private:
  Coor_t Coordinates[Dim];

public:
  // Constructor con lista variable de parámetros
  PositionDim(int sz, ...)
  {
    va_list vl;
    va_start(vl, sz);
    for (int d = 0; d < Dim; d++)
    {
      Coordinates[d] = va_arg(vl, Coor_t);
    }
    va_end(vl);
  }

  Coor_t operator[](unsigned int) const override;
  bool operator<(const PositionDim<Dim, Coordinate_t> &other) const
  {
    for (int i = 0; i < Dim; ++i)
    {
      if (Coordinates[i] < other.Coordinates[i])
        return true;
      if (Coordinates[i] > other.Coordinates[i])
        return false;
    }
    return false;
  }
};

class ac_exception : public std::exception
{
public:
  const char *what() const throw()
  {
    return "Error: Coordinate out of range";
  }
};



//ejemplo de uso
// PositionDim<2> p(1, 2);
// PositionDim<3> p(1, 2, 3);
