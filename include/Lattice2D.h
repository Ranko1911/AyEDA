#include "Lattice.h"


//clase Lattice2D hereda de Lattice pero sigue siendo plantilla
class Lattice2D : public Lattice{
 public:
  Lattice2D(const int& b, const int& v, const std::string& file_name, const FactoryCell& factory); // Hecho, no comprobado
  Lattice2D(const int& b, const int& v, const int& size_N, const int& size_M, const FactoryCell& factory); // Hecho, no comprobado
  ~Lattice2D(); // Hecho, no comprobado
  Position getSize() const; // Hecho, no comprobado
  void nextGeneration(); // Hecho, no comprobado
  int Population(); // Hecho, no comprobado
  Cell& operator[](const Position&) const; // Hecho, no comprobado
  friend std::ostream& operator<<(std::ostream&, const Lattice&); // Hecho, no comprobado
  void saveToFile(const std::string& file_name); // Hecho, no comprobado
  void display();  // Hecho, no comprobado
};

// clase Lattice2D_reflective hereda de Lattice, esta no es una plantilla
class Lattice2D_reflective : public Lattice {
 public:
  Lattice2D_reflective(const int& b, const int& v, const std::string& file_name, const FactoryCell& factory); // Hecho, no comprobado
  Lattice2D_reflective(const int& b, const int& v, const int& size_N, const int& size_M, const FactoryCell& factory); // Hecho, no comprobado
  ~Lattice2D_reflective(); // Hecho, no comprobado
  Cell& operator[](const Position&) const; // Hecho, no comprobado

  private:
  int size_N;  // columnas
  int size_M;  // filas
  int b;
  int v = 0;
  std::string file_name = "";
  std::vector<std::vector<Cell*>> cells;
  int vivas;
};


// clase Lattice2D_NoBorder hereda de Lattice, esta no es una plantilla
class Lattice2D_NoBorder : public Lattice {
 public:
  Lattice2D_NoBorder(const int& b, const int& v, const std::string& file_name, const FactoryCell& factory); // Hecho, no comprobado
  Lattice2D_NoBorder(const int& b, const int& v, const int& size_N, const int& size_M, const FactoryCell& factory); // Hecho, no comprobado
  ~Lattice2D_NoBorder();  // Hecho, no comprobado
  void nextGeneration(); // Hecho, no comprobado
  Cell& operator[](const Position&) const;// Hecho, no comprobado
  void increaseSize();// Hecho, no comprobado

  private:
  int size_N;  // columnas
  int size_M;  // filas
  int b;
  int v = 0;
  std::string file_name = "";
  std::vector<std::vector<Cell*>> cells;
  int vivas;

  void aumentarAbajo();// Hecho, no comprobado
  void aumentarArriba();// Hecho, no comprobado
  void aumentarDerecha();// Hecho, no comprobado
  void aumentarIzquierda();// Hecho, no comprobado
};

