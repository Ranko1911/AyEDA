#include "Lattice.h"

#include "Cell.h"

Lattice::Lattice(const int& b, const int& v, const std::string& file_name) {
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

  // // imprimr el contenido del archivo
  // std::cout << "Contenido del archivo: " << std::endl;
  // for (int i = 0; i < lineas.size(); i++) {
  //   for (int j = 0; j < lineas[i].size(); j++) {
  //     std::cout << lineas[i][j];
  //   }
  //   std::cout << std::endl;
  // }
  // std::cout << std::endl;

  // resize de cells para que tenga el mismo tamaño que el archivo
  cells.resize(lineas.size());
  for (int i = 0; i < lineas.size(); i++) {
    cells[i].resize(lineas[i].size());
  }

  this->size_N = lineas.size();
  // buscar el mayor tamaño de las lineas y asignarlo a size_N
  for (int i = 0; i < lineas.size(); i++) {
    if (lineas[i].size() > this->size_N) {
      this->size_M = lineas[i].size();
    }
  }
  std::cout << "size_N: " << this->size_N << " size_M: " << this->size_M
            << std::endl;

  // rellenar las lineas que no están completas con celdas vacias
  for (int i = 0; i < lineas.size(); i++) {
    for (int j = lineas[i].size(); j < this->size_M; j++) {
      lineas[i].push_back('0');
    }
  }

  // asignar el estado de las celdas
  for (int i = 0; i < lineas.size(); i++) {
    for (int j = 0; j < lineas[i].size(); j++) {
      Position pos = {i, j};
      if (lineas[i][j] == '0') {
        cells[i][j] = new Cell(pos, 0);
      } else if (lineas[i][j] == '1') {
        cells[i][j] = new Cell(pos, 1);
      }
    }
  }

  // imprimir cells
}

Lattice::Lattice(const int& b, const int& v, const int& size_N,
                 const int& size_M) {
  this->b = b;
  this->v = v;
  this->size_M = size_M;
  this->size_N = size_N;

  cells.resize(size_M);
  // dos bucles que ponen todas las Cell en valor 0
  for (int i = 0; i < size_M; i++) {
    for (int j = 0; j < size_N; j++) {
      Position pos = {i, j};
      // std::cout << "pos: " << pos.x << "," << pos.y << std::endl;
      cells[i].push_back(new Cell(pos, 0));
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
    Position pos = {x, y};
    this->setCell(pos, 1);
  }
}

Lattice::~Lattice() {
  for (int i = 0; i < size_M; i++) {
    for (int j = 0; j < size_N; j++) {
      delete cells[i][j];
    }
  }
  cells.clear();
}

const Cell& Lattice::getCell(const Position& x) const {
  //  return *cells[x];
  Position temporal = {x.x, x.y};  // x, y
  Cell* VIVA = new Cell(temporal, 1);
  Cell* MUERTA = new Cell(temporal, 0);

  // codigo de las diferentes fronteras
  if (b == 1) {  // frontera peridica b = 1
    if (temporal.x < 0) {
      temporal.x = size_N - 1;
    } else if (temporal.x >= size_N) {
      temporal.x = 0;
    }
    if (temporal.y < 0) {
      temporal.y = size_M - 1;
    } else if (temporal.y >= size_M) {
      temporal.y = 0;
    }
  } else if (b == 0 && v == 0) {  // frontera abierta fria b = 0 v = 0
    if (temporal.x < 0 || temporal.x >= size_N || temporal.y < 0 ||
        temporal.y >= size_M) {
      return *MUERTA;
    }
  } else if (b == 0 && v == 1) {  // frontera abierta caliente b = 0 v = 1
    if (temporal.x < 0 || temporal.x >= size_N || temporal.y < 0 ||
        temporal.y >= size_M) {
      return *VIVA;
    }
  } else if (b == 2) {  // frontera dinamica b = 2

    std::cout << "Frontera dinamica" << std::endl;
  }

  return *cells[temporal.x][temporal.y];
}

Position Lattice::getSize() const {
  Position size = {size_N, size_M};
  return size;
}

int Lattice::getB() const { return this->b; }

int Lattice::getV() const { return this->v; }

void Lattice::nextGeneration() {
  std::cout << "nextGeneration" << std::endl;
  Position size = getSize();
  std::cout << "Size: " << size.x << "x" << size.y << std::endl;
  vivas = Population();
  std::cout << "Poblacion: " << vivas << std::endl;

  // calcular el siguiente estado de todas las celdas
  for (int i = 0; i < size.x; i++) {
    for (int j = 0; j < size.y; j++) {
      cells[i][j]->nextState(*this);
    }
  }

  std::cout << "nextState satisfactorio " << std::endl;

  // actualizar todas las celdas
  for (int i = 0; i < size.x; i++) {
    for (int j = 0; j < size.y; j++) {
      cells[i][j]->updateState();
    }
  }

  return;
}

std::ostream& operator<<(std::ostream& os, const Lattice& lattice) {
  // limpiar la pantalla aqui o en el main?
  Position size = lattice.getSize();
  for (int i = 0; i < size.x; i++) {
    for (int j = 0; j < size.y; j++) {
      os << *lattice.cells[i][j];
    }
    os << std::endl;
  }
  return os;
}

Cell& Lattice::operator[](const Position& pos) const {
  return *cells[pos.x][pos.y];
}

int Lattice::Population() {
  int population = 0;
  Position size = getSize();
  for (int i = 0; i < size.x; i++) {
    for (int j = 0; j < size.y; j++) {
      population += cells[i][j]->getState();
    }
  }
  return population;
}

void Lattice::saveToFile(const std::string& file_name) {
  std::ofstream archivo(file_name);
  if (!archivo.is_open()) {
    std::cerr << "Error al abrir el archivo." << std::endl;
    return;
  }
  Position size = getSize();
  for (int i = 0; i < size.x; i++) {
    for (int j = 0; j < size.y; j++) {
      archivo << cells[i][j]->getState();
    }
    archivo << std::endl;
  }
  archivo.close();
}

void Lattice::setCell(const Position& pos, const int& state) {
  cells[pos.x][pos.y]->setState(state);
  return;
}