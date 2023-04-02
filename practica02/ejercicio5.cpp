#include <iostream>
#define MAX 100

using namespace std;

void mostrarCategoria(int i, int total, char categorias[MAX], string nombres[MAX], float ventas[MAX], char categoria);

int main() {
    int n, i;
    cout<<"Ingrese la cantidad de empleados: ";
    cin>>n;

    string nombres[n];
    char categorias[n]; // A, B
    float ventas[n];

    for(i=0; i<n; i++){
        cout<<"Ingrese el NOMBRE del empleado con codigo "<< i <<": ";
        cin>>nombres[i];
        cout<<"Ingrese la CATEGORIA del empleado (A/B) con codigo "<< i <<": ";
        cin>>categorias[i];
        cout<<"Ingrese las VENTAS del empleado (s/.) con codigo "<< i <<": ";
        cin>>ventas[i];
        cout<<"--------------------------------------"<<endl;
    }

    //promedio de ventas
    float suma=0;
    for(i=0; i<n; i++){
        suma+=ventas[i];
    }
    cout<<"--------------------------------------"<<endl;

    cout<<"Nombre empleado \t| Categoría\t| Venta"<<endl;
    for(i=0; i<n; i++){
        cout<<nombres[i]<<" \t| "<<categorias[i]<<" \t| s/. "<<ventas[i]<<endl;
    }
    cout<<"\n"<<endl;
    cout<<"Cantidad de empleados: "<<n<<endl;
    cout<<"Promedio de ventas: s/. "<<suma/n<<endl;
    cout<<"--------------------------------------"<<endl;

    mostrarCategoria(i,n, categorias,nombres,ventas,'A');
    cout<<"--------------------------------------"<<endl;
    mostrarCategoria(i,n, categorias,nombres,ventas,'B');
    
    return 0;
}

void mostrarCategoria(int i,int total, char categorias[MAX], string nombres[MAX], float ventas[MAX], char categoria){
    //promedio de ventas
    float suma=0;
    int total_empleado=0;

    cout<<"Empleados de la categoria "<<categoria<<":"<<endl;

    cout<<"Nombre empleado | Categoría | Venta"<<endl;
    for(i=0; i<total; i++){
        if(categorias[i]==categoria){
            cout<<nombres[i]<<" | "<<categorias[i]<<" | s/. "<<ventas[i]<<endl;
            suma+=ventas[i];
            total_empleado++;
        }
    }
    cout<<"\n"<<endl;
    cout<<"Cantidad de empleados: "<<total_empleado<<endl;
    cout<<"Promedio de ventas: s/. "<<suma/total_empleado<<endl;
};