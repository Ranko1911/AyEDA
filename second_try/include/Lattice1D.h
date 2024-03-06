#pragma once

#include <fstream>

#include "Lattice.h"

class Lattice1D : public Lattice {
 public:
  Lattice1D(const int& b, const int& v, const std::string& file_name,
            const FactoryCell* factory)
      : Lattice(b, v, file_name, factory) {}
  Lattice1D(const int& b, const int& v, const FactoryCell* factory,
            const Position* size)
      : Lattice(b, v, factory, size) {}

  virtual ~Lattice1D();                           // done
  int Population();                               // done
  void saveToFile(const std::string& file_name);  // done
  void nextGeneration();                          // done

  // metodos de acceso
  Cell& operator[](const Position&)
      const;  // se tiene que sobreescribir en los metodos de las clases hijas

  // metodos de display
  std::ostream& display(std::ostream&);                        // done
  friend std::ostream& operator<<(std::ostream&, Lattice1D&);  // done

 protected:
  std::vector<Cell*> cells;
};

class Lattice1D_open : public Lattice {
 public:
  Lattice1D_open(const int& b, const int& v, const std::string& file_name,
                 const FactoryCell* factory)
      : Lattice(b, v, file_name, factory) {}
  Lattice1D_open(const int& b, const int& v, const FactoryCell* factory,
                 const Position* size)
      : Lattice(b, v, factory, size) {}

  ~Lattice1D_open();

  Cell& operator[](const Position&)
      const;  // se tiene que sobreescribir en los metodos de las clases hijas

 protected:
};

class Lattice1D_periodic : public Lattice {};