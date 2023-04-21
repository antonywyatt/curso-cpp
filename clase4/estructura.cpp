#include<iostream>
#define MAX 3

using namespace std;

struct sPersona
{
    string nombre;
    string apellidoPaterno;
    string apellidoMaterno;
    int edad;
};


sPersona registrarPersona();
void mostrarDetallePersona(sPersona per);
void mostrarPersona(sPersona per);

int main(){

    sPersona alumnos[MAX];

    int i;
    for(i=0; i < MAX; i++){
        alumnos[i] = registrarPersona();
    }
    system("Pause");
    system("cls");
    cout << "===================Mostrar Persona ===================" << endl;
    for(i=0;i< MAX; i++){
        mostrarPersona(alumnos[i]);
        mostrarDetallePersona(alumnos[i]);
    }

    return 0;
}

sPersona registrarPersona(){
    sPersona per;

    cout << "===================Registro Persona ===================" << endl;
    cout << "Ingrese el Nombre: " ; cin >> per.nombre;
    cout << "Ingrese el Apelido Paterno: " ; cin >> per.apellidoPaterno;
    cout << "Ingrese el Apellido Materno: " ; cin >> per.apellidoMaterno;
    cout << "Ingrese la Edad: " ; cin >> per.edad;
    cout << "=======================================================" << endl;

    return per;
}

void mostrarDetallePersona(sPersona per){
    cout << "   Nombre:"  << per.nombre << endl;
    cout << "   Apelido Paterno:" << per.apellidoPaterno << endl;
    cout << "   Apellido Materno:" << per.apellidoMaterno << endl;
    cout << "   Edad" << per.edad << endl;
    cout << "_______________________________________________________" << endl;
}

void mostrarPersona(sPersona per){
    cout << per.nombre << "\t\t"
         << per.apellidoPaterno << " "
         << per.apellidoMaterno << endl;
}