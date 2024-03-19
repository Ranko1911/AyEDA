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
    //comprobar que el size del ISBN es 10
    if (ISBN.size() != 10) {
      //si no es 10, se rellena con 0 a la derecha hasta que sean 10
      while (ISBN.size() < 10) {
        ISBN = ISBN + "0";
      }
    }
    
    //el sub string numerico es de la pos 4 hasta la 8 del ISBN
    std::string sub = ISBN.substr(4, 4);
    //comprobar que el substring numerico es un numero
    for (int i = 0; i < sub.size(); i++) {
      if (sub[i] < '0' || sub[i] > '9') {
        //si no es un numero, se rellena con 0 a la derecha hasta que sean 4
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

  // Operador de comparacion
  bool operator==(const libro& other) const { return ISBN == other.ISBN; }

  bool operator==(int value) const { return static_cast<long>(*this) == value; }

  //sobrecarga del operador de insercion para facilitar la entrada
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
      //asegurarse de que la entrada tenga 10 caracteres
      if (l.ISBN.size() != 10) {
        std::cout << "El ISBN debe tener 10 caracteres. Inténtelo de nuevo: ";
      }
    } while (l.ISBN.size() != 10);
    return in;
  }

  //sobrecarga del operator<<
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