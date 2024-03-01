#pragma once

#include <iostream>
#include "../Lattice/Lattice.h"
#include "../Position/Position.h"

// Cell clase plantilla
template <typename PositionType>
class Cell {
protected:
    PositionType position;
    int value;
    int nextValue;

public:
    // Constructor
    Cell(const PositionType& pos, const int val) : position(pos), value(val), nextValue(0) {}

    // Destructor virtual para permitir la herencia
    virtual ~Cell() {}

    // Métodos virtuales puros
    int getState() const;
    void setState(int val);
    void setPosition(const PositionType& pos);
    PositionType getPosition() const;
    virtual int nextState(const Lattice& lattice) = 0;
    void updateState();
    // Sobrecarga del operador de inserción como función amiga
    friend std::ostream& operator<<(std::ostream& os, const Cell<PositionType>& cell);
};

// Ahora PositionType puede ser cualquier tipo de posición, como PositionDim

// clase cellACE hereda de Cell
template <typename PositionType>
class CellACE : public Cell<PositionType> {
public:
    // Constructor
    CellACE(const PositionType& pos, const int val) : Cell<PositionType>(pos, val) {}

    // Destructor
    ~CellACE() {}

    // Implementación de nextState virtual
    virtual int nextState(const Lattice& lattice) ;
};

// clase cellACE110 hereda de Cell
template <typename PositionType>
class CellACE110 : public Cell<PositionType> {
public:
    // Constructor
    CellACE110(const PositionType& pos, const int val) : Cell<PositionType>(pos, val) {}

    // Destructor
    ~CellACE110() {}

    // Implementación de nextState
    int nextState(const Lattice& lattice) ;
};

// clase cellACE30 hereda de Cell
template <typename PositionType>
class CellACE30 : public Cell<PositionType> {
public:
    // Constructor
    CellACE30(const PositionType& pos, const int val) : Cell<PositionType>(pos, val) {}

    // Destructor
    ~CellACE30() {}

    // Implementación de nextState
    int nextState(const Lattice& lattice) ;
};

// clase CellLife hereda de Cell
template <typename PositionType>
class CellLife : public Cell<PositionType> {
public:
    // Constructor
    CellLife(const PositionType& pos, const int val) : Cell<PositionType>(pos, val) {}

    // Destructor
    ~CellLife() {}

    // Implementación de nextState
    int nextState(const Lattice& lattice) ;
};

// clase CellLife23_3 hereda de CellLife
template <typename PositionType>
class CellLife23_3 : public CellLife<PositionType> {
public:
    // Constructor
    CellLife23_3(const PositionType& pos, const int val) : CellLife<PositionType>(pos, val) {}

    // Destructor
    ~CellLife23_3() {}

    // Implementación de nextState
    int nextState(const Lattice& lattice) ;
};

// clase CellLife51_346 hereda de CellLife
template <typename PositionType>
class CellLife51_346 : public CellLife<PositionType> {
public:
    // Constructor
    CellLife51_346(const PositionType& pos, const int val) : CellLife<PositionType>(pos, val) {}

    // Destructor
    ~CellLife51_346() {}

    // Implementación de nextState
    int nextState(const Lattice& lattice) ;
};