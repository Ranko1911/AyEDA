#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>

class date {
  public:

  date() : value_(1011900) {
  }

  //constructor de conversión a partir de un int
  date(int num) {
    value_ = num;
  }

  operator int() const {
    return value_;
  }

  bool operator==(const date& other) const {
    return value_ == other.value_;
  }

  bool operator==(int value) const {
    return static_cast<int>(*this) == value;
  }

  friend std::istream& operator>>(std::istream& in, date& f) {
    in >> f.value_;
    return in;
  }

  friend std::ostream& operator<<(std::ostream& out, const date& f) {
    out << f.value_;
    return out;
  }


  private:
  int value_;
};

#endif