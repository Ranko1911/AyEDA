#include "../include/Lattice2D.h"

#include "../include/Lattice.h"

// constructor de la clase template Lattice2D por fichero
Lattice2D::Lattice2D(const int& b, const int& v, const std::string& file_name,
                     FactoryCell& factory)
    : factory(factory) {
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
  //   std::cout << std::endl;
  // }
  // std::cout << std::endl;

  // // resize de cells para que tenga el mismo tamaño que el archivo
  // cells.resize(lineas.size());
  // for (int i = 0; i < lineas.size(); i++) {
  //   cells[i].resize(lineas[i].size());
  // }

  // primera linea es las dimensiones
  std::string dimensiones = lineas[0];
  // std::cout << "dimensiones: " << dimensiones << std::endl;

  // separar el string lineas[1] en dos strings
  // std::cout << "Lineas[1]:"<< lineas[1] << std::endl;
  std::string size_N_str = lineas[1].substr(0, lineas[1].find(" "));
  // std::cout << "size_N_str: " << size_N_str << std::endl;
  this->size_N = std::stoi(size_N_str);
  std::string size_M_str = lineas[1].substr(lineas[1].find(" ") + 1);
  // std::cout << "size_M_str: " << size_M_str << std::endl;
  this->size_M = std::stoi(size_M_str);

  // this->size_N = lineas.size();
  // this->size_M = 0;

  // // buscar el mayor tamaño de las lineas y asignarlo a size_N
  // for (int i = 0; i < lineas.size(); i++) {
  //   if (lineas[i].size() > this->size_M) {
  //     this->size_M = lineas[i].size();
  //     // std::cout << "Mayor tamaño: " << this->size_M << std::endl;
  //   }
  // }

  // std::cout << "size_N: " << this->size_N << " size_M: " << this->size_M
  //           << std::endl;

  // rellenar las lineas que no están completas con celdas vacias
  for (int i = 2; i < lineas.size(); i++) {
    // std::cout << "lineas[" << i << "].size(): " << lineas[i].size() <<
    // std::endl;
    for (int j = lineas[i].size(); j < this->size_M; j++) {
      // std::cout << "Rellenar con 0" << std::endl;
      lineas[i].push_back(' ');
    }
  }

  // imprimir lineas
  std::cout << "Contenido de lineas: " << std::endl;
  for (int i = 0; i < lineas.size(); i++) {
    for (int j = 0; j < lineas[i].size(); j++) {
      std::cout << lineas[i][j];
    }
    std::cout << std::endl;
  }

  // resize de cells para que tenga el mismo tamaño que el archivo
  cells.resize(this->size_N);
  // std::cout << "cells.size(): " << cells.size() << std::endl;
  for (int i = 0; i < this->size_N; i++) {
    cells[i].resize(this->size_M);
    // std::cout << "cells[" << i << "].size(): " << cells[i].size() <<
    // std::endl;
  }

  // asignar el estado de las celdas
  for (int i = 2; i < lineas.size(); i++) {
    for (int j = 0; j < this->size_M; j++) {
      PositionDim<3> pos(2, i - 2, j);
      // Position pos = {i - 2, j};
      // std::cout << "lineas[" << i << "][" << j << "]: " << lineas[i][j] << "
      // --- " << "cells[" << i - 2 << "][" << j << "]: " << cells[i - 2][j] <<
      // " --- " << "Pos: " << pos.x << "," << pos.y << std::endl; std::cout <<
      // i - 2 << "," << j << " ";
      if (lineas[i][j] == ' ') {
        Cell* c = factory.createCell(pos, 0);
        cells[i - 2][j] = c;
        // std::cout << "cells[" << i - 2 << "][" << j << "]: " << *cells[i -
        // 2][j] << std::endl;
      } else if (lineas[i][j] == 'X') {
        Cell* c = factory.createCell(pos, 1);
        cells[i - 2][j] = c;
        // std::cout << "cells[" << i - 2 << "][" << j << "]: " << *cells[i -
        // 2][j] << std::endl;
      }
    }
    // std::cout << std::endl;
  }

  // imprimir cells
  // std::cout << "Contenido de cells: " << std::endl;
  // for (int i = 0; i < this->size_N; i++) {
  //   for (int j = 0; j < this->size_M; j++) {
  //     std::cout << *cells[i][j];
  //   }
  //   std::cout << std::endl;
  // }

  // imprimir this
  // std::cout << "Contenido de cells: " << std::endl;
  // std::cout << *this << std::endl;
}

