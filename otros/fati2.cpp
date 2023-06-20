#include<iostream>

using namespace std;

int cantidadHijos = 0;
int cantidadEmpleadosSinEsposa = 0;
int cantidadEmpleadosSinHijos = 0;
int cantidadEsposasDesempleadas = 0;
int cantidadHijosUniversidad;
int cantidadHijosEmpleado = 0;
float sueldoBase = 0;
float sueldoTotal = 0;


void mostrarMenu();
void registrarEmpleado();
void mostrarReporte();


int main(){
    mostrarMenu();
    return 0;
}

void mostrarMenu(){
    int opcion;
    do{
        cout<< "______________Menu_____________" << endl;
        cout<<"1. Registrar empleado"<<endl;
        cout<<"2. Mostrar empleados"<<endl;
        cout<<"3. Salir"<<endl;
        cout<< "_______________________________" << endl;
        cout<<"Ingrese una opcion: ";
        cin>>opcion;
        switch(opcion){
            case 1:
                registrarEmpleado();
                break;
            case 2:
                mostrarReporte();    
                break;
            case 3:
                cout<<"Gracias por usar el programa"<<endl;
                break;
            default:
                cout<<"Opcion incorrecta"<<endl;
                break;
        }
    }while(opcion!=3);
}

bool validarRespuesta(){
    char respuesta;
    cin>>respuesta;
    if(respuesta=='s' || respuesta=='S'){
        return true;
    }else if(respuesta=='n' || respuesta=='N'){
        return false;
    }else{
        cout<<"Respuesta incorrecta"<<endl;
        return validarRespuesta();
    }
}

void registrarEmpleado(){
    bool tieneEsposa = false;
    bool tieneHijos = false;
    bool tieneHijosUniversidad = false;
    cout<<"Ingrese el sueldo base: ";
    cin>>sueldoBase;
    sueldoTotal+=sueldoBase;
    cout<<"Ingrese la cantidad de hijos: ";
    cin>>cantidadHijosEmpleado;
    cantidadHijos+=cantidadHijosEmpleado;
    if(cantidadHijosEmpleado>0){
        tieneHijos = true;
        if(cantidadHijos > 3){
            sueldoTotal+=200; //200 soles por cada hijo mayor a 3
        }
    }else{
        cantidadEmpleadosSinHijos++;
    }
    cout<<"Tiene esposa? (s/n): ";
    tieneEsposa = validarRespuesta();
    if(tieneEsposa){
        cout<<"Esposa trabaja? (s/n): ";
        if(!validarRespuesta()){
            cantidadEsposasDesempleadas++;
            sueldoTotal+=100; //100 soles por esposa desempleada
        }
    }else{
        cantidadEmpleadosSinEsposa++;
    }
    cout<<"Tiene hijos en la universidad? (s/n): ";
    if(validarRespuesta()){
        do{
            cout<<"Ingrese la cantidad de hijos en la universidad: ";
            cin>>cantidadHijosUniversidad;
            sueldoTotal+=cantidadHijosUniversidad*100; //100 soles por cada hijo en la universidad
            if(cantidadHijosUniversidad>cantidadHijosEmpleado){
                cout<<"La cantidad de hijos en la universidad no puede ser mayor a la cantidad de hijos"<<endl;
            }
        }while(cantidadHijosUniversidad>cantidadHijosEmpleado);
    }
}

void mostrarReporte(){
    cout<<"______________Reporte_____________"<<endl;
    cout<<"Sueldo total: "<<sueldoTotal<<endl;
    cout<<"Cantidad de empleados sin esposa: "<<cantidadEmpleadosSinEsposa<<endl;
    cout<<"Cantidad de empleados sin hijos: "<<cantidadEmpleadosSinHijos<<endl;
    cout<<"Cantidad de esposas desempleadas: "<<cantidadEsposasDesempleadas<<endl;
    cout<<"Cantidad de hijos en la universidad: "<<cantidadHijosUniversidad<<endl;
    cout<<"Cantidad de hijos: "<<cantidadHijos<<endl;
}