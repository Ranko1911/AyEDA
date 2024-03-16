#ifndef _DISPERSION_FUNCTION_PSEUDORANDOM_H_
#define _DISPERSION_FUNCTION_PSEUDORANDOM_H_

#include "dispersion_function.h"

template <class Key>
class DispersionFunctionPseudorandom: public DispersionFunction<Key> {
 public:
  DispersionFunctionPseudorandom(const unsigned n): table_size_(n){}
  unsigned operator()(const Key& key) const{
    srand(key);
    return rand() % table_size_;
  }
 private:
  unsigned table_size_;
};

#endif