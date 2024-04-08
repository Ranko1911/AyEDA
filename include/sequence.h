#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <cstdlib>
#include <iostream>
#include <vector>

// clase sequence abstracta
template <class Key>
class Sequence {
 public:
  virtual bool Search(const Key& key) const = 0;
  virtual bool Insert(const Key& key) = 0;
  virtual bool Is_full() const = 0;
  virtual Key operator[](const int&) const = 0;
};

// class staticSequence deriva de sequence
template <class Key>
class staticSequence : public Sequence<Key> {
 public:
  staticSequence(int n) {
    block_size_ = n;
    block_ = new int[block_size_];
    e_insert_ = 0;
  }

  bool Search(const Key& key) const {
    for(int i = 0; i < e_insert_; i++){
      if(key == block_[i]){
        return true;
      }
    }
    return false;
  }

  bool Insert(const Key& key) {
    if (!Search(key) && !Is_full()) {
      block_[e_insert_] = key;
      e_insert_++;
      return true;
    }
    return false;
  }

  bool Is_full() const { return (e_insert_ == block_size_); }

  Key operator[](const int& p) const {
    return block_[p];
  }

 private:
  int block_size_;
  int* block_;
  int e_insert_;
};

#endif