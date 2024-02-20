#include "Lattice.h"

#include "Cell.h"

// funcion para comprobar la frontera del lattice
void Lattice::checkBorder() {
  if (b == 0) {
  }
}

Lattice::Lattice(const int& b, const int& v, const std::string& file_name) {
  this->b = b;
  this->v = v;
  this->file_name = file_name;

  std::vector<std::string> lineas;

  std::ifstream archivo(file_name);

  if (!archivo.is_open()) {
    std::cerr << "Error al abrir el archivo." << std::endl;
  } else {
    std::string linea;
    while (std::getline(archivo, linea)) {
      lineas.push_back(linea);
    }

    archivo.close();

    // //imprimr el contenido del archivo
    // for (int i = 0; i < lineas.size(); i++) {
    //   for (int j = 0; j < lineas[i].size(); j++) {
    //     std::cout << "testing: "<< lineas[i][j];
    //   }
    // }

    for (int i = 0; i < lineas[0].size(); i++) {
      cells.push_back(new Cell(i, lineas[0][i]));
      std::cout << "Cell: " << i << " State: " << lineas[0][i] << std::endl;
    }
  }
}

Lattice::Lattice(const int& b, const int& v, const int& size) {
  this->b = b;
  this->v = v;
  this->size = size;

  int pos = 0;
  for (pos = 0; pos < (size / 2 ); pos++) {
    cells.push_back(new Cell(pos, 0));

  }

  cells.push_back(new Cell(pos, 1));
  // pos++;

  for (pos = pos + 1; pos < size; pos++) {
    cells.push_back(new Cell(pos, 0));
  }
}

Lattice::~Lattice() {
    for (Cell* cell : cells) {
        delete cell;
    }
    cells.clear();
}

const Cell& Lattice::getCell(const int& x) const {
  //  return *cells[x];
  Cell* VIVA = new Cell(0, 1);
  Cell* MUERTA = new Cell(0, 0);
  if (b == 1) {
    if (x < 0) {
      return *cells[size - 1];
    } else if (x > size - 1) {
      return *cells[0];
    } else {
      return *cells[x];
    }
  } else if (b == 0) {
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
  }
  return *cells[x];
}

// void Lattice::setCell(const int& position, const int& state) {
//   cells[position]->setState(state);
// }

int Lattice::getSize() const { return this->size; }

int Lattice::getB() const { return this->b; }

int Lattice::getV() const { return this->v; }

void Lattice::nextGeneration() {
  for (int i = 0; i < size; i++) {
    cells[i]->nextState(*this);
  }

  // actualizar todas las celdas
  for (int i = 0; i < size; i++) {
    cells[i]->updateState();
  }

  return;
}

std::ostream& operator<<(std::ostream& os, const Lattice& lattice) {
  for (int i = 0; i < lattice.size; i++) {
    os << *lattice.cells[i];
  }
  return os;
}