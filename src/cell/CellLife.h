#include "Cell.h"


// clase CellLife hereda de Cell
template <typename PositionType, typename Lattice>
class CellLife : public Cell<PositionType> {
public:
    // Constructor
    CellLife(const PositionType& pos, const int val) : Cell<PositionType>(pos, val) {}

    // Destructor
    ~CellLife() {}

    // Implementación de nextState
    virtual int nextState(const Lattice& lattice) = 0 ;
};

// clase CellLife23_3 hereda de CellLife
template <typename PositionType, typename Lattice>
class CellLife23_3 : public CellLife<PositionType> {
public:
    // Constructor
    CellLife23_3(const PositionType& pos, const int val) : CellLife<PositionType>(pos, val) {}

    // Destructor
    ~CellLife23_3() {}

    // Implementación de nextState
    int nextState(const Lattice& lattice) ; // hecho, no comprobado
};

// clase CellLife51_346 hereda de CellLife
template <typename PositionType, typename Lattice>
class CellLife51_346 : public CellLife<PositionType> {
public:
    // Constructor
    CellLife51_346(const PositionType& pos, const int val) : CellLife<PositionType>(pos, val) {}

    // Destructor
    ~CellLife51_346() {}

    // Implementación de nextState
    int nextState(const Lattice& lattice) ; // hecho, no comprobado
};