#include "Lattice.h"

//clase Lattice1D hereda de Lattice pero sigue siendo plantilla
class Lattice1D : public Lattice {
 public:
  Lattice1D(const int& b, const int& v, const std::string& file_name,  FactoryCell& factory); // Hecho, no comprobado
  Lattice1D(const int& b, const int& v, const int& size,  FactoryCell& factory); // Hecho, no comprobado
  ~Lattice1D(); // Hecho, no comprobado
  Position& getSize() const; // Hecho, no comprobado
  void nextGeneration(); // Hecho, no comprobado
  int Population(); // Hecho, no comprobado
  void saveToFile(const std::string& file_name); // Hecho, no comprobado
  std::ostream& display(std::ostream&, const Lattice1D&); // Hecho, no comprobado
  friend std::ostream& operator<<(std::ostream&, const Lattice&); // Hecho, no comprobado

  protected:
  int size;  // columnas
  
  int b;
  int v = 0;
  std::string file_name = "";
  std::vector<Cell*> cells;
  int vivas;
  FactoryCell& factory;
  void setCell (const int& i, const int& val); // NO Hecho, no comprobado

};

//clase Lattice1D_open hereda de Lattice, esta no es una plantilla
class Lattice1D_open : public Lattice1D{
 public:
  Lattice1D_open(const int& b, const int& v, const std::string& file_name, const FactoryCell& factory);
  Lattice1D_open(const int& b, const int& v, const int& size_N, const int& size_M, const FactoryCell& factory);
  ~Lattice1D_open();
  Cell& operator[](const Position&) const;

  private:
  int size_N;  // columnas
  int b;
  int v = 0;
  std::string file_name = "";
  std::vector<Cell*> cells;
  int vivas;
};

//clase Lattice1D_periodic hereda de Lattice, esta no es una plantilla
class Lattice1D_periodic : public Lattice1D {
 public:
  Lattice1D_periodic(const int& b, const int& v, const std::string& file_name, const FactoryCell& factory);
  Lattice1D_periodic(const int& b, const int& v, const int& size_N, const int& size_M, const FactoryCell& factory);
  ~Lattice1D_periodic();
  Cell& operator[](const Position&) const;

  private:
  int size_N;  // columnas
  int b;
  int v = 0;
  std::string file_name = "";
  std::vector<Cell*> cells;
  int vivas;

};