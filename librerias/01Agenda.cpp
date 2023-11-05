#include "ListaSimple.h"

using namespace std;

bool esNumero(const string &str) {
    for (char c : str) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

int main(){
    ListaSimple agenda;
    int opcion = 0;

    Nodo contacto;

    do {
        cout << "1) Agregar contacto" << endl;
        cout << "2) Eliminar contacto" << endl;
        cout << "3) Imprimir agenda" << endl;
        cout << "4) Salir" << endl;
        cout << "Opción: ";
        cin >> opcion;
        switch (opcion) {
            case 1:
                cout << "Ingrese el nombre: ";
                cin >> contacto.valor1;
                cout << "Ingrese numero de telefono: ";
                //validar que sea un numero y no una letra
                cin >> contacto.codigo;
                while (!esNumero(contacto.codigo)) {
                    cout << "Entrada no válida. Ingresa un número: ";
                    cin >> contacto.codigo;
                }
                agenda.agregar(contacto);
                break;
            case 2:
                cout << "Ingrese el numero para eliminar: ";
                cin >> contacto.codigo;
                agenda.eliminar(contacto.codigo);
                break;
            case 3:
                agenda.imprimir();
                break;
            case 4:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opción inválida" << endl;
                break;
        }
    } while (opcion != 4);

    return 0;
}