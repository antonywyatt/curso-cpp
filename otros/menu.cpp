#include <iostream>

using namespace std;

int main(){
    int opcion_menu;
    float sueldo, nuevo_sueldo;
    char categoria;


    do {
        cout << "===============MENU==============" << endl;
        cout << "Bienvenido al programa de sueldos" << endl;
        cout << "Por favor seleccione una opcion" << endl;
        cout << "1. Ingresar sueldo" << endl;
        cout << "2. Ingresar categoría de trabajador" << endl;
        cout << "3. Mostrar sueldo" << endl;
        cout << "0. Salir" << endl;
        cout << "================================" << endl;
        cout << "Opcion: ";
        cin >> opcion_menu;

        switch (opcion_menu)
        {
        case 1:
            cout << "Ingrese su sueldo actual: ";
            cin >> sueldo;
            break;
        case 2:
            cout << "Ingrese su categoria de trabajador: ";
            cin >> categoria;
            break;
        case 3:
            switch (categoria)
            {
                case 'S':
                    nuevo_sueldo = sueldo + (sueldo * 0.20);
                    cout << "Su nuevo sueldo es: " << nuevo_sueldo << endl;
                    break;
                case 'C':
                    nuevo_sueldo = sueldo + (sueldo * 0.10);
                    cout << "Su nuevo sueldo es: " << nuevo_sueldo << endl;
                    break;
                case 'D':
                    nuevo_sueldo = sueldo + (sueldo * 0.05);
                    cout << "Su nuevo sueldo es: " << nuevo_sueldo << endl;
                    break;
                case 'E':
                    cout << "Su nuevo sueldo es: " << sueldo << endl;
                    break;
            }
            break;
        default:
            cout << "Opcion no valida" << endl;
            break;
        }
    } while (opcion_menu != 0);

    return 0;
}