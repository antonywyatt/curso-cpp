#include<iostream>

using namespace std;

int main(){
    int Nota[10], i;
    int *p;

    cout<<"---Registro de notas---"<<endl;
    for(i = 0; i < 10; i++){
        cout<<"Ingrese la nota "<< i <<": ";
        cin>>Nota[i];
    }

    p = Nota;

    cout<<"----------------------"<<endl;
    cout<<"     Lista de Notas   "<<endl;
    cout<<"----------------------"<<endl;
    cout<<"Direccion 	Nota "<<endl;
    cout<<"----------------------"<<endl;
    for(i = 0; i < 10; i++){
        cout<<p<<"     	"<<*p<<endl;
        p++;
    }

    //determinar la cantidad de notas aprobadas, desaprobadas y promedio de notas usando punteros
    int aprobados = 0, desaprobados = 0;
    float promedio = 0;
    
    p = Nota;

    for(i = 0; i < 10; i++){
        if(*p >= 11){
            aprobados++;
        }else{
            desaprobados++;
        }
        promedio += *p;
        p++;
    }

    cout<<"----------------------"<<endl;
    cout<<"Cantidad de aprobados: "<<aprobados<<endl;
    cout<<"Cantidad de desaprobados: "<<desaprobados<<endl;
    cout<<"Promedio de notas: "<<promedio/10<<endl;


    system("pause");
    return 0;
}
