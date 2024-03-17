#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <iostream>
#include <vector>
#include <cstdlib>

//clase sequence abstracta
template <class Key>
class Sequence{
 public:
  virtual bool Search(const Key& key) const = 0;
  virtual bool Insert(const Key& key) = 0;
  virtual bool Is_full() const = 0;
};


//class staticSequence deriva de sequence
template <class Key>
class staticSequence : public Sequence<Key> {
 public:
  staticSequence(int n){ 
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

//class dynamicSequence deriva de sequence
template <class Key>
class dynamicSequence : public Sequence<Key> {
 public:
  dynamicSequence(){ 
    list_.clear();  
  }

  bool Search(const Key& key) const{
    for(int i = 0; i < list_.size(); i++){
      if(key == list_.at(i)){
        return true;
      }
    }
    return false;
  }

  bool Insert(const Key& key){
    if(!Search(key) && !Is_full()){
      list_.push_back(key);
      return true;
    }
    return false;
  }

  bool Is_full() const{
    return false;
  }

 private:
  std::vector<int> list_;

};



#endif