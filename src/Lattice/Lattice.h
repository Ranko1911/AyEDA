
#pragma once

#include <fstream>
#include <iostream>
#include <vector>

#include "../Position/Position.h"
#include "../cell/Cell.h"
// class Position

// Clase plantilla Lattice
template <typename PositionType>
class Lattice {
 protected:
  int size_N;  // columnas
  int size_M;  // filas
  int b;
  int v = 0;
  std::string file_name = "";
  std::vector<std::vector<Cell*>> cells;
  int vivas;

  // Utiliza PositionDim en lugar de Position
  const Cell& getCell(const PositionType&) const;
  void setCell(const PositionType&, const int&);
  void aumentarDerecha();
  void aumentarIzquierda();
  void aumentarArriba();
  void aumentarAbajo();

 public:
  Lattice() {}
  Lattice(const int& b, const int& v, const std::string& file_name);
  Lattice(const int& b, const int& v, const int& size_N, const int& size_M);
  virtual ~Lattice() = 0;  // Destructor virtual para permitir la herencia

  // Métodos virtuales puros
  virtual PositionType getSize() const = 0;
  int getB() const = 0;
  int getV() const = 0;
  virtual void nextGeneration() = 0;
  virtual int Population() = 0;
  virtual Cell& operator[](const PositionType&) const = 0;
  virtual void saveToFile(const std::string& file_name) = 0;
  virtual void increaseSize() = 0;
};

//clase Lattice1D hereda de Lattice pero sigue siendo plantilla
template <typename PositionType>
class Lattice1D : public Lattice<PositionType> {
 public:
  Lattice1D(const int& b, const int& v, const std::string& file_name);
  Lattice1D(const int& b, const int& v, const int& size_N, const int& size_M);
  ~Lattice1D();
  PositionType getSize() const;
  int getB() const;
  int getV() const;
  void nextGeneration();
  int Population();
  Cell& operator[](const PositionType&) const;
  void saveToFile(const std::string& file_name);
  void increaseSize();
};

//clase Lattice1D_open hereda de Lattice, esta no es una plantilla
//clase Lattice1D_periodic hereda de Lattice, esta no es una plantilla

//clase Lattice2D hereda de Lattice pero sigue siendo plantilla
template <typename PositionType>
class Lattice2D : public Lattice<PositionType> {
 public:
  Lattice2D(const int& b, const int& v, const std::string& file_name);
  Lattice2D(const int& b, const int& v, const int& size_N, const int& size_M);
  ~Lattice2D();
  PositionType getSize() const;
  int getB() const;
  int getV() const;
  void nextGeneration();
  int Population();
  Cell& operator[](const PositionType&) const;
  void saveToFile(const std::string& file_name);
  void increaseSize();
};

// clase Lattice2D_reflective hereda de Lattice, esta no es una plantilla
// clase Lattice2D_periodic hereda de Lattice, esta no es una plantilla

