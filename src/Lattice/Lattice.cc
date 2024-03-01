#pragma once

#include "Lattice.h"

// Constructor
template <typename PositionType>
Lattice1D<PositionType>::Lattice1D(const int& b, const int& v, const std::string& file_name) : Lattice<PositionType>(b, v, file_name) {
  

}
