#pragma once

// Path: include/Cell.h
#include "Position.h"
#include "Lattice.h"

#include <iostream>

class Lattice;

class Cell {
  protected:
    Position& position;
    int value;
    int nextValue;
    int vivas;

  public:
    // cosntructor y destructor
    Cell(const Position&, const int&): position(position), value(value), nextValue(0) {};
    ~Cell();

    // métodos de acceso
    Position& getPosition() const;
    int getState() const;

    // métodos de modificación
    void setPosition(const Position&);
    void setValue( int&);

    // método de evolución
    virtual void nextState(const Lattice&) = 0;
    void Cell::updateState();


    // sobrecarga de operadores
    friend std::ostream& operator<<(std::ostream&, const Cell&);
    std::ostream& Cell::display(std::ostream&) const;
};