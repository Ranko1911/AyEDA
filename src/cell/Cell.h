// #pragma once

// #include <iostream>
// #include "Lattice.h"
// #include "../Position/Position.h" // Asegúrate de incluir la definición de PositionDim.h

// // Utiliza PositionDim en lugar de Position
// template <int Dim = 2, class Coordinate_t = int>
// class Cell {
//  private:
//   PositionDim<Dim, Coordinate_t> position; // Cambia el tipo de position a PositionDim
//   int value;
//   int nextValue;

//  public:
//   // Declaración de constructores y destructores
//   Cell(const PositionDim<Dim, Coordinate_t>& pos, const int val) : position(pos), value(val), nextValue(0) {}
//   ~Cell() {}

//   // Métodos de acceso para position y otros miembros
//   PositionDim<Dim, Coordinate_t> getPosition() const { return position; }
//   void setPosition(const PositionDim<Dim, Coordinate_t>& pos) { position = pos; }

//   int getState() const { return value; }
//   void setState(int val) { value = val; }

//   int nextState(const Lattice& lattice) {
//     // Implementa la lógica para calcular el siguiente estado basado en la posición actual y la red (lattice)
//     // Devuelve el próximo estado calculado
//     return 0; // Solo un valor de ejemplo
//   }

//   void updateState() {
//     // Implementa la lógica para actualizar el estado actual al siguiente estado
//     // Usualmente, esto involucra asignar nextValue a value
//     value = nextValue;
//   }

//   friend std::ostream& operator<<(std::ostream& os, const Cell& cell) {
//     // Implementa la sobrecarga del operador de inserción para imprimir la celda
//     os << "Cell at position: " << cell.position << ", value: " << cell.value;
//     return os;
//   }
// };

#pragma once

#include <iostream>
#include "../Lattice/Lattice.h"
#include "../Position/Position.h"

// Modifica Cell para ser una clase plantilla
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