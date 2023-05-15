#include <iostream>

using namespace std;

// Variables globales
int facturas = 0;
int facturas600 = 0;
float montoTotal = 0;
float litrosVendidos = 0;

// Funciones
void leerDatos(){
    int codigo;
    float cantidad;
    float precio;

    cout << "Ingrese el codigo: ";
    cin >> codigo;
    cout << "Ingrese la cantidad: ";
    cin >> cantidad;
    cout << "Ingrese el precio: ";
    cin >> precio;

    facturas++;
    montoTotal += cantidad * precio;
    litrosVendidos += cantidad;

    if(cantidad * precio > 600){
        facturas600++;
    }
}

void reporteFinal(){
    cout << "Cantidad de facturas: " << facturas << endl;
    cout << "Cantidad de facturas con monto total a facturar de mas de 600: " << facturas600 << endl;
    cout << "Acumulado de monto total a facturar: " << montoTotal << endl;
    cout << "Acumulado de litros vendidos: " << litrosVendidos << endl;
}

int main(){

    int cantidad;
    cout << "Ingrese la cantidad de facturas: ";
    cin >> cantidad;

    for(int i = 0; i < cantidad; i++){
        leerDatos();
    }

    reporteFinal();

    return 0;
}