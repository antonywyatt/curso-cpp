#include<iostream>

using namespace std;

int main(){
    /**
     * - Programa que almacene números enteros en una matriz cuadrada de 3x3, para mostrar la
        matriz y los elementos múltiplos de 5 y su posición en la matriz.
    */

    int matriz[3][3];
    int i, j;

    //llenar matriz
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            cout<<"Ingrese el valor de la posicion ["<<i<<","<<j<<"]: ";
            cin>>matriz[i][j];
        }
    }

    //mostrar matriz
    cout<<"La matriz es: "<<endl;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            cout<<matriz[i][j]<<"\t";
        }
        cout<<endl;
    }

    //multiplos de 5
    cout<<"Los multiplos de 5 son: "<<endl;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if(matriz[i][j] % 5 == 0){
                cout<<matriz[i][j]<<" en la posicion ["<<i<<","<<j<<"]"<<endl;
            }
        }
    }

    return 0;
}