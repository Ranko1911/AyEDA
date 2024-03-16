#ifndef _EXPLORATION_FUNCTION_DOUBLE_H_
#define _EXPLORATION_FUNCTION_DOUBLE_H_

#include "exploration_function.h"
#include "dispersion_function.h"

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

#endif