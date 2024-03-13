#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <iostream>
#include <vector>
#include <cstdlib>

//clase sequence abstracta
template <typename T>
class Sequence {
 public:
  virtual void insert(const T& x) = 0;
  virtual bool search(const T& x) const = 0;
  virtual void print(std::ostream& o) const = 0;
  virtual ~Sequence() {}
};

//class template deriva de sequence
template <typename T>
class ArraySequence : public Sequence<T> {
 private:
  std::vector<T> v;

 public:
  void insert(const T& x) override {
    v.push_back(x);
  }

  bool search(const T& x) const override {
    for (const auto& e : v) {
      if (e == x) {
        return true;
      }
    }
    return false;
  }

  void print(std::ostream& o) const override {
    for (const auto& e : v) {
      o << e << " ";
    }
    o << std::endl;
  }
};

//class array deriva de sequence
template <typename T>
class ListSequence : public Sequence<T> {
 private:
  std::vector<T> v;

 public:
  void insert(const T& x) override {
    v.push_back(x);
  }

  bool search(const T& x) const override {
    for (const auto& e : v) {
      if (e == x) {
        return true;
      }
    }
    return false;
  }

  void print(std::ostream& o) const override {
    for (const auto& e : v) {
      o << e << " ";
    }
    o << std::endl;
  }
};


#endif