#include <iostream>
#include "../include/personaje.h" // Asumiendo que el archivo de encabezado se llama perso.h

int main() {
    // Crear un personaje llamado "Gandalf" con ciertas estadísticas
    personaje gandalf(100, 12, 10, 8, 18, 16, 16, 14, 30, "Gandalf el Gris");

    // Mostrar las estadísticas del personaje usando el operador de salida <<
    std::cout << "Estadísticas de " << gandalf.getNombre() << ":" << std::endl;
    std::cout << "Vida: " << gandalf.getVida() << std::endl;
    std::cout << "Fuerza: " << gandalf.getFuerza() << std::endl;
    std::cout << "Destreza: " << gandalf.getDestreza() << std::endl;
    std::cout << "Constitución: " << gandalf.getConstitucion() << std::endl;
    std::cout << "Inteligencia: " << gandalf.getInteligencia() << std::endl;
    std::cout << "Sabiduría: " << gandalf.getSabiduria() << std::endl;
    std::cout << "Carisma: " << gandalf.getCarisma() << std::endl;
    std::cout << "Defensa: " << gandalf.getDefensa() << std::endl;
    std::cout << "Velocidad: " << gandalf.getVelocidad() << std::endl;
    std::cout << "Media: " << gandalf.getMedia() << std::endl;

    // Modificar una estadística (en este caso, la vida)
    gandalf[0] = 120; // Modificamos la vida

    // Mostrar la nueva vida del personaje
    std::cout << "Nueva vida de " << gandalf.getNombre() << ": " << gandalf.getVida() << std::endl;

    return 0;
}
