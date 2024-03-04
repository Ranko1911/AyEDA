#pragma once

#include <iostream>
#include "Lattice.h"
#include "Position.h"

// Cell clase plantilla
class Cell {
protected:
    Position& position;
    int value;
    int nextValue;

public:
    // Constructor
    Cell(Position& pos, const int val) : position(pos), value(val), nextValue(0) {}

    // Destructor virtual para permitir la herencia
    virtual ~Cell() {}

    // Métodos virtuales puros
    int getState() const; // hecho, no comprobado
    void setState(int val); // hecho, no comprobado
    void setPosition(const Position& pos); // hecho, no comprobado
    Position& getPosition() const; // hecho, no comprobado
    virtual int nextState(const Lattice& lattice) = 0;
    void updateState(); 
    // Sobrecarga del operador de inserción como función amiga
    friend std::ostream& operator<<(std::ostream& os, const Cell& cell); // hecho, no comprobado
    std::ostream& display(std::ostream& os, const Cell& cell) const;

};
