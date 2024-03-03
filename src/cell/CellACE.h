#include "Cell.h"


// clase cellACE hereda de Cell
template <typename PositionType, typename Lattice>
class CellACE : public Cell<PositionType> {
public:
    // Constructor
    CellACE(const PositionType& pos, const int val) : Cell<PositionType>(pos, val) {}

    // Destructor
    ~CellACE() {}

    // Implementación de nextState virtual
    virtual int nextState(const Lattice& lattice) = 0 ;
};

// clase cellACE110 hereda de Cell
template <typename PositionType, typename Lattice>
class CellACE110 : public Cell<PositionType> {
public:
    // Constructor
    CellACE110(const PositionType& pos, const int val) : Cell<PositionType>(pos, val) {}

    // Destructor
    ~CellACE110() {}

    // Implementación de nextState
    int nextState(const Lattice& lattice) ; // hecho, no comprobado
};

// clase cellACE30 hereda de Cell
template <typename PositionType, typename Lattice>
class CellACE30 : public Cell<PositionType> {
public:
    // Constructor
    CellACE30(const PositionType& pos, const int val) : Cell<PositionType>(pos, val) {}

    // Destructor
    ~CellACE30() {}

    // Implementación de nextState
    int nextState(const Lattice& lattice) ; // hecho, no comprobado
};