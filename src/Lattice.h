#pragma once

#include <fstream>
#include <iostream>
#include <vector>

class Cell;
struct Position;
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

 public:
  Lattice() {}
  Lattice(const int& b, const int& v, const std::string& file_name);
  Lattice(const int& b, const int& v, const int& size_N, const int& size_M);
  ~Lattice();
  const Cell& getCell(const Position&) const;
  void setCell(const Position&, const int&);  
  Position getSize() const;
  int getB() const;
  int getV() const;
  void nextGeneration();
  int Population();  
  friend std::ostream& operator<<(std::ostream&, const Lattice&);
  Cell& operator[](const Position&) const;
  void saveToFile(const std::string& file_name);
  void increaseSize();
  void aumentarDerecha();
  void aumentarIzquierda();
  void aumentarArriba();
  void aumentarAbajo();
};