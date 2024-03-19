#include <iostream>
#include <string>

class libro {
  private:
  std::string ISBN;
  std::string titulo;
  std::string autor;
  std::string fecha;
  std::string edicion;
  std::string editorial;

  public:
  libro() : ISBN("00000000"), titulo("Sin titulo"), autor("Sin autor"), fecha("Sin fecha"), edicion("Sin edicion"), editorial("Sin editorial") {
  }

  libro(std::string ISBN, std::string titulo, std::string autor, std::string fecha, std::string edicion, std::string editorial) : ISBN(ISBN), titulo(titulo), autor(autor), fecha(fecha), edicion(edicion), editorial(editorial) {
    if (ISBN.size() != 10) {
      while (ISBN.size() < 10) {
        ISBN = ISBN + "0";
      }
    }
    
    std::string sub = ISBN.substr(4, 4);
    for (int i = 0; i < sub.size(); i++) {
      if (sub[i] < '0' || sub[i] > '9') {
        while (sub.size() < 4) {
          sub = sub + "0";
        }
      }
    }

    titulo = titulo.empty() ? "Sin titulo" : titulo;
    autor = autor.empty() ? "Sin autor" : autor;
    fecha = fecha.empty() ? "Sin fecha" : fecha;
    edicion = edicion.empty() ? "Sin edicion" : edicion;
    editorial = editorial.empty() ? "Sin editorial" : editorial;
  }

  // Operador de conversion a long 
  operator long() const {
    long result = 0;
    long multiplier = 1;
    for (int i = ISBN.size() - 1; i >= 0; --i) {
      if (ISBN[i] >= '0' && ISBN[i] <= '9') {
        result += (ISBN[i] - '0') * multiplier;
      }
      multiplier *= 10;
    }
    return result;
  }

  bool operator==(const libro& other) const { return ISBN == other.ISBN; }

  bool operator==(int value) const { return static_cast<long>(*this) == value; }

  friend std::istream& operator>>(std::istream& in, libro& l) {
    do {
      in >> l.ISBN;
      std::cout << "Introduzca el titulo: ";
      in >> l.titulo;
      std::cout << "Introduzca el autor: ";
      in >> l.autor;
      std::cout << "Introduzca la fecha: ";
      in >> l.fecha;
      std::cout << "Introduzca la edicion: ";
      in >> l.edicion;
      std::cout << "Introduzca la editorial: ";
      in >> l.editorial;
      if (l.ISBN.size() != 10) {
        std::cout << "El ISBN debe tener 10 caracteres. Inténtelo de nuevo: ";
      }
    } while (l.ISBN.size() != 10);
    return in;
  }

  friend std::ostream& operator<<(std::ostream& out, const libro& l) {
    out << "ISBN: " << l.ISBN << std::endl;
    out << "Titulo: " << l.titulo << std::endl;
    out << "Autor: " << l.autor << std::endl;
    out << "Fecha: " << l.fecha << std::endl;
    out << "Edicion: " << l.edicion << std::endl;
    out << "Editorial: " << l.editorial << std::endl;
    return out;
  }
};