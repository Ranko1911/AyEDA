#pragma once

#include <fstream>
#include <iostream>
#include <vector>

class Cell;
// struct Position;
class Position;
struct State;

class Lattice {
 private:
  int size_N; // columnas
  int size_M; // filas
  int b;
  int v = 0;
  std::string file_name = "";
  std::vector<std::vector<Cell*>> cells;
  int vivas;
  const Cell& getCell(const Position&) const;
  void setCell(const Position&, const int&); 
  void aumentarDerecha();
  void aumentarIzquierda();
  void aumentarArriba();
  void aumentarAbajo();
  
 public:
  Lattice() {}
  Lattice(const int& b, const int& v, const std::string& file_name);
  Lattice(const int& b, const int& v, const int& size_N, const int& size_M);
  ~Lattice();
  Position getSize() const;
  int getB() const;
  int getV() const;
  void nextGeneration();
  int Population();  
  friend std::ostream& operator<<(std::ostream&, const Lattice&);
  Cell& operator[](const Position&) const;
  void saveToFile(const std::string& file_name);
  void increaseSize();

};

class Lattice1D : public Lattice {
 public:
  Lattice1D(const int& b, const int& v, const std::string& file_name);
  Lattice1D(const int& b, const int& v, const int& size_N);
  ~Lattice1D();
};

class Lattice1d_open : public Lattice1D {
 public:
  Lattice1d_open(const int& b, const int& v, const std::string& file_name);
  Lattice1d_open(const int& b, const int& v, const int& size_N);
  ~Lattice1d_open();
};

class Lattice1d_periodic : public Lattice1D {
 public:
  Lattice1d_periodic(const int& b, const int& v, const std::string& file_name);
  Lattice1d_periodic(const int& b, const int& v, const int& size_N);
  ~Lattice1d_periodic();
};

class Lattice2D : public Lattice {
 public:
  Lattice2D(const int& b, const int& v, const std::string& file_name);
  Lattice2D(const int& b, const int& v, const int& size_N, const int& size_M);
  ~Lattice2D();
};

class Lattice2D_reflective : public Lattice2D {
 public:
  Lattice2D_reflective(const int& b, const int& v, const std::string& file_name);
  Lattice2D_reflective(const int& b, const int& v, const int& size_N, const int& size_M);
  ~Lattice2D_reflective();
};

class lattice2d_NoBorder : public Lattice2D {
 public:
  lattice2d_NoBorder(const int& b, const int& v, const std::string& file_name);
  lattice2d_NoBorder(const int& b, const int& v, const int& size_N, const int& size_M);
  ~lattice2d_NoBorder();
};


