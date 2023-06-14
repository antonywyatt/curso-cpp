#include <iostream>
#include "LecturaDatos.h"
#include "Recursividad.h"

using namespace std;
void menu()
{
    int opc, n, b, e;
    double f;
    char rpta;
    do
    {
        cout << endl
             << endl;
        cout << "===== MENU RECURSIVIDAD ===\n";
        cout << "1. Factorial \n";
        cout << "2. Potencia \n";
        cout << "3. Fibonacci \n";
        cout << "4. Multiplicacion \n";
        cout << "5. Division \n";
        cout << "6. Salir \n";
        cout << "===========================\n";
        // validamos la opcion
        do
        {
            cout << "Ingrese opcion(1-6): ";
            opc = leedatoe(); // cin>>opc;
            if (opc < 1 || opc > 6)
                cout << "\tError. Opcion debe ser 1-4 \n";
        } while (opc < 1 || opc > 6);
        // Evaluando la opcion
        switch (opc)
        {
        case 1: // factorial
            cout << "Ingrese numero (>0): ";
            cin >> n;
            f = factorial(n);
            cout << "El factorial es : " << f << "\n\n";
            break;
        case 2: // Potencia
            cout << "Ingrese base: ";
            cin >> b;
            do{
                cout << "Ingrese exponente (>0): ";
                cin >> e;
                if(e <= 0)
                    cout << "Error. Debe ser > 0 \n";
            }while(e <= 0);
            //mostrar resultado
            for(int i = 1; i <= e; i++){
                cout << b << "^" << i << " = " << potencia(b, i) << endl;
            }
            break;
        case 3: // Fibonacci
            cout << "Ingrese numero (>0): ";
            cin >> n;
            for(int i = 0; i <= n; i++){
                cout << fibonacci(i) << " ";
            }
            break;
        case 4: // Multiplicacion
            cout << "Ingrese numero 1: ";
            cin >> n;
            cout << "Ingrese numero 2: ";
            cin >> b;
            cout << n << " * " << b << " = " << multiplicacion(n, b) << endl;
            break;
        case 5:
            cout << "Ingrese numero 1: ";
            cin >> n;
            cout << "Ingrese numero 2: ";
            cin >> b;
            cout << n << " / " << b << " = " << division(n, b) << endl;
            break;
        case 6:
            do
            {
                cout << "Esta seguro que desea salir(s/n) ? ";
                rpta = leedatoc();
                rpta = toupper(rpta);
                if (rpta != 'S' && rpta != 'N')
                    cout << "Error. Debe ser S o N \n";
            } while (rpta != 'S' && rpta != 'N');
            if (rpta == 'S')
                cout << "Adios!!!\n\n";
            else
                menu();
            break;
        }
    } while (opc != 6);
}
int main()
{
    setlocale(LC_CTYPE, "Spanish");

    menu();
    return 0;
}
