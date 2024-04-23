#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>

class date {
  public:

  date() : value_("01/01/1900") {
    day_ = "01";
    month_ = "01";
    year_ = "1900";
    dayInt = 1;
    monthInt = 1;
    yearInt = 1900;
  }

  //constructor de conversión a partir de un int
  date(std::string date) {
    //separar el string en day, month y year por el formato daymonthyear con /
    int pos = date.find("/");
    day_ = date.substr(0, pos);
    // std::cout << "dayint " << day_ << "\n";
    int pos2 = date.find("/", pos + 1);
    month_ = date.substr(pos + 1, pos2 - pos - 1);
    // std::cout << "monthint " << month_ << "\n";
    year_ = date.substr(pos2 + 1, date.size() - pos2 - 1);
    // std::cout << "yearint " << year_ << "\n";

    //convertir day, month y year a int
    dayInt = std::stoi(day_);
    monthInt = std::stoi(month_);
    yearInt = std::stoi(year_);

    //comprobar que el número sea válido
    //comprobar el year
    if (yearInt < 1900 || yearInt > 2100) {
      std::cout << "YEAR: " << yearInt << "\n";
      throw std::invalid_argument("Year out of range");
    }

    //comprobar el month
    if (monthInt < 1 || monthInt > 12) {
      std::cout << "MONTH: " << monthInt << "\n";
      throw std::invalid_argument("Month out of range");
    }

    //comprobar el day
    if (dayInt < 1 || dayInt > 31) {
      std::cout << "DAY: " << dayInt << "\n";
      throw std::invalid_argument("Day out of range");
    }

    //comprobar que el día sea válido para el mes
    if (dayInt > 30 && (monthInt == 4 || monthInt == 6 || monthInt == 9 || monthInt == 11)) {
      throw std::invalid_argument("Day out of range for month");
    }

    if (dayInt > 29 && monthInt == 2) {
      throw std::invalid_argument("Day out of range for month");
    }

    if (dayInt == 29 && monthInt == 2 && yearInt % 4 != 0) {
      throw std::invalid_argument("Day out of range for month");
    }

    // value_ = day + month * 100 + year * 10000;
    // value tiene que tener el formato daymonthyear

    value_ = day_ + month_ + year_;

  }

  operator std::string() const {
    return value_;
  }

  bool operator==(const date& other) const {
    return value_ == other.value_;
  }

  bool operator==(std::string value) const {
    return static_cast<std::string>(*this) == value;
  }

  bool operator<(const date& other) const {
    return value_ < other.value_;
  }

  bool operator>(const date& other) const {
    return value_ > other.value_;
  }

  friend std::istream& operator>>(std::istream& in, date& f) {
    in >> f.value_;
    return in;
  }

  friend std::ostream& operator<<(std::ostream& out, const date& f) {
    // out << f.value_;
    out << f.day_ << "/" << f.month_ << "/" << f.year_;
    return out;
  }

  std::string day() const {
    return day_;
  }

  std::string month() const {
    return month_;
  }

  std::string year() const {
    return year_;
  }

  int dayint() const {
    return dayInt;
  }

  int monthint() const {
    return monthInt;
  }

  int yearint() const {
    return yearInt;
  }

  private:
  std::string value_;
  std::string day_;
  std::string month_;
  std::string year_;
  int dayInt;
  int monthInt;
  int yearInt;
};

#endif