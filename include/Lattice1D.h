#pragma once

#include "Lattice.h"
#include "Cell.h"

//clase Lattice1D hereda de Lattice pero sigue siendo plantilla
class Lattice1D : public Lattice {
 public:
  Lattice1D(const int& b, const int& v, const std::string& file_name, FactoryCell& factory); // Hecho, no comprobado
  Lattice1D(const int& b, const int& v, const Position& size, FactoryCell& factory); // Hecho, no comprobado
  ~Lattice1D(); // Hecho, no comprobado
  Position& getSize() const; // Hecho, no comprobado
  void nextGeneration(); // Hecho, no comprobado
  int Population(); // Hecho, no comprobado
  void saveToFile(const std::string& file_name); // Hecho, no comprobado
  std::ostream& display(std::ostream&, const Lattice1D&); // Hecho, no comprobado
  std::ostream& display(std::ostream&, const Lattice&){
    //llamar al display de esta clase
    this->display(std::cout, *this);
    return std::cout;
  } // Hecho, no comprobado
  friend std::ostream& operator<<(std::ostream&, const Lattice&); // Hecho, no comprobado
  std::vector<Cell*> getCells() const {return cells;}

  protected:
   PositionDim<2> size;  // columnas
  
  int b;
  int v = 0;
  std::string file_name = "";
  std::vector<Cell*> cells;
  int vivas;
  const FactoryCell& factory;
  void setCell (const int& i, const int& val); // NO Hecho, no comprobado
  Cell& getCell (const int& i) const; // NO Hecho, no comprobado

};

//clase Lattice1D_open hereda de Lattice, esta no es una plantilla
class Lattice1D_open : public Lattice1D{
 public:
  Lattice1D_open(const int& b, const int& v, const std::string& file_name, FactoryCell& factory): Lattice1D (b, v, file_name, factory) {}
  Lattice1D_open(const int& b, const int& v, const Position& size,  FactoryCell& factory) : Lattice1D (b, v, size, factory) {}
  ~Lattice1D_open() { 
    for (Cell* cell : cells) {
      delete cell;
    }
    cells.clear();
  }
  Cell& operator[](const Position&) const;

  protected:
  int size_N;  // columnas
  int b;
  int v = 0;
  std::string file_name = "";
  std::vector<Cell*> cells;
  int vivas;
  Cell& getCell (const Position& i) const; // NO Hecho, no comprobado
};

//clase Lattice1D_periodic hereda de Lattice, esta no es una plantilla
class Lattice1D_periodic : public Lattice1D {
 public:
  Lattice1D_periodic(const int& b, const int& v, const std::string& file_name,  FactoryCell& factory) : Lattice1D(b, v, file_name, factory) {}
  Lattice1D_periodic(const int& b, const int& v, const Position& size,  FactoryCell& factory) : Lattice1D(b, v, size, factory) {}
  ~Lattice1D_periodic(){
    for (Cell* cell : cells) {
      delete cell;
    }
    cells.clear();
  }
  Cell& operator[](const Position&) const;

  protected:
  int size_N;  // columnas
  int b;
  int v = 0;
  std::string file_name = "";
  std::vector<Cell*> cells;
  int vivas;
  Cell& getCell (const Position& i) const; // NO Hecho, no comprobado
};

//ejemplo de objeto de la clase Lattice1D
// FactoryCellACE110 factory;
// Lattice1D_open l1(1, 1, "file.txt", factory);