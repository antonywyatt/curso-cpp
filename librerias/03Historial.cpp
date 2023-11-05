#include <iostream>
#include "Pila.h"

int main() {
    Pila historial;
    std::string paginaActual;

    while (true) {
        std::cout << "Simulador de Historial de Navegador\n";
        std::cout << "1. Ir a una página\n";
        std::cout << "2. Retroceder\n";
        std::cout << "3. Avanzar\n";
        std::cout << "4. Salir\n";
        std::cout << "Elija una opción: ";
        int opcion;
        std::cin >> opcion;

        if (opcion == 1) {
            std::string nuevaPagina;
            std::cout << "Ingrese la URL de la página: ";
            std::cin >> nuevaPagina;

            historial.push(paginaActual);
            paginaActual = nuevaPagina;

            std::cout << "Navegando a: " << paginaActual << std::endl;
        } else if (opcion == 2) {
            if (!historial.vacia()) {
                std::string paginaAnterior = historial.top();
                historial.pop();
                std::cout << "Retrocediendo a: " << paginaAnterior << std::endl;
                paginaActual = paginaAnterior;
            } else {
                std::cout << "No hay páginas anteriores en el historial.\n";
            }
        } else if (opcion == 3) {
            std::string paginaSiguiente = historial.top();
            if (!paginaSiguiente.empty()) {
                historial.pop();
                std::cout << "Avanzando a: " << paginaSiguiente << std::endl;
                paginaActual = paginaSiguiente;
            } else {
                std::cout << "No hay páginas siguientes en el historial.\n";
            }
        } else if (opcion == 4) {
            std::cout << "Saliendo del simulador de historial de navegador.\n";
            break;
        } else {
            std::cout << "Opción no válida. Intente de nuevo.\n";
        }
    }

    return 0;
}
