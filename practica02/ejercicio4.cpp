#include<iostream>
#define MAX 100

using namespace std;

void mayorSueldo(int total,float sueldos[MAX], string nombres[MAX]);
void promedio(int total, float sueldos[MAX]);

int main(){
    int n;
    cout<<"Ingrese la cantidad de empleados: ";
    cin>>n;

    float sueldos[n];
    string nombres[n];

    for(int i=0; i<n; i++){
        cout<<"Ingrese el NOMBRE del empleado con codigo "<< i <<": ";
        cin>>nombres[i];
        cout<<"Ingrese el SUELDO del empleado (s/.) con codigo "<< i <<": ";
        cin>>sueldos[i];
    }
    mayorSueldo(n,sueldos, nombres);
    promedio(n,sueldos);
}

void mayorSueldo(int total,float sueldos[MAX], string nombres[MAX]){
    int mayor=0;
    for(int i=0; i<total; i++){
        if(sueldos[i]>sueldos[mayor]){
            mayor=i;
        }
    }
    cout<<"======================================"<<endl;
    cout<<"El empleado con mayor sueldo es: "<<nombres[mayor]<<endl;
    cout<<"El sueldo del empleado es: "<<sueldos[mayor]<<endl;
    cout<<"======================================"<<endl;
}

void promedio(int total, float sueldos[MAX]){
    float suma=0;
    for(int i=0; i<total; i++){
        suma+=sueldos[i];
    }
    cout<<"El promedio de los sueldos es: "<<suma/total<<endl;
}
