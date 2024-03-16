#ifndef _EXPLORATION_FUNCTION_LINEAL_H_
#define _EXPLORATION_FUNCTION_LINEAL_H_

#include "exploration_function.h"

template <class Key>
class ExplorationFunctionLineal: public ExplorationFunction<Key> {
 public:
  unsigned operator()(const Key& key, unsigned i) const{
    return i;
  }
};

#endif