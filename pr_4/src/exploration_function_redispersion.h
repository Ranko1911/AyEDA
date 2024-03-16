#ifndef _EXPLORATION_FUNCTION_REDISPERSION_H_
#define _EXPLORATION_FUNCTION_REDISPERSION_H_

#include "exploration_function.h"
#include "dispersion_function.h"

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

#endif