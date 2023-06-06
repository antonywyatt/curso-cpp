#include<iostream>
#include<string>
#include<fstream>
#include<sstream>

using namespace std;

struct sProyecto{
    int id;
    string nombre;
    int prioridad; // 3:alta, 2;media, 1;baja
    string estado; // pendiente, en proceso, finalizado
    float porcentajeAvance; // 0% - 100%
};

struct Nodo{
    sProyecto proyecto;
    Nodo *sgte;
};

Nodo* listaActividades = NULL;

//funciones para agregar, mostrar, actualizar y finalizar actividad
void agregarActividad(sProyecto proyecto);
void mostrarActividades();
void actualizarActividad(int indice);
void finalizarActividad(int indice);

//funciones para almacenar y recuperar datos
void guardarDatos();
void cargarDatos();

int main()
{
    int dato, i;
    Nodo *pila = NULL;
    int opcion;

    //menu
    do {
        cout << "=================MENU=================" << endl;
        cout << "1. Ingresar actividad" << endl;
        cout << "2. Mostrar actividades" << endl;
        cout << "3. Actualizar actividad" << endl;
        cout << "4. Finalizar actividad" << endl;
        cout << "5. Guardar datos" << endl;
        cout << "6. Recuperar datos" << endl;
        cout << "8. Salir" << endl;
        cout << "======================================" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            //con opcion de continuar o no
            char respuesta;
            do
            {
                cout << "=====CREAR ACTIVIDAD=====" << endl;
                sProyecto proyecto;
                cout << "Digite nombre del proyecto: ";
                cin.ignore();
                getline(cin, proyecto.nombre);
                cout << "Digite prioridad (3:alta, 2:media, 1:baja): "; // alta, media, baja
                do{
                    cin >> proyecto.prioridad;
                    if(proyecto.prioridad != 3 && proyecto.prioridad != 2 && proyecto.prioridad != 1){
                        cout << "Prioridad incorrecta. Digite nuevamente: ";
                    }
                }while(proyecto.prioridad != 3 && proyecto.prioridad != 2 && proyecto.prioridad != 1);
                proyecto.estado = "pendiente";
                proyecto.porcentajeAvance = 0;
                agregarActividad(proyecto);
                cout << "Desea agregar otro elemento? (S/N) ";
                cin >> respuesta;
            } while (respuesta == 's' || respuesta == 'S');
            break;
        case 2:
            //mostrar elementos de la pila
            mostrarActividades();
            break;
        case 3:
            //actualizar actividad
            int indice;
            cout << "Digite indice de actividad a actualizar: ";
            cin >> indice;
            actualizarActividad(indice);
            break;
        case 4:
            //finalizar actividad
            int indice2;
            cout << "Digite indice de actividad a finalizar: ";
            cin >> indice2;
            finalizarActividad(indice2);
            break;
        case 5:
            //guardar datos
            guardarDatos();
            break;
        case 6:
            //recuperar datos
            cargarDatos();
            break;
        }
    } while (opcion != 8);

    return 0;
}

//funciones
void agregarActividad(sProyecto proyecto){
    Nodo *nuevoNodo = new Nodo();
    nuevoNodo->proyecto = proyecto;
    nuevoNodo->sgte = NULL;

    if(listaActividades == NULL){
        listaActividades = nuevoNodo;
    }else{
        Nodo *aux = listaActividades;
        while(aux->sgte != NULL){
            aux = aux->sgte;
        }
        aux->sgte = nuevoNodo;
    }
}

void mostrarActividades(){
    Nodo *aux = listaActividades;
    while(aux != NULL){
        cout << aux->proyecto.nombre << endl;
        aux = aux->sgte;
    }

    cout<< "=============ACTIVIDADES================" << endl;
    aux = listaActividades;
    while(aux != NULL){
        cout<< "Nombre: "<< aux->proyecto.nombre << "\n";
        cout<< "Prioridad: " << aux->proyecto.prioridad;
        if(aux->proyecto.prioridad == 3){
            cout<< " (alta)" << endl;
        }else if(aux->proyecto.prioridad == 2){
            cout<< " (media)" << endl;
        }else if(aux->proyecto.prioridad == 1){
            cout<< " (baja)" << endl;
        }
        cout<< "Estado: " << aux->proyecto.estado << "\n";
        //calcuar porcentaje de avance con barra de progreso
        cout<< "Porcentaje de avance:" << endl;
        cout<< "[";
        for(int i=0; i<aux->proyecto.porcentajeAvance; i++){
            cout << "|";
        }
        cout<< "] " << aux->proyecto.porcentajeAvance << "%" << endl;
        cout << endl;
        aux = aux->sgte;
    }
}

void actualizarActividad(int indice){
    Nodo *aux = listaActividades;
    int contador = 1;
    while(aux != NULL){
        if(contador == indice){
            cout << "Digite prioridad (3:alta, 2:media, 1:baja):"; // alta, media, baja
            do{
                cin >> aux->proyecto.prioridad;
                if(aux->proyecto.prioridad != 3 && aux->proyecto.prioridad != 2 && aux->proyecto.prioridad != 1){
                    cout << "Prioridad incorrecta. Digite nuevamente: ";
                }
            }while(aux->proyecto.prioridad != 3 && aux->proyecto.prioridad != 2 && aux->proyecto.prioridad != 1);

            //nuevo porcentaje de avance
            cout << "Digite nuevo porcentaje de avance: ";
            cin >> aux->proyecto.porcentajeAvance;

            //estado mayor a 0 entonces en proceso y mayor a 100 entonces finalizado
            if(aux->proyecto.porcentajeAvance > 0 && aux->proyecto.porcentajeAvance < 100){
                aux->proyecto.estado = "en proceso";
            }else if(aux->proyecto.porcentajeAvance == 100){
                aux->proyecto.estado = "finalizado 😀";
            }
        }
        aux = aux->sgte;
        contador++;
    }
}

void finalizarActividad(int indice){
    Nodo *aux = listaActividades;
    int contador = 1;
    while(aux != NULL){
        if(contador == indice){
            aux->proyecto.estado = "finalizado 😀";
            aux->proyecto.porcentajeAvance = 100;
        }
        aux = aux->sgte;
        contador++;
    }
}

void guardarDatos(){
    Nodo *aux = listaActividades;
    ofstream archivo;
    archivo.open("actividades.txt", ios::out); //se abre en modo de escritura

    if(archivo.fail()){
        cout << "No se pudo abrir el archivo";
        exit(1);
    }

    while(aux != NULL){
        archivo << aux->proyecto.nombre << endl;
        archivo << aux->proyecto.prioridad << endl;
        archivo << aux->proyecto.estado << endl;
        archivo << aux->proyecto.porcentajeAvance << endl;
        aux = aux->sgte;
    }

    archivo.close();
}

void cargarDatos(){
    ifstream archivo;
    string texto;
    archivo.open("actividades.txt", ios::in); //se abre en modo de lectura

    if(archivo.fail()){
        cout << "No se pudo abrir el archivo";
        exit(1);
    }

    while(!archivo.eof()){ //mientras no sea el final del archivo
        sProyecto proyecto;
        getline(archivo, texto);
        if(texto.empty()){
            break;
        }
        proyecto.nombre = texto;
        getline(archivo, texto);
        proyecto.prioridad = atoi(texto.c_str()); //convierte string a entero
        getline(archivo, texto);
        proyecto.estado = texto;
        getline(archivo, texto);
        proyecto.porcentajeAvance = atoi(texto.c_str()); //convierte string a entero
        agregarActividad(proyecto);
    }

    archivo.close();
}