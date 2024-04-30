#ifndef PERSO_H
#define PERSO_H

// sistema DnD 5e (vida, fuerza, destreza, constitucion, inteligencia, sabiduria, carisma, defensa, velocidad)

#include <iostream>

class personaje {
private:
  int vida;
  int fuerza;
  int destreza;
  int constitucion;
  int inteligencia;
  int sabiduria;
  int carisma;
  int defensa;
  int velocidad;
  int media;
  std::string nombre;

public:

  personaje() {
    vida = 0;
    fuerza = 0;
    destreza = 0;
    constitucion = 0;
    inteligencia = 0;
    sabiduria = 0;
    carisma = 0;
    defensa = 0;
    velocidad = 0;
    media = 0;
    nombre = "";
  } 

  personaje(int vida, int fuerza, int destreza, int constitucion, int inteligencia, int sabiduria, int carisma, int defensa, int velocidad, std::string nombre) {
    this->vida = vida;
    this->fuerza = fuerza;
    this->destreza = destreza;
    this->constitucion = constitucion;
    this->inteligencia = inteligencia;
    this->sabiduria = sabiduria;
    this->carisma = carisma;
    this->defensa = defensa;
    this->velocidad = velocidad;
    this->media = (vida + fuerza + destreza + constitucion + inteligencia + sabiduria + carisma + defensa + velocidad) / 9;
    this->nombre = nombre;
  }

  int getVida() {
    return vida;
  }

  int getFuerza() {
    return fuerza;
  }

  int getDestreza() {
    return destreza;
  }

  int getConstitucion() {
    return constitucion;
  }

  int getInteligencia() {
    return inteligencia;
  }

  int getSabiduria() {
    return sabiduria;
  }

  int getCarisma() {
    return carisma;
  }

  int getDefensa() {
    return defensa;
  }

  int getVelocidad() {
    return velocidad;
  }

  int getMedia() {
    return media;
  }

  std::string getNombre() {
    return nombre;
  }

  bool operator==(const personaje& other) const {
    return vida == other.vida && fuerza == other.fuerza && destreza == other.destreza && constitucion == other.constitucion && inteligencia == other.inteligencia && sabiduria == other.sabiduria && carisma == other.carisma && defensa == other.defensa && velocidad == other.velocidad && media == other.media && nombre == other.nombre;
  }

  bool operator==(int value) const {
    return media == value;
  }

  friend std::istream& operator>>(std::istream& in, personaje& p) {
    // in >> p.vida >> p.fuerza >> p.destreza >> p.constitucion >> p.inteligencia >> p.sabiduria >> p.carisma >> p.defensa >> p.velocidad;
    // p.media = (p.vida + p.fuerza + p.destreza + p.constitucion + p.inteligencia + p.sabiduria + p.carisma + p.defensa + p.velocidad) / 9;
    // return in;
    in >> p.vida >> p.fuerza >> p.destreza >> p.constitucion >> p.inteligencia >> p.sabiduria >> p.carisma >> p.defensa >> p.velocidad >> p.media >> p.nombre;
    return in;
  }

  friend std::ostream& operator<<(std::ostream& out, const personaje& p) {
    out << p.nombre << "--" << p.media;
    return out;
  }



  int& operator[](size_t index) {
    switch (index) {
      case 0:
        return vida;
      case 1:
        return fuerza;
      case 2:
        return destreza;
      case 3:
        return constitucion;
      case 4:
        return inteligencia;
      case 5:
        return sabiduria;
      case 6:
        return carisma;
      case 7:
        return defensa;
      case 8:
        return velocidad;
      case 9:
        return media;
    }

    return media;
  }

  const int& operator[](size_t index) const {
    switch (index) {
      case 0:
        return vida;
      case 1:
        return fuerza;
      case 2:
        return destreza;
      case 3:
        return constitucion;
      case 4:
        return inteligencia;
      case 5:
        return sabiduria;
      case 6:
        return carisma;
      case 7:
        return defensa;
      case 8:
        return velocidad;
      case 9:
        return media;
    }
  }

  void calcular_media(){
    media = (vida + fuerza + destreza + constitucion + inteligencia + sabiduria + carisma + defensa + velocidad) / 9;
  }

  
  bool operator<(const personaje& other) const {
    return media < other.media;
}


};



#endif // PERSO_H