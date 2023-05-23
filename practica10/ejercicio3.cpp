#include<iostream>

using namespace std;

struct Nodo {
    int dato;
    Nodo* siguiente;
};

Nodo* lista1 = NULL;
Nodo* lista2 = NULL;

void agregarLista1(int dato);
void agregarLista2(int dato);
void mostrarElementos();
void mesclarListas();

int main(){

    int opcion, dato;
    char rpta;

    do {
        cout << "=================MENU=================" << endl;
        cout << "1. Ingresar elemento a LISTA 1" << endl;
        cout << "2. Ingresar elemento a LISTA 2" << endl;
        cout << "3. Mostrar elementos de LISTA 1 Y 2" << endl;
        cout << "4. Mezclar LISTA 1 Y LISTA 2 (ordenado)" << endl;
        cout << "8. Salir" << endl;
        cout << "======================================" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        switch(opcion){
            case 1:
                cout<<"Ingresando datos a la LISTA 1" << endl;
                do{
                    cout<<endl;
                    cout<<"Ingrese un numero que desee agregar a la lista 1: ",
                    cin>>dato;
                    cout<<endl;
                    agregarLista1(dato);
                    do{
                        cout<<"Desea agregar otro elemento a la lista? (S/N): ";
                        cin>>rpta;
                        rpta = toupper(rpta);
                    }while(rpta!='s' && rpta!='S' && rpta!='n' && rpta!='N');
                }while(rpta=='s' || rpta=='S');
                break;
            case 2:
                cout<<"Ingresando datos a la LISTA 2" << endl;
                do{
                    cout<<endl;
                    cout<<"Ingrese un numero que desee agregar a la lista 2: ",
                    cin>>dato;
                    cout<<endl;
                    agregarLista2(dato);
                    do{
                        cout<<"Desea agregar otro elemento a la lista? (S/N): ";
                        cin>>rpta;
                        rpta = toupper(rpta);
                    }while(rpta!='s' && rpta!='S' && rpta!='n' && rpta!='N');
                }while(rpta=='s' || rpta=='S');
                break;

                break;
            case 3:
                cout << "Mostrando elementos de la lista 1 Y 2: "<< endl;
                mostrarElementos();
                break;
            case 4:
                mesclarListas();
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo." << endl;
        }

    }while(opcion != 8);

    return 0;
}

void agregarLista1(int dato){
    Nodo* nuevoNodo = new Nodo();
    nuevoNodo->dato = dato;
    nuevoNodo->siguiente = NULL;

    if (lista1 == NULL) {
        lista1 = nuevoNodo;
    } else {
        Nodo* actual = lista1;
        while (actual->siguiente != NULL) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevoNodo;
    }
}


void agregarLista2(int dato){
    Nodo* nuevoNodo = new Nodo();
    nuevoNodo->dato = dato;
    nuevoNodo->siguiente = NULL;

    if (lista2 == NULL) {
        lista2 = nuevoNodo;
    } else {
        Nodo* actual = lista2;
        while (actual->siguiente != NULL) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevoNodo;
    }
}

void mostrarElementos() {
    Nodo* actual1 = lista1;
    Nodo* actual2 = lista2;

    if (actual1 == NULL) {
        cout << "La lista esta vacia." << endl;
    } else {
        cout<<"================LISTA 1======================"<<endl;
        while (actual1 != NULL) {
            cout << actual1->dato << " - ";
            actual1 = actual1->siguiente;
        }
        cout << endl;
    }

    if (actual2 == NULL) {
        cout << "La lista esta vacia." << endl;
    } else {
        cout<<"================LISTA 2======================"<<endl;
        while (actual2 != NULL) {
            cout << actual2->dato << " - ";
            actual2 = actual2->siguiente;
        }
        cout << endl;
    }
}

void mesclarListas(){
    //mesclar las listas en forma ordenada de menor a mayor y mostrarla
    Nodo* actual1 = lista1;
    Nodo* actual2 = lista2;
    Nodo* lista3 = NULL;

    while(actual1 != NULL){
        Nodo* nuevoNodo = new Nodo();
        nuevoNodo->dato = actual1->dato;
        nuevoNodo->siguiente = NULL;

        if (lista3 == NULL) {
            lista3 = nuevoNodo;
        } else {
            Nodo* actual = lista3;
            while (actual->siguiente != NULL) {
                actual = actual->siguiente;
            }
            actual->siguiente = nuevoNodo;
        }
        actual1 = actual1->siguiente;
    }

    while(actual2 != NULL){
        Nodo* nuevoNodo = new Nodo();
        nuevoNodo->dato = actual2->dato;
        nuevoNodo->siguiente = NULL;

        if (lista3 == NULL) {
            lista3 = nuevoNodo;
        } else {
            Nodo* actual = lista3;
            while (actual->siguiente != NULL) {
                actual = actual->siguiente;
            }
            actual->siguiente = nuevoNodo;
        }
        actual2 = actual2->siguiente;
    }

    //ordenar la lista
    Nodo* actual3 = lista3;
    Nodo* aux = NULL;
    int temp;

    while(actual3 != NULL){
        aux = actual3->siguiente;
        while(aux != NULL){
            if(actual3->dato > aux->dato){
                temp = actual3->dato;
                actual3->dato = aux->dato;
                aux->dato = temp;
            }
            aux = aux->siguiente;
        }
        actual3 = actual3->siguiente;
    }

    //mostrar la lista ordenada
    Nodo* actual4 = lista3;
    if (actual4 == NULL) {
        cout << "La lista esta vacia." << endl;
    } else {
        cout<<"================LISTA 3======================"<<endl;
        while (actual4 != NULL) {
            cout << actual4->dato << " - ";
            actual4 = actual4->siguiente;
        }
        cout << endl;
    }
}