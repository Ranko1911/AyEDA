#pragma once

#include "Cell.h"
#include "Position.h"


// clase cellACE hereda de Cell
class CellACE : public Cell {
public:
    // Constructor
    CellACE( Position& pos, const int val) : Cell(pos, val) {}

    // Destructor
    ~CellACE() {}

    // Implementación de nextState virtual
    virtual int nextState(const Lattice& lattice) = 0 ;
};

// clase cellACE110 hereda de Cell
class CellACE110 : public CellACE {
public:
    // Constructor
    CellACE110( Position& pos, const int val) : CellACE(pos, val) {}

    // Destructor
    ~CellACE110() {}

    // Implementación de nextState
    int nextState(const Lattice& lattice) ; // hecho, no comprobado
};

// clase cellACE30 hereda de Cell
class CellACE30 : public CellACE{
public:
    // Constructor
    CellACE30( Position& pos, const int val) : CellACE(pos, val) {}

    // Destructor
    ~CellACE30() {}

    // Implementación de nextState
    int nextState(const Lattice& lattice)  ; // hecho, no comprobado
};

// ejemplo de objeto CellACE30

// PositionDim<2> p(1, 2);
// CellACE30 c(p, 1);