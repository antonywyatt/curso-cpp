#include<iostream>

using namespace std;

struct sEmpresado{
    string nombre;
    float sueldo;
    char genero;
};


int main(){

    sEmpresado empleados[10], *pEmpleados;
    
    //Registar datos de los 10 empleados
    for(int i = 0; i < 3; i++){
        cout << "Ingrese nombre del empleado [" << i << "]: ";
        cin >> empleados[i].nombre;
        do{
            cout << "Ingrese sueldo del empleado mayor a 1000 [" << i << "]: ";
            cin >> empleados[i].sueldo;
        }while(empleados[i].sueldo < 1000);
        do{
            cout << "Ingrese genero del empleado [" << i << "] (F/M): ";
            cin >> empleados[i].genero;
        }while(empleados[i].genero != 'F' && empleados[i].genero != 'M');
    }

    //Mostrar datos de los 10 empleados
    cout << "Nombre\t\tGenero\t\tSueldo" << endl;
    
    pEmpleados = empleados;
    
    //declarar variables necesarias
    int cantMujeres = 0;
    float totalSueldos = 0;
    float totalSueldosMujeres = 0;
    float mayorSueldo = 0;
    float menorSueldo = 1000;
    string nombreMayorSueldo;
    string nombreMenorSueldo;

    for(int i = 0; i < 3; i++){
	    cout << pEmpleados->nombre << "\t\t" << pEmpleados->genero << "\t\t" << pEmpleados->sueldo << endl;
	
        //calcular cantidad de mujeres
        if(pEmpleados->genero == 'F'){
            cantMujeres++;
        }

        //calcular total de sueldos
        totalSueldos += pEmpleados->sueldo;

        //calcular total de sueldos de mujeres
        if(pEmpleados->genero == 'F'){
            totalSueldosMujeres += pEmpleados->sueldo;
        }

        //capturar nombre del empleado con mayor sueldo
        if(pEmpleados->sueldo > mayorSueldo){
            mayorSueldo = pEmpleados->sueldo;
            nombreMayorSueldo = pEmpleados->nombre;
        }

        //capturar nombre del empleado con menor sueldo
        if(pEmpleados->sueldo < menorSueldo){
            menorSueldo = pEmpleados->sueldo;
            nombreMenorSueldo = pEmpleados->nombre;
        }

        pEmpleados++;
    }

    cout << "-------------------------------------------------" << endl;
    cout << "Cantidad de mujeres: " << cantMujeres << endl; 
    cout << "Total de sueldos: " << totalSueldos << endl;
    cout << "Total de sueldos de mujeres: " << totalSueldosMujeres << endl;
    cout << "Nombre del empleado con mayor sueldo: " << nombreMayorSueldo << " - Con Sueldo: " << mayorSueldo << endl;
    cout << "Nombre del empleado con menor sueldo: " << nombreMenorSueldo << " - Con Sueldo: " << menorSueldo <<endl;

    return 0;
}
