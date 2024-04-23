#include <iostream>
#include "../include/date.h"

int main() {
    try {
        // Crear objetos de fecha usando el constructor
        date today("01/01/2021");
        date newYear("01/01/2022");

        // // Imprimir las fechas
        // std::cout << "Today's date: " << today << std::endl;
        // std::cout << "Day: " << today.day() << std::endl;
        // std::cout << "Month: " << today.month() << std::endl;
        // std::cout << "Year: " << today.year() << std::endl;
        // std::cout << "New Year's date: " << newYear << std::endl;

        // // Prueba de la sobrecarga del operador de igualdad
        // if (today == newYear) {
        //     std::cout << "Today is New Year's Day!" << std::endl;
        // } else {
        //     std::cout << "Today is not New Year's Day." << std::endl;
        // }

        // // Prueba de la conversión a entero
        // std::string todayInt = today;
        // std::cout << "Today's date as an integer: " << todayInt << std::endl;

        // Prueba de la entrada desde el usuario
        std::cout << "Enter a date (daymonthyear): ";
        std::string userDate;
        std::cin >> userDate;
        date user(userDate);
        std::cout << "You entered: " << userDate << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
