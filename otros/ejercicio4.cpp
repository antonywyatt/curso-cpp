#include <iostream>

using namespace std;

// Variables globales
int personas = 0;
int pesoNormal = 0;
int obesidadMedia = 0;
int obesidadMorbida = 0;

// Funciones
void leerDatos(){
    float peso;
    float talla;
    float imc;

    //validar
    do{
        cout << "Ingrese el peso: ";
        cin >> peso;
    }while(peso < 38 || peso > 260);
    do{
        cout << "Ingrese la talla: ";
        cin >> talla;
    }while(talla < 0.90 || talla > 2.20);

    imc = peso / (talla * talla);

    if(imc < 18.50){
        cout << "Infra Peso" << endl;
    }else if(imc >= 18.50 && imc <= 24.99){
        cout << "Peso Normal" << endl;
        pesoNormal++;
    }else if(imc >= 25 && imc <= 29.99){
        cout << "Sobre Peso" << endl;
    }else if(imc >= 30 && imc <= 34.99){
        cout << "Obesidad leve" << endl;
    }else if(imc >= 35 && imc <= 39.99){
        cout << "Obesidad media" << endl;
        obesidadMedia++;
    }else if(imc >= 40){
        cout << "Obesidad morbida" << endl;
        obesidadMorbida++;
    }

    personas++;
}

void reporteFinal(){
    cout << "Cantidad de personas: " << personas << endl;
    cout << "Cantidad de personas con peso normal: " << pesoNormal << endl;
    cout << "Cantidad de personas con obesidad media: " << obesidadMedia << endl;
    cout << "Cantidad de personas con obesidad morbida: " << obesidadMorbida << endl;
}

int main(){

    int cantidad;
    cout << "Ingrese la cantidad de personas: ";
    cin >> cantidad;

    for(int i = 0; i < cantidad; i++){
        leerDatos();
    }

    reporteFinal();

    return 0;
}