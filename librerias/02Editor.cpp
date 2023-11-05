#include <iostream>
#include "ListaDoble.h"

int main() {
    ListaDoble texto;

    char opcion;
    char caracter;

    do {
        std::cout << "Editor de texto simple\n";
        std::cout << "1. Agregar texto\n";
        std::cout << "2. Eliminar caracter\n";
        std::cout << "3. Imprimir texto\n";
        std::cout << "4. Salir\n";
        std::cout << "Elija una opción: ";
        std::cin >> opcion;

        switch (opcion) {
            case '1':
                std::cout << "Ingrese el texto a agregar: ";
                std::cin.ignore(); // Limpiar el búfer de entrada
                std::cin.get(caracter);
                while (caracter != '\n') {
                    texto.agregar(caracter);
                    std::cin.get(caracter);
                }
                break;
            case '2':
                std::cout << "Ingrese el texto a eliminar: ";
                std::cin.ignore(); // Limpiar el búfer de entrada
                std::cin.get(caracter);
                while (caracter != '\n')
                {
                    texto.eliminar(caracter);
                    std::cin.get(caracter);
                }
                
                break;
            case '3':
                std::cout << "Texto: ";
                texto.imprimir();
                break;
            case '4':
                std::cout << "Saliendo del editor de texto.\n";
                break;
            default:
                std::cout << "Opción no válida. Intente de nuevo.\n";
        }
    } while (opcion != '4');

    return 0;
}
