#include <iostream>

using namespace std;

// Variables globales
int hombresAprobados = 0;
int mujeresAprobadas = 0;
int hombresCasadosDesaprobados = 0;
int mujeresSolterasAprobadas = 0;
float sumatoriaNotas = 0;
float promedioNotas = 0;

// Funciones
void leerDatos(){
    char genero;
    char estadoCivil;
    float nota;

    cout << "Ingrese el genero (M/F): ";
    cin >> genero;
    cout << "Ingrese el estado civil (C/S): ";
    cin >> estadoCivil;
    cout << "Ingrese la nota: ";
    cin >> nota;

    if(nota >= 11){
        if(genero == 'M'){
            hombresAprobados++;
        }else if(genero == 'F'){
            mujeresAprobadas++;
        }
    }else{
        if(genero == 'M' && estadoCivil == 'C'){
            hombresCasadosDesaprobados++;
        }else if(genero == 'F' && estadoCivil == 'S'){
            mujeresSolterasAprobadas++;
        }
    }

    sumatoriaNotas += nota;
}

void reporteFinal(){
    cout << "Cantidad de hombres aprobados: " << hombresAprobados << endl;
    cout << "Cantidad de mujeres aprobadas: " << mujeresAprobadas << endl;
    cout << "Cantidad de hombres casados desaprobados: " << hombresCasadosDesaprobados << endl;
    cout << "Cantidad de mujeres solteras aprobadas: " << mujeresSolterasAprobadas << endl;
    cout << "Sumatoria de notas: " << sumatoriaNotas << endl;
    cout << "Promedio de notas: " << sumatoriaNotas / (hombresAprobados + mujeresAprobadas + hombresCasadosDesaprobados + mujeresSolterasAprobadas) << endl;
}

int main(){

    int cantidad;
    cout << "Ingrese la cantidad de estudiantes: ";
    cin >> cantidad;

    for(int i = 0; i < cantidad; i++){
        leerDatos();
    }

    reporteFinal();

    return 0;
}