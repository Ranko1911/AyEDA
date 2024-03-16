#ifndef _BLOCK_H_
#define _BLOCK_H_

#include "sequence.h"

template <class Key>
class Block : public Sequence<Key> {
 public:
  Block(int n){ 
    block_size_ = n;
    block_ = new int [block_size_];
    e_insert_ = 0;
  }

  bool Search(const Key& key) const{
    for(int i = 0; i < block_size_; i++){
      if(key == block_[i]){
        return true;
      }
    }
    return false;
  }

  bool Insert(const Key& key){
    if(!Search(key) && !Is_full()){
      block_[e_insert_] = key;
      e_insert_++;
      return true;
    }
    return false;
  }

  bool Is_full() const{
    for(int i = 0; i < block_size_; i++){
      if(block_[i] != NULL){
        return false;
      }
    }
    return true;
  }

 private:
  int block_size_;
  int *block_;
  int e_insert_;

};

#endif