// constructor de la clase template Lattice2d por tamaño
Lattice2D::Lattice2D(const int& b, const int& v, const Position& pos,
                     FactoryCell& factory)
    : factory(factory) {
  this->b = b;
  this->v = v;
  // this->size_M = size_M;
  this->size_M = pos[2];
  this->size_N = pos[1];

  cells.resize(size_M);
  // dos bucles que ponen todas las Cell en valor 0
  for (int i = 0; i < size_M; i++) {
    for (int j = 0; j < size_N; j++) {
      // Position pos = {i, j};
      PositionDim<3> pos(2, i, j);
      // std::cout << "pos: " << pos.x << "," << pos.y << std::endl;
      Cell* c = factory.createCell(pos, 0);
      // cells[i].push_back(*c);
      cells[i][j] = c;
      // std::cout << "celda: " << cells[i][j] << std::endl;
    }
  }
  std::cout << "Intrduzca cuantas celdas desea poner en estado 1: ";
  int n;
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    int x, y;
    std::cout << "Introduzca la coordenada x: ";
    std::cin >> x;
    std::cout << "Introduzca la coordenada y: ";
    std::cin >> y;
    // Position pos = {x, y};
    PositionDim<3> pos(2, x, y);
    this->setCell(pos, 1);
  }
}

// destructor de la clase template Lattice2D
Lattice2D::~Lattice2D() {
  for (int i = 0; i < size_M; i++) {
    for (int j = 0; j < size_N; j++) {
      delete cells[i][j];
    }
  }
  cells.clear();
}

// getsize de la clase template Lattice2D
Position& Lattice2D::getSize() const {
  // Position pos = {size_N, size_M};
  PositionDim<3> pos(2, size_N, size_M);
  return pos;
}

// setCell de la clase template Lattice2D
void Lattice2D::setCell(const Position& pos, const int& val) {
  cells[pos[0]][pos[1]]->setState(val);
}

// getCell de la clase template Lattice2D
Cell& Lattice2D::getCell(const Position& pos) const {
  return *cells[pos[0]][pos[1]];
}

// population de la clase template Lattice2D
int Lattice2D::Population() {
  int population = 0;
  for (int i = 0; i < size_M; i++) {
    for (int j = 0; j < size_N; j++) {
      population += cells[i][j]->getState();
    }
  }
  return population;
}

// saveToFile de la clase template Lattice2D
void Lattice2D::saveToFile(const std::string& file_name) {
  std::ofstream archivo(file_name);
  if (!archivo.is_open()) {
    std::cerr << "Error al abrir el archivo." << std::endl;
    return;
  }
  archivo << size_N << " " << size_M << std::endl;
  for (int i = 0; i < size_M; i++) {
    for (int j = 0; j < size_N; j++) {
      archivo << cells[i][j]->getState();
    }
    archivo << std::endl;
  }
  archivo.close();
}

// operador<< de la clase template Lattice2D
std::ostream& operator<<(std::ostream& os, const Lattice2D& lattice) {
  Position& size = lattice.getSize();

  for (int i = 0; i < size[2]; i++) {
    for (int j = 0; j < size[1]; j++) {
      os << *lattice.cells[i][j];
    }
    os << std::endl;
  }
  return os;
}

// nextGeneration de la clase template Lattice2D
void Lattice2D::nextGeneration() {
  Position& size = this->getSize();
  this->vivas = Population();

  // bucle para nextStates
  for (int i = 0; i < size_M; i++) {
    for (int j = 0; j < size_N; j++) {
      cells[i][j]->nextState(*this);
    }
  }

  // bucle para updateStates
  for (int i = 0; i < size_M; i++) {
    for (int j = 0; j < size_N; j++) {
      cells[i][j]->updateState();
    }
  }
}

