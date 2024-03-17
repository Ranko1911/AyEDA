# include "../include/hashtable.h"
#include "../include/nif.h"
#include <iostream>

DispersionFunction<nif>* dispersion_menu(unsigned table_size){
  char option;
  while(true){
    std::cout << " Seleccione el tipo de dispersion que se quiera utilizar" << std::endl
    << "1. Modulo" << std::endl
    << "2. Pseudoaleatoria" << std::endl
    << "3. Suma" << std::endl;
    std::cin >> option;
    switch(option){
      case '1': {
        DispersionFunction<nif> *fd = new DispersionFunctionModule<nif>(table_size); 
        return fd;
        break;
      }
      
      case '2': {
        DispersionFunction<nif> *fd = new DispersionFunctionPseudorandom<nif>(table_size); 
        return fd;
        break;
      }

      case '3': {
        DispersionFunction<nif> *fd = new DispersionFunctionSum<nif>(table_size); 
        return fd;
        break;
      }

      default:
        std::cout << "Opcion Incorrecta, vuelva a escoger otra opcion" << std::endl;
        break;
    }
  }
}

ExplorationFunction<nif>* exploration_menu(DispersionFunction<nif>* fd){
  char option;
  while(true){
    std::cout << " Seleccione el tipo de exploracion que se quiera utilizar" << std::endl
    << "1. Lineal" << std::endl
    << "2. Doble" << std::endl
    << "3. Cuadratica" << std::endl
    << "4. Redispersion" << std::endl;
    std::cin >> option;
    switch(option){
      case '1': {
        ExplorationFunction<nif> *fe = new ExplorationFunctionLineal<nif>; 
        return fe;
        break;
      }
      
      case '2': {
        ExplorationFunction<nif> *fe = new ExplorationFunctionDouble<nif>(fd); 
        return fe;
        break;
      }

      case '3': {
        ExplorationFunction<nif> *fe = new ExplorationFunctionQuadratic<nif>;
        return fe;
        break;
      }

      case '4': {
        ExplorationFunction<nif> *fe = new ExplorationFunctionRedispersion<nif>(fd);
        return fe;
        break;
      }

      default:
        std::cout << "Opcion Incorrecta, vuelva a escoger otra opcion" << std::endl;
        break;
    }
  }
}

int main(){
  HashTable<nif> ht;
  bool is_table_created = false;
  char option, dispersion_type;
  unsigned table_size, block_size;
  nif key;
  while(true){
    std::cout << "1.Crear Tabla" << std::endl 
    << "2.Buscar en la tabla" << std::endl  
    << "3.Insertar en la tabla" << std::endl 
    << "Q.Salir" << std::endl;
    std::cin >> option;
    switch(option){
      case '1':
        while(true){
          if(is_table_created){
            break;
          } 
          std::cout << "Introduzca el tamaño de la tabla: " << std::endl;
          std::cin >> table_size;
          std::cout << "Seleccione el tipo de dispersion: " << std::endl
          << "1. Abierta" << std::endl
          << "2. Cerrada" << std::endl;
          std::cin >> dispersion_type;
          switch(dispersion_type){
            case '1': {
              DispersionFunction<nif> *dispersion_function = dispersion_menu(table_size);
              HashTable<nif> hash_table(table_size, dispersion_function);
              ht = hash_table;
              is_table_created = true;
              break;
            }
            
            case '2': {
              DispersionFunction<nif> *dispersion_function = dispersion_menu(table_size);
              ExplorationFunction<nif> *exploration_function = exploration_menu(dispersion_function);
              std::cout << "Introduzca el tamaño del bloque: " << std::endl;
              std::cin >> block_size;
              HashTable<nif> hash_table(table_size, dispersion_function, exploration_function, block_size);
              ht = hash_table;
              is_table_created = true;
              break;
            }
            
            default:
              std::cout << "Opcion Incorrecta, vuelva a escoger otra opcion" << std::endl;
              break;
          }
        }
        break;

      case '2':
        if(is_table_created){
          std::cout << "Introduzca una clave: " << std::endl;
          std::cin >> key;
          if(ht.Search(key)){
            std::cout << "Se ha encontrado la clave" << std::endl;
          } else {
            std::cout << "No se ha encontrado la clave" << std::endl;
          }
        }
        break;

      case '3':
        if(is_table_created){
          std::cout << "Introduzca una clave: " << std::endl;
          std::cin >> key;
          //std::cout << "A" << std::endl;
          if(ht.Insert(key)){
            //std::cout << "B" << std::endl;
            std::cout << "Se ha insertado la clave" << std::endl;
          } else {
            std::cout << "No se ha insertado la clave" << std::endl;
          }
        }
        break;

      case 'Q':
        return 0;
        break;

      case 'q':
        return 0;
        break;
        
      default:
        std::cout << "Opcion Incorrecta, vuelva a escoger otra opcion" << std::endl;
        break;
    }

  }
  
  return 0;
}
