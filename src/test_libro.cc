#include "../include/libro.h"

int main(){
  //prueba de creacion de libro
  libro l1("1234567890", "titulo", "autor", "fecha", "edicion", "editorial");

  //prueba de conversion a long
  long l = l1;

  //prueba de comparacion
  libro l2("1234567890", "titulo", "autor", "fecha", "edicion", "editorial");
  if(l1 == l2){
    std::cout << "Son iguales" << std::endl;
  } else {
    std::cout << "No son iguales" << std::endl;
  }

  //prueba de sibrecarga operator>>
  std::cin >> l1;

  //prueba de sobrecarga operator<<
  std::cout << "prueba de sobrecarga operator<<:" << std::endl;
  std::cout << l1;
}