// metodo display de la clase template Lattice2D
// realmente solo es una llama a operator<<
std::ostream& Lattice2D::display(std::ostream& os, const Lattice2D& lattice) {
  Position& size = this->getSize();
  for (int i = 0; i < size[1]; i++) {
    std::cout << "i: " << i << std::endl;
    for (int j = 0; j < size[0]; j++) {
      os << *lattice.cells[i][j] ;  // << "(" << i << "," << j << ") "
      // os << "[ " << i << "," << j << " ]";
      // os << "[" << lattice.cells[i][j]->getPosition().x << "," << lattice.cells[i][j]->getPosition().y << "]";
    }
    os << std::endl;
  }
  return os;
}

// getCell de la clase template Lattice2D_reflective
Cell& Lattice2D_reflective::operator[](const Position& pos) const {
  return *const_cast<Cell*>(&getCell(pos));
}

// getCell se la clase template Lattice2D_NoBorder
Cell& Lattice2D_NoBorder::operator[](const Position& pos) const {
  return *const_cast<Cell*>(&getCell(pos));
}

// nextGeneration de la clase template Lattice2D_NoBorder
void Lattice2D_NoBorder::nextGeneration() {
  Position& size = this->getSize();

  this->vivas = Population();

  // bucle para nextStates
  for (int i = 0; i < size_M; i++) {
    for (int j = 0; j < size_N; j++) {
      cells[i][j]->nextState(*this);
    }
  }

  // bucle para updateStates
  for (int i = 0; i < size_M; i++) {
    for (int j = 0; j < size_N; j++) {
      cells[i][j]->updateState();
    }
  }

  increaseSize();
}

// increaseSize de la clase template Lattice2D_NoBorder
void Lattice2D_NoBorder::increaseSize() {
  // revisar si hay celulas vivas en el borde derecho
  // aumentarDerecha();
  for (int i = 0; i < size_M; i++) {
    if (cells[size_N - 1][i]->getState() == 1) {
      aumentarDerecha();
      break;
    }
  }

  // std::cout << "SALIDAAAAA" << std::endl;

  // revisar si hay celulas vivas en el borde izquierdo
  // aumentarIzquierda();
  for (int i = 0; i < size_N; i++) {
    if (cells[i][0]->getState() == 1) {
      aumentarIzquierda();
      break;
    }
  }

  // revisar si hay celulas vivas en el borde superior
  // aumentarArriba();
  for (int i = 0; i < size_M; i++) {
    if (cells[0][i]->getState() == 1) {
      aumentarArriba();
      break;
    }
  }

  // comprobar si hay celulas vivas en el borde inferior
  // aumentarAbajo();
  for (int i = 0; i < size_M; i++) {
    if (cells[size_N - 1][i]->getState() == 1) {
      aumentarAbajo();
      break;
    }
  }

  return;
}

// aumentarDerecha de la clase template Lattice2D_NoBorder
void Lattice2D_NoBorder::aumentarDerecha() {
  // imprimr el contenido de cells
  // std::cout << "Contenido de cells antes de aumentar: " << std::endl;
  // std::cout << *this << std::endl;

  // aumentar el valor de size_M
  size_M++;

  for (int i = 0; i < size_N; i++) {
    // PositionType pos = {0, size_M - 1};
    PositionDim<3> pos = {2, i, size_M - 1};
    Cell* c = factory.createCell(pos, 0);
    // cells[i].push_back(*c);
    cells[i].push_back(c);
  }

  // imprimr el contenido de cells
  // std::cout << "Contenido de cells despues de aumentar: " << std::endl;
  // std::cout << *this << std::endl;

  // std::cout << "SALSA DE MORA" << std::endl;

  return;
}

// aumentarIzquierda de la clase template Lattice2D_NoBorder
void Lattice2D_NoBorder::aumentarIzquierda() {
  // insertar una celula muerta en la primera columna
  // std::cout << "Insertar celdas muertas en la primera columna" << std::endl;
  for (int i = 0; i < size_N; i++) {
    // PositionType pos = {0, 0};
    PositionDim<3> pos = {2, 0, 0};
    Cell& c = this->getCell(pos);
    PositionDim<3> pos1 = {2, 0, c.getPosition()[1] - 1};

    Cell* c1 = factory.createCell(pos1, 0);
    cells[i].insert(cells[i].begin(), c1);
  }

  // aumentar el valor de size_M
  // std::cout << "Aumentar el valor de size_M" << std::endl;
  size_M++;

  // recorre todas las filas y aumenta la coordenada x de cada celda
  // std::cout << "Aumentar la coordenada x de cada celda" << std::endl;
  // for (int i = 0; i < size_N; i++) {
  //   for (int j = 0; j < size_M; j++) {
  //     Position temporal = {i, j};
  //     cells[i][j]->setPosition(temporal);
  //   }
  // }
}

