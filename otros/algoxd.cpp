#include<iostream>

using namespace std;

float CalcularPromedioFinal();
string DeterminaCondicion();

//variables globales
float C1=0, EP=0, C2=0, EF=0;

int main(){
    int opcion;

    do{
        cout<<"------------------------"<<endl;
        cout<<"MENU DE NOTAS"<<endl;
        cout<<"------------------------"<<endl;
        cout<<"1. Ingresar notas"<<endl;
        cout<<"2. Mostrar notas"<<endl;
        cout<<"3. Calcular promedio final"<<endl;
        cout<<"4. Determinar condicion"<<endl;
        cout<<"8. Salir"<<endl;
        cout<<"Ingrese una opcion: ";
        cin>>opcion;

        switch(opcion){
            case 1:
                cout<<"Ingrese la nota del C1: ";
                cin>>C1;
                cout<<"Ingrese la nota del examen parcial: ";
                cin>>EP;
                cout<<"Ingrese la nota del C2: ";
                cin>>C2;
                cout<<"Ingrese la nota del examen final: ";
                cin>>EF;
                break;
            case 2:
                cout<<"La nota del C1 es: "<<C1<<endl;
                cout<<"La nota del examen parcial es: "<<EP<<endl;
                cout<<"La nota del C2 es: "<<C2<<endl;
                cout<<"La nota del examen final es: "<<EF<<endl;
                break;
            case 3:
                cout<<"El promedio final es: "<<CalcularPromedioFinal()<<endl;
                break;
            case 4:
                cout<<"La condicion del alumno es: "<<DeterminaCondicion()<<endl;
                break;
            case 8:
                cout<<"Saliendo..."<<endl;
                break;
            default:
                cout<<"Opcion invalida. Intente de nuevo."<<endl;
        }
    }while(opcion!=8);

}

float CalcularPromedioFinal(){
    float promedioFinal = 0;
    promedioFinal = (C1*0.2)+(EP*0.25)+(C2*0.2)+(EF*0.35);
    return promedioFinal;
}

string DeterminaCondicion(){
    string condicion;
    float promedioFinal = CalcularPromedioFinal();
    if(promedioFinal>=15){
        condicion = "Con honores";
    }else if(promedioFinal >= 10.5 && promedioFinal < 15){
        condicion = "Aprobó";
    }else if(promedioFinal < 10.5){
        condicion = "Quedó";
    }
    return condicion;
}
