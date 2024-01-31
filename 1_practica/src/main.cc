#include "Cell.h"
#include "Lattice.h"

#include <iostream>

int main(int argc, char** argv) {
  Lattice lattice = Lattice(10);
  std::cout << lattice << std::endl;
  return 0;
}