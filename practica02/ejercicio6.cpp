#include<iostream>

using namespace std;

int main(){
    //vectores que guarden nombre, nota y sexo (M, F) de "n" estudiantes
    int n;
    cout<<"Ingrese el numero de estudiantes: ";
    cin>>n;
    string nombres[n];
    int notas[n];
    char sexos[n];

    //recoger datos de estudiantes
    for(int i=0; i<n; i++){
        cout<<"Ingrese el nombre del estudiante "<<i+1<<": ";
        cin>>nombres[i];
        cout<<"Ingrese la nota del estudiante "<<i+1<<": ";
        cin>>notas[i];
        cout<<"Ingrese el sexo del estudiante "<<i+1<<": ";
        cin>>sexos[i];
        cout<<"-------------------------------------"<<endl;
    }
}