// aumentarArriba de la clase template Lattice2D_NoBorder
void Lattice2D_NoBorder::aumentarArriba() {
  // crear un vector de celdas muertas
  std::vector<Cell*> fila;

  // llenar el vector de celdas muertas
  for (int i = 0; i < size_M; i++) {
    PositionDim<3> pos = {2, 0, 0};
    Cell& c = this->getCell(pos);
    PositionDim<3> pos1 = {2, c.getPosition()[2] - 1, 0};
    Cell* c1 = factory.createCell(pos1, 0);
    fila.push_back(c1);
  }

  // insertar en el principio de cells el vector de celdas muertas
  cells.insert(cells.begin(), fila);

  // aumentar el valor de size_N
  size_N++;
}

// aumentarAbajo de la clase template Lattice2D_NoBorder
void Lattice2D_NoBorder::aumentarAbajo() {
  // imprimr el contenido de cells
  // std::cout << "Contenido de cells antes de aumentar: " << std::endl;
  // std::cout << *this << std::endl;

  // crear un vector de celdas
  std::vector<Cell*> fila;

  // llenar en vector de celulas muertas
  for (int i = 0; i < size_M; i++) {
    PositionDim<3> pos = {2, size_N - 1, 0};
    Cell& c = this->getCell(pos);
    PositionDim<3> pos1 = {2, c.getPosition()[2], 0};
    Cell* c1 = factory.createCell(pos1, 0);
    fila.push_back(c1);
  }

  // agregar el vector de celdas muertas a cells
  cells.push_back(fila);

  // aumentar el valor de size_N
  size_N++;

  // imprimr el contenido de cells
  // std::cout << "Contenido de cells despues de aumentar: " << std::endl;
  // std::cout << *this << std::endl;
}

// getCell de la clase template Lattice2D_reflective
Cell& Lattice2D_reflective::getCell(const Position& pos) const {
  // std::cout << "pos: " << pos.x << "," << pos.y << std::endl;
  // std::cout << "size_N: " << size_N << " size_M: " << size_M << std::endl;
  if (pos[0] < 0) {
    if (pos[1] < 0) {
      // std::cout << "1" << std::endl;
      return *cells[0][0];
    } else if (pos[1] >= size_N) {
      // std::cout << "2" << std::endl;
      return *cells[0][size_N - 1];
    } else {
      // std::cout << "3" << std::endl;
      return *cells[0][pos[1]];
    }
  } else if (pos[0] >= size_M) {
    if (pos[1] < 0) {
      // std::cout << "4" << std::endl;
      return *cells[size_M - 1][0];
    } else if (pos[1] >= size_N) {
      // std::cout << "5" << std::endl;
      return *cells[size_M - 1][size_N - 1];
    } else {
      // std::cout << "6" << std::endl;
      return *cells[size_M - 1][pos[1]];
    }
  } else {
    if (pos[1] < 0) {
      // std::cout << "7" << std::endl;
      return *cells[pos[0]][0];
    } else if (pos[1] >= size_N) {
      // std::cout << "8" << std::endl;
      return *cells[pos[0]][size_N - 1];
    } else {
      // std::cout << "9" << std::endl;
      return *cells[pos[0]][pos[1]];
    }
  }
}

// getCell de la clase template Lattice2D_NoBorder
Cell& Lattice2D_NoBorder::getCell(const Position& pos) const {
  if (pos[0] < 0 || pos[0] >= size_M || pos[1] < 0 || pos[1] >= size_N) {
    PositionDim<3> pos1(2, 0, 0);
    Cell* VIVA = factory.createCell(pos1, 1);
    Cell* MUERTA = factory.createCell(pos1, 0);
    return *MUERTA;
  } else {
    return *cells[pos[0]][pos[1]];
  }
}