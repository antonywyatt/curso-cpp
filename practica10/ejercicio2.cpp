#include <iostream>
#include <stdlib.h>
using namespace std;
//**********
struct nodo
{
    int dato;
    nodo *sig;
};
//**********
// prototipos de las funciones
void agregarpila(nodo *&, int);
void mostrarPila(nodo *&pila);
void mostrarparesimpares(nodo *&pila);
void sacarpila(nodo *&, int &);
// Función principal
int main()
{
    int dato, i;
    nodo *pila = NULL;
    int opcion;

    //menu
    do {
        cout << "=================MENU=================" << endl;
        cout << "1. Ingresar elemento a la pila" << endl;
        cout << "2. Mostrar elementos de la pila" << endl;
        cout << "3. Cantidad de pares e impares" << endl;
        cout << "4. Eliminar elementos de la pila" << endl;
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
                cout << "Digite numero: ";
                cin >> dato;
                agregarpila(pila, dato);
                cout << "Desea agregar otro elemento? (S/N) ";
                cin >> respuesta;
            } while (respuesta == 's' || respuesta == 'S');
        case 2:
            //mostrar elementos de la pila
            mostrarPila(pila);
            break;
        case 3:
            mostrarparesimpares(pila);
            break;
        case 4:
            cout << "Eliminando elementos de la pila" << endl;
            while (pila != NULL)
            {
                sacarpila(pila, dato);
                if (pila != NULL)
                {
                    cout << dato << " , ";
                }
                else
                {
                    cout << dato << ". "<<endl;
                }
            }
            break;
        case 8:
            cout << "Saliendo..." << endl;
            break;
        default:
            cout << "Opcion no valida" << endl;
            break;
        }
    }while(opcion != 8);
}

void agregarpila(nodo *&pila, int n){
    nodo *nuevonodo = new nodo(); // 1. crear el espacio de memoria para almacenar el nodo
    nuevonodo->dato = n;          // 2. cargar el valor dentro del nodo
    nuevonodo->sig = pila;        // 3. pasar la pila al siguiente nodo
    pila = nuevonodo;             // 4. asignar pila al nuevo nodo
    cout << "\nEl elemento " << n << " Se agregó correctamente \n\n";
}

void mostrarPila(nodo *&pila){
    nodo *aux = pila;
    if (aux == NULL)
    {
        cout << "La pila esta vacia" << endl;
    }
    else
    {
        while (aux != NULL)
        {
            cout << aux->dato << " - " << endl;
            aux = aux->sig;
        }
    }
}

void mostrarparesimpares(nodo *&pila){
    nodo *aux = pila;
    int pares = 0;
    int impares = 0;
    if (aux == NULL)
    {
        cout << "La pila esta vacia" << endl;
    }
    else
    {
        while (aux != NULL)
        {
            if (aux->dato % 2 == 0)
            {
                pares++;
            }
            else
            {
                impares++;
            }
            aux = aux->sig;
        }
        cout << "La pila tiene " << pares << " numeros pares y " << impares << " numeros impares" << endl;
    }
}

void sacarpila(nodo *&pila, int &n){
    nodo *aux = pila; // 1. crear variable auxiliar que señalará la cima de la pila
    n = aux->dato;    // 2. igualar n a la variable auxiliar
    pila = aux->sig;  // 3. Pila debe de pasar al siguiente nodo para que su valor sea diferente denull 
    delete aux;  // 4. Eliminar el nodo
}