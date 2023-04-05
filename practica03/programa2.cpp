#include<iostream>

using namespace std;

int main(){
    int matriz[4][4];
    int i, j;

    //llenar matriz
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cout<<"Ingrese el valor de la posicion ["<<i<<","<<j<<"]: ";
            cin>>matriz[i][j];
        }
    }

    //mostrar matriz
    cout<<"La matriz es: "<<endl;
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            cout<<matriz[i][j]<<" ";
        }
        cout<<endl;
    }

    //suma de la diagonal principal
    int sumadiagonalP = 0;
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            if(i==j){
                sumadiagonalP += matriz[i][j];
            }
        }
    }
    cout<<"La suma de la diagonal principal es: "<<sumadiagonalP<<endl;
    
    //suma de la diagonal secundaria
    int sumadiagonalS = 0;
    for(i=0; i<4;i++){
        for(j=0; j<4; j++){
            if(i+j==3){
                sumadiagonalS += matriz[i][j];
            }
        }
    }
    cout<<"La suma de la diagonal secundaria es: "<<sumadiagonalS<<endl;

}