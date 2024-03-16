#ifndef _DISPERSION_FUNCTION_H_
#define _DISPERSION_FUNCTION_H_

template <class Key>
class DispersionFunction{
 public:
  virtual unsigned operator()(const Key& key) const = 0;
 private:
};

#endif