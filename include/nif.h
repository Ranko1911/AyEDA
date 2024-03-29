#include <iostream>
#include <string>

class nif {
 public:
  // Constructor por defecto que inicializa un dato nif con un valor
  // predeterminado
  nif() : value_("00000000") {}

  // Constructor de conversión a partir de un dato entero long
  nif(long num) {
    value_ = std::to_string(num);
    // Rellenar con ceros a la izquierda si el número no tiene 8 dígitos
    while (value_.size() < 8) {
      value_ = "0" + value_;
    }
  }

  // Operador de conversión a long
  operator long() const {
    long result = 0;
    long multiplier = 1;
    for (int i = value_.size() - 1; i >= 0; --i) {
      if (value_[i] >= '0' && value_[i] <= '9') {
        result += (value_[i] - '0') * multiplier;
      }
      multiplier *= 10;
    }
    return result;
  }

  // Operador de comparación
  bool operator==(const nif& other) const { return value_ == other.value_; }

  bool operator==(int value) const { return static_cast<long>(*this) == value; }

  // Sobrecarga del operador de inserción para facilitar la entrada
  friend std::istream& operator>>(std::istream& in, nif& n) {
    do {
      in >> n.value_;
      // Asegurarse de que la entrada tenga 8 caracteres
      if (n.value_.size() != 8) {
        std::cout << "El NIF debe tener 8 caracteres. Inténtelo de nuevo: ";
      }
    } while (n.value_.size() != 8);
    return in;
  }

 private:
  std::string value_;
};
