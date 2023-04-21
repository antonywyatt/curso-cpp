#include<iostream>
#define MAX 40 //cantidad de alumnos

using namespace std;

struct sAlumno{
    int codigo;
    string nombre;
    char sexo;
    float prom_practicas;
    float nota_parcial;
    float nota_final;
    float promedio_final;
};

sAlumno ingresarAlumno();
float calcularPromedio(sAlumno alumno);
void mostrarAlumnosAprobados(sAlumno alumnos[MAX], int nro_alumnos);
void mostrarAlumnosxSexo(sAlumno alumnos[MAX], int nro_alumnos);

int main(){

    sAlumno alumnos[MAX];
    int nro_alumnos, i;

    cout << "Ingrese la cantidad de Alumnos: ";
    cin >> nro_alumnos;

    for(i = 0; i < nro_alumnos; i++){
        alumnos[i] = ingresarAlumno();
        alumnos[i].promedio_final = calcularPromedio(alumnos[i]);
    }

    mostrarAlumnosxSexo(alumnos, nro_alumnos);
    mostrarAlumnosAprobados(alumnos, nro_alumnos);

    return 0;
}

sAlumno ingresarAlumno(){
    sAlumno alumno;

    cout << "Ingrese codigo del Alumno: ";
    cin >> alumno.codigo;
    cout << "Ingrese nombre del Alumno: ";
    cin >> alumno.nombre;
    cout << "Ingrese el SEXO del Alumno(M/F): ";
    cin >> alumno.sexo;
    cout << "Ingrese su promedio de prácticas: ";
    cin >> alumno.prom_practicas;
    cout << "Ingrese el promedio del Examen Parcial: ";
    cin >> alumno.nota_parcial;
    cout << "Ingrese el promedio del Examen Final: ";
    cin >> alumno.nota_final;

    return alumno;    
}

float calcularPromedio(sAlumno alumno){
    float promedio = 0;
    promedio = (alumno.prom_practicas * 2 + alumno.nota_parcial * 2 + alumno.nota_final * 3) / 7;
    return promedio;
}

void mostrarAlumnosAprobados(sAlumno alumnos[MAX], int nro_alumnos){
    int total_apro = 0;
    int total_desapro = 0;

    cout << "==========Todos los Aprobados y Desaprobados =============" << endl << endl;
    cout << "Nombre \t Promedio Final" << endl;
    for(int i = 0; i < nro_alumnos; i++){
        cout << alumnos[i].nombre << "\t" << alumnos[i].promedio_final << endl;
        if(alumnos[i].promedio_final >= 11){
            total_apro++;
        }else{
            total_desapro++;
        }
    }
    cout << "Total de alumnos Aprobado son: " << total_apro << endl;
    cout << "Total de alumnos Desaprobados son: " << total_desapro << endl;
}

void mostrarAlumnosxSexo(sAlumno alumnos[MAX], int nro_alumnos){
    cout << "==========Todos los Aprobados y Desaprobados por Sexo =============" << endl << endl;
    int total_m_a = 0;
    int total_f_a = 0;
    
    int total_m_d = 0;
    int total_f_d = 0;

    for(int i = 0; i < nro_alumnos; i++){
        if(alumnos[i].sexo == 'M' && alumnos[i].promedio_final >= 11){
            total_m_a++;
        }else if(alumnos[i].sexo == 'F' && alumnos[i].promedio_final >= 11){
            total_f_a++;
        }
        
        if(alumnos[i].sexo == 'F' && alumnos[i].promedio_final < 11){
            total_f_d++;
        }else if(alumnos[i].sexo == 'M' && alumnos[i].promedio_final < 11){
            total_m_d++;
        }
    }

    cout << "Total de alumnos MASCULINOS Aprobados son: " << total_m_a << endl;
    cout << "Total de alumnos MASCULINOS Desaprobados son: " << total_m_d << endl;
    cout << "Total de alumnos FEMENINOS Aprobados son: " << total_f_a << endl;
    cout << "Total de alumnos FEMENINOS Desaprobados son: " << total_f_d << endl;

}