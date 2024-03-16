#ifndef _EXPLORATION_FUNCTION_QUADRATIC_H_
#define _EXPLORATION_FUNCTION_QUADRATIC_H_

#include "exploration_function.h"

template <class Key>
class ExplorationFunctionQuadratic: public ExplorationFunction<Key> {
 public:
  unsigned operator()(const Key& key, unsigned i) const{
    return i * i;
  }
};

#endif