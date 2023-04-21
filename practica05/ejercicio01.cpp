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

sAlumno registrarAlumno(int i);
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
				alumnos[i] = registrarAlumno(i);
			}
			break;
	    case 2:
			cout << "================================================" << endl;
			cout << "Mostrando Nro de Alumnos Aprobado y Desaprobados" << endl;
			cout << "================================================" << endl;
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


sAlumno registrarAlumno(int i){
	sAlumno alumno;

	cout << "Ingrese el codigo del alumno: ";
	cin >> alumno.codigo;

	cout << "Ingrese el nombre del alumno [" << alumno.codigo << "]: ";
	cin >> alumno.nombre;

	//validar que el sexo sea M o F
	do{
	    cout << "Ingrese el sexo del alumno (F/M) [" << alumno.codigo << "]: ";
	    cin >> alumno.sexo;
	}while(alumno.sexo != 'M' && alumno.sexo != 'F');

	cout << "Ingrese el promedio de practicas del alumno [" << alumno.codigo << "]: ";
	cin >> alumno.promedio_practicas;

	cout << "Ingrese la nota de parciales del alumno [" << alumno.codigo << "]: ";
	cin >> alumno.nota_parciales;

	cout << "Ingrese la nota final del alumno [" << alumno.codigo << "]: ";
	cin >> alumno.nota_final;

	cout << "================================================" << endl;

	alumno.promedio_final = (alumno.promedio_practicas*2 + alumno.nota_parciales*2 + alumno.nota_final*3) / 7;

	return alumno;
}                   
        
void mostrarAprobadosDesaprobados(sAlumno alumnos[MAX], int cantAlumnos){
 	int aprobados = 0;
 	int desaprobados = 0;
	int aprobados_m = 0;
	int aprobados_f = 0;

	cout << "Nombre\t\tPromedio Final\t\tSexo" << endl;
	for(int i = 0; i < cantAlumnos; i++){

	    cout << alumnos[i].nombre << "\t\t" << alumnos[i].promedio_final << "\t\t\t" << alumnos[i].sexo << endl;

	    if(alumnos[i].promedio_final >= 11){
			aprobados++;
	    }else{
			desaprobados++;
	    }
		if(alumnos[i].sexo == 'M' && alumnos[i].promedio_final >= 11){
			aprobados_m++;
		}else if(alumnos[i].sexo == 'F' && alumnos[i].promedio_final >= 11){
			aprobados_f++;
		}
	}
	cout << "================================================" << endl;
	cout << "Cantidad de alumnos aprobados: " << aprobados << endl;
    cout << "Cantidad de alumnos desaprobados: " << desaprobados << endl;
	cout << "Cantidad de alumnos aprobados de genero masculino: " << aprobados_m << endl;
	cout << "Cantidad de alumnos aprobados de genero femenino: " << aprobados_f << endl;
} 
