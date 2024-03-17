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
class DispersionFunctionModule : public DispersionFunction<Key> {
 private:
  unsigned tableSize;

 public:
  DispersionFunctionModule(unsigned size) : tableSize(size) {}
  unsigned operator()(const Key& key) const override { return key % tableSize; }
};

// Clase derivada que implementa la función de dispersión basada en la suma.
template <class Key>
class DispersionFunctionSum : public DispersionFunction<Key> {
 public:
  DispersionFunctionSum(const unsigned n) : table_size_(n) {}
  unsigned operator()(const Key& key) const {
    unsigned sum = 0, k = key, aux;
    while (k > 0) {
      aux = k % 10;
      sum += aux;
      k /= 10;
    }
    return sum % table_size_;
  }

 private:
  unsigned table_size_;
};

// Clase derivada que implementa la función de dispersión pseudoaleatoria.
template <class Key>
class DispersionFunctionPseudorandom : public DispersionFunction<Key> {
 public:
  DispersionFunctionPseudorandom(const unsigned n) : table_size_(n) {}
  unsigned operator()(const Key& key) const {
    srand(key);
    return rand() % table_size_;
  }

 private:
  unsigned table_size_;
};

//ejemplo de dipersionmodular
//  DispersionFunction<int> *fd = new DispersionFunctionModule<int>(10);

#endif  // DISPERSION_H
