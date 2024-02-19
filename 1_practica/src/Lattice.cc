#include "Lattice.h"

#include "Cell.h"



//   if (b == 0) {
//     pos.x = pos.x + 1;
//     cells.push_back(base);
//     pos.x = pos.x + 1;
//     cells.push_back(base);
//     if (v == 1) {
//       cells[0].setState(state_true);
//       cells[1].setState(state_true);
//     } else if (v == 0) {
//       cells[0].setState(state_false);
//       cells[1].setState(state_false);
//     }
//   }

//funcion para comprobar la frontera del lattice
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

    for (int i = 0; i < lineas[0].size(); i++) {
      cells.push_back(new Cell(i, lineas[0][i] - '0'));
    }
  }


}

Lattice::Lattice(const int& b, const int& v, const int& size) {
  this->b = b;
  this->v = v;
  this->size = size;

  int pos = 0;
  for (pos = 0; pos < size / 2; pos++) {
    cells.push_back(new Cell(pos, 0));
  }
  cells[pos] = new Cell(pos, 1);
  for (pos = pos + 1; pos < size; pos++) {
    cells.push_back(new Cell(pos, 0));
  }
}

Lattice::~Lattice() {
  for (int i = 0; i < size; i++) {
    delete &cells[i];
  }
}

const Cell& Lattice::getCell(const int& x) const {
  //  return *cells[x]; 
  if(b == 1){
    if(x < 0){
      return *cells[size - 1];
    } else if(x > size - 1){
      return *cells[0];
    } else {
      return *cells[x];
    }
   }else if (b == 0)
   {
    // if (v == )
    // {
    //   /* code */
    // }
    
   }
   
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
    os << lattice.cells[i]->getState();
  }
  return os;
}