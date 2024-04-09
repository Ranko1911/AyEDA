#include <iostream>

#include "nodo.h"

//abstract class for binary trees
template <class T>
class AB {
 public:
  virtual void insert(T data) = 0;
  virtual void remove(T data) = 0;
  virtual bool search(T data) = 0;
  virtual void print() = 0;

  protected:
    //puntero a la raiz del arbol
    NodeB<T> *root;
};