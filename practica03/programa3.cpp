#include<iostream>

using namespace std;

int main(){
    int matriz[5][4];
    int i, j;
    int menor = 0;
    int posicion_i = 0, posicion_j = 0;

    //llenar matriz
    for(i=0;i<5;i++){
        for(j=0;j<4;j++){
            cout<<"Ingrese el valor de la posicion ["<<i<<","<<j<<"]: ";
            cin>>matriz[i][j];
        }
    }

    //mostrar matriz
    cout<<"La matriz es: "<<endl;
    for(i=0;i<5;i++){
        for(j=0;j<4;j++){
            cout<<matriz[i][j]<<"\t";
        }
        cout<<endl;
    }

    //menor de los elementos
    menor = matriz[0][0]; //agarro el primer elemento de la matriz
    for(i=0;i<5;i++){
        for(j=0;j<4;j++){
            if(matriz[i][j] < menor){
                menor = matriz[i][j];
                posicion_i = i;
                posicion_j = j;
            }
        }
    }

    cout<<"El menor de los elementos es: "<<menor<<endl;
    cout<<"Su posicion es: ["<<posicion_i<<","<<posicion_j<<"]"<<endl;

    return 0;
}