#include<iostream>

using namespace std;

// VARIABLES GLOBALES
int promedioFinal;
int acumuladorPromediosFinales = 0;
int cantidadPromediosFinales = 0;
float promedioGeneral = 0;

// PROTOTIPOS DE FUNCIONES
void ingresarPromedioFinal();
void mostrarAcumuladorPromediosFinales();
void mostrarPromedioGeneral();

int main(){
    int opcion;
    do{
        cout << "===========MENU PRINCIPAL===========" << endl;
        cout << "1. Ingresar promedio final" << endl;
        cout << "2. Mostrar promedios finales ingresados" << endl;
        cout << "3. Mostrar promedio general" << endl;
        cout << "4. Salir" << endl;
        cout << "====================================" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        switch(opcion){
            case 1:
                ingresarPromedioFinal();
                break;
            case 2:
                mostrarAcumuladorPromediosFinales();
                break;
            case 3:
                mostrarPromedioGeneral();
                break;
            case 4:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opcion incorrecta" << endl;
                break;
        }
    }while(opcion != 4);

    return 0;
}

// FUNCIONES
void ingresarPromedioFinal(){
    char continuar; // s S || n N
    do{
        do{
            cout << "Ingrese el promedio final: ";
            cin >> promedioFinal;
        }while(promedioFinal < 0 || promedioFinal > 20);
        acumuladorPromediosFinales += promedioFinal;
        cantidadPromediosFinales++;
        cout << "Desea continuar? (s/n): ";
        cin >> continuar;
    }while(continuar == 's' || continuar == 'S');
}

void mostrarPromedioFinal(){
    cout << "El promedio final es: " << promedioFinal << endl;
}

void mostrarAcumuladorPromediosFinales(){
    cout << "El acumulador de promedios finales es: " << acumuladorPromediosFinales << endl;
    cout << "La cantidad de promedios finales es: " << cantidadPromediosFinales << endl;
}

void mostrarPromedioGeneral(){
    promedioGeneral = acumuladorPromediosFinales / cantidadPromediosFinales;
    cout << "El promedio general es: " << promedioGeneral << endl;
}