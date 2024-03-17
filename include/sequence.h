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
    if(!Search(key) && !Is_full()){
      block_[e_insert_] = key;
      e_insert_++;
      return true;
    }
    return false;
  }

  bool Is_full() const {
    return (e_insert_ == block_size_);
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
    // No es necesario hacer nada aquí, ya que el vector se inicializa vacío automáticamente
  }

  bool Search(const Key& key) const{
    // Itera sobre el vector para buscar el elemento
    for(const auto& item : list_){
      if(key == item){
        return true;
      }
    }
    return false;
  }

  bool Insert(const Key& key){
    // Inserta el elemento si no se encuentra y el vector no está lleno
    if(!Search(key) && !Is_full()){
      list_.push_back(key);
      return true;
    }
    return false;
  }

  bool Is_full() const{
    // Devuelve verdadero si el tamaño del vector alcanza cierto límite (por ejemplo, 100)
    return (list_.size() >= 100); // Puedes ajustar el límite según sea necesario
  }

 private:
  std::vector<Key> list_; // Usa Key en lugar de int para hacer la clase más genérica
};


#endif