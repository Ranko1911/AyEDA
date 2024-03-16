#ifndef _LIST_H_
#define _LIST_H_

#include "sequence.h"

template <class Key>
class List : public Sequence<Key> {
 public:
  List(){ 
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