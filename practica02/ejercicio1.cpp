#include<iostream>

using namespace std;

int main(){
    //Escribe un programa que defina un vector de números y calcule la suma de sus elementos.
    int vector[100], nro, suma = 0;

    do{
        cout << "Ingrese la cantidad de elementos [1,100]:";
        cin >> nro;
        if(nro >=100 || nro < 0){
            cout << "La cantidad a ingresar debe ser entre 1 y 100" <<endl;
        }}
    while(nro>=100 || nro < 0);

    cout << "Ingrese el arreglo " << endl;
    //leemos datos
    for(int i = 0; i < nro; i++){
        cout << "Ingrese el elemento ["<<i<<"]: ";
        cin >> vector[i];
    }

    for(int i = 0; i < nro; i++){
        suma += vector[i];
    }
    
    cout << "La suma de los elementos es: " << suma << endl;

    return 0;
}