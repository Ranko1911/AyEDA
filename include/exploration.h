#include "dispersion.h"

#ifndef EXPLORACION_H
#define EXPLORACION_H

// Clase base abstracta para representar una estrategia de exploración en caso
// de colisiones.
class Exploracion {
 public:
  virtual unsigned operator()(unsigned key, unsigned i) const = 0;
  virtual ~Exploracion() {}
};

// Clase derivada que implementa la exploración lineal.
class ExploracionLineal : public Exploracion {
 public:
  unsigned operator()(unsigned key, unsigned i) const override;
};

// Clase derivada que implementa la exploración cuadrática.
class ExploracionCuadratica : public Exploracion {
 public:
  unsigned operator()(unsigned key, unsigned i) const override;
};

// Clase derivada que implementa la doble dispersión.
class DobleDispersion : public Exploracion {
 private:
  DispersionFunction<unsigned>* f;

 public:
  DobleDispersion(DispersionFunction<unsigned>* function);
  unsigned operator()(unsigned key, unsigned i) const override;
};

// Clase derivada que implementa la re-dispersión.
class Redispersion : public Exploracion {
 private:
  DispersionFunction<unsigned>* f;

 public:
  Redispersion(DispersionFunction<unsigned>* function);
  unsigned operator()(unsigned key, unsigned i) const override;
};

unsigned ExploracionLineal::operator()(unsigned key, unsigned i) const {
  return i;
}

unsigned ExploracionCuadratica::operator()(unsigned key, unsigned i) const {
  return i * i;
}

DobleDispersion::DobleDispersion(DispersionFunction<unsigned>* function)
    : f(function) {}

unsigned DobleDispersion::operator()(unsigned key, unsigned i) const {
  return (*f)(key)*i;
}

Redispersion::Redispersion(DispersionFunction<unsigned>* function)
    : f(function) {}

unsigned Redispersion::operator()(unsigned key, unsigned i) const {
  return (*f)(key + i);
}


#endif  // EXPLORACION_H
