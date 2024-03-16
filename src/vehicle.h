#ifndef _VEHICLE_H_
#define _VEHICLE_H_

#include <iostream>
static unsigned counter = 0;

class Vehicle {
 public:
  Vehicle() {license_ = "0000";}
  Vehicle(std::string license) : license_(license) {}
  operator long() const {
    long result = 0;
    int multiplier = 1;
    for (int i = license_.size() - 1; i >= 0; --i) {
      if (license_[i] >= '0' && license_[i] <= '9') {
        result += (license_[i] - '0') * multiplier;
      }
      multiplier *= 10;
    }
    return result;
  }
bool operator==(const Vehicle& otro_Vehicle) {
    ++counter;
    std::cout << counter;
    return license_ == otro_Vehicle.license_;
  }
  friend std::istream& operator>>(std::istream& in, Vehicle& Vehicle) {
    in >> Vehicle.license_;
    return in;
  }

 private:
  std::string license_;
};

#endif