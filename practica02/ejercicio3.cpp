#include<iostream>

using namespace std;

int main(){
    // Hacer un programa que lea 5 números en un arreglo, los copie a otro arreglo multiplicados por 2 y muestre el segundo arreglo
    int vector[5];
    int vector2[5];
    for(int i=0; i<5; i++){
        cout<<"Ingrese un numero["<<i<<"]: ";
        cin>>vector[i];
        vector2[i]=vector[i]*2;
    }
    cout<<"El vector 2 es: [";
    for(int i=0; i<5; i++){
        cout<<vector2[i]<<" ";
    }
    cout<<"]";

    return 0;
}