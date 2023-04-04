#include<iostream>

using namespace std;

int main(){
    int matriz[3][3];
    int i,j;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            cout<<"Ingrese el valor de la posicion "<<i<<","<<j<<": ";
            cin>>matriz[i][j];
        }
    }
    cout<<"La matriz es: "<<endl;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            cout<<matriz[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}