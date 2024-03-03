#pragma once

#include <iostream>
#include "../Lattice/Lattice.h"
#include "../Position/Position.h"

// Cell clase plantilla
template <typename PositionType, typename Lattice>
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
    int getState() const; // hecho, no comprobado
    void setState(int val); // hecho, no comprobado
    void setPosition(const PositionType& pos); // hecho, no comprobado
    PositionType getPosition() const; // hecho, no comprobado
    virtual int nextState(const Lattice& lattice) = 0;
    virtual void updateState(); 
    // Sobrecarga del operador de inserción como función amiga
    friend std::ostream& operator<<(std::ostream& os, const Cell<PositionType, Lattice>& cell); // hecho, no comprobado
    std::ostream& display(std::ostream& os) const;

};

// Ahora PositionType puede ser cualquier tipo de posición, como PositionDim

// // clase cellACE hereda de Cell
// template <typename PositionType, typename Lattice>
// class CellACE : public Cell<PositionType> {
// public:
//     // Constructor
//     CellACE(const PositionType& pos, const int val) : Cell<PositionType>(pos, val) {}

//     // Destructor
//     ~CellACE() {}

//     // Implementación de nextState virtual
//     virtual int nextState(const Lattice& lattice) = 0 ;
// };

// // clase cellACE110 hereda de Cell
// template <typename PositionType, typename Lattice>
// class CellACE110 : public Cell<PositionType> {
// public:
//     // Constructor
//     CellACE110(const PositionType& pos, const int val) : Cell<PositionType>(pos, val) {}

//     // Destructor
//     ~CellACE110() {}

//     // Implementación de nextState
//     int nextState(const Lattice& lattice) ; // hecho, no comprobado
// };

// // clase cellACE30 hereda de Cell
// template <typename PositionType, typename Lattice>
// class CellACE30 : public Cell<PositionType> {
// public:
//     // Constructor
//     CellACE30(const PositionType& pos, const int val) : Cell<PositionType>(pos, val) {}

//     // Destructor
//     ~CellACE30() {}

//     // Implementación de nextState
//     int nextState(const Lattice& lattice) ; // hecho, no comprobado
// };

// // clase CellLife hereda de Cell
// template <typename PositionType, typename Lattice>
// class CellLife : public Cell<PositionType> {
// public:
//     // Constructor
//     CellLife(const PositionType& pos, const int val) : Cell<PositionType>(pos, val) {}

//     // Destructor
//     ~CellLife() {}

//     // Implementación de nextState
//     virtual int nextState(const Lattice& lattice) = 0 ;
// };

// // clase CellLife23_3 hereda de CellLife
// template <typename PositionType, typename Lattice>
// class CellLife23_3 : public CellLife<PositionType> {
// public:
//     // Constructor
//     CellLife23_3(const PositionType& pos, const int val) : CellLife<PositionType>(pos, val) {}

//     // Destructor
//     ~CellLife23_3() {}

//     // Implementación de nextState
//     int nextState(const Lattice& lattice) ; // hecho, no comprobado
// };

// // clase CellLife51_346 hereda de CellLife
// template <typename PositionType, typename Lattice>
// class CellLife51_346 : public CellLife<PositionType> {
// public:
//     // Constructor
//     CellLife51_346(const PositionType& pos, const int val) : CellLife<PositionType>(pos, val) {}

//     // Destructor
//     ~CellLife51_346() {}

//     // Implementación de nextState
//     int nextState(const Lattice& lattice) ; // hecho, no comprobado
// };