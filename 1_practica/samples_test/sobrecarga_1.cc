#include <iostream>
#include <string>

class Persona {
public:
    std::string nombre;
    int edad;
    double altura;

    // Constructor
    Persona(const std::string& n, int e, double a) : nombre(n), edad(e), altura(a) {}

    // Sobrecarga del operador de inserción
    friend std::ostream& operator<<(std::ostream& os, const Persona& persona) {
        os << "Nombre: " << persona.nombre << ", Edad: " << persona.edad << ", Altura: " << persona.altura;
        return os;
    }
};

int main() {
    // Crear una instancia de la clase
    Persona persona1("Juan", 25, 1.75);

    // Utilizar el operador de inserción sobrecargado para imprimir la instancia en la salida estándar
    std::cout << persona1 << std::endl;

    return 0;
}