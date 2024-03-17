#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <cstdlib>
#include <iostream>
#include <vector>

#include "dispersion.h"
#include "exploration.h"
#include "sequence.h"

template <class Key>
class HashTable{
 public:
  HashTable(){
    table_size_ = 0;
    block_size_ = 0;
    fd_ = nullptr;
    fe_ = nullptr;
  }

  HashTable(int table_size, DispersionFunction<Key> *fd = nullptr, ExplorationFunction<Key> *fe = nullptr, int block_size = 0){
    table_size_ = table_size;
    block_size_ = block_size;
    fd_ = fd;
    table_ = new Sequence<Key> *[table_size_];
    if(fe != nullptr && block_size != 0){
      fe_ = fe;
      for(int i = 0; i < table_size_; i++){
        Sequence<Key> *block = new staticSequence<Key>(block_size_);
        table_[i] = block;
      }
    } else {
      for(int i = 0; i < table_size_; i++){
        Sequence<Key> *list = new dynamicSequence<Key>();
        table_[i] = list;
      }
    }
  }

  bool Search(const Key& key) const {
    unsigned jump, gap = 1, pos = (*fd_)(key);
    if(table_[pos]->Search(key)){
      return true;
    } else {
      if(table_[pos]->Is_full()){
        while(true){
          jump = (*fe_)(key,gap);
          pos += jump;
          gap++;
          if(pos >= table_size_){
            pos = pos % table_size_;
          } 
          if(table_[pos]->Search(key)){
            return true;
          } else {
            if(!table_[pos]->Is_full()){
              return false;
            }
          }
        }
      } else {
        return false;
      }
    }
  }

  bool Insert(const Key& key) {
    std::cout << "Insertar" << std::endl;
    if (!Search(key)) {
        unsigned jump, gap = 1, pos = (*fd_)(key);
        if (table_[pos]->Is_full()) {
            unsigned max_attempts = table_size_; // Número máximo de intentos
            while (max_attempts > 0) {
                jump = (*fe_)(key, gap);
                pos += jump;
                gap++;
                if (pos >= table_size_) {
                    pos = pos % table_size_;
                }
                if (!table_[pos]->Is_full()) {
                    table_[pos]->Insert(key);
                    return true;
                }
                std::cout << "Intento fallido" << max_attempts << std::endl;
                max_attempts--; // Decrementa el contador de intentos
            }
            // Si se han agotado los intentos, la inserción falla
            return false;
        } else {
            table_[pos]->Insert(key);
            return true;
        }
    } else {
        return false;
    }
}

 private:
  int block_size_, table_size_;
  DispersionFunction<Key> *fd_;
  ExplorationFunction<Key> *fe_;
  Sequence<Key> **table_;

};


#endif  // HASHTABLE_H