#include "Lattice.h"

//clase Lattice2D hereda de Lattice pero sigue siendo plantilla
class Lattice2D : public Lattice{
 public:
  // constructor por defecto de la clase Lattice2d
  Lattice2D() = default;
  Lattice2D(const int& b, const int& v, const std::string& file_name,  FactoryCell& factory); // Hecho, no comprobado
  Lattice2D(const int& b, const int& v, const Position&,  FactoryCell& factory); // Hecho, no comprobado
  ~Lattice2D(); // Hecho, no comprobado
  Position& getSize() const; // Hecho, no comprobado
  void nextGeneration(); // Hecho, no comprobado
  int Population(); // Hecho, no comprobado
  friend std::ostream& operator<<(std::ostream&, const Lattice2D&); // Hecho, no comprobado
  void saveToFile(const std::string& file_name); // Hecho, no comprobado
  std::ostream& display(std::ostream&, const Lattice2D&); // Hecho, no comprobado
  std::ostream& display(std::ostream&, const Lattice&){
    //llamar al display de esta clase
    this->display(std::cout, *this);
    return std::cout;
  } // Hecho, no comprobado
  
  protected:
  int size_N;  // columnas
  int size_M;  // filas
  int b;
  int v = 0;
  std::string file_name = "";
  std::vector<std::vector<Cell*>> cells;
  int vivas;
  FactoryCell& factory;
  void setCell (const Position& i, const int& val); // NO Hecho, no comprobado
  Cell& getCell (const Position& i) const; // NO Hecho, no comprobado
};

// clase Lattice2D_reflective hereda de Lattice, esta no es una plantilla
class Lattice2D_reflective : public Lattice2D {
 public:
  Lattice2D_reflective(const int& b, const int& v, const std::string& file_name, FactoryCell& factory) : Lattice2D(b, v, file_name, factory) {}// Hecho, no comprobado
  Lattice2D_reflective(const int& b, const int& v, const Position& size,  FactoryCell& factory): Lattice2D(b,v,size, factory) {} // Hecho, no comprobado
  ~Lattice2D_reflective(); // Hecho, no comprobado
  Cell& operator[](const Position&) const; // Hecho, no comprobado

  protected:
  int size_N;  // columnas
  int size_M;  // filas
  int b;
  int v = 0;
  std::string file_name = "";
  std::vector<std::vector<Cell*>> cells;
  int vivas;
  Cell &getCell(const Position &pos) const; // Hecho, no comprobado
};


// clase Lattice2D_NoBorder hereda de Lattice, esta no es una plantilla
class Lattice2D_NoBorder : public Lattice2D {
 public:
  Lattice2D_NoBorder(const int& b, const int& v, const std::string& file_name,  FactoryCell& factory) : Lattice2D(b,v,file_name, factory){} // Hecho, no comprobado
  Lattice2D_NoBorder(const int& b, const int& v, const Position& size,  FactoryCell& factory) : Lattice2D(b,v, size, factory) {}// Hecho, no comprobado
  ~Lattice2D_NoBorder();  // Hecho, no comprobado
  void nextGeneration(); // Hecho, no comprobado
  Cell& operator[](const Position&) const;// Hecho, no comprobado
  void increaseSize();// Hecho, no comprobado

  protected:
  int size_N;  // columnas
  int size_M;  // filas
  int b;
  int v = 0;
  std::string file_name = "";
  std::vector<std::vector<Cell*>> cells;
  int vivas;
  Cell &getCell(const Position &pos) const; // Hecho, no comprobado

  void aumentarAbajo();// Hecho, no comprobado
  void aumentarArriba();// Hecho, no comprobado
  void aumentarDerecha();// Hecho, no comprobado
  void aumentarIzquierda();// Hecho, no comprobado
};

