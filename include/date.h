#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>

class date {
  public:

  date() : value_(1011900) {
    day_ = 1;
    month_ = 1;
    year_ = 1900;
  }

  //constructor de conversión a partir de un int
  date(int day, int month, int year) {
    //comprobar que el número sea válido
    //comprobar el year
    if (year < 1900 || year > 2100) {
      throw std::invalid_argument("Year out of range");
    }

    //comprobar el month
    if (month < 1 || month > 12) {
      throw std::invalid_argument("Month out of range");
    }

    //comprobar el day
    if (day < 1 || day > 31) {
      throw std::invalid_argument("Day out of range");
    }

    //comprobar que el día sea válido para el mes
    if (day > 30 && (month == 4 || month == 6 || month == 9 || month == 11)) {
      throw std::invalid_argument("Day out of range for month");
    }

    if (day > 29 && month == 2) {
      throw std::invalid_argument("Day out of range for month");
    }

    if (day == 29 && month == 2 && year % 4 != 0) {
      throw std::invalid_argument("Day out of range for month");
    }

    value_ = day + month * 100 + year * 10000;
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
  int day_;
  int month_;
  int year_;
};

#endif