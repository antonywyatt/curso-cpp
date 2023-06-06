#include<iostream>

using namespace std;

struct nodo{
    string nombre;
    string direccion;
    string nombreJuego;
    int tiempoPrestamo;
    struct nodo *sgte;
};

struct cola{
    nodo *delante;
    nodo *atras;
};

struct cola q;

void encolar(string nombre, string direccion, string nombreJuego, int tiempoPrestamo);
void mostrarDatos();

int main(){

    //menu de opciones
    int opcion = 0;
    string nombre, direccion, nombreJuego;
    int tiempoPrestamo;

    q.delante = NULL;
    q.atras = NULL;

    while(opcion != 3){
        cout << "=================Menu de opciones=================" << endl;
        cout << "1. Ingresar datos de cliente" << endl;
        cout << "2. Mostrar datos de cliente" << endl;
        cout << "3. Salir" << endl;
        cout << "==================================================" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        switch(opcion){
            case 1:
                char respuesta;
                do{
                    cout << "Ingrese el nombre del cliente: ";
                    cin >> nombre;
                    cout << "Ingrese la direccion del cliente: ";
                    cin >> direccion;
                    cout << "Ingrese el nombre del juego: ";
                    cin >> nombreJuego;
                    cout << "Ingrese el tiempo de prestamo: ";
                    cin >> tiempoPrestamo;
                    encolar(nombre, direccion, nombreJuego, tiempoPrestamo);
                    cout << "Desea ingresar otro cliente? (s/n): ";
                    cin >> respuesta;
                }while(respuesta == 's' || respuesta == 'S');
                break;
            case 2:
                mostrarDatos();
                break;
            case 3:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opcion incorrecta" << endl;
                break;
        }
    }

    return 0;
}

void encolar(string nombre, string direccion, string nombreJuego, int tiempoPrestamo){
    struct nodo*aux = new (struct nodo);
 	aux->nombre = nombre;
    aux->direccion = direccion;
    aux->nombreJuego = nombreJuego;
    aux->tiempoPrestamo = tiempoPrestamo;
 	aux->sgte = NULL;
 	
 	if (q.delante ==NULL)
 	    q.delante = aux;
    else
        (q.atras)->sgte =aux;
    q.atras = aux;
}

void mostrarDatos(){
    struct nodo*aux = new (struct nodo);
    aux = q.delante;
    int montoPagar = 0;
    cout << "==============Datos del cliente=================" << endl;
    while(aux != NULL){
        cout << "Nombre: " << aux->nombre << endl;
        cout << "Direccion: " << aux->direccion << endl;
        cout << "Nombre del juego: " << aux->nombreJuego << endl;
        cout << "Tiempo de prestamo: " << aux->tiempoPrestamo << endl;
        montoPagar = aux->tiempoPrestamo * 10;
        cout << "Monto a pagar: s/. " << montoPagar << endl;
        cout << "================================================" << endl;
        aux = aux->sgte;
    }
}