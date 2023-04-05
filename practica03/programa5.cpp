#include<iostream>
#define MAX 1000

using namespace std;

void leerMatriz(int matriz[MAX][MAX], int filas, int columnas, int i, int j);
void mostrarMatriz(int matriz[MAX][MAX], int filas, int columnas, int i, int j);

int main(){
    /*
    Programa que suma dos matrices cuyo tamaño va a ser definido por el usuario, el resultado de
    la suma lo guarda en otra matriz y se imprime en pantalla.
    */
    int filas, columnas, i, j;

    cout<<"Ingrese el numero de filas de la matriz: ";
    cin>>filas;

    cout<<"Ingrese el numero de columnas de la matriz: ";
    cin>>columnas;

    int matriz1[filas][columnas];
    int matriz2[filas][columnas];

    //llenar matriz 1
    for(i=0;i<filas;i++){
        for(j=0;j<columnas;j++){
            cout<<"Ingrese el valor de la posicion ["<<i<<","<<j<<"]: ";
            cin>>matriz1[i][j];
        }
    }
    //llenar matriz 2
    for(i=0;i<filas;i++){
        for(j=0;j<columnas;j++){
            cout<<"Ingrese el valor de la posicion ["<<i<<","<<j<<"]: ";
            cin>>matriz2[i][j];
        }
    }

    //mostrar matriz 1
    cout<<"Matriz 1"<<endl;
    for(i=0;i<filas;i++){
        for(j=0;j<columnas;j++){
            cout<<matriz1[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Matriz 2"<<endl;
    //mostrar matriz 2
    for(i=0;i<filas;i++){
        for(j=0;j<columnas;j++){
            cout<<matriz2[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"Matriz suma"<<endl;
    //mostrar matriz suma
    for(i=0;i<filas;i++){
        for(j=0;j<columnas;j++){
            cout<<matriz1[i][j] + matriz2[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}