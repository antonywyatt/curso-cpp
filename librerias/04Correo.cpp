#include <iostream>
#include "Cola.h"

using namespace std;

int main() {
    Cola correoQueue;
    int correoID = 1; // Variable para asignar IDs a los correos
    string opcionStr;

    do {
        cout << "Sistema de Correo\n";
        cout << "1. Enviar correo\n";
        cout << "2. Ver ultimo correo\n";
        cout << "3. Eliminar ultimo correo\n";
        cout << "4. Salir\n";
        cout << "Elija una opción: ";
        cin >> opcionStr;

        try {
        int opcion = stoi(opcionStr);
            switch (opcion) {
                case 1: {
                    Nodo nuevoCorreo;
                    nuevoCorreo.dato = correoID++;
                    cout << "Ingrese el remitente: ";
                    getline(cin >> ws, nuevoCorreo.valor1);
                    cout << "Ingrese el asunto: ";
                    getline(cin >> ws, nuevoCorreo.valor2);
                    cout << "Ingrese el contenido: ";
                    getline(cin >> ws, nuevoCorreo.valor3);
                    correoQueue.push(nuevoCorreo);
                    cout << "Correo enviado con éxito.\n";
                    break;
                }
                case 2: {
                    if (!correoQueue.vacia()) {
                        Nodo correo = correoQueue.front();
                        correoQueue.pop();
                        cout << "Correo #" << correo.dato << "\n";
                        cout << "Remitente: " << correo.valor1 << "\n";
                        cout << "Asunto: " << correo.valor2 << "\n";
                        cout << "Contenido: " << correo.valor3 << "\n";
                    } else {
                        cout << "No hay correos entrantes.\n";
                    }
                    break;
                }
                case 3:
                    if (!correoQueue.vacia()) {
                        correoQueue.pop();
                        cout << "Correo eliminado con éxito.\n";
                    } else {
                        cout << "No hay correos entrantes.\n";
                    }
                    break;
                case 4:
                    cout << "Saliendo del sistema de correo.\n";
                    break;
                default:
                    cout << "Opción no válida. Intente de nuevo.\n";
            } 
        }catch (const invalid_argument& e) {
            cout << "Entrada no válida. Ingrese un número válido.\n";
            cin.clear();
        }
    } while (opcionStr != "4");

    return 0;
}
