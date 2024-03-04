#pragma once

#include "Cell.h"

// clase CellLife hereda de Cell
class CellLife : public Cell {
public:
    // Constructor
    CellLife( Position& pos, const int val) : Cell(pos, val) {}

    // Destructor
    ~CellLife() {}

    // Implementación de nextState
    virtual int nextState(const Lattice& lattice) = 0 ;
};

// clase CellLife23_3 hereda de CellLife
class CellLife23_3 : public CellLife {
public:
    // Constructor
    CellLife23_3( Position& pos, const int val) : CellLife(pos, val) {}

    // Destructor
    ~CellLife23_3() {}

    // Implementación de nextState
    int nextState(const Lattice& lattice) ; // hecho, no comprobado
};

// clase CellLife51_346 hereda de CellLife
class CellLife51_346 : public CellLife {
public:
    // Constructor
    CellLife51_346( Position& pos, const int val) : CellLife(pos, val) {}

    // Destructor
    ~CellLife51_346() {}

    // Implementación de nextState
    int nextState(const Lattice& lattice) ; // hecho, no comprobado
};