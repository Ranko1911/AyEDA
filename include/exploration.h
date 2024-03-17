#ifndef EXPLORACION_H
#define EXPLORACION_H

#include "dispersion.h"

// Clase base abstracta para representar una estrategia de exploración en caso
// de colisiones.
template <class Key>
class ExplorationFunction{
 public:
  virtual unsigned operator()(const Key& key, unsigned i) const = 0;
};


// Clase derivada que implementa la exploración lineal.
template <class Key>
class ExplorationFunctionLineal: public ExplorationFunction<Key> {
 public:
  unsigned operator()(const Key& key, unsigned i) const{
    return i;
  }
};


// Clase derivada que implementa la exploración cuadrática.
template <class Key>
class ExplorationFunctionQuadratic: public ExplorationFunction<Key> {
 public:
  unsigned operator()(const Key& key, unsigned i) const{
    return i * i;
  }
};

// Clase derivada que implementa la doble dispersión.
template <class Key>
class ExplorationFunctionDouble: public ExplorationFunction<Key> {
 public:
 ExplorationFunctionDouble(DispersionFunction<Key> *fd): fd_(fd){}
  unsigned operator()(const Key& key, unsigned i) const{
    return i * i;
  }
 private:
  DispersionFunction<Key> *fd_;
};

// Clase derivada que implementa la re-dispersión.
template <class Key>
class ExplorationFunctionRedispersion: public ExplorationFunction<Key> {
 public:
 ExplorationFunctionRedispersion(DispersionFunction<Key> *fd): fd_(fd){}
  unsigned operator()(const Key& key, unsigned i) const{
    unsigned op = (*fd_)(key);
    return i * op;
  }
 private:
  DispersionFunction<Key> *fd_;
};

#endif  // EXPLORACION_H
