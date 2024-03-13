#ifndef DISPERSION_H
#define DISPERSION_H

#include <cstdlib>
#include <iostream>
#include <vector>

// Clase base abstracta para representar una función de dispersión genérica.
template <typename Key>
class DispersionFunction {
 public:
  virtual unsigned operator()(const Key&) const = 0;
  virtual ~DispersionFunction() {}
};

// Clase derivada que implementa la función de dispersión utilizando el operador
// módulo.
template <typename Key>
class ModuloDispersion : public DispersionFunction<Key> {
 private:
  unsigned tableSize;

 public:
  ModuloDispersion(unsigned size) : tableSize(size) {}
  unsigned operator()(const Key& key) const override {
    return key % tableSize;
}

};

// Clase derivada que implementa la función de dispersión basada en la suma.
template <typename Key>
class SumaDispersion : public DispersionFunction<Key> {
 private:
  unsigned tableSize;

 public:
  SumaDispersion(unsigned size) : tableSize(size) {}
  unsigned operator()(const Key& key) const override {
    unsigned sum = 0;
    for (const auto& k : key) {
      sum += k;
    }
    return sum % tableSize;
  }
};

// Clase derivada que implementa la función de dispersión pseudoaleatoria.
template <typename Key>
class PseudoaleatoriaDispersion : public DispersionFunction<Key> {
  private:
  unsigned tableSize;
 public:
  PseudoaleatoriaDispersion(unsigned size) : tableSize(size) {}
  unsigned operator()(const Key& key) const override {
    srand(key);
    return rand();
  }
};

#endif  // DISPERSION_H
