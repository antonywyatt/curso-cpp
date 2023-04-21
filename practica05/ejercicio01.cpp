#include <iostream>
#define MAX 40 //maxima cantida de alumnos

using namespace std;

struct sAlumno{
    int codigo;
    string nombre;
    char sexo; //M o F
    float promedio_practicas;
    float nota_parciales;
    float nota_final;
    float promedio_final;
};

sAlumno registrarAlumno();
void mostrarAprobadosDesaprobados(sAlumno alumnos[MAX], int cantAlumnos);

int main(){
    //validar la cantidad de alumnos
    //si es mayor a 40, no se puede
    int cantAlumnos;
    sAlumno alumnos[MAX];

    do{
	cout << "La cantidad de alumnos no puede ser mayor a " << MAX << endl;
	cout << "Ingrese la cantidad de alumnos: ";
	cin >> cantAlumnos;
    }while(cantAlumnos > MAX);

    int opcion;

    do{
	cout << "1. Ingresar alumnos" << endl;
	cout << "2. Listar aprobados y desaprobados" << endl;
	cout << "3. Salir" << endl;
	cout << "Ingrese una opcion: ";
	cin >> opcion;

	switch(opcion){
	    case 1:
		cout << "Ingresar alumnos" << endl;
		for(int i = 0; i < cantAlumnos; i++){
		    alumnos[i] = registrarAlumno();
		}
		break;
	    case 2:
		cout << "================================================" << endl;
		cout << "Mostrando Nro de Alumnos Aprobado y Desaprobados" << endl;
		mostrarAprobadosDesaprobados(alumnos, cantAlumnos);
		break;
	    case 3:
		cout << "Salir" << endl;
		break;
	    default:
		cout << "Opcion incorrecta" << endl;
		break;
	}

    }while(opcion != 3);


    return 0;
}


sAlumno registrarAlumno(){
	sAlumno alumno;

	cout << "Ingrese el codigo del alumno: ";
	cin >> alumno.codigo;

	cout << "Ingrese el nombre del alumno: ";
	cin >> alumno.nombre;

	cout << "Ingrese el sexo del alumno: ";
	cin >> alumno.sexo;

	cout << "Ingrese el promedio de practicas del alumno: ";
	cin >> alumno.promedio_practicas;

	cout << "Ingrese la nota de parciales del alumno: ";
	cin >> alumno.nota_parciales;

	cout << "Ingrese la nota final del alumno: ";
	cin >> alumno.nota_final;

	alumno.promedio_final = (alumno.promedio_practicas*2 + alumno.nota_parciales*2 + alumno.nota_final*3) / 7;

	return alumno;
}                   
        
void mostrarAprobadosDesaprobados(sAlumno alumnos[], int cantAlumnos){
 	int aprobados = 0;
 	int desaprobados = 0;
  
	for(int i = 0; i < cantAlumnos; i++){
	    if(alumnos[i].promedio_final >= 4){
		aprobados++;
	    }else{
		desaprobados++;
	    }
	}
 
	cout << "Cantidad de alumnos aprobados: " << aprobados << endl;
        cout << "Cantidad de alumnos desaprobados: " << desaprobados << endl;
} 
