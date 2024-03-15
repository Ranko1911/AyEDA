#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <cstdlib>
#include <iostream>
#include <vector>

#include "dispersion.h"
#include "exploration.h"
#include "sequence.h"

template <class Key, class Container = ArraySequence<Key> >
class HashTable {
 private:
  Container table;
  DispersionFunction<Key>* dispersion;
  Exploracion* exploration;
  int tableSize;
  int blockSize;

 public:
  HashTable(int tableSize_, DispersionFunction<Key>* dispersion_,
            Exploracion* exploration_, int blockSize_ )
      : tableSize(tableSize_),
        dispersion(dispersion_),
        exploration(exploration_),
        blockSize(blockSize_) {}

  void insert(const Key& key) {
    unsigned i = 0;
    unsigned index = (*dispersion)(key);
    while (i < tableSize && table.search(index)) {
      index = (index + (*exploration)(key, i)) % tableSize;
      i++;
    }
    if (i < tableSize) {
      table.insert(index);
      blockSize++;
    }
  }

  bool search(const Key& key) const {
    unsigned i = 0;
    unsigned index = (*dispersion)(key);
    while (i < tableSize && table.search(index)) {
      index = (index + (*exploration)(key, i)) % tableSize;
      i++;
    }
    return i < tableSize;
  }

  void print(std::ostream& o) const { table.print(o); }
};

template <class Key >
class HashTable<Key, ListSequence<Key> > {
 private:
  std::vector<ListSequence<Key>> table;
  DispersionFunction<Key>* dispersion;
  Exploracion* exploration;
  int tableSize;
  int blockSize;

 public:
  HashTable(int tableSize_, DispersionFunction<Key>* dispersion_,
            Exploracion* exploration_, Sequence<Key>* table_)
      : tableSize(tableSize_),
        dispersion(dispersion_),
        exploration(exploration_),
        table(table_) {}

  void insert(const Key& key) {
    unsigned i = 0;
    unsigned index = (*dispersion)(key);
    while (i < tableSize && table.search(index)) {
      index = (index + (*exploration)(key, i)) % tableSize;
      i++;
    }
    if (i < tableSize) {
      table.insert(index);
      blockSize++;
    }
  }

  bool search(const Key& key) const {
    unsigned i = 0;
    unsigned index = (*dispersion)(key);
    while (i < tableSize && table.search(index)) {
      index = (index + (*exploration)(key, i)) % tableSize;
      i++;
    }
    return i < tableSize;
  }

  void print(std::ostream& o) const { table.print(o); }
};

#endif  // HASHTABLE_H