#ifndef _DISPERSION_FUNCTION_MODULE_H_
#define _DISPERSION_FUNCTION_MODULE_H_

#include "dispersion_function.h"

template <class Key>
class DispersionFunctionModule: public DispersionFunction<Key> {
 public:
  DispersionFunctionModule(const unsigned n): table_size_(n){}
  unsigned operator()(const Key& key) const{
    return key % table_size_;
  }
 private:
  unsigned table_size_;
};

#endif