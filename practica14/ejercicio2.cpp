/*Insertar un nodo en un árbol*/
#include <iostream>
#include <stdlib.h>
using namespace std;
// crear la estructura nodo para un arbol
struct nodo
{
    int dato;
    nodo *der;
    nodo *izq;
};
// VARIABLE GLOBAL
int cantidadNodo = 0; // contador de nodos
int alturaArbol = 0; // contador de altura del arbol

// prototipos de las funciones
nodo *crearnodo(int);
void insertarnodo(nodo *&arbol, int n);
void mostrararbol(nodo *arbol, int cont);
bool busqueda(nodo *arbol, int n);
void preorden(nodo *arbol);          // Muestra los elementos siguiente raiz, izquierda, derecha 
void inorden(nodo *arbol);   // Muestra los elementos siguientes: izquierda - raiz -derecha 
void postorden(nodo *arbol); // Muestra los elementos siguientes:izquierda - derecha- raiz 
int altura(nodo *arbol);
void menu();
// crear un nodo árbol con valor NULL
nodo *arbol = NULL;
// Programa principal
int main()
{
    setlocale(LC_CTYPE, "Spanish");
    menu();
}
// funcion para crear un nodo
nodo *crearnodo(int n)
{
    nodo *nuevonodo = new nodo(); // asignamos espacio de memorial al nuevo nodo
    nuevonodo->dato = n;          // asignamos el valor de n al nuevo nodo
    nuevonodo->der = NULL;        // asignamos null al hijo derecho
    nuevonodo->izq = NULL;        // asignamos null al hijo izquierdo
    return nuevonodo;             // retornamos el nuevo nodo creado
}
// funcion para isertar valores al árbol
void insertarnodo(nodo *&arbol, int n)
{
    if (arbol == NULL)
    {
        nodo *nuevonodo = crearnodo(n); // se crea un nuevo nodo al árbol
        arbol = nuevonodo;              // asignamos un elemento a la raiz
    }
    else
    {
        int valorraiz = arbol->dato; // creamos una variable para poder asignar el elemento dato del árbol 
        if (n < valorraiz)
        {                                // Permite comprobar el elemento si es menor o no
            insertarnodo(arbol->izq, n); // inserta valor en el lado izquierdo del árbol
        }
        else
        {
            insertarnodo(arbol->der, n); // inserta valor en el lado derecho del árbol
        }
    }
}
// funcion para mostrar los elementos del árbol
void mostrararbol(nodo *arbol, int cont)
{
    //inicializar en 0
    if (arbol == NULL)
    {
        return;
    }
    else
    {
        mostrararbol(arbol->der, cont + 1);
        // Sumando los nodos
        cantidadNodo++;

        // imprimir arbol
        for (int i = 0; i < cont; i++)
        {
            cout << " ";
        }
        cout << arbol->dato << endl;
        mostrararbol(arbol->izq, cont + 1);
    }
}
// funcion busqueda

bool busqueda(nodo *arbol, int n)
{
    if (arbol == NULL)
    {
        return false;
    }
    else if (arbol->dato == n)
    { // si el dato se encuentra en el primer lugar
        return true;
    }
    else if (n < arbol->dato)
    {
        return busqueda(arbol->izq, n); // realizar la busqueda por el lado izquierdo
    }
    else
    {
        return busqueda(arbol->der, n); // realizar la busqueda por el lado derecho
    }
}
// Funcion de recorrido en PREORDEN (raiz - izquierda - derecha)
void preorden(nodo *arbol)
{
    if (arbol == NULL)
    {
        return;
    }
    else
    {
        cout << arbol->dato << " "; // Imprimir la raiz
        preorden(arbol->izq);       // realiza el recorrido por el lado izquierdo
        preorden(arbol->der);       // realiza el recorrido por el lado derecho
    }
}
void inorden(nodo *arbol)
{
    if (arbol == NULL)
    {
        return;
    }
    else
    {
        inorden(arbol->izq);
        cout << arbol->dato << " - ";
        inorden(arbol->der);
    }
}
void postorden(nodo *arbol)
{
    if (arbol == NULL)
    {
        return;
    }
    else
    {
        postorden(arbol->izq);
        postorden(arbol->der);
        cout << arbol->dato << " - ";
    }
}

int altura(nodo *arbol)
{
    int alturaIzq, alturaDer;
    if (arbol == NULL)
    {
        return -1;
    }
    else
    {
        alturaIzq = altura(arbol->izq);
        alturaDer = altura(arbol->der);
        if (alturaIzq > alturaDer)
        {
            return alturaIzq + 1;
        }
        else
        {
            return alturaDer + 1;
        }
    }
}

// Funcion menu
void menu()
{
    int dato, op, cont = 0;
    setlocale(LC_CTYPE, "Spanish");
    do
    {
        cout << "\t \t Menu de Opciones \n ";
        cout << "\t [1] Insertar nuevo nodo \n";
        cout << "\t [2] Mostrar cantidad y altura del árbol \n";
        cout << "\t [3] Búsqueda de un Nodo \n";
        cout << "\t [4] Recorrido Pre Orden \n";
        cout << "\t [5] Recorrido In Orden \n";
        cout << "\t [6] Recorrido Post Orden \n";
        cout << "\t [7] Salir del Programa \n";
        cout << "\t Elegir opcion: ";
        cin >> op;
        switch (op)
        {
        case 1:
            cout << "INGRESO DE DATOS AL ÁRBOL\n";
            cout << "Ingrese elemento al árbol: ";
            cin >> dato;
            insertarnodo(arbol, dato);
            break;
        case 2:
            cout << "\n==============================\n";
            cout << "MOSTRAR ELEMENTOS DEL ÁRBOL \n";
            cout << "==============================\n\n";
            cantidadNodo = 0;
            mostrararbol(arbol, cont);
            cout << "\n\n==============================\n";
            cout << "CANTIDAD DE NODOS: " << cantidadNodo << endl;
            cout << "ALTURA DEL ÁRBOL: " << altura(arbol) << endl;
            cout << "==============================\n";
            break;
        case 3:
            cout << "BUSQUEDA DE UN ELEMENTO EN EL ÁRBOL \n";
            cout << "Ingrese elemento a buscar: ";
            cin >> dato;
            if (busqueda(arbol, dato) == true)
            {
                cout << "Elemento " << dato << " ha sido encontrado \n";
            }
            else
            {
                cout << "Elemento " << dato << " no existe \n";
            }
            break;
        case 4:
            cout << "RECORRIDO EN PRE ORDEN \n";
            preorden(arbol);
            cout << "\n \n ";
            break;
        case 5:
            cout << "RECORRIDO IN ORDEN \n";
            inorden(arbol);
            cout << "\n \n";
            break;
        case 6:
            cout << "RECORRIDO POST ORDEN \n";
            postorden(arbol);
            cout << "\n \n";
            break;
        }
        system("pause");
        system("cls");
    } while (op != 7);
}