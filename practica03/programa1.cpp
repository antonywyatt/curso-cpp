#include<iostream>

using namespace std;

int main(){

    char matriz1[3][5] = 
    {'a', 'y', 'h', 's', 'u',
     't', 'v', 'A', 'm', 'z',
     '#', '$', 'b', 'N', 'p'};

    int i, j;
    
    //mostrar datos de la matriz
    cout<<"La matriz TABLA es: "<<endl;
    for(i = 0; i < 3; i++){
        for(j = 0; j < 5; j++){
            cout << matriz1[i][j] << " ";
        }
        cout << endl;
    }

    //modificar datos de la matriz
    cout<<"La nueva matriz TABLA es: "<<endl;
    for(i = 0; i < 3; i++){
        for(j = 0; j < 5; j++){
            if(matriz1[i][j] == 'a'){matriz1[i][j] = 'A';}
            if(matriz1[i][j] == 'y'){matriz1[i][j] = '&';}
            if(matriz1[i][j] == 'm'){matriz1[i][j] = 'X';}
            if(matriz1[i][j] == '$'){matriz1[i][j] = 'C';}
            if(matriz1[i][j] == 'b'){matriz1[i][j] = 'H';}
            cout << matriz1[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}