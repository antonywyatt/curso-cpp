// ListaCircularDoble.h
#include <iostream>
#ifndef LISTACIRCULARDOBLE_H
#define LISTACIRCULARDOBLE_H

using namespace std;

struct Nodo {
    int dato;
    Nodo* siguiente;
    Nodo* anterior;
};

class ListaCircularDoble {
public:
    ListaCircularDoble();
    ~ListaCircularDoble();
    void agregar(int valor);
    void eliminar(int valor);
    void imprimir();
private:
    Nodo* cabeza;
};

#endif

ListaCircularDoble::ListaCircularDoble() : cabeza(nullptr) {}

ListaCircularDoble::~ListaCircularDoble() {
    if (!cabeza) {
        return;
    }
    Nodo* actual = cabeza;
    do {
        Nodo* siguiente = actual->siguiente;
        delete actual;
        actual = siguiente;
    } while (actual != cabeza);
}

void ListaCircularDoble::agregar(int valor) {
    Nodo* nuevoNodo = new Nodo{valor, nullptr, nullptr};
    if (!cabeza) {
        cabeza = nuevoNodo;
        cabeza->siguiente = cabeza;
        cabeza->anterior = cabeza;
    } else {
        Nodo* actual = cabeza;
        while (actual->siguiente != cabeza) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevoNodo;
        nuevoNodo->anterior = actual;
        nuevoNodo->siguiente = cabeza;
        cabeza->anterior = nuevoNodo;
    }
}

void ListaCircularDoble::eliminar(int valor) {
    if (!cabeza) {
        return; // Lista vacía, no se puede eliminar
    }

    Nodo* actual = cabeza;
    do {
        if (actual->dato == valor) {
            Nodo* nodoEliminar = actual;
            Nodo* anterior = actual->anterior;
            Nodo* siguiente = actual->siguiente;

            anterior->siguiente = siguiente;
            siguiente->anterior = anterior;

            if (actual == cabeza) {
                cabeza = siguiente;
            }

            delete nodoEliminar;
            return;
        }
        actual = actual->siguiente;
    } while (actual != cabeza);
}

void ListaCircularDoble::imprimir() {
    if (!cabeza) {
        return;
    }
    Nodo* actual = cabeza;
    do {
        cout << actual->dato << " ";
        actual = actual->siguiente;
    } while (actual != cabeza);
    cout << endl;
}
