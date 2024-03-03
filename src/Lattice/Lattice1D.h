#include "Lattice.h"

//clase Lattice1D hereda de Lattice pero sigue siendo plantilla
template <typename PositionType, typename Cell, typename FactoryCell>
class Lattice1D : public Lattice<PositionType, Cell, FactoryCell> {
 public:
  Lattice1D(const int& b, const int& v, const std::string& file_name, const FactoryCell& factory); // Hecho, no comprobado
  Lattice1D(const int& b, const int& v, const int& size_N, const int& size_M, const FactoryCell& factory); // Hecho, no comprobado
  ~Lattice1D(); // Hecho, no comprobado
  PositionType getSize() const; // Hecho, no comprobado
  void nextGeneration(); // Hecho, no comprobado
  int Population(); // Hecho, no comprobado
  void saveToFile(const std::string& file_name); // Hecho, no comprobado
  void display(); // Hecho, no comprobado
  friend std::ostream& operator<<(std::ostream&, const Lattice<PositionType, Cell, FactoryCell>&); // Hecho, no comprobado

  protected:
  int size_N;  // columnas
  int b;
  int v = 0;
  std::string file_name = "";
  std::vector<Cell*> cells;
  int vivas;
  void setCell(const PositionType&, const int& i) { cells[PositionType[i]] = Cell; }
};

//clase Lattice1D_open hereda de Lattice, esta no es una plantilla
template <typename PositionType, typename Cell, typename FactoryCell>
class Lattice1D_open : public Lattice<PositionType, Cell, FactoryCell> {
 public:
  Lattice1D_open(const int& b, const int& v, const std::string& file_name, const FactoryCell& factory);
  Lattice1D_open(const int& b, const int& v, const int& size_N, const int& size_M, const FactoryCell& factory);
  ~Lattice1D_open();
  Cell& operator[](const PositionType&) const;

  private:
  int size_N;  // columnas
  int b;
  int v = 0;
  std::string file_name = "";
  std::vector<Cell*> cells;
  int vivas;
};

//clase Lattice1D_periodic hereda de Lattice, esta no es una plantilla
template <typename PositionType, typename Cell, typename FactoryCell>
class Lattice1D_periodic : public Lattice<PositionType, Cell, FactoryCell> {
 public:
  Lattice1D_periodic(const int& b, const int& v, const std::string& file_name, const FactoryCell& factory);
  Lattice1D_periodic(const int& b, const int& v, const int& size_N, const int& size_M, const FactoryCell& factory);
  ~Lattice1D_periodic();
  Cell& operator[](const PositionType&) const;

  private:
  int size_N;  // columnas
  int b;
  int v = 0;
  std::string file_name = "";
  std::vector<Cell*> cells;
  int vivas;

};