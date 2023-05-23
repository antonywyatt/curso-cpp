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
void sacarpila(nodo *&, int &);
// Función principal
int main()
{
    setlocale(LC_CTYPE, "Spanish");
    int dato, i, cant;
    nodo *pila = NULL; // variable tipo nodo llamada pila donde se asigna el valor nulo
    cout << "Ingrese cantidad de nodos : \n";
    cin >> cant;
    for (i = 1; i <= cant; i++)
    {
        cout << "Digite numero: ";
        cin >> dato;
        agregarpila(pila, dato);
    }
    cout << "sacando valores de la pila \n";
    while (pila != NULL)
    {
        sacarpila(pila, dato);
        if (pila != NULL)
        {
            cout << dato << " , ";
        }
        else
        {
            cout << dato << ". ";
        }
    }
}
void agregarpila(nodo *&pila, int n)
{
    nodo *nuevonodo = new nodo(); // 1. crear el espacio de memoria para almacenar el nodo
    nuevonodo->dato = n;          // 2. cargar el valor dentro del nodo
    nuevonodo->sig = pila;        // 3. pasar la pila al siguiente nodo
    pila = nuevonodo;             // 4. asignar pila al nuevo nodo
    cout << "\nEl elemento " << n << " Se agregó correctamente \n\n";
}
void sacarpila(nodo *&pila, int &n)
{
    nodo *aux = pila; // 1. crear variable auxiliar que señalará la cima de la pila
    n = aux->dato;    // 2. igualar n a la variable auxiliar
    pila = aux->sig;  // 3. Pila debe de pasar al siguiente nodo para que su valor sea diferente denull 
    delete aux;  // 4. Eliminar el nodo
}