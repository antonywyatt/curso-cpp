#include<iostream>
#define MAX 100

using namespace std;

void listarAproDesaprov(int notas[MAX], 
    string nombres[MAX], 
    char sexos[MAX],
    int i, int n, int total, float promedio, string estado);
void listarporSexo(string nombres[MAX], char sexos[MAX], string sexo, int total, int n, int i);

int main(){
    //vectores que guarden nombre, nota y sexo (M, F) de "n" estudiantes
    int n, i, total;
    float promedio;
    cout<<"Ingrese el numero de estudiantes: ";
    cin>>n;
    string nombres[n];
    int notas[n];
    char sexos[n];

    //recoger datos de estudiantes
    for(i=0; i<n; i++){
        cout<<"Ingrese el Nombre del estudiante "<<i+1<<": ";
        cin>>nombres[i];
        cout<<"Ingrese la Nota del estudiante 0-20 "<<i+1<<": ";
        cin>>notas[i];
        cout<<"Ingrese el Sexo del estudiante (M/F) "<<i+1<<": ";
        cin>>sexos[i];
        cout<<"-------------------------------------"<<endl;
    }

    listarAproDesaprov(notas, nombres, sexos, i, n, total, promedio, "Aprobados");
    cout<<"-------------------------------------"<<endl;
    listarAproDesaprov(notas, nombres, sexos, i, n, total, promedio, "Desaprobados");
    cout<<"====================================="<<endl;
    listarporSexo(nombres, sexos, "M", total,n, i);
    cout<<"-------------------------------------"<<endl;
    listarporSexo(nombres, sexos, "F", total,n, i);

    //promedio total de notas
    cout<<"-------------------------------------"<<endl;
    promedio = 0;
    for(i=0;i<n;i++){
        promedio += notas[i];
    }
    
    cout<<"Promedio Total de Notas: "<<promedio/n<<endl;
}

void listarAproDesaprov(int notas[MAX], 
    string nombres[MAX], char sexos[MAX], 
    int i, int n, int total, float promedio, string estado){
    total = 0;
    promedio = 0;
    if(estado == "Aprobados"){
        cout<<"Estudiantes Aprobados"<<endl;
        cout<<"Nombres\tNotas\tSexos"<<endl;
        for(i=0;i<n;i++){
            if(notas[i] >= 11){
                cout<<nombres[i]<<"\t"<<notas[i]<<"\t"<<sexos[i]<<endl;
                promedio += notas[i];
                total++;
            }
        }
        cout<<"Total de Alumnos Aprobados: "<<total<<endl;
        cout<<"Promedio de Notas Aprobadas: "<<promedio/total<<endl;
    }else if(estado == "Desaprobados"){
        cout<<"Estudiantes Desaprobados"<<endl;
        cout<<"Nombres\tNotas\tSexos"<<endl;
        for(i=0;i<n;i++){
            if(notas[i] < 11){
                cout<<nombres[i]<<"\t"<<notas[i]<<"\t"<<sexos[i]<<endl;
                promedio += notas[i];
                total++;
            }
        }
        cout<<"Total de Alumnos Desprobados: "<<total<<endl;
        cout<<"Promedio de Notas Desaprobadas: "<<promedio/total<<endl;
    }
}

void listarporSexo(string nombres[MAX], char sexos[MAX], string sexo, int total, int n, int i){
    total = 0;
    if(sexo == "M"){
        cout<<"Estudiantes Masculinos"<<endl;
        cout<<"Nombres\tSexos"<<endl;
        for(i=0;i<n;i++){
            if(sexos[i] == 'M'){
                cout<<nombres[i]<<"\t"<<sexos[i]<<endl;
                total++;
            }
        }
        cout<<"Total de Alumnos Masculinos: "<<total<<endl;
        
    }else if(sexo == "F"){
        cout<<"Estudiantes Femeninos"<<endl;
        cout<<"Nombres\tSexos"<<endl;
        for(i=0;i<n;i++){
            if(sexos[i] == 'F'){
                cout<<nombres[i]<<"\t"<<sexos[i]<<endl;
                total++;
            }
        }
        cout<<"Total de Alumnos Femeninos: "<<total<<endl;
    }
}