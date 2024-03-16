#ifndef _DISPERSION_FUNCTION_SUM_H_
#define _DISPERSION_FUNCTION_SUM_H_

#include "dispersion_function.h"

template <class Key>
class DispersionFunctionSum: public DispersionFunction<Key> {
 public:
  DispersionFunctionSum(const unsigned n): table_size_(n){}
  unsigned operator()(const Key& key) const{
    unsigned sum = 0, k = key, aux;
    while( k > 0 ){
      aux = k % 10;
      sum += aux;
      k /= 10;
    }
    return sum % table_size_;
  }
 private:
  unsigned table_size_;
};

#endif