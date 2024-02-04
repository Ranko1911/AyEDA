#include "Lattice.h"

#include "Cell.h"

Lattice::Lattice(const int& size, const int& b, const int& v, const std::string& file_name) {
  this->size = size;
  this->b = b;
  this->v = v;
  this->file_name = file_name;

  State state_true;
  state_true.value = 1;
  State state_false;
  state_false.value = 0;

  Position pos;
  State state;
  Cell base = Cell(pos, state);

  new (&cells) std::vector<Cell>(size, base);

  for(int i = 0; i < size; i++){
    pos.x = i;
    cells[i].setPosition(pos);
  }

  if(b == 0){
    pos.x = pos.x +1;
    cells.push_back(base);
    pos.x = pos.x +1;
    cells.push_back(base);
    if(v == 1){
      cells[0].setState(state_true);
      cells[1].setState(state_true);
    }else if(v == 0){
      cells[0].setState(state_false);
      cells[1].setState(state_false);
    }
  }
  cells[cells.size()/2].setState(state_true);
}

Lattice::~Lattice() {
}

const Cell& Lattice::getCell(const Position& position) const {
  return this->cells[position.x];
}

void Lattice::setCell(const Position& position, const State& state) {
  this->cells[position.x].setState(state);
}

int Lattice::getSize() const {
  return this->size;
}

int Lattice::getB() const {
  return this->b;
}

int Lattice::getV() const {
  return this->v;
}

void Lattice::nextGeneration() { // no muy seguro de que esta miedra funciona, pero es una primera prueba
  //recorrer todas las celdas y calcular su proximo estado
  State temp_state;
  for(int i = 0; i < size; i++){
    // std::cout << "ESTADO ANTES i: " << i << " " << this->cells[i].getState().value << " " << this->cells[i].getState().nextValue << std::endl;
    temp_state.nextValue = this->cells[i].nextState(*this);
    temp_state.value = this->cells[i].getState().value;
    // std::cout << "ESTADO LUEGO i: " << i << " " << temp_state.value << " " << temp_state.nextValue << std::endl;
    this->cells[i].setState(temp_state  );
    temp_state.nextValue = 0;
    temp_state.value = 0;

  }

  //actualizar todas las celdas  
  for(int i = 0; i < size; i++){
    this->cells[i].updateState();
  }

  return;
}

std::ostream& operator<<(std::ostream& os, const Lattice& lattice) {
  for (int i = 0; i < lattice.size; i++) {
    if (lattice.cells[i].getState().value)
      // os << "X " << lattice.cells[i].getState().value << " " << lattice.cells[i].getState().nextValue << " " << std::endl;
      os << "X" ;
    else
      // os << "O " << lattice.cells[i].getState().value << " " << lattice.cells[i].getState().nextValue << " " << std::endl;
      os << "O" ;
  }
  return os;
}