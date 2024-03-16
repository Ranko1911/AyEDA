#ifndef _SEQUENCE_H_
#define _SEQUENCE_H_

template <class Key>
class Sequence{
 public:
  virtual bool Search(const Key& key) const = 0;
  virtual bool Insert(const Key& key) = 0;
  virtual bool Is_full() const = 0;
};

#endif