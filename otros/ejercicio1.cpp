#include <iostream>

using namespace std;

// Variables globales
int trabajadores = 0;
int trabajadores10 = 0;
int trabajadores15 = 0;
int trabajadores20 = 0;
int trabajadores25 = 0;
float sueldos = 0;

// Funciones
void leerDatos(){
    int sueldo;
    cout << "Ingrese el sueldo: ";
    cin >> sueldo;
    trabajadores++;
    sueldos += sueldo;
    if(sueldo >= 5001){
        trabajadores10++;
    }else if(sueldo >= 3501 && sueldo <= 5000){
        trabajadores15++;
    }else if(sueldo >= 2001 && sueldo <= 3500){
        trabajadores20++;
    }else if(sueldo >= 2000){
        trabajadores25++;
    }
}

void reporteFinal(){
    cout << "Cantidad de trabajadores: " << trabajadores << endl;
    cout << "Cantidad de trabajadores con aumento de 10%: " << trabajadores10 << endl;
    cout << "Cantidad de trabajadores con aumento de 15%: " << trabajadores15 << endl;
    cout << "Cantidad de trabajadores con aumento de 20%: " << trabajadores20 << endl;
    cout << "Cantidad de trabajadores con aumento de 25%: " << trabajadores25 << endl;
    cout << "Sueldos totales: " << sueldos << endl;
}

int main(){

    int cantidad;
    cout << "Ingrese la cantidad de trabajadores: ";
    cin >> cantidad;

    for(int i = 0; i < cantidad; i++){
        leerDatos();
    }

    reporteFinal();

    return 0;
}