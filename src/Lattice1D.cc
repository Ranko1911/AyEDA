#include "../include/Lattice1D.h"

#include "../include/Lattice.h"

// constructor de la clase template Lattice1D con entrada por fichero
Lattice1D::Lattice1D(const int& b, const int& v, const std::string& file_name,
                     FactoryCell& factory): factory(factory) {
  this->b = b;
  this->v = v;
  this->file_name = file_name;

  std::vector<std::string> lineas;

  std::ifstream archivo(file_name);

  if (!archivo.is_open()) {
    std::cerr << "Error al abrir el archivo." << std::endl;
    return;
  }

  std::string linea;
  while (std::getline(archivo, linea)) {
    lineas.push_back(linea);
  }

  archivo.close();

  // imprimr el contenido del archivo
  // std::cout << "Contenido del archivo: " << std::endl;
  // for (int i = 0; i < lineas.size(); i++) {
  //   for (int j = 0; j < lineas[i].size(); j++) {
  //     std::cout << lineas[i][j];
  //   }
  // }
  // std::cout << std::endl;

  this->size = lineas[0].size();

  for (int pos = 0; pos < lineas[0].size(); pos++) {
    if (lineas[0][pos] == '0') {
      PositionDim<2> pos1(pos, 0);
      Cell* c = factory.createCell(pos1, 0);
      // cells.push_back(*c);
      cells[pos] = c;
      // std::cout << "cero" << std::endl;
    } else if (lineas[0][pos] == '1') {
      PositionDim<2> pos1(pos, 0);
      Cell* c = factory.createCell(pos1, 1);
      // cells.push_back(*c);
      cells[pos] = c;
      // std::cout << "uno" << std::endl;
    }
  }

  // imprimir cells, funciona
  // std::cout << "Contenido de cells: " << std::endl;
  // for (int i = 0; i < cells.size(); i++) {
  //   std::cout << *cells[i];
  // }
  // std::cout << std::endl;
}

// constructor de la clase template Lattice1D con entrada por tamaño
// se que no es necesario la parte de usar el constructor de la clase base
// pero lo pongo por si a caso
Lattice1D::Lattice1D(const int& b, const int& v, const int& size,
                     FactoryCell& factory) : factory(factory){
  this->b = b;
  this->v = v;
  this->size = size;

  int pos = 0;
  for (pos = 0; pos < (size / 2); pos++) {
    PositionDim<2> pos1(pos, 0);
    Cell* c = factory.createCell(pos1, 0);
    // cells.push_back(*c);
    cells[pos] = c;
  }

  PositionDim<2> pos1(pos, 0);
  Cell* d = factory.createCell(pos1, 1);
  // Cell* d = factory.create(pos, 1);
  // cells.push_back(*d);
  cells[pos] = d;
  // pos++;

  for (pos = pos + 1; pos < size; pos++) {
    // Cell* c = factory.create(pos, 0);
    // cells.push_back(*c);
    PositionDim<2> pos1(pos, 0);
    Cell* c = factory.createCell(pos1, 0);
    cells[pos] = c;
  }
}

// nextGeneration de la clase template Lattice1D
void Lattice1D::nextGeneration() {
  this->vivas = Population();

  // bucle para nextStates
  for (int i = 0; i < size; i++) {
    cells[i]->nextState(*this);
  }

  // bucle para updateStates
  for (int i = 0; i < size; i++) {
    cells[i]->updateState();
  }
}

// saveToFile de la clase template Lattice1D
void Lattice1D::saveToFile(const std::string& file_name) {
  std::ofstream archivo(file_name);
  if (!archivo.is_open()) {
    std::cerr << "Error al abrir el archivo." << std::endl;
    return;
  }
  for (int i = 0; i < cells.size(); i++) {
    archivo << cells[i]->getState();
  }
  archivo.close();
}

// population de la clase template Lattice1D
int Lattice1D::Population() {
  int population = 0;
  for (int i = 0; i < cells.size(); i++) {
    population += cells[i]->getState();
  }
  return population;
}

// destructor de la clase template Lattice1D
Lattice1D::~Lattice1D() {
  for (Cell* cell : cells) {
    delete cell;
  }
  cells.clear();
}

// getsize de la clase template Lattice1D
Position& Lattice1D::getSize() const {
  PositionDim<2> pos(size, 0);
  return pos;
}

// operador << de la clase template Lattice1D
std::ostream& operator<<(std::ostream& os, Lattice1D& lattice) {
  // lamada a display de la clase template Lattice1D
  lattice.display(os, lattice);
  return os;
}

// metodo display de la clase template Lattice1D
// realmente solo es una llama a operator<<
std::ostream& Lattice1D::display(std::ostream& os, const Lattice1D& lattice) {
  for (int i = 0; i < lattice.size; i++) {
    os << *lattice.cells[i];
  }
  return os;
}

// getCell de la clase template Lattice1D_open

Cell& Lattice1D_open::operator[](const Position& pos) const {
  PositionDim<2> pos1(2, 0);
  Cell* VIVA = factory.createCell(pos1, 1);
  Cell* MUERTA = factory.createCell(pos1, 0);
  int x = pos[0];
  int v = this->v;
  if (v == 0) {
    // std::cout << "open cold" << std::endl;
    if (x < 0) {
      return *MUERTA;
    } else if (x > size - 1) {
      return *MUERTA;
    } else {
      return *cells[x];
    }
  } else if (v == 1) {
    // std::cout << "open hot" << std::endl;
    if (x < 0) {
      return *VIVA;
    } else if (x > size - 1) {
      return *VIVA;
    } else {
      return *cells[x];
    }
  }
  return *cells[x];
}

// getCell de la clase template Lattice1D_periodic

Cell& Lattice1D_periodic::operator[](const Position& pos) const {
  PositionDim<2> pos1(2, 0);
  Cell* VIVA = factory.createCell(pos1, 1);
  Cell* MUERTA = factory.createCell(pos1, 0);
  int x = pos[0];
  int v = this->v;
  if (v == 0) {
    // std::cout << "periodic cold" << std::endl;
    if (x < 0) {
      return *cells[size + x];
    } else if (x > size - 1) {
      return *cells[x - size];
    } else {
      return *cells[x];
    }
  } else if (v == 1) {
    // std::cout << "periodic hot" << std::endl;
    if (x < 0) {
      return *cells[size + x];
    } else if (x > size - 1) {
      return *cells[x - size];
    } else {
      return *cells[x];
    }
  }
  return *cells[x];
}
