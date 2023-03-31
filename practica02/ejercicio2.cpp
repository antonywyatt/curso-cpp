#include<iostream>

using namespace std;

int main(){
    //Desarrolle un vector donde se ingresen 10 números enteros de 0 a 100, para luego mostrar en pantalla la cantidad de enteros de 0 a 50, de 51 a 75 y de 76 a 100
    int vector[10];
    int contador1=0, contador2=0, contador3=0;
    for(int i=0; i<10; i++){
        cout<<"Ingrese un numero: ";
        cin>>vector[i];
        if(vector[i]>=0 && vector[i]<=50){
            contador1++;
        }else if(vector[i]>=51 && vector[i]<=75){
            contador2++;
        }else if(vector[i]>=76 && vector[i]<=100){
            contador3++;
        }
    }
    cout<<"La cantidad de numeros entre 0 y 50 es: "<<contador1<<endl;
    cout<<"La cantidad de numeros entre 51 y 75 es: "<<contador2<<endl;
    cout<<"La cantidad de numeros entre 76 y 100 es: "<<contador3<<endl;
    return 0